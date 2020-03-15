#include "__cf_graduteWork.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "graduteWork_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#ifndef SS_INT64
#define SS_INT64  18
#endif
#ifndef SS_UINT64
#define SS_UINT64  19
#endif
#else
#include "builtin_typeid_types.h"
#include "graduteWork.h"
#include "graduteWork_capi.h"
#include "graduteWork_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"graduteWork/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "graduteWork/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 2 , 0 , TARGET_STRING ( "graduteWork/Gain2" ) , TARGET_STRING ( ""
) , 0 , 1 , 0 , 1 , 1 } , { 3 , 0 , TARGET_STRING ( "graduteWork/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"graduteWork/Product1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 ,
0 , TARGET_STRING ( "graduteWork/APLL /Derivative" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING ( "graduteWork/APLL /Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"graduteWork/APLL /Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
8 , 0 , TARGET_STRING ( "graduteWork/APLL /Sum" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"graduteWork/APLL /Transfer Fcn" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 10 , 0 , TARGET_STRING ( "graduteWork/APLL /Transfer Fcn1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"graduteWork/AWGN Channel/Dynamic AWGN" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 2 } , { 12 , 0 , TARGET_STRING (
"graduteWork/AWGN Channel1/Dynamic AWGN" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 2 } , { 13 , 0 , TARGET_STRING ( "graduteWork/DCSK_mod/Pulse Generator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 14 , 0 , TARGET_STRING (
"graduteWork/DCSK_mod/Pulse Generator1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 4 } , { 15 , 0 , TARGET_STRING ( "graduteWork/DCSK_mod/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 16 , 0 , TARGET_STRING (
"graduteWork/DCSK_mod_1/Pulse Generator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 5 } , { 17 , 0 , TARGET_STRING (
"graduteWork/DCSK_mod_1/Pulse Generator1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 6 } , { 18 , 0 , TARGET_STRING ( "graduteWork/DCSK_mod_1/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 19 , 0 , TARGET_STRING (
"graduteWork/Unipolar to Bipolar Converter1/Conversion1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 ,
0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 20 ,
TARGET_STRING ( "graduteWork/AWGN Channel" ) , TARGET_STRING ( "seed" ) , 2 ,
0 , 0 } , { 21 , TARGET_STRING ( "graduteWork/AWGN Channel" ) , TARGET_STRING
( "EbNodB" ) , 0 , 0 , 0 } , { 22 , TARGET_STRING (
"graduteWork/AWGN Channel" ) , TARGET_STRING ( "Ps" ) , 0 , 0 , 0 } , { 23 ,
TARGET_STRING ( "graduteWork/AWGN Channel1" ) , TARGET_STRING ( "seed" ) , 2
, 0 , 0 } , { 24 , TARGET_STRING ( "graduteWork/AWGN Channel1" ) ,
TARGET_STRING ( "EbNodB" ) , 0 , 0 , 0 } , { 25 , TARGET_STRING (
"graduteWork/AWGN Channel1" ) , TARGET_STRING ( "Ps" ) , 0 , 0 , 0 } , { 26 ,
TARGET_STRING ( "graduteWork/Gain2" ) , TARGET_STRING ( "Gain" ) , 3 , 0 , 2
} , { 27 , TARGET_STRING ( "graduteWork/Variable Time Delay" ) ,
TARGET_STRING ( "MaximumDelay" ) , 0 , 0 , 0 } , { 28 , TARGET_STRING (
"graduteWork/Variable Time Delay" ) , TARGET_STRING ( "InitialOutput" ) , 0 ,
0 , 0 } , { 29 , TARGET_STRING ( "graduteWork/Variable Time Delay1" ) ,
TARGET_STRING ( "MaximumDelay" ) , 0 , 0 , 0 } , { 30 , TARGET_STRING (
"graduteWork/Variable Time Delay1" ) , TARGET_STRING ( "InitialOutput" ) , 0
, 0 , 0 } , { 31 , TARGET_STRING ( "graduteWork/APLL /Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"graduteWork/APLL /Transfer Fcn" ) , TARGET_STRING ( "A" ) , 0 , 1 , 0 } , {
33 , TARGET_STRING ( "graduteWork/APLL /Transfer Fcn" ) , TARGET_STRING ( "C"
) , 0 , 2 , 0 } , { 34 , TARGET_STRING ( "graduteWork/APLL /Transfer Fcn" ) ,
TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"graduteWork/APLL /Transfer Fcn1" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , {
36 , TARGET_STRING ( "graduteWork/APLL /Transfer Fcn1" ) , TARGET_STRING (
"C" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"graduteWork/AWGN Channel/Random Source" ) , TARGET_STRING ( "MeanVal" ) , 0
, 0 , 0 } , { 38 , TARGET_STRING ( "graduteWork/AWGN Channel/Random Source" )
, TARGET_STRING ( "VarianceRTP" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"graduteWork/AWGN Channel1/Random Source" ) , TARGET_STRING ( "MeanVal" ) , 0
, 0 , 0 } , { 40 , TARGET_STRING ( "graduteWork/AWGN Channel1/Random Source"
) , TARGET_STRING ( "VarianceRTP" ) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
"graduteWork/Compare To Zero/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 42 , TARGET_STRING ( "graduteWork/Compare To Zero1/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"graduteWork/DCSK_mod/Pulse Generator" ) , TARGET_STRING ( "Amplitude" ) , 0
, 0 , 0 } , { 44 , TARGET_STRING ( "graduteWork/DCSK_mod/Pulse Generator" ) ,
TARGET_STRING ( "PulseWidth" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
"graduteWork/DCSK_mod/Pulse Generator" ) , TARGET_STRING ( "PhaseDelay" ) , 0
, 0 , 0 } , { 46 , TARGET_STRING ( "graduteWork/DCSK_mod/Pulse Generator1" )
, TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"graduteWork/DCSK_mod/Pulse Generator1" ) , TARGET_STRING ( "PulseWidth" ) ,
0 , 0 , 0 } , { 48 , TARGET_STRING ( "graduteWork/DCSK_mod/Pulse Generator1"
) , TARGET_STRING ( "PhaseDelay" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"graduteWork/DCSK_mod/Variable Time Delay" ) , TARGET_STRING ( "MaximumDelay"
) , 0 , 0 , 0 } , { 50 , TARGET_STRING (
"graduteWork/DCSK_mod/Variable Time Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"graduteWork/DCSK_mod_1/Pulse Generator" ) , TARGET_STRING ( "Amplitude" ) ,
0 , 0 , 0 } , { 52 , TARGET_STRING ( "graduteWork/DCSK_mod_1/Pulse Generator"
) , TARGET_STRING ( "PulseWidth" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"graduteWork/DCSK_mod_1/Pulse Generator" ) , TARGET_STRING ( "PhaseDelay" ) ,
0 , 0 , 0 } , { 54 , TARGET_STRING (
"graduteWork/DCSK_mod_1/Pulse Generator1" ) , TARGET_STRING ( "Amplitude" ) ,
0 , 0 , 0 } , { 55 , TARGET_STRING (
"graduteWork/DCSK_mod_1/Pulse Generator1" ) , TARGET_STRING ( "PulseWidth" )
, 0 , 0 , 0 } , { 56 , TARGET_STRING (
"graduteWork/DCSK_mod_1/Pulse Generator1" ) , TARGET_STRING ( "PhaseDelay" )
, 0 , 0 , 0 } , { 57 , TARGET_STRING (
"graduteWork/DCSK_mod_1/Variable Time Delay" ) , TARGET_STRING (
"MaximumDelay" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING (
"graduteWork/DCSK_mod_1/Variable Time Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING (
"graduteWork/Unipolar to Bipolar Converter1/Bias" ) , TARGET_STRING ( "Bias"
) , 4 , 0 , 0 } , { 60 , TARGET_STRING (
"graduteWork/Unipolar to Bipolar Converter1/Gain" ) , TARGET_STRING ( "Gain"
) , 4 , 0 , 0 } , { 61 , TARGET_STRING (
"graduteWork/Unipolar to Bipolar Converter1/Gain1" ) , TARGET_STRING ( "Gain"
) , 4 , 0 , 0 } , { 62 , TARGET_STRING (
"graduteWork/Windowed Integrator/Discrete FIR Filter" ) , TARGET_STRING (
"InitialStates" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"graduteWork/Windowed Integrator/Discrete FIR Filter" ) , TARGET_STRING (
"Coefficients" ) , 0 , 3 , 0 } , { 64 , TARGET_STRING (
"graduteWork/Windowed Integrator1/Discrete FIR Filter" ) , TARGET_STRING (
"InitialStates" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"graduteWork/Windowed Integrator1/Discrete FIR Filter" ) , TARGET_STRING (
"Coefficients" ) , 0 , 3 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ;
static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 66 ,
TARGET_STRING ( "K" ) , 0 , 0 , 0 } , { 67 , TARGET_STRING ( "K_p" ) , 0 , 0
, 0 } , { 68 , TARGET_STRING ( "T_b" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING (
"omega_0" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . f4cfbddfyy , & rtB . ogevcwncpn ,
& rtB . dwklrf454t , & rtB . mmtgqryjya , & rtB . elxpo0dj2v , & rtB .
nn4m2ue31i , & rtB . euqkdgostn , & rtB . nsv3wpjgsy , & rtB . ngd20rywmn , &
rtB . fmn00c1djj , & rtB . a4xfolphoz , & rtB . dq5pf1r1kq , & rtB .
kiwdh5dnyr , & rtB . arogusvauw , & rtB . lonj3bmhdp , & rtB . m4x5j3wrne , &
rtB . d2do4by5rh , & rtB . pvii1a3nq2 , & rtB . dtss3js3fd , & rtB .
gr1lg4b5kc , & rtP . AWGNChannel_seed , & rtP . AWGNChannel_EbNodB , & rtP .
AWGNChannel_Ps , & rtP . AWGNChannel1_seed , & rtP . AWGNChannel1_EbNodB , &
rtP . AWGNChannel1_Ps , & rtP . Gain2_Gain , & rtP .
VariableTimeDelay_MaxDelay_dusxlj4oib , & rtP .
VariableTimeDelay_InitOutput_nbhpmtp2jg , & rtP . VariableTimeDelay1_MaxDelay
, & rtP . VariableTimeDelay1_InitOutput , & rtP . Constant3_Value , & rtP .
TransferFcn_A [ 0 ] , & rtP . TransferFcn_C [ 0 ] , & rtP . TransferFcn_D , &
rtP . TransferFcn1_A , & rtP . TransferFcn1_C , & rtP .
RandomSource_MeanVal_g055kln1nb , & rtP . RandomSource_VarianceRTP_kadmsoaacu
, & rtP . RandomSource_MeanVal , & rtP . RandomSource_VarianceRTP , & rtP .
Constant_Value , & rtP . Constant_Value_b4h3lxdqw5 , & rtP .
PulseGenerator_Amp , & rtP . PulseGenerator_Duty , & rtP .
PulseGenerator_PhaseDelay , & rtP . PulseGenerator1_Amp , & rtP .
PulseGenerator1_Duty , & rtP . PulseGenerator1_PhaseDelay , & rtP .
VariableTimeDelay_MaxDelay , & rtP . VariableTimeDelay_InitOutput , & rtP .
PulseGenerator_Amp_dpc1bd5pjc , & rtP . PulseGenerator_Duty_bgi2ymfa2r , &
rtP . PulseGenerator_PhaseDelay_atvywtkvwr , & rtP .
PulseGenerator1_Amp_drqz5ufz4h , & rtP . PulseGenerator1_Duty_g4r4ampfv4 , &
rtP . PulseGenerator1_PhaseDelay_mbbvjh54k2 , & rtP .
VariableTimeDelay_MaxDelay_m2225lzqk4 , & rtP .
VariableTimeDelay_InitOutput_bhowtxsjbn , & rtP . Bias_Bias , & rtP .
Gain_Gain , & rtP . Gain1_Gain , & rtP .
DiscreteFIRFilter_InitialStates_bcwzpsb0dc , & rtP .
DiscreteFIRFilter_Coefficients_mbm3buv1vn [ 0 ] , & rtP .
DiscreteFIRFilter_InitialStates , & rtP . DiscreteFIRFilter_Coefficients [ 0
] , & rtP . K , & rtP . K_p , & rtP . T_b , & rtP . omega_0 , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned short" , "uint16_T" , 0 , 0 , sizeof ( uint16_T ) , SS_UINT16 , 0 ,
0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 , sizeof ( uint32_T ) ,
SS_UINT32 , 0 , 0 , 0 } , { "unsigned char" , "uint8_T" , 0 , 0 , sizeof (
uint8_T ) , SS_UINT8 , 0 , 0 , 0 } , { "int" , "int32_T" , 0 , 0 , sizeof (
int32_T ) , SS_INT32 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 2 , 1 , 1 , 2 , 1 , 10 } ;
static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 , 40.0 , - 2.0 , 2.0
, 3.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , (
NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
rtwCAPI_FIX_UNIFORM_SCALING , 16 , - 8 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
rtwCAPI_FIX_UNIFORM_SCALING , 8 , - 8 , 0 } } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 0 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 2 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 , 0 } , { ( const
void * ) & rtcapiStoredFloats [ 3 ] , ( const void * ) & rtcapiStoredFloats [
4 ] , 5 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 3 ] , ( const void
* ) & rtcapiStoredFloats [ 5 ] , 6 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 3 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 3 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 3 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , 4 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 20 , ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockParameters , 46 , rtModelParameters , 4 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 4170770201U , 232831895U , 2260892825U ,
3417646548U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
graduteWork_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void graduteWork_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void graduteWork_host_InitializeDataMapInfo ( graduteWork_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
