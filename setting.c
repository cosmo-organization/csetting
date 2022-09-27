#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SETTING_API_BUILD_MODE
#include "setting.h"



SETTING_API Status copy_mem(void* dest,const void* src,size_t start,size_t len){
	
	if (len<start)return Status_FAIL;
	
	char* byte_buff_dest=(char*)dest;
	const char* byte_buff_src=(const char*)src;
	int i=0;
	for (i;i<(start+len);i++){
		byte_buff_dest[i]=byte_buff_src[i];
	}
	
	return Status_OK;
}

SETTING_API Status is_little(char* pis_little){
	int check_byte=0x00000001;
	(*pis_little)=((char*)((void*)&check_byte))[0]&0x01;
	return Status_OK;
}

SETTING_API Status int_to_bytes(const int __in_integer,char __out_pchar[4]){
	char little;
	is_little(&little);
	const char* buff=(const char*)((const void*)&__in_integer);
	
	__out_pchar[3-3*(__BYTE_ORDER&__LITTLE_ENDIAN)]=buff[3];
	__out_pchar[2-(__BYTE_ORDER&__LITTLE_ENDIAN)]=buff[2];
	__out_pchar[1+ (__BYTE_ORDER & __LITTLE_ENDIAN)]=buff[1];
	__out_pchar[3* (__BYTE_ORDER & __LITTLE_ENDIAN)]=buff[0];
	return Status_OK;
}
SETTING_API Status short_to_bytes(const short __in_short,char __out_pchar[2]){
	const char* buff=(const char*)((const void*)&__in_short);
	
	__out_pchar[1- (__BYTE_ORDER & __LITTLE_ENDIAN)]=buff[1];
	__out_pchar[1* (__BYTE_ORDER & __LITTLE_ENDIAN)]=buff[0];
	return Status_OK;
}

SETTING_API Status double_to_bytes(const double __in_double,char __out_pchar[8]){
	union{
		double double_val;
		char byte_array[8];
	}union_double_char_array_size_8;
	
	union_double_char_array_size_8.double_val=__in_double;
	
#if (__BYTE_ORDER == __LITTLE_ENDIAN)
		__out_pchar[0]=union_double_char_array_size_8.byte_array[7];
		__out_pchar[1]=union_double_char_array_size_8.byte_array[6];
		__out_pchar[2]=union_double_char_array_size_8.byte_array[5];
		__out_pchar[3]=union_double_char_array_size_8.byte_array[4];
		__out_pchar[4]=union_double_char_array_size_8.byte_array[3];
		__out_pchar[5]=union_double_char_array_size_8.byte_array[2];
		__out_pchar[6]=union_double_char_array_size_8.byte_array[1];
		__out_pchar[7]=union_double_char_array_size_8.byte_array[0];	
		return;
#else
	__out_pchar[7]=union_double_char_array_size_8.byte_array[7];
	__out_pchar[6]=union_double_char_array_size_8.byte_array[6];
	__out_pchar[5]=union_double_char_array_size_8.byte_array[5];
	__out_pchar[4]=union_double_char_array_size_8.byte_array[4];
	__out_pchar[3]=union_double_char_array_size_8.byte_array[3];
	__out_pchar[2]=union_double_char_array_size_8.byte_array[2];
	__out_pchar[1]=union_double_char_array_size_8.byte_array[1];
	__out_pchar[0]=union_double_char_array_size_8.byte_array[0];
#endif
	//Reduced or branchless code may be latter
	
	return  Status_OK;
}
SETTING_API Status float_to_bytes(const float __in_float,char __out_pchar[4]){
	char little;
	is_little(&little);
	union{
		float float_val;
		char byte_array[4];
	}union_float_char_array_size_4;
	
	union_float_char_array_size_4.float_val=__in_float;
	
	if (little){
		__out_pchar[0]=union_float_char_array_size_4.byte_array[3];
		__out_pchar[1]=union_float_char_array_size_4.byte_array[2];
		__out_pchar[2]=union_float_char_array_size_4.byte_array[1];
		__out_pchar[3]=union_float_char_array_size_4.byte_array[0];
		return;
	}
	
	__out_pchar[3]=union_float_char_array_size_4.byte_array[3];
	__out_pchar[2]=union_float_char_array_size_4.byte_array[2];
	__out_pchar[1]=union_float_char_array_size_4.byte_array[1];
	__out_pchar[0]=union_float_char_array_size_4.byte_array[0];
	
	//Reduced or branchless code may be latter
	return Status_OK;
}

SETTING_API Status long_long_to_bytes(const long long __in_long_long,char __out_pchar[8]){
	union{
		long long long_long_val;
		char byte_array[8];
	}union_long_long_char_array_size_8;
	
	union_long_long_char_array_size_8.long_long_val=__in_long_long;
	
	char little;
	is_little(&little);
	
	if (little){
		__out_pchar[0]=union_long_long_char_array_size_8.byte_array[7];
		__out_pchar[1]=union_long_long_char_array_size_8.byte_array[6];
		__out_pchar[2]=union_long_long_char_array_size_8.byte_array[5];
		__out_pchar[3]=union_long_long_char_array_size_8.byte_array[4];
		__out_pchar[4]=union_long_long_char_array_size_8.byte_array[3];
		__out_pchar[5]=union_long_long_char_array_size_8.byte_array[2];
		__out_pchar[6]=union_long_long_char_array_size_8.byte_array[1];
		__out_pchar[7]=union_long_long_char_array_size_8.byte_array[0];	
		return;
	}
	
	__out_pchar[7]=union_long_long_char_array_size_8.byte_array[7];
	__out_pchar[6]=union_long_long_char_array_size_8.byte_array[6];
	__out_pchar[5]=union_long_long_char_array_size_8.byte_array[5];
	__out_pchar[4]=union_long_long_char_array_size_8.byte_array[4];
	__out_pchar[3]=union_long_long_char_array_size_8.byte_array[3];
	__out_pchar[2]=union_long_long_char_array_size_8.byte_array[2];
	__out_pchar[1]=union_long_long_char_array_size_8.byte_array[1];
	__out_pchar[0]=union_long_long_char_array_size_8.byte_array[0];
	
	//Reduced or branchless code may be latter
	
	return Status_OK;
}


SETTING_API Status bytes_to_int(const char __in_pchar[4],int* __out_pint){
	
	return Status_OK;
}
SETTING_API Status bytes_to_short(const char __in_pchar[2],short* __out_pshort){
	
	return Status_OK;
}
SETTING_API Status bytes_to_double(const char __in_pchar[8],double* __out_pdouble){
	
	
	return Status_OK;
}
SETTING_API Status bytes_to_float(const char __in_pchar[4],float* __out_pfloat){
	
	
	return Status_OK;
}
SETTING_API Status bytes_to_long_long(const char __in_pchar[8],long long* __out_plong_long){
	
	
	return Status_OK;
}


SETTING_API Status create_ktvdp(lpktvdp __out_ktvdp){
	(*__out_ktvdp)=(pktvdp)malloc(sizeof(ktvdp));
	(*__out_ktvdp)->key=NULL;
	(*__out_ktvdp)->field_type=FT_NULL;
	(*__out_ktvdp)->description=NULL;
	return Status_OK;
}


SETTING_API Status fill_ktvdp(pktvdp __in_ktvdp,short __in_type,const void* __in_value,const char* __in_description){
	const char* mem_buffer=(const char*)__in_value;
	char little;
	is_little(&little);
	switch(__in_type){
		case FT_STRING:{
			size_t value_byte_len=strlen(mem_buffer)+1;
			__in_ktvdp->value.string_val=(char*)malloc(sizeof(char)*value_byte_len);
			__in_ktvdp->field_type=__in_type;
			copy_mem(__in_ktvdp->value.string_val,mem_buffer,0,value_byte_len);
			break;
		}
		case FT_INTEGER:{
			
			break;
		}
	}
	size_t description_byte_len=strlen(__in_description)+1;
	__in_ktvdp->description=(char*)malloc(sizeof(char)*description_byte_len);
	copy_mem(__in_ktvdp->description,__in_description,0,description_byte_len);
	return Status_OK;
}
