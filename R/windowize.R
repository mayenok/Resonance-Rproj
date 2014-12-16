#' Split data stream to windows using event stream
#' 
#' @param data Data stream
#' @param events Events stream
#' @param windowSize Size of resulting window
#' @param backBuffer Size of buffer for data, may be increased in case of big delay in events arrival
#' @return pipe with type=window
cross.windowizeByEvents <- function(data, events, windowSize, backBuffer=10000){
  bp <- block.processor(data, type="window", size=windowSize)
  
  backBuffer <- max(backBuffer, windowSize*2)
  
  backBuffer <- matrix(NA, ncol=data$channels, nrow=backBuffer)
  
  lastTS <- NA
  lastSample <- 0
  grabSample <- Inf
  
  ifWindowReady <- function(){
    if(grabSample <= lastSample){
      last <- nrow(backBuffer)-(lastSample-grabSample)
      block <- backBuffer[ (last-windowSize+1):last,, drop=F]
      ts <- lastTS - (lastSample-grabSample)*1E9/data$samplingRate
      
      bp$emit(DataBlock(block, ts))
      
      grabSample <<- Inf
    }
  }
  
  data$connect(function(db){
    # populate backBuffer
    data <- as.matrix(db)
    backBuffer[1:(nrow(backBuffer)-nrow(data)),] <<- backBuffer[(nrow(data)+1):nrow(backBuffer),, drop=F]
    backBuffer[(nrow(backBuffer)-nrow(data)+1):nrow(backBuffer), ] <<- data
    lastTS <<- attr(db, 'timestamp')
    lastSample <<- lastSample+nrow(data)
    ifWindowReady()
  })
  
  events$connect(function(db){
    time <- attr(db,'timestamp')
    # recalc time to samples
     
    grabSample <<- lastSample + floor((time-lastTS)*data$samplingRate/1E9) + windowSize
    ifWindowReady()
  })
  
  bp
}