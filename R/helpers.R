SI.channels <- function(channels, samplingRate){
  list(
    type='channels',
    channels=channels,
    samplingRate=samplingRate
    )
}

SI.window <- function(channels, samples, samplingRate){
  list(
    type='window',
    channels = channels,
    samples = samples,
    samplingRate = samplingRate
    )
}

SI.event <- function(){
  list(
    type='event'
    )
}

SI.is.channels <- function(input){
  r <- SI(input)$type=='channels'
  all(r, length(r)>0)
}

SI.is.window <- function(input){
  r <- SI(input)$type=='window'
  all(r, length(r)>0)
}

SI.is.event <- function(input){
  r <- SI(input)$type == 'event'
  all(r, length(r)>0)
}

SI <- function(input){
  attr(input, '.StreamInfo')
}

`SI<-` <- function(x, name=NULL, value){
  if(is.null(name)) {
    attr(x, '.StreamInfo') <- value
  } else {
    attr(x, '.StreamInfo')[[name]] <- value
  }
  x
}

.processor_cache <- new.env()
.processor_si_cache <- new.env()
.reset_processor_cache <- function(){
  rm(list = ls(.processor_cache),envir = .processor_cache)
  rm(list = ls(.processor_si_cache),envir = .processor_si_cache)
}

#' Wraps all necessary handlers to pipeline function
#'
#'
processor <- function(
  ...,
  prepare,
  online,
  offline=NULL
  ){

  inputs <- list(...)
  #check if it is online stream and already initialized
  # need to carefully hash callstack
  # it is hack here

  #sc <- as.list(sys.frame(-1))
  #sc[ sc %in% inputs ] <- NULL
  #sc <- as.list(sys.frame(-1))

  #hash <- paste('RE',digest(sys.call(-1)), digest(sc), sep = '_')
  hash <- paste0('RE_', digest(sys.call(-1)))


  if(is.null(.processor_cache[[hash]]))
  {
    env <- new.env(parent=environment(online))

    si <- prepare(env)
    if(is.character(si)) stop(si)

    if(!is.null(SI(inputs[[1]])$online)){
      # prepare online processing
      environment(online) <- env
      .processor_cache[[hash]] <- online;
      .processor_si_cache[[hash]] <- si;
      result <- list()
      SI(result) <- si
      SI(result, 'online') <- TRUE
      return(result)
    } else {
      result <- if(is.null(offline)){
        environment(online) <- env
        online(...)
      } else {
        environment(offline) <- env
        offline(...)
      }
      SI(result) <- si
      return(result);
    }
  }
  else
  {
    # perform online processing
    result <- do.call(.processor_cache[[hash]], inputs)
    SI(result) <- .processor_si_cache[[hash]]
    return(result)
  }
}