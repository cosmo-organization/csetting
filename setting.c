#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SETTING_API_BUILD_MODE
#include "setting.h"


SETTING_API void copy_mem(void* dest,const void* src,size_t start,size_t len){
	char* byte_buff_dest=(char*)dest;
	const char* byte_buff_src=(const char*)src;
	int i=0;
	for (i;i<(start+len);i++){
		byte_buff_dest[i]=byte_buff_src[i];
	}
}

SETTING_API void is_little(char* pis_little){
	int check_byte=0x00000001;
	(*pis_little)=((char*)((void*)&check_byte))[0]&0x01;
}

SETTING_API void int_to_byte(const int __in_integer,char __out_pchar[4]){
	char little;
	is_little(&little);
	char* buff=(char*)((void*)&__in_integer);
	/*
	if (little){
		__out_pchar[0]=buff[3];
		__out_pchar[1]=buff[2];
		__out_pchar[2]=buff[1];
		__out_pchar[3]=buff[0];
		return;
	}
	
	__out_pchar[3]=buff[3];
	__out_pchar[2]=buff[2];
	__out_pchar[1]=buff[1];
	__out_pchar[0]=buff[0];
	*/
	
	//Reduced code branch less code
	
	__out_pchar[3-3*little]=buff[3];
	__out_pchar[2-little]=buff[2];
	__out_pchar[1+little]=buff[1];
	__out_pchar[3*little]=buff[0];
	
}
SETTING_API void short_to_byte(const short __in_short,char __out_pchar[2]){
	
}
SETTING_API void double_to_byte(const double __in_double,char __out_pchar[8]){
	
}
SETTING_API void float_to_byte(const float __in_float,char __out_pchar[4]){
	
}



SETTING_API void create_ktvdp(lpktvdp __out_ktvdp){
	(*__out_ktvdp)=(pktvdp)malloc(sizeof(ktvdp));
}


SETTING_API void fill_ktvdp(pktvdp __in_ktvdp,short __in_type,const void* __in_value,const char* __in_description){
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
	
}