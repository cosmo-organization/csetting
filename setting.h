#ifndef SETTING_H
#define SETTING_H
/**
*@author Sonu Aryan cosmo-developer@github.com
*/

#include <stddef.h>

#define MAGIC 0x636F736D6F646576
#define MAJOR_VER 0
#define MINOR_VER 1

#define FT_STRING 0
#define FT_INTEGER 1
#define FT_SHORT 2
#define FT_FLOAT 3
#define FT_DOUBLE 4
#define FT_NULL 5
#define FT_EMPTY 6
#define FT_BOOLEAN 7


#ifdef SETTING_API_BUILD_MODE
#ifdef WIN32
#define SETTING_API __declspec(dllexport)
#else
#define SETTING_API
#endif
#else
#ifdef WIN32
#define SETTING_API __declspec(dllimport)
#else
#define SETTING_API
#endif
#endif

typedef struct __KTVDP{ //key, type, value and description pair
	char* key;
	unsigned short field_type;
	union{
		char* string_val;
		int int_val;
		short short_val;
		void* null_val;
		double double_val;
		unsigned char bool_val;
		float float_val;
	}value;
	char* description;
}ktvdp,*pktvdp,**lpktvdp;

typedef struct __SETTING_PROFILE{
	char* profile_name; //Reserved profile_name length to 256
	unsigned int n_rows;
	pktvdp field_value_table;
}setting_profile,*psetting_profile,**lpsetting_profile;

typedef struct __SETTING{
	unsigned long long magic;
	unsigned char maj_ver;
	unsigned char min_ver;
	unsigned int n_profile_table;
	psetting_profile setting_profile_table;
}setting,*psetting,**lpsetting;

SETTING_API void copy_mem(void* dest,const void* src,size_t start,size_t len);
SETTING_API void is_little(char* pis_little);
SETTING_API void int_to_byte(const int __in_integer,char __out_pchar[4]);
SETTING_API void short_to_byte(const short __in_short,char __out_pchar[2]);
SETTING_API void double_to_byte(const double __in_double,char __out_pchar[8]);
SETTING_API void float_to_byte(const float __in_float,char __out_pchar[4]);
SETTING_API void long_long_to_byte(const long long __in_long_long,char __out_pchar[8]);



SETTING_API void create_ktvdp(lpktvdp __out_ktvdp);
SETTING_API void fill_ktvdp(pktvdp __in_ktvdp,short __in_type,const void* __in_value,const char* __in_description);

#endif