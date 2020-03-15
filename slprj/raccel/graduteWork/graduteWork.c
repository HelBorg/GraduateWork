#include "__cf_graduteWork.h"
#include "rt_logging_mmi.h"
#include "graduteWork_capi.h"
#include <math.h>
#include "graduteWork.h"
#include "graduteWork_private.h"
#include "graduteWork_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 7 , & stopRequested ) ; }
rtExtModeShutdown ( 7 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 8 ; const char_T
* gbl_raccel_Version = "10.0 (R2019b) 18-Jul-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\graduteWork\\graduteWork_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ;
const char * raccelLoadInputsAndAperiodicHitTimes ( const char *
inportFileName , int * matFileFormat ) { return rt_RapidReadInportsMatFile (
inportFileName , matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static uint32_T m5gq5dremb ( void ) ; static real_T lrygujtyg2j (
uint32_T state [ 625 ] ) ; static real_T jmu25rrt32 ( void ) ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * tBufPtr ; real_T *
xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer =
3 ; xBuf = * xBufPtr ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) :
0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
tBufPtr = tempT ; * uBufPtr = tempU ; if ( istransportdelay ) * xBufPtr =
tempX ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * tBuf ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } static uint32_T
m5gq5dremb ( void ) { return 7U ; } void RandSrcInitState_GZ ( const uint32_T
seed [ ] , uint32_T state [ ] , int32_T nChans ) { int32_T i ; for ( i = 0 ;
i < nChans ; i ++ ) { state [ i << 1 ] = 362436069U ; state [ ( i << 1 ) + 1
] = seed [ i ] == 0U ? 521288629U : seed [ i ] ; } } static real_T
lrygujtyg2j ( uint32_T state [ 625 ] ) { real_T r ; uint32_T b_u [ 2 ] ;
uint32_T mti ; uint32_T y ; int32_T b_kk ; int32_T k ; boolean_T b_isvalid ;
int32_T exitg1 ; boolean_T exitg2 ; do { exitg1 = 0 ; for ( k = 0 ; k < 2 ; k
++ ) { mti = state [ 624 ] + 1U ; if ( mti >= 625U ) { for ( b_kk = 0 ; b_kk
< 227 ; b_kk ++ ) { y = ( state [ b_kk + 1 ] & 2147483647U ) | ( state [ b_kk
] & 2147483648U ) ; if ( ( y & 1U ) == 0U ) { y >>= 1U ; } else { y = y >> 1U
^ 2567483615U ; } state [ b_kk ] = state [ b_kk + 397 ] ^ y ; } for ( b_kk =
0 ; b_kk < 396 ; b_kk ++ ) { y = ( state [ b_kk + 227 ] & 2147483648U ) | (
state [ b_kk + 228 ] & 2147483647U ) ; if ( ( y & 1U ) == 0U ) { y >>= 1U ; }
else { y = y >> 1U ^ 2567483615U ; } state [ b_kk + 227 ] = state [ b_kk ] ^
y ; } y = ( state [ 623 ] & 2147483648U ) | ( state [ 0 ] & 2147483647U ) ;
mti = 1U ; if ( ( y & 1U ) == 0U ) { y >>= 1U ; } else { y = y >> 1U ^
2567483615U ; } state [ 623 ] = state [ 396 ] ^ y ; } y = state [ ( int32_T )
mti - 1 ] ; state [ 624 ] = mti ; y ^= y >> 11U ; y ^= y << 7U & 2636928640U
; y ^= y << 15U & 4022730752U ; b_u [ k ] = y >> 18U ^ y ; } r = ( ( real_T )
( b_u [ 0 ] >> 5U ) * 6.7108864E+7 + ( real_T ) ( b_u [ 1 ] >> 6U ) ) *
1.1102230246251565E-16 ; if ( r == 0.0 ) { if ( ( state [ 624 ] >= 1U ) && (
state [ 624 ] < 625U ) ) { b_isvalid = false ; k = 1 ; exitg2 = false ; while
( ( ! exitg2 ) && ( k < 625 ) ) { if ( state [ k - 1 ] == 0U ) { k ++ ; }
else { b_isvalid = true ; exitg2 = true ; } } } else { b_isvalid = false ; }
if ( ! b_isvalid ) { mti = 5489U ; state [ 0 ] = 5489U ; for ( k = 0 ; k <
623 ; k ++ ) { mti = ( ( mti >> 30U ^ mti ) * 1812433253U + k ) + 1U ; state
[ k + 1 ] = mti ; } state [ 624 ] = 624U ; } } else { exitg1 = 1 ; } } while
( exitg1 == 0 ) ; return r ; } static real_T jmu25rrt32 ( void ) { real_T r ;
uint32_T INIT_FACTOR ; uint32_T r_p ; int32_T b_mti ; if ( rtDW . h4hok5wmjg
== 4U ) { INIT_FACTOR = rtDW . gn3icq1q2g / 127773U ; r_p = ( rtDW .
gn3icq1q2g - INIT_FACTOR * 127773U ) * 16807U ; INIT_FACTOR *= 2836U ; if (
r_p < INIT_FACTOR ) { INIT_FACTOR = ~ ( INIT_FACTOR - r_p ) & 2147483647U ; }
else { INIT_FACTOR = r_p - INIT_FACTOR ; } rtDW . gn3icq1q2g = INIT_FACTOR ;
r = ( real_T ) INIT_FACTOR * 4.6566128752457969E-10 ; } else if ( rtDW .
h4hok5wmjg == 5U ) { INIT_FACTOR = 69069U * rtDW . bizznvvjue [ 0 ] +
1234567U ; r_p = rtDW . bizznvvjue [ 1 ] << 13 ^ rtDW . bizznvvjue [ 1 ] ;
r_p ^= r_p >> 17 ; r_p ^= r_p << 5 ; rtDW . bizznvvjue [ 0 ] = INIT_FACTOR ;
rtDW . bizznvvjue [ 1 ] = r_p ; r = ( real_T ) ( INIT_FACTOR + r_p ) *
2.328306436538696E-10 ; } else { if ( ! rtDW . azmor0scbe ) { memset ( & rtDW
. od4sllwisx [ 0 ] , 0 , 625U * sizeof ( uint32_T ) ) ; r_p = 5489U ; rtDW .
od4sllwisx [ 0 ] = 5489U ; for ( b_mti = 0 ; b_mti < 623 ; b_mti ++ ) { r_p =
( ( r_p >> 30U ^ r_p ) * 1812433253U + b_mti ) + 1U ; rtDW . od4sllwisx [
b_mti + 1 ] = r_p ; } rtDW . od4sllwisx [ 624 ] = 624U ; rtDW . azmor0scbe =
true ; } r = lrygujtyg2j ( rtDW . od4sllwisx ) ; } return r ; } void
RandSrc_GZ_D ( real_T y [ ] , const real_T mean [ ] , int32_T meanLen , const
real_T xstd [ ] , int32_T xstdLen , uint32_T state [ ] , int32_T nChans ,
int32_T nSamps ) { int32_T i ; int32_T j ; real_T r ; real_T x ; real_T s ;
real_T y_p ; int32_T chan ; real_T std ; uint32_T icng ; uint32_T jsr ;
int32_T samp ; static const real_T vt [ 65 ] = { 0.340945 , 0.4573146 ,
0.5397793 , 0.6062427 , 0.6631691 , 0.7136975 , 0.7596125 , 0.8020356 ,
0.8417227 , 0.8792102 , 0.9148948 , 0.9490791 , 0.9820005 , 1.0138492 ,
1.044781 , 1.0749254 , 1.1043917 , 1.1332738 , 1.161653 , 1.189601 ,
1.2171815 , 1.2444516 , 1.2714635 , 1.298265 , 1.3249008 , 1.3514125 ,
1.3778399 , 1.4042211 , 1.4305929 , 1.4569915 , 1.4834527 , 1.5100122 ,
1.5367061 , 1.5635712 , 1.5906454 , 1.617968 , 1.6455802 , 1.6735255 ,
1.7018503 , 1.7306045 , 1.7598422 , 1.7896223 , 1.8200099 , 1.851077 ,
1.8829044 , 1.9155831 , 1.9492166 , 1.9839239 , 2.0198431 , 2.0571356 ,
2.095993 , 2.136645 , 2.1793713 , 2.2245175 , 2.2725186 , 2.3239338 ,
2.3795008 , 2.4402218 , 2.5075117 , 2.5834658 , 2.6713916 , 2.7769942 ,
2.7769942 , 2.7769942 , 2.7769942 } ; for ( chan = 0 ; chan < nChans ; chan
++ ) { std = xstd [ xstdLen > 1 ? chan : 0 ] ; icng = state [ chan << 1 ] ;
jsr = state [ ( chan << 1 ) + 1 ] ; for ( samp = 0 ; samp < nSamps ; samp ++
) { icng = 69069U * icng + 1234567U ; jsr ^= jsr << 13 ; jsr ^= jsr >> 17 ;
jsr ^= jsr << 5 ; i = ( int32_T ) ( icng + jsr ) ; j = ( i & 63 ) + 1 ; r = (
real_T ) i * 4.6566128730773926E-10 * vt [ j ] ; if ( ! ( muDoubleScalarAbs (
r ) <= vt [ j - 1 ] ) ) { x = ( muDoubleScalarAbs ( r ) - vt [ j - 1 ] ) / (
vt [ j ] - vt [ j - 1 ] ) ; icng = 69069U * icng + 1234567U ; jsr ^= jsr <<
13 ; jsr ^= jsr >> 17 ; jsr ^= jsr << 5 ; y_p = ( real_T ) ( int32_T ) ( icng
+ jsr ) * 2.328306436538696E-10 + 0.5 ; s = x + y_p ; if ( s > 1.301198 ) { r
= r < 0.0 ? 0.4878992 * x - 0.4878992 : 0.4878992 - 0.4878992 * x ; } else {
if ( ! ( s <= 0.9689279 ) ) { x = 0.4878992 - 0.4878992 * x ; if ( y_p >
12.67706 - muDoubleScalarExp ( - 0.5 * x * x ) * 12.37586 ) { r = r < 0.0 ? -
x : x ; } else { if ( ! ( muDoubleScalarExp ( - 0.5 * vt [ j ] * vt [ j ] ) +
y_p * 0.01958303 / vt [ j ] <= muDoubleScalarExp ( - 0.5 * r * r ) ) ) { do {
icng = 69069U * icng + 1234567U ; jsr ^= jsr << 13 ; jsr ^= jsr >> 17 ; jsr
^= jsr << 5 ; x = muDoubleScalarLog ( ( real_T ) ( int32_T ) ( icng + jsr ) *
2.328306436538696E-10 + 0.5 ) / 2.776994 ; icng = 69069U * icng + 1234567U ;
jsr ^= jsr << 13 ; jsr ^= jsr >> 17 ; jsr ^= jsr << 5 ; } while (
muDoubleScalarLog ( ( real_T ) ( int32_T ) ( icng + jsr ) *
2.328306436538696E-10 + 0.5 ) * - 2.0 <= x * x ) ; r = r < 0.0 ? x - 2.776994
: 2.776994 - x ; } } } } } y [ chan * nSamps + samp ] = mean [ meanLen > 1 ?
chan : 0 ] + std * r ; } state [ chan << 1 ] = icng ; state [ ( chan << 1 ) +
1 ] = jsr ; } } void MdlInitialize ( void ) { int32_T i ; rtX . fipgb2dv5w =
0.0 ; rtDW . gidxstxvag = ( rtInf ) ; rtDW . hrgwoqkxsi = ( rtInf ) ; rtX .
ewcbusxpqt [ 0 ] = 0.0 ; rtX . ewcbusxpqt [ 1 ] = 0.0 ; rtDW . hlvhcmlowo =
rtP . AWGNChannel1_seed ; RandSrcInitState_GZ ( & rtDW . hlvhcmlowo , & rtDW
. jbppeizd1x [ 0 ] , 1 ) ; for ( i = 0 ; i < 9 ; i ++ ) { rtDW . akitjtxsla [
i ] = rtP . DiscreteFIRFilter_InitialStates ; } rtDW . bojqotfxnb = rtP .
AWGNChannel_seed ; RandSrcInitState_GZ ( & rtDW . bojqotfxnb , & rtDW .
nc0dkv5gky [ 0 ] , 1 ) ; for ( i = 0 ; i < 9 ; i ++ ) { rtDW . hc5gld2nwz [ i
] = rtP . DiscreteFIRFilter_InitialStates_bcwzpsb0dc ; } } void MdlEnable (
void ) { rtDW . iik5cqzr1o = 1 ; _ssSetSampleHit ( rtS , 5 , 1 ) ;
_ssSetTaskTime ( rtS , 5 , ssGetT ( rtS ) ) ; _ssSetVarNextHitTime ( rtS , 2
, ssGetT ( rtS ) ) ; ; rtDW . o0aqq215bl = 1 ; _ssSetSampleHit ( rtS , 6 , 1
) ; _ssSetTaskTime ( rtS , 6 , ssGetT ( rtS ) ) ; _ssSetVarNextHitTime ( rtS
, 3 , ssGetT ( rtS ) ) ; ; rtDW . a0nnxzfeub = 1 ; _ssSetSampleHit ( rtS , 3
, 1 ) ; _ssSetTaskTime ( rtS , 3 , ssGetT ( rtS ) ) ; _ssSetVarNextHitTime (
rtS , 0 , ssGetT ( rtS ) ) ; ; rtDW . etw2p5ad3w = 1 ; _ssSetSampleHit ( rtS
, 4 , 1 ) ; _ssSetTaskTime ( rtS , 4 , ssGetT ( rtS ) ) ;
_ssSetVarNextHitTime ( rtS , 1 , ssGetT ( rtS ) ) ; ; } void MdlStart ( void
) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = (
NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const int
maxErrorBufferSize = 16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ;
bool errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { int_T j ; { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "vtdelay memory allocation error" )
; return ; } rtDW . n3mlm25bwm . Tail = 0 ; rtDW . n3mlm25bwm . Head = 0 ;
rtDW . n3mlm25bwm . Last = 0 ; rtDW . n3mlm25bwm . CircularBufSize = 1024 ;
for ( j = 0 ; j < 1024 ; j ++ ) { pBuffer [ j ] = rtP .
VariableTimeDelay1_InitOutput ; pBuffer [ 1024 + j ] = ssGetT ( rtS ) ; }
rtDW . fqydmkxc1f . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
fqydmkxc1f . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { int_T
j ; { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof
( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } rtDW . idh4wrqtoh . Tail = 0
; rtDW . idh4wrqtoh . Head = 0 ; rtDW . idh4wrqtoh . Last = 0 ; rtDW .
idh4wrqtoh . CircularBufSize = 1024 ; for ( j = 0 ; j < 1024 ; j ++ ) {
pBuffer [ j ] = rtP . VariableTimeDelay_InitOutput ; pBuffer [ 1024 + j ] =
ssGetT ( rtS ) ; } rtDW . h20mxqf3h4 . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; rtDW . h20mxqf3h4 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer
[ 1024 ] ; } } rtDW . h4hok5wmjg = m5gq5dremb ( ) ; rtDW . j4s4odcqip = true
; rtDW . gn3icq1q2g = 1144108930U ; rtDW . lbx1mtfejs = true ; rtDW .
bizznvvjue [ 0 ] = 362436069U ; rtDW . bizznvvjue [ 1 ] = 521288629U ; rtDW .
myt1d5w44r = true ; rtDW . eihuvcejq2 = true ; rtDW . cg25jop35d .
isInitialized = 1 ; { int_T j ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ;
} rtDW . aqjeiun535 . Tail = 0 ; rtDW . aqjeiun535 . Head = 0 ; rtDW .
aqjeiun535 . Last = 0 ; rtDW . aqjeiun535 . CircularBufSize = 1024 ; for ( j
= 0 ; j < 1024 ; j ++ ) { pBuffer [ j ] = rtP .
VariableTimeDelay_InitOutput_bhowtxsjbn ; pBuffer [ 1024 + j ] = ssGetT ( rtS
) ; } rtDW . pz2yc0tozj . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
rtDW . pz2yc0tozj . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } }
{ int_T j ; { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 ,
sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } rtDW . mc2bl0bzbl . Tail = 0
; rtDW . mc2bl0bzbl . Head = 0 ; rtDW . mc2bl0bzbl . Last = 0 ; rtDW .
mc2bl0bzbl . CircularBufSize = 1024 ; for ( j = 0 ; j < 1024 ; j ++ ) {
pBuffer [ j ] = rtP . VariableTimeDelay_InitOutput_nbhpmtp2jg ; pBuffer [
1024 + j ] = ssGetT ( rtS ) ; } rtDW . lhx0lj4i05 . TUbufferPtrs [ 0 ] = (
void * ) & pBuffer [ 0 ] ; rtDW . lhx0lj4i05 . TUbufferPtrs [ 1 ] = ( void *
) & pBuffer [ 1024 ] ; } } MdlInitialize ( ) ; MdlEnable ( ) ; } void
MdlOutputs ( int_T tid ) { real_T dxpj2fdqxb ; real_T om12obuajo ; real_T
n0h4b1vry4 ; real_T degbbw0sgw ; real_T * lastU ; int32_T j ; real_T
taskTimeV ; real_T ratio ; uint32_T numCycles ; boolean_T oop02asj1s ; real_T
bhhm3g5dhx ; real_T b2ck0lyshm ; rtB . euqkdgostn = rtP . w_r * ssGetT ( rtS
) ; rtB . a4xfolphoz = 0.0 ; rtB . a4xfolphoz += rtP . TransferFcn1_C * rtX .
fipgb2dv5w ; rtB . ngd20rywmn = rtB . euqkdgostn - rtB . a4xfolphoz ; rtB .
nsv3wpjgsy = rtP . K_p * muDoubleScalarSin ( rtB . ngd20rywmn ) ; if ( ( rtDW
. gidxstxvag >= ssGetT ( rtS ) ) && ( rtDW . hrgwoqkxsi >= ssGetT ( rtS ) ) )
{ rtB . nn4m2ue31i = 0.0 ; } else { taskTimeV = rtDW . gidxstxvag ; lastU = &
rtDW . ewu2ifjblb ; if ( rtDW . gidxstxvag < rtDW . hrgwoqkxsi ) { if ( rtDW
. hrgwoqkxsi < ssGetT ( rtS ) ) { taskTimeV = rtDW . hrgwoqkxsi ; lastU = &
rtDW . hqrrzfrnm4 ; } } else { if ( rtDW . gidxstxvag >= ssGetT ( rtS ) ) {
taskTimeV = rtDW . hrgwoqkxsi ; lastU = & rtDW . hqrrzfrnm4 ; } } rtB .
nn4m2ue31i = ( rtB . nsv3wpjgsy - * lastU ) / ( ssGetT ( rtS ) - taskTimeV )
; } rtB . fmn00c1djj = 0.0 ; rtB . fmn00c1djj += rtP . TransferFcn_C [ 0 ] *
rtX . ewcbusxpqt [ 0 ] ; rtB . fmn00c1djj += rtP . TransferFcn_C [ 1 ] * rtX
. ewcbusxpqt [ 1 ] ; rtB . fmn00c1djj += rtP . TransferFcn_D * rtB .
nsv3wpjgsy ; taskTimeV = rtP . T_b / 2.0 ; { real_T * * uBuffer = ( real_T *
* ) & rtDW . fqydmkxc1f . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . fqydmkxc1f . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; real_T appliedDelay ; appliedDelay = taskTimeV ; if ( appliedDelay >
rtP . VariableTimeDelay1_MaxDelay ) { appliedDelay = rtP .
VariableTimeDelay1_MaxDelay ; } if ( appliedDelay < 0.0 ) { appliedDelay =
0.0 ; } dxpj2fdqxb = rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , *
tBuffer , * uBuffer , rtDW . n3mlm25bwm . CircularBufSize , & rtDW .
n3mlm25bwm . Last , rtDW . n3mlm25bwm . Tail , rtDW . n3mlm25bwm . Head , rtP
. VariableTimeDelay1_InitOutput , 1 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS
) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } if (
ssIsSampleHit ( rtS , 5 , 0 ) ) { taskTimeV = ssGetTaskTime ( rtS , 5 ) ; if
( ssGetTNextWasAdjusted ( rtS , 5 ) ) { rtDW . mcups15blx =
_ssGetVarNextHitTime ( rtS , 2 ) ; } if ( rtDW . iik5cqzr1o != 0 ) { rtDW .
iik5cqzr1o = 0 ; if ( taskTimeV >= rtP . PulseGenerator_PhaseDelay ) { ratio
= ( taskTimeV - rtP . PulseGenerator_PhaseDelay ) / rtP . T_b ; numCycles = (
uint32_T ) muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T
) ( numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; }
rtDW . hxeldrnh31 = numCycles ; ratio = ( ( real_T ) numCycles * rtP . T_b +
rtP . PulseGenerator_PhaseDelay ) + rtP . PulseGenerator_Duty * rtP . T_b /
100.0 ; if ( taskTimeV < ratio ) { rtDW . naafmtzk4n = 1 ; rtDW . mcups15blx
= ratio ; } else { rtDW . naafmtzk4n = 0 ; rtDW . mcups15blx = ( real_T ) (
numCycles + 1U ) * rtP . T_b + rtP . PulseGenerator_PhaseDelay ; } } else {
rtDW . hxeldrnh31 = rtP . PulseGenerator_PhaseDelay != 0.0 ? - 1 : 0 ; rtDW .
naafmtzk4n = 0 ; rtDW . mcups15blx = rtP . PulseGenerator_PhaseDelay ; } }
else { if ( rtDW . mcups15blx <= taskTimeV ) { if ( rtDW . naafmtzk4n == 1 )
{ rtDW . naafmtzk4n = 0 ; rtDW . mcups15blx = ( real_T ) ( rtDW . hxeldrnh31
+ 1LL ) * rtP . T_b + rtP . PulseGenerator_PhaseDelay ; } else { rtDW .
hxeldrnh31 ++ ; rtDW . naafmtzk4n = 1 ; rtDW . mcups15blx = ( rtP .
PulseGenerator_Duty * rtP . T_b * 0.01 + ( real_T ) rtDW . hxeldrnh31 * rtP .
T_b ) + rtP . PulseGenerator_PhaseDelay ; } } } _ssSetVarNextHitTime ( rtS ,
2 , rtDW . mcups15blx ) ; if ( rtDW . naafmtzk4n == 1 ) { rtB . arogusvauw =
rtP . PulseGenerator_Amp ; } else { rtB . arogusvauw = 0.0 ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . m4x5j3wrne = 0.0 * rtB . arogusvauw ;
} taskTimeV = rtP . T_b / 2.0 ; { real_T * * uBuffer = ( real_T * * ) & rtDW
. h20mxqf3h4 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) &
rtDW . h20mxqf3h4 . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T appliedDelay ; appliedDelay = taskTimeV ; if ( appliedDelay > rtP .
VariableTimeDelay_MaxDelay ) { appliedDelay = rtP .
VariableTimeDelay_MaxDelay ; } if ( appliedDelay < 0.0 ) { appliedDelay = 0.0
; } om12obuajo = rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , *
tBuffer , * uBuffer , rtDW . idh4wrqtoh . CircularBufSize , & rtDW .
idh4wrqtoh . Last , rtDW . idh4wrqtoh . Tail , rtDW . idh4wrqtoh . Head , rtP
. VariableTimeDelay_InitOutput , 1 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS
) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } if (
ssIsSampleHit ( rtS , 6 , 0 ) ) { taskTimeV = ssGetTaskTime ( rtS , 6 ) ; if
( ssGetTNextWasAdjusted ( rtS , 6 ) ) { rtDW . dpqogci02g =
_ssGetVarNextHitTime ( rtS , 3 ) ; } if ( rtDW . o0aqq215bl != 0 ) { rtDW .
o0aqq215bl = 0 ; if ( taskTimeV >= rtP . PulseGenerator1_PhaseDelay ) { ratio
= ( taskTimeV - rtP . PulseGenerator1_PhaseDelay ) / rtP . T_b ; numCycles =
( uint32_T ) muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( (
real_T ) ( numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++
; } rtDW . jo3vvyegpy = numCycles ; ratio = ( ( real_T ) numCycles * rtP .
T_b + rtP . PulseGenerator1_PhaseDelay ) + rtP . PulseGenerator1_Duty * rtP .
T_b / 100.0 ; if ( taskTimeV < ratio ) { rtDW . cdqd414jgr = 1 ; rtDW .
dpqogci02g = ratio ; } else { rtDW . cdqd414jgr = 0 ; rtDW . dpqogci02g = (
real_T ) ( numCycles + 1U ) * rtP . T_b + rtP . PulseGenerator1_PhaseDelay ;
} } else { rtDW . jo3vvyegpy = rtP . PulseGenerator1_PhaseDelay != 0.0 ? - 1
: 0 ; rtDW . cdqd414jgr = 0 ; rtDW . dpqogci02g = rtP .
PulseGenerator1_PhaseDelay ; } } else { if ( rtDW . dpqogci02g <= taskTimeV )
{ if ( rtDW . cdqd414jgr == 1 ) { rtDW . cdqd414jgr = 0 ; rtDW . dpqogci02g =
( real_T ) ( rtDW . jo3vvyegpy + 1LL ) * rtP . T_b + rtP .
PulseGenerator1_PhaseDelay ; } else { rtDW . jo3vvyegpy ++ ; rtDW .
cdqd414jgr = 1 ; rtDW . dpqogci02g = ( rtP . PulseGenerator1_Duty * rtP . T_b
* 0.01 + ( real_T ) rtDW . jo3vvyegpy * rtP . T_b ) + rtP .
PulseGenerator1_PhaseDelay ; } } } _ssSetVarNextHitTime ( rtS , 3 , rtDW .
dpqogci02g ) ; if ( rtDW . cdqd414jgr == 1 ) { rtB . lonj3bmhdp = rtP .
PulseGenerator1_Amp ; } else { rtB . lonj3bmhdp = 0.0 ; } } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { taskTimeV = ( jmu25rrt32 ( ) > 0.5 ) ; rtB
. gr1lg4b5kc = ( int8_T ) ( ( rtP . Gain_Gain * ( int32_T ) taskTimeV + rtP .
Bias_Bias ) * rtP . Gain1_Gain ) ; } rtB . ogevcwncpn = ( om12obuajo * rtB .
lonj3bmhdp * rtB . gr1lg4b5kc + rtB . m4x5j3wrne ) * rtP . K ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { RandSrc_GZ_D ( & bhhm3g5dhx , & rtP .
RandomSource_MeanVal , 1 , & rtP . RandomSource_VarianceRTP , 1 , rtDW .
jbppeizd1x , 1 , 1 ) ; rtDW . mq4qxkalfe = muDoubleScalarSqrt ( rtP .
AWGNChannel1_Ps / ( muDoubleScalarPower ( 10.0 , rtP . AWGNChannel1_EbNodB /
10.0 ) * 0.0 ) ) ; rtB . kiwdh5dnyr = rtDW . mq4qxkalfe * bhhm3g5dhx ; rtB .
kiwdh5dnyr /= 1.4142135623730951 ; rtB . kiwdh5dnyr += rtB . ogevcwncpn ; }
rtB . mmtgqryjya = dxpj2fdqxb * rtB . kiwdh5dnyr ; if ( ssIsSampleHit ( rtS ,
2 , 0 ) ) { taskTimeV = rtB . mmtgqryjya * rtP .
DiscreteFIRFilter_Coefficients [ 0 ] ; for ( j = 0 ; j < 9 ; j ++ ) {
taskTimeV += rtP . DiscreteFIRFilter_Coefficients [ j + 1 ] * rtDW .
akitjtxsla [ j ] ; } for ( j = 7 ; j >= 0 ; j -- ) { rtDW . akitjtxsla [ j +
1 ] = rtDW . akitjtxsla [ j ] ; } rtDW . akitjtxsla [ 0 ] = rtB . mmtgqryjya
; oop02asj1s = ( taskTimeV > rtP . Constant_Value ) ; } if ( ssIsSampleHit (
rtS , 3 , 0 ) ) { taskTimeV = ssGetTaskTime ( rtS , 3 ) ; if (
ssGetTNextWasAdjusted ( rtS , 3 ) ) { rtDW . jzz1wckozg =
_ssGetVarNextHitTime ( rtS , 0 ) ; } if ( rtDW . a0nnxzfeub != 0 ) { rtDW .
a0nnxzfeub = 0 ; if ( taskTimeV >= rtP . PulseGenerator_PhaseDelay_atvywtkvwr
) { ratio = ( taskTimeV - rtP . PulseGenerator_PhaseDelay_atvywtkvwr ) / rtP
. T_b ; numCycles = ( uint32_T ) muDoubleScalarFloor ( ratio ) ; if (
muDoubleScalarAbs ( ( real_T ) ( numCycles + 1U ) - ratio ) < DBL_EPSILON *
ratio ) { numCycles ++ ; } rtDW . fqzlq5lwky = numCycles ; ratio = ( ( real_T
) numCycles * rtP . T_b + rtP . PulseGenerator_PhaseDelay_atvywtkvwr ) + rtP
. PulseGenerator_Duty_bgi2ymfa2r * rtP . T_b / 100.0 ; if ( taskTimeV < ratio
) { rtDW . bqbxgzjswl = 1 ; rtDW . jzz1wckozg = ratio ; } else { rtDW .
bqbxgzjswl = 0 ; rtDW . jzz1wckozg = ( real_T ) ( numCycles + 1U ) * rtP .
T_b + rtP . PulseGenerator_PhaseDelay_atvywtkvwr ; } } else { rtDW .
fqzlq5lwky = rtP . PulseGenerator_PhaseDelay_atvywtkvwr != 0.0 ? - 1 : 0 ;
rtDW . bqbxgzjswl = 0 ; rtDW . jzz1wckozg = rtP .
PulseGenerator_PhaseDelay_atvywtkvwr ; } } else { if ( rtDW . jzz1wckozg <=
taskTimeV ) { if ( rtDW . bqbxgzjswl == 1 ) { rtDW . bqbxgzjswl = 0 ; rtDW .
jzz1wckozg = ( real_T ) ( rtDW . fqzlq5lwky + 1LL ) * rtP . T_b + rtP .
PulseGenerator_PhaseDelay_atvywtkvwr ; } else { rtDW . fqzlq5lwky ++ ; rtDW .
bqbxgzjswl = 1 ; rtDW . jzz1wckozg = ( rtP . PulseGenerator_Duty_bgi2ymfa2r *
rtP . T_b * 0.01 + ( real_T ) rtDW . fqzlq5lwky * rtP . T_b ) + rtP .
PulseGenerator_PhaseDelay_atvywtkvwr ; } } } _ssSetVarNextHitTime ( rtS , 0 ,
rtDW . jzz1wckozg ) ; if ( rtDW . bqbxgzjswl == 1 ) { rtB . d2do4by5rh = rtP
. PulseGenerator_Amp_dpc1bd5pjc ; } else { rtB . d2do4by5rh = 0.0 ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . dtss3js3fd = 0.0 * rtB . d2do4by5rh ;
} taskTimeV = rtP . T_b / 2.0 ; { real_T * * uBuffer = ( real_T * * ) & rtDW
. pz2yc0tozj . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) &
rtDW . pz2yc0tozj . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T appliedDelay ; appliedDelay = taskTimeV ; if ( appliedDelay > rtP .
VariableTimeDelay_MaxDelay_m2225lzqk4 ) { appliedDelay = rtP .
VariableTimeDelay_MaxDelay_m2225lzqk4 ; } if ( appliedDelay < 0.0 ) {
appliedDelay = 0.0 ; } n0h4b1vry4 = rt_TDelayInterpolate ( simTime -
appliedDelay , 0.0 , * tBuffer , * uBuffer , rtDW . aqjeiun535 .
CircularBufSize , & rtDW . aqjeiun535 . Last , rtDW . aqjeiun535 . Tail ,
rtDW . aqjeiun535 . Head , rtP . VariableTimeDelay_InitOutput_bhowtxsjbn , 1
, ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS
) == ssGetT ( rtS ) ) ) ) ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) {
taskTimeV = ssGetTaskTime ( rtS , 4 ) ; if ( ssGetTNextWasAdjusted ( rtS , 4
) ) { rtDW . dgchxx4fdz = _ssGetVarNextHitTime ( rtS , 1 ) ; } if ( rtDW .
etw2p5ad3w != 0 ) { rtDW . etw2p5ad3w = 0 ; if ( taskTimeV >= rtP .
PulseGenerator1_PhaseDelay_mbbvjh54k2 ) { ratio = ( taskTimeV - rtP .
PulseGenerator1_PhaseDelay_mbbvjh54k2 ) / rtP . T_b ; numCycles = ( uint32_T
) muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } rtDW .
kdiskgiof3 = numCycles ; ratio = ( ( real_T ) numCycles * rtP . T_b + rtP .
PulseGenerator1_PhaseDelay_mbbvjh54k2 ) + rtP .
PulseGenerator1_Duty_g4r4ampfv4 * rtP . T_b / 100.0 ; if ( taskTimeV < ratio
) { rtDW . ow1mt1w4wu = 1 ; rtDW . dgchxx4fdz = ratio ; } else { rtDW .
ow1mt1w4wu = 0 ; rtDW . dgchxx4fdz = ( real_T ) ( numCycles + 1U ) * rtP .
T_b + rtP . PulseGenerator1_PhaseDelay_mbbvjh54k2 ; } } else { rtDW .
kdiskgiof3 = rtP . PulseGenerator1_PhaseDelay_mbbvjh54k2 != 0.0 ? - 1 : 0 ;
rtDW . ow1mt1w4wu = 0 ; rtDW . dgchxx4fdz = rtP .
PulseGenerator1_PhaseDelay_mbbvjh54k2 ; } } else { if ( rtDW . dgchxx4fdz <=
taskTimeV ) { if ( rtDW . ow1mt1w4wu == 1 ) { rtDW . ow1mt1w4wu = 0 ; rtDW .
dgchxx4fdz = ( real_T ) ( rtDW . kdiskgiof3 + 1LL ) * rtP . T_b + rtP .
PulseGenerator1_PhaseDelay_mbbvjh54k2 ; } else { rtDW . kdiskgiof3 ++ ; rtDW
. ow1mt1w4wu = 1 ; rtDW . dgchxx4fdz = ( rtP .
PulseGenerator1_Duty_g4r4ampfv4 * rtP . T_b * 0.01 + ( real_T ) rtDW .
kdiskgiof3 * rtP . T_b ) + rtP . PulseGenerator1_PhaseDelay_mbbvjh54k2 ; } }
} _ssSetVarNextHitTime ( rtS , 1 , rtDW . dgchxx4fdz ) ; if ( rtDW .
ow1mt1w4wu == 1 ) { rtB . pvii1a3nq2 = rtP . PulseGenerator1_Amp_drqz5ufz4h ;
} else { rtB . pvii1a3nq2 = 0.0 ; } } rtB . f4cfbddfyy = ( n0h4b1vry4 * rtB .
pvii1a3nq2 * rtB . gr1lg4b5kc + rtB . dtss3js3fd ) * rtP . K ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { RandSrc_GZ_D ( & b2ck0lyshm , & rtP .
RandomSource_MeanVal_g055kln1nb , 1 , & rtP .
RandomSource_VarianceRTP_kadmsoaacu , 1 , rtDW . nc0dkv5gky , 1 , 1 ) ; rtDW
. p0fceflrke = muDoubleScalarSqrt ( rtP . AWGNChannel_Ps / (
muDoubleScalarPower ( 10.0 , rtP . AWGNChannel_EbNodB / 10.0 ) * 0.0 ) ) ;
rtB . dq5pf1r1kq = rtDW . p0fceflrke * b2ck0lyshm ; rtB . dq5pf1r1kq /=
1.4142135623730951 ; rtB . dq5pf1r1kq += rtB . f4cfbddfyy ; } taskTimeV = rtP
. T_b / 2.0 ; { real_T * * uBuffer = ( real_T * * ) & rtDW . lhx0lj4i05 .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . lhx0lj4i05
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T appliedDelay
; appliedDelay = taskTimeV ; if ( appliedDelay > rtP .
VariableTimeDelay_MaxDelay_dusxlj4oib ) { appliedDelay = rtP .
VariableTimeDelay_MaxDelay_dusxlj4oib ; } if ( appliedDelay < 0.0 ) {
appliedDelay = 0.0 ; } degbbw0sgw = rt_TDelayInterpolate ( simTime -
appliedDelay , 0.0 , * tBuffer , * uBuffer , rtDW . mc2bl0bzbl .
CircularBufSize , & rtDW . mc2bl0bzbl . Last , rtDW . mc2bl0bzbl . Tail ,
rtDW . mc2bl0bzbl . Head , rtP . VariableTimeDelay_InitOutput_nbhpmtp2jg , 1
, ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS
) == ssGetT ( rtS ) ) ) ) ; } rtB . elxpo0dj2v = rtB . dq5pf1r1kq *
degbbw0sgw ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { b2ck0lyshm = rtB .
elxpo0dj2v * rtP . DiscreteFIRFilter_Coefficients_mbm3buv1vn [ 0 ] ; for ( j
= 0 ; j < 9 ; j ++ ) { b2ck0lyshm += rtP .
DiscreteFIRFilter_Coefficients_mbm3buv1vn [ j + 1 ] * rtDW . hc5gld2nwz [ j ]
; } for ( j = 7 ; j >= 0 ; j -- ) { rtDW . hc5gld2nwz [ j + 1 ] = rtDW .
hc5gld2nwz [ j ] ; } rtDW . hc5gld2nwz [ 0 ] = rtB . elxpo0dj2v ; rtB .
dwklrf454t = ( uint16_T ) ( ( ( uint32_T ) ( b2ck0lyshm > rtP .
Constant_Value_b4h3lxdqw5 ) + oop02asj1s ) * rtP . Gain2_Gain ) ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { real_T * lastU ;
if ( rtDW . gidxstxvag == ( rtInf ) ) { rtDW . gidxstxvag = ssGetT ( rtS ) ;
lastU = & rtDW . ewu2ifjblb ; } else if ( rtDW . hrgwoqkxsi == ( rtInf ) ) {
rtDW . hrgwoqkxsi = ssGetT ( rtS ) ; lastU = & rtDW . hqrrzfrnm4 ; } else if
( rtDW . gidxstxvag < rtDW . hrgwoqkxsi ) { rtDW . gidxstxvag = ssGetT ( rtS
) ; lastU = & rtDW . ewu2ifjblb ; } else { rtDW . hrgwoqkxsi = ssGetT ( rtS )
; lastU = & rtDW . hqrrzfrnm4 ; } * lastU = rtB . nsv3wpjgsy ; { real_T * *
uBuffer = ( real_T * * ) & rtDW . fqydmkxc1f . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . fqydmkxc1f . TUbufferPtrs [ 1 ] ; real_T
* * xBuffer = ( NULL ) ; real_T simTime = ssGetT ( rtS ) ; rtDW . n3mlm25bwm
. Head = ( ( rtDW . n3mlm25bwm . Head < ( rtDW . n3mlm25bwm . CircularBufSize
- 1 ) ) ? ( rtDW . n3mlm25bwm . Head + 1 ) : 0 ) ; if ( rtDW . n3mlm25bwm .
Head == rtDW . n3mlm25bwm . Tail ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
rtDW . n3mlm25bwm . CircularBufSize , & rtDW . n3mlm25bwm . Tail , & rtDW .
n3mlm25bwm . Head , & rtDW . n3mlm25bwm . Last , simTime - rtP .
VariableTimeDelay1_MaxDelay , tBuffer , uBuffer , xBuffer , ( boolean_T ) 0 ,
( boolean_T ) 0 , & rtDW . n3mlm25bwm . MaxNewBufSize ) ) { ssSetErrorStatus
( rtS , "vtdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [
rtDW . n3mlm25bwm . Head ] = simTime ; ( * uBuffer ) [ rtDW . n3mlm25bwm .
Head ] = rtB . kiwdh5dnyr ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
h20mxqf3h4 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. h20mxqf3h4 . TUbufferPtrs [ 1 ] ; real_T * * xBuffer = ( NULL ) ; real_T
simTime = ssGetT ( rtS ) ; rtDW . idh4wrqtoh . Head = ( ( rtDW . idh4wrqtoh .
Head < ( rtDW . idh4wrqtoh . CircularBufSize - 1 ) ) ? ( rtDW . idh4wrqtoh .
Head + 1 ) : 0 ) ; if ( rtDW . idh4wrqtoh . Head == rtDW . idh4wrqtoh . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . idh4wrqtoh .
CircularBufSize , & rtDW . idh4wrqtoh . Tail , & rtDW . idh4wrqtoh . Head , &
rtDW . idh4wrqtoh . Last , simTime - rtP . VariableTimeDelay_MaxDelay ,
tBuffer , uBuffer , xBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , & rtDW .
idh4wrqtoh . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
idh4wrqtoh . Head ] = simTime ; ( * uBuffer ) [ rtDW . idh4wrqtoh . Head ] =
0.0 ; } { real_T * * uBuffer = ( real_T * * ) & rtDW . pz2yc0tozj .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . pz2yc0tozj
. TUbufferPtrs [ 1 ] ; real_T * * xBuffer = ( NULL ) ; real_T simTime =
ssGetT ( rtS ) ; rtDW . aqjeiun535 . Head = ( ( rtDW . aqjeiun535 . Head < (
rtDW . aqjeiun535 . CircularBufSize - 1 ) ) ? ( rtDW . aqjeiun535 . Head + 1
) : 0 ) ; if ( rtDW . aqjeiun535 . Head == rtDW . aqjeiun535 . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . aqjeiun535 . CircularBufSize , &
rtDW . aqjeiun535 . Tail , & rtDW . aqjeiun535 . Head , & rtDW . aqjeiun535 .
Last , simTime - rtP . VariableTimeDelay_MaxDelay_m2225lzqk4 , tBuffer ,
uBuffer , xBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , & rtDW . aqjeiun535 .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
aqjeiun535 . Head ] = simTime ; ( * uBuffer ) [ rtDW . aqjeiun535 . Head ] =
0.0 ; } { real_T * * uBuffer = ( real_T * * ) & rtDW . lhx0lj4i05 .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . lhx0lj4i05
. TUbufferPtrs [ 1 ] ; real_T * * xBuffer = ( NULL ) ; real_T simTime =
ssGetT ( rtS ) ; rtDW . mc2bl0bzbl . Head = ( ( rtDW . mc2bl0bzbl . Head < (
rtDW . mc2bl0bzbl . CircularBufSize - 1 ) ) ? ( rtDW . mc2bl0bzbl . Head + 1
) : 0 ) ; if ( rtDW . mc2bl0bzbl . Head == rtDW . mc2bl0bzbl . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . mc2bl0bzbl . CircularBufSize , &
rtDW . mc2bl0bzbl . Tail , & rtDW . mc2bl0bzbl . Head , & rtDW . mc2bl0bzbl .
Last , simTime - rtP . VariableTimeDelay_MaxDelay_dusxlj4oib , tBuffer ,
uBuffer , xBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , & rtDW . mc2bl0bzbl .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
mc2bl0bzbl . Head ] = simTime ; ( * uBuffer ) [ rtDW . mc2bl0bzbl . Head ] =
rtB . dq5pf1r1kq ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID7 ( int_T
tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot *
_rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> fipgb2dv5w =
0.0 ; _rtXdot -> fipgb2dv5w += rtP . TransferFcn1_A * rtX . fipgb2dv5w ;
_rtXdot -> fipgb2dv5w += rtB . fmn00c1djj ; _rtXdot -> ewcbusxpqt [ 0 ] = 0.0
; _rtXdot -> ewcbusxpqt [ 0 ] += rtP . TransferFcn_A [ 0 ] * rtX . ewcbusxpqt
[ 0 ] ; _rtXdot -> ewcbusxpqt [ 1 ] = 0.0 ; _rtXdot -> ewcbusxpqt [ 0 ] +=
rtP . TransferFcn_A [ 1 ] * rtX . ewcbusxpqt [ 1 ] ; _rtXdot -> ewcbusxpqt [
1 ] += rtX . ewcbusxpqt [ 0 ] ; _rtXdot -> ewcbusxpqt [ 0 ] += rtB .
nsv3wpjgsy ; { } { } { } { } } void MdlProjection ( void ) { } void
MdlTerminate ( void ) { rt_TDelayFreeBuf ( rtDW . fqydmkxc1f . TUbufferPtrs [
0 ] ) ; rt_TDelayFreeBuf ( rtDW . h20mxqf3h4 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . pz2yc0tozj . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . lhx0lj4i05 . TUbufferPtrs [ 0 ] ) ; if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 3 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
7 ) ; ssSetNumBlocks ( rtS , 61 ) ; ssSetNumBlockIO ( rtS , 21 ) ;
ssSetNumBlockParams ( rtS , 69 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 40.0 ) ; ssSetSampleTime ( rtS , 3 , - 2.0 ) ;
ssSetSampleTime ( rtS , 4 , - 2.0 ) ; ssSetSampleTime ( rtS , 5 , - 2.0 ) ;
ssSetSampleTime ( rtS , 6 , - 2.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; ssSetOffsetTime ( rtS , 4 , 1.0 ) ;
ssSetOffsetTime ( rtS , 5 , 2.0 ) ; ssSetOffsetTime ( rtS , 6 , 3.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 1893728671U ) ;
ssSetChecksumVal ( rtS , 1 , 295662189U ) ; ssSetChecksumVal ( rtS , 2 ,
3154996807U ) ; ssSetChecksumVal ( rtS , 3 , 3160123458U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 20 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
graduteWork_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "graduteWork" ) ;
ssSetPath ( rtS , "graduteWork" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 200.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 3 ] ; static
real_T absTol [ 3 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T
absTolControl [ 3 ] = { 0U , 0U , 0U } ; ssSetSolverRelTol ( rtS , 0.001 ) ;
ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 4.0 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepAuto" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1893728671U ) ; ssSetChecksumVal ( rtS , 1 ,
295662189U ) ; ssSetChecksumVal ( rtS , 2 , 3154996807U ) ; ssSetChecksumVal
( rtS , 3 , 3160123458U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 3 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 7 ; void MdlOutputsParameterSampleTime (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
