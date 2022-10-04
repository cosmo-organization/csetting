#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SETTING_API_BUILD_MODE
#include "setting.h"



SETTING_API Status copy_mem(void* dest,const void* src,size_t start,size_t len,unsigned dest_start){
	
	char* byte_buff_dest=(char*)dest;
	const char* byte_buff_src=(const char*)src;
	int i=(int)start;
	for (i;i<(start+len);i++){
		byte_buff_dest[dest_start+i]=byte_buff_src[i];
	}
	
	return Status_OK;
}

SETTING_API Status is_little(char* pis_little){
	short check_byte=0x0001;
	(*pis_little)=((char*)((void*)&check_byte))[0]&0x01;
	return Status_OK;
}

SETTING_API Status int_to_bytes(const int __in_integer,char __out_pchar[4]){
	char little;
	is_little(&little);
	const char* buff=(const char*)((const void*)&__in_integer);
	
	__out_pchar[3-3*(MBYTE_ORDER & MLITTLE_ORDER)]=buff[3];
	__out_pchar[2-(MBYTE_ORDER & MLITTLE_ORDER)]=buff[2];
	__out_pchar[1+ (MBYTE_ORDER & MLITTLE_ORDER)]=buff[1];
	__out_pchar[3* (MBYTE_ORDER & MLITTLE_ORDER)]=buff[0];
	return Status_OK;
}
SETTING_API Status short_to_bytes(const short __in_short,char __out_pchar[2]){
	const char* buff=(const char*)((const void*)&__in_short);
	
	__out_pchar[1- (MBYTE_ORDER & MLITTLE_ORDER)]=buff[1];
	__out_pchar[1* (MBYTE_ORDER & MLITTLE_ORDER)]=buff[0];
	return Status_OK;
}

SETTING_API Status double_to_bytes(const double __in_double,char __out_pchar[8]){
	union{
		double double_val;
		char byte_array[8];
	}union_double_char_array_size_8;
	
	union_double_char_array_size_8.double_val=__in_double;
	
#if (MBYTE_ORDER == MLITTLE_ORDER)
		__out_pchar[0]=union_double_char_array_size_8.byte_array[7];
		__out_pchar[1]=union_double_char_array_size_8.byte_array[6];
		__out_pchar[2]=union_double_char_array_size_8.byte_array[5];
		__out_pchar[3]=union_double_char_array_size_8.byte_array[4];
		__out_pchar[4]=union_double_char_array_size_8.byte_array[3];
		__out_pchar[5]=union_double_char_array_size_8.byte_array[2];
		__out_pchar[6]=union_double_char_array_size_8.byte_array[1];
		__out_pchar[7]=union_double_char_array_size_8.byte_array[0];	
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

	union{
		float float_val;
		char byte_array[4];
	}union_float_char_array_size_4;
	
	union_float_char_array_size_4.float_val=__in_float;

#if (MBYTE_ORDER==MLITTLE_ORDER)	
	__out_pchar[0]=union_float_char_array_size_4.byte_array[3];
	__out_pchar[1]=union_float_char_array_size_4.byte_array[2];
	__out_pchar[2]=union_float_char_array_size_4.byte_array[1];
	__out_pchar[3]=union_float_char_array_size_4.byte_array[0];
#else
	
	__out_pchar[3]=union_float_char_array_size_4.byte_array[3];
	__out_pchar[2]=union_float_char_array_size_4.byte_array[2];
	__out_pchar[1]=union_float_char_array_size_4.byte_array[1];
	__out_pchar[0]=union_float_char_array_size_4.byte_array[0];
	
	//Reduced or branchless code may be latter
#endif
	return Status_OK;
}

SETTING_API Status long_long_to_bytes(const long long __in_long_long,char __out_pchar[8]){
	union{
		long long long_long_val;
		char byte_array[8];
	}union_long_long_char_array_size_8;
	
	union_long_long_char_array_size_8.long_long_val=__in_long_long;
	
	
#if (MBYTE_ORDER==MLITTLE_ORDER)	
	__out_pchar[0]=union_long_long_char_array_size_8.byte_array[7];
	__out_pchar[1]=union_long_long_char_array_size_8.byte_array[6];
	__out_pchar[2]=union_long_long_char_array_size_8.byte_array[5];
	__out_pchar[3]=union_long_long_char_array_size_8.byte_array[4];
	__out_pchar[4]=union_long_long_char_array_size_8.byte_array[3];
	__out_pchar[5]=union_long_long_char_array_size_8.byte_array[2];
	__out_pchar[6]=union_long_long_char_array_size_8.byte_array[1];
	__out_pchar[7]=union_long_long_char_array_size_8.byte_array[0];	
#else
	
	__out_pchar[7]=union_long_long_char_array_size_8.byte_array[7];
	__out_pchar[6]=union_long_long_char_array_size_8.byte_array[6];
	__out_pchar[5]=union_long_long_char_array_size_8.byte_array[5];
	__out_pchar[4]=union_long_long_char_array_size_8.byte_array[4];
	__out_pchar[3]=union_long_long_char_array_size_8.byte_array[3];
	__out_pchar[2]=union_long_long_char_array_size_8.byte_array[2];
	__out_pchar[1]=union_long_long_char_array_size_8.byte_array[1];
	__out_pchar[0]=union_long_long_char_array_size_8.byte_array[0];
	
	//Reduced or branchless code may be latter
	
#endif
	return Status_OK;
}


SETTING_API Status bytes_to_int(const char __in_pchar[4],int* __out_pint){
	union{
		char byte_array[4];
		int int_val;
	}union_char_array_size_4_int;
	
#if (MBYTE_ORDER==MLITTLE_ORDER)
	union_char_array_size_4_int.byte_array[3]=__in_pchar[0];
	union_char_array_size_4_int.byte_array[2]=__in_pchar[1];
	union_char_array_size_4_int.byte_array[1]=__in_pchar[2];
	union_char_array_size_4_int.byte_array[0]=__in_pchar[3];
	
#else
	union_char_array_size_4_int.byte_array[3]=__in_pchar[3];
	union_char_array_size_4_int.byte_array[2]=__in_pchar[2];
	union_char_array_size_4_int.byte_array[1]=__in_pchar[1];
	union_char_array_size_4_int.byte_array[0]=__in_pchar[0];
#endif
	(*__out_pint)=union_char_array_size_4_int.int_val;
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

EXTERN_C SETTING_API Status create_setting_profile(const char* __in_profile_name,lpsetting_profile __out_setting_profile){
	size_t profile_name_size=strlen(__in_profile_name);
	if (profile_name_size>250)return Status_FAIL;
	
	(*__out_setting_profile)=(psetting_profile)malloc(sizeof(setting_profile));
	(*__out_setting_profile)->profile_name_size=(unsigned char)strlen(__in_profile_name);
	(*__out_setting_profile)->profile_name=(char*)malloc(sizeof(char)*(profile_name_size+1));
	copy_mem((*__out_setting_profile)->profile_name,__in_profile_name,0,profile_name_size+1,0);
	(*__out_setting_profile)->n_rows=0;
	(*__out_setting_profile)->field_value_table=NULL;
	
	return Status_OK;
}

EXTERN_C SETTING_API Status add_ktvdp(const psetting_profile __in_setting_profile,const pktvdp __in_ktvdp){
	
	if (__in_setting_profile==NULL || __in_ktvdp==NULL) return Status_FAIL;
	
	unsigned int* n_rows=&__in_setting_profile->n_rows;
	if (*n_rows==0){
		__in_setting_profile->field_value_table=(lpktvdp)malloc(sizeof(pktvdp));
		(*n_rows)++;
		__in_setting_profile->field_value_table[0]=__in_ktvdp;
		return Status_OK;
	}
	
	(*n_rows)++;
	
	__in_setting_profile->field_value_table=(lpktvdp)realloc(__in_setting_profile->field_value_table,sizeof(pktvdp)*(*n_rows));
	__in_setting_profile->field_value_table[(*n_rows)-1]=__in_ktvdp;
	return Status_OK;
}

EXTERN_C SETTING_API Status create_setting(lpsetting __out_setting){
	(*__out_setting)=(psetting)malloc(sizeof(setting));
	(*__out_setting)->magic=MAGIC;
	(*__out_setting)->maj_ver=MAJOR_VER;
	(*__out_setting)->min_ver=MINOR_VER;
	(*__out_setting)->n_rows=0;
	(*__out_setting)->setting_profile_table=NULL;
	return Status_OK;
}

EXTERN_C SETTING_API Status add_setting_profile(const psetting __in_setting,const psetting_profile __in_setting_profile){
	if (__in_setting==NULL || __in_setting_profile==NULL)return Status_FAIL;
	
	unsigned int* n_rows=&__in_setting->n_rows;
	if (*n_rows==0){
		__in_setting->setting_profile_table=(lpsetting_profile)malloc(sizeof(psetting_profile));
		(*n_rows)++;
		__in_setting->setting_profile_table[0]=__in_setting_profile;
		return Status_OK;
	}
	
	(*n_rows)++;
	
	__in_setting->setting_profile_table=(lpsetting_profile)realloc(__in_setting->setting_profile_table,sizeof(psetting_profile)*(*n_rows));
	__in_setting->setting_profile_table[(*n_rows)-1]=__in_setting_profile;
	return Status_OK;
}


SETTING_API Status fill_ktvdp(pktvdp __in_ktvdp,const char* __in_key,short __in_type,const void* __in_value,const char* __in_description){
	
	if (__in_value==NULL&&__in_type!=FT_NULL) return Status_FAIL;
	if (__in_ktvdp==NULL)return Status_FAIL;
	if (__in_key==NULL)return Status_FAIL;
	
	size_t key_size=strlen(__in_key);
	
	if (key_size>250) return Status_FAIL;
	
	__in_ktvdp->key_size=(unsigned char)key_size;
	__in_ktvdp->key=(char*)malloc(sizeof(char)*(key_size+1));
	copy_mem(__in_ktvdp->key,__in_key,0,key_size+1,0);
	
	//printf("%s==%s %d\n",__in_ktvdp->key,__in_key,strcmp(__in_ktvdp->key,__in_key));
	

	switch(__in_type){
		case FT_STRING:{
			const char* mem_buffer=(const char*)__in_value;
			size_t value_byte_len=strlen(mem_buffer)+1;
			__in_ktvdp->value.string_val=(char*)malloc(sizeof(char)*value_byte_len);
			__in_ktvdp->field_type=__in_type;
			copy_mem(__in_ktvdp->value.string_val,mem_buffer,0,value_byte_len,0);
			break;
		}
		case FT_INTEGER:{
			const int int_val=*((const int*)__in_value);
			__in_ktvdp->value.int_val=int_val;
			__in_ktvdp->field_type=__in_type;
			break;
		}
		case FT_NULL:{
			__in_ktvdp->value.null_val=NULL;
			__in_ktvdp->field_type=__in_type;
		}
	}
	if (__in_description!=NULL){
		size_t description_byte_len=strlen(__in_description)+1;
		__in_ktvdp->description=(char*)malloc(sizeof(char)*description_byte_len);
		copy_mem(__in_ktvdp->description,__in_description,0,description_byte_len,0);
	}else{
		__in_ktvdp->description=(char*)malloc(sizeof(char)*2);
		copy_mem(__in_ktvdp->description,"",0,2,0);
	}
	return Status_OK;
}


EXTERN_C SETTING_API Status serialize_ktvdp(const pktvdp __in_ktvdp,char** __out_pchar,unsigned int* __out_puint){
	if (__in_ktvdp==NULL) return Status_FAIL;
	
	int track=0;
	
	(*__out_pchar)=(char*)malloc(sizeof(char)*__in_ktvdp->key_size+1+2+1); //+2 bytes for short field_type +1 for key_size +1 for end string escape \0
	copy_mem((*__out_pchar),&__in_ktvdp->key_size,0,1,track);
	track+=1;
	copy_mem((*__out_pchar),__in_ktvdp->key,0,__in_ktvdp->key_size+1,track);
	track+=__in_ktvdp->key_size;//This area may leads to future bug working fine for now
	
	
	char field_type_bytes[2];
	short_to_bytes(__in_ktvdp->field_type,field_type_bytes);
	copy_mem((*__out_pchar),field_type_bytes,0,2,track);
	track+=2;
	
	switch(__in_ktvdp->field_type){
		case FT_STRING:{
			size_t string_length=strlen(__in_ktvdp->value.string_val);
			char int_bytes[4];
			int_to_bytes((int)string_length,int_bytes);
			(*__out_pchar)=(char*)realloc((*__out_pchar),sizeof(char)*(track+4+string_length+1)); //4 byte string length size data + string_length_size+ 1 byte end of string escape \0
			copy_mem((*__out_pchar),int_bytes,0,4,track);
			track+=4;
			copy_mem((*__out_pchar),__in_ktvdp->value.string_val,0,string_length+1,track);
			track+=(int)string_length+1;
			break;
		}
		case FT_INTEGER:{
			char int_bytes[4];
			int_to_bytes(__in_ktvdp->value.int_val,int_bytes);
			(*__out_pchar)=(char*)realloc((*__out_pchar),sizeof(char)*(track+4)); //4 byte
			copy_mem((*__out_pchar),int_bytes,0,4,track);
			track+=4;
			break;
		}
	}
	
	size_t string_length=strlen(__in_ktvdp->description);
	char int_bytes[4];
	int_to_bytes((int)string_length,int_bytes);
	(*__out_pchar)=(char*)realloc((*__out_pchar),sizeof(char)*(track+4+string_length+1)); //4 byte string length size data + string_length_size+ 1 byte end of string escape \0
	copy_mem((*__out_pchar),int_bytes,0,4,track);
	track+=4;
	int currtrack=track;
	copy_mem((*__out_pchar),__in_ktvdp->description,0,string_length+1,track);
	track+=(int)string_length+1;
	
	(*__out_puint)=track;
	
	
	return Status_OK;
}