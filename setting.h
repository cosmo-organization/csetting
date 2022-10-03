#ifndef SETTING_H
#define SETTING_H
/**
*@author Sonu Aryan cosmo-developer@github.com
*/

#include <stddef.h>
#include "endianess.h"

#define MAGIC 0x636F736D6F6F7267
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


#if defined(_MSC_VER) || defined(WIN32)
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
#define EXPORT
#define IMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif


#ifdef SETTING_API_BUILD_MODE
#define SETTING_API EXPORT
#else
#define SETTING_API IMPORT
#endif


#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

typedef unsigned char Status;
#define Status_OK	1
#define Status_FAIL	0



typedef struct __KTVDP { //key, type, value and description pair
	char* key;
	unsigned short field_type;
	union {
		char* string_val;
		int int_val;
		short short_val;
		void* null_val;
		double double_val;
		unsigned char bool_val;
		float float_val;
	}value;
	char* description;
}ktvdp, * pktvdp, ** lpktvdp;

typedef struct __SETTING_PROFILE {
	unsigned char profile_name_size;
	char* profile_name; //max profile_name length to 250
	unsigned int n_rows;
	lpktvdp field_value_table;
}setting_profile, * psetting_profile, ** lpsetting_profile;

typedef struct __SETTING {
	unsigned long long magic;
	unsigned char maj_ver;
	unsigned char min_ver;
	unsigned int n_profile_table;
	lpsetting_profile setting_profile_table;
}setting, * psetting, ** lpsetting;


EXTERN_C SETTING_API Status copy_mem(void* dest, const void* src, size_t start, size_t len);
EXTERN_C SETTING_API Status is_little(char* pis_little);

//All take any type of byte order primitive but give out only big endian byte order in __out_pchar
EXTERN_C SETTING_API Status int_to_bytes(const int __in_integer, char __out_pchar[4]);
EXTERN_C SETTING_API Status short_to_bytes(const short __in_short, char __out_pchar[2]);
EXTERN_C SETTING_API Status double_to_bytes(const double __in_double, char __out_pchar[8]);
EXTERN_C SETTING_API Status float_to_bytes(const float __in_float, char __out_pchar[4]);
EXTERN_C SETTING_API Status long_long_to_bytes(const long long __in_long_long, char __out_pchar[8]);

//Take big endian order byte in __in_pchar and give out machine specific byte ordered primitive
EXTERN_C SETTING_API Status bytes_to_int(const char __in_pchar[4], int* __out_pint);
EXTERN_C SETTING_API Status bytes_to_short(const char __in_pchar[2], short* __out_pshort);
EXTERN_C SETTING_API Status bytes_to_double(const char __in_pchar[8], double* __out_pdouble);
EXTERN_C SETTING_API Status bytes_to_float(const char __in_pchar[4], float* __out_pfloat);
EXTERN_C SETTING_API Status bytes_to_long_long(const char __in_pchar[8], long long* __out_plong_long);

EXTERN_C SETTING_API Status create_ktvdp(lpktvdp __out_ktvdp);
EXTERN_C SETTING_API Status fill_ktvdp(pktvdp __in_ktvdp, short __in_type, const void* __in_value, const char* __in_description);

EXTERN_C SETTING_API Status create_setting_profile(const char* __in_profile_name,lpsetting_profile __out_setting_profile);

#endif