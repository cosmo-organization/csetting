#include <stdio.h>

/*
*@author Sonu Aryan (cosmo-developer@github.com) All Copyright reserved
*/

int main(const int argc,const char** argv){
	FILE* fptr=fopen("endianess.h","w");
	short check_byte=0x0001;
	char flag=((char*)((void*)&check_byte))[0]&0x01;
	fprintf(fptr,"#ifndef ENDIANESS_H\n"
				 "#define ENDIANESS_H\n"
				 "#define MLITTLE_ORDER 1\n"
				 "#define MBIG_ORDER 0\n"
				 "#define MBYTE_ORDER %s\n"
				 "#endif",(flag==0x1)?"MLITTLE_ORDER":"MBIG_ORDER");
	fclose(fptr);
	printf("your machine is %s\n",(flag==0x1)?"little endian":"big endian");
	return 0;
}