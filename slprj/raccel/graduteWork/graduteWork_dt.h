#include "__cf_graduteWork.h"
#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "uint8_T" , 14 , 1 } , { "uint16_T" , 15
, 2 } , { "pbicqml2dv" , 16 , 4 } , { "int64_T" , 17 , 8 } , { "int64_T" , 18
, 8 } , { "uint64_T" , 19 , 8 } } ; static uint_T rtDataTypeSizes [ ] = {
sizeof ( real_T ) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof (
uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) ,
sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof (
int_T ) , sizeof ( pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T
) , sizeof ( uint8_T ) , sizeof ( uint16_T ) , sizeof ( pbicqml2dv ) , sizeof
( int64_T ) , sizeof ( int64_T ) , sizeof ( uint64_T ) } ; static const
char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T"
, "int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" ,
"fcn_call_T" , "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"uint8_T" , "uint16_T" , "pbicqml2dv" , "int64_T" , "int64_T" , "uint64_T" }
; static DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB .
ljlynbslzt ) , 0 , 0 , 28 } , { ( char_T * ) ( & rtB . dwklrf454t ) , 15 , 0
, 1 } , { ( char_T * ) ( & rtDW . akitjtxsla [ 0 ] ) , 0 , 0 , 24 } , { (
char_T * ) ( & rtDW . hxeldrnh31 ) , 17 , 0 , 4 } , { ( char_T * ) ( & rtDW .
ezdyi0bpjz . modelTStart ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtDW .
fpgdvluwcr . LoggedData [ 0 ] ) , 11 , 0 , 18 } , { ( char_T * ) ( & rtDW .
iik5cqzr1o ) , 6 , 0 , 8 } , { ( char_T * ) ( & rtDW . hlvhcmlowo ) , 7 , 0 ,
635 } , { ( char_T * ) ( & rtDW . cg25jop35d ) , 16 , 0 , 1 } , { ( char_T *
) ( & rtDW . n3mlm25bwm . Tail ) , 10 , 0 , 4 } , { ( char_T * ) ( & rtDW .
eihuvcejq2 ) , 8 , 0 , 5 } } ; static DataTypeTransitionTable rtBTransTable =
{ 11U , rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { {
( char_T * ) ( & rtP . G_0 ) , 0 , 0 , 17 } , { ( char_T * ) ( & rtP .
AWGNChannel1_seed ) , 7 , 0 , 2 } , { ( char_T * ) ( & rtP . Constant_Value )
, 0 , 0 , 57 } , { ( char_T * ) ( & rtP . Gain_Gain ) , 6 , 0 , 3 } , { (
char_T * ) ( & rtP . Gain2_Gain ) , 14 , 0 , 1 } } ; static
DataTypeTransitionTable rtPTransTable = { 5U , rtPTransitions } ;
