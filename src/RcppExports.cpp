// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// call_hash
std::string call_hash(SEXP s);
RcppExport SEXP _Resonance_call_hash(SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type s(sSEXP);
    rcpp_result_gen = Rcpp::wrap(call_hash(s));
    return rcpp_result_gen;
END_RCPP
}
// forceCopy
NumericMatrix forceCopy(NumericMatrix m);
RcppExport SEXP _Resonance_forceCopy(SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(forceCopy(m));
    return rcpp_result_gen;
END_RCPP
}
// shiftRows
void shiftRows(SEXP m, int shift);
RcppExport SEXP _Resonance_shiftRows(SEXP mSEXP, SEXP shiftSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type shift(shiftSEXP);
    shiftRows(m, shift);
    return R_NilValue;
END_RCPP
}
// pushRows_bottom
void pushRows_bottom(NumericMatrix m, NumericMatrix p);
RcppExport SEXP _Resonance_pushRows_bottom(SEXP mSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type m(mSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type p(pSEXP);
    pushRows_bottom(m, p);
    return R_NilValue;
END_RCPP
}
// pushRows_top
void pushRows_top(NumericMatrix m, NumericMatrix p);
RcppExport SEXP _Resonance_pushRows_top(SEXP mSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type m(mSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type p(pSEXP);
    pushRows_top(m, p);
    return R_NilValue;
END_RCPP
}
// push_slice_rows_back
void push_slice_rows_back(NumericMatrix dest, NumericMatrix src, int slicePos, int sliceSize);
RcppExport SEXP _Resonance_push_slice_rows_back(SEXP destSEXP, SEXP srcSEXP, SEXP slicePosSEXP, SEXP sliceSizeSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type dest(destSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type src(srcSEXP);
    Rcpp::traits::input_parameter< int >::type slicePos(slicePosSEXP);
    Rcpp::traits::input_parameter< int >::type sliceSize(sliceSizeSEXP);
    push_slice_rows_back(dest, src, slicePos, sliceSize);
    return R_NilValue;
END_RCPP
}
// rowsCopy
void rowsCopy(NumericMatrix dest, int destBegin, NumericMatrix src, int srcBegin, int srcSize);
RcppExport SEXP _Resonance_rowsCopy(SEXP destSEXP, SEXP destBeginSEXP, SEXP srcSEXP, SEXP srcBeginSEXP, SEXP srcSizeSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type dest(destSEXP);
    Rcpp::traits::input_parameter< int >::type destBegin(destBeginSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type src(srcSEXP);
    Rcpp::traits::input_parameter< int >::type srcBegin(srcBeginSEXP);
    Rcpp::traits::input_parameter< int >::type srcSize(srcSizeSEXP);
    rowsCopy(dest, destBegin, src, srcBegin, srcSize);
    return R_NilValue;
END_RCPP
}
// replace_columns_block
void replace_columns_block(SEXP m, int destRow, int destCol, NumericMatrix src);
RcppExport SEXP _Resonance_replace_columns_block(SEXP mSEXP, SEXP destRowSEXP, SEXP destColSEXP, SEXP srcSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type destRow(destRowSEXP);
    Rcpp::traits::input_parameter< int >::type destCol(destColSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type src(srcSEXP);
    replace_columns_block(m, destRow, destCol, src);
    return R_NilValue;
END_RCPP
}
// copyColumns
void copyColumns(NumericMatrix dest, NumericMatrix src, IntegerVector cols);
RcppExport SEXP _Resonance_copyColumns(SEXP destSEXP, SEXP srcSEXP, SEXP colsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type dest(destSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type src(srcSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type cols(colsSEXP);
    copyColumns(dest, src, cols);
    return R_NilValue;
END_RCPP
}

RcppExport SEXP upfirdn__apply_multichannel(SEXP, SEXP);
RcppExport SEXP upfirdn__new(SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_Resonance_call_hash", (DL_FUNC) &_Resonance_call_hash, 1},
    {"_Resonance_forceCopy", (DL_FUNC) &_Resonance_forceCopy, 1},
    {"_Resonance_shiftRows", (DL_FUNC) &_Resonance_shiftRows, 2},
    {"_Resonance_pushRows_bottom", (DL_FUNC) &_Resonance_pushRows_bottom, 2},
    {"_Resonance_pushRows_top", (DL_FUNC) &_Resonance_pushRows_top, 2},
    {"_Resonance_push_slice_rows_back", (DL_FUNC) &_Resonance_push_slice_rows_back, 4},
    {"_Resonance_rowsCopy", (DL_FUNC) &_Resonance_rowsCopy, 5},
    {"_Resonance_replace_columns_block", (DL_FUNC) &_Resonance_replace_columns_block, 4},
    {"_Resonance_copyColumns", (DL_FUNC) &_Resonance_copyColumns, 3},
    {"upfirdn__apply_multichannel",      (DL_FUNC) &upfirdn__apply_multichannel,      2},
    {"upfirdn__new",                     (DL_FUNC) &upfirdn__new,                     3},
    {NULL, NULL, 0}
};

RcppExport void R_init_Resonance(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
