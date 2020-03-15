#include "__cf_graduteWork.h"
#ifndef RTW_HEADER_graduteWork_h_
#define RTW_HEADER_graduteWork_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef graduteWork_COMMON_INCLUDES_
#define graduteWork_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "graduteWork_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#define MODEL_NAME graduteWork
#define NSAMPLE_TIMES (8) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (21) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T euqkdgostn ; real_T a4xfolphoz ; real_T ngd20rywmn ;
real_T nsv3wpjgsy ; real_T nn4m2ue31i ; real_T fmn00c1djj ; real_T arogusvauw
; real_T m4x5j3wrne ; real_T lonj3bmhdp ; real_T gr1lg4b5kc ; real_T
ogevcwncpn ; real_T kiwdh5dnyr ; real_T mmtgqryjya ; real_T d2do4by5rh ;
real_T dtss3js3fd ; real_T pvii1a3nq2 ; real_T f4cfbddfyy ; real_T dq5pf1r1kq
; real_T elxpo0dj2v ; real_T hz5dwxxhh5 [ 2 ] ; uint16_T dwklrf454t ; } B ;
typedef struct { real_T akitjtxsla [ 9 ] ; real_T hc5gld2nwz [ 9 ] ; real_T
gidxstxvag ; real_T ewu2ifjblb ; real_T hrgwoqkxsi ; real_T hqrrzfrnm4 ;
real_T mcups15blx ; real_T dpqogci02g ; real_T mq4qxkalfe ; real_T jzz1wckozg
; real_T dgchxx4fdz ; real_T p0fceflrke ; int64_T hxeldrnh31 ; int64_T
jo3vvyegpy ; int64_T fqzlq5lwky ; int64_T kdiskgiof3 ; struct { real_T
modelTStart ; } ezdyi0bpjz ; struct { real_T modelTStart ; } bkbzto50nk ;
struct { real_T modelTStart ; } jbx3emlvm2 ; struct { real_T modelTStart ; }
gr2zi5l51e ; struct { void * LoggedData ; } hewqvudxrp ; struct { void *
LoggedData ; } bglwdv4oyw ; struct { void * LoggedData ; } k3nx12mzik ;
struct { void * TUbufferPtrs [ 2 ] ; } fqydmkxc1f ; struct { void *
TUbufferPtrs [ 2 ] ; } h20mxqf3h4 ; struct { void * TUbufferPtrs [ 2 ] ; }
pz2yc0tozj ; struct { void * TUbufferPtrs [ 2 ] ; } lhx0lj4i05 ; struct {
void * LoggedData ; } cg1vpdblix ; int32_T iik5cqzr1o ; int32_T naafmtzk4n ;
int32_T o0aqq215bl ; int32_T cdqd414jgr ; int32_T a0nnxzfeub ; int32_T
bqbxgzjswl ; int32_T etw2p5ad3w ; int32_T ow1mt1w4wu ; uint32_T hlvhcmlowo ;
uint32_T jbppeizd1x [ 2 ] ; uint32_T bojqotfxnb ; uint32_T nc0dkv5gky [ 2 ] ;
uint32_T gn3icq1q2g ; uint32_T bizznvvjue [ 2 ] ; uint32_T od4sllwisx [ 625 ]
; uint32_T h4hok5wmjg ; pbicqml2dv cg25jop35d ; struct { int_T Tail ; int_T
Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
n3mlm25bwm ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } idh4wrqtoh ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
aqjeiun535 ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } mc2bl0bzbl ; boolean_T eihuvcejq2 ;
boolean_T lbx1mtfejs ; boolean_T j4s4odcqip ; boolean_T azmor0scbe ;
boolean_T myt1d5w44r ; } DW ; typedef struct { real_T fipgb2dv5w ; real_T
ewcbusxpqt [ 2 ] ; } X ; typedef struct { real_T fipgb2dv5w ; real_T
ewcbusxpqt [ 2 ] ; } XDot ; typedef struct { boolean_T fipgb2dv5w ; boolean_T
ewcbusxpqt [ 2 ] ; } XDis ; typedef struct { real_T fipgb2dv5w ; real_T
ewcbusxpqt [ 2 ] ; } CStateAbsTol ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T K ; real_T K_p ; real_T T_b ; real_T
w_r ; real_T AWGNChannel1_EbNodB ; real_T AWGNChannel_EbNodB ; real_T
RandomSource_MeanVal ; real_T RandomSource_MeanVal_g055kln1nb ; real_T
AWGNChannel1_Ps ; real_T AWGNChannel_Ps ; uint32_T AWGNChannel1_seed ;
uint32_T AWGNChannel_seed ; real_T Constant_Value ; real_T
Constant_Value_b4h3lxdqw5 ; real_T TransferFcn1_A ; real_T TransferFcn1_C ;
real_T TransferFcn_A [ 2 ] ; real_T TransferFcn_C [ 2 ] ; real_T
TransferFcn_D ; real_T VariableTimeDelay1_MaxDelay ; real_T
VariableTimeDelay1_InitOutput ; real_T PulseGenerator_Amp ; real_T
PulseGenerator_Duty ; real_T PulseGenerator_PhaseDelay ; real_T
VariableTimeDelay_MaxDelay ; real_T VariableTimeDelay_InitOutput ; real_T
PulseGenerator1_Amp ; real_T PulseGenerator1_Duty ; real_T
PulseGenerator1_PhaseDelay ; real_T RandomSource_VarianceRTP ; real_T
DiscreteFIRFilter_InitialStates ; real_T DiscreteFIRFilter_Coefficients [ 10
] ; real_T PulseGenerator_Amp_dpc1bd5pjc ; real_T
PulseGenerator_Duty_bgi2ymfa2r ; real_T PulseGenerator_PhaseDelay_atvywtkvwr
; real_T VariableTimeDelay_MaxDelay_m2225lzqk4 ; real_T
VariableTimeDelay_InitOutput_bhowtxsjbn ; real_T
PulseGenerator1_Amp_drqz5ufz4h ; real_T PulseGenerator1_Duty_g4r4ampfv4 ;
real_T PulseGenerator1_PhaseDelay_mbbvjh54k2 ; real_T
RandomSource_VarianceRTP_kadmsoaacu ; real_T
VariableTimeDelay_MaxDelay_dusxlj4oib ; real_T
VariableTimeDelay_InitOutput_nbhpmtp2jg ; real_T
DiscreteFIRFilter_InitialStates_bcwzpsb0dc ; real_T
DiscreteFIRFilter_Coefficients_mbm3buv1vn [ 10 ] ; int32_T Gain_Gain ;
int32_T Bias_Bias ; int32_T Gain1_Gain ; uint8_T Gain2_Gain ; } ; extern
const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ;
extern DW rtDW ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
graduteWork_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern const int_T
gblParameterTuningTid ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
