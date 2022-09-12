#include "setting.h"
#include <stdio.h>

int main(const int argc,const char** argv){
	char _is_little;
	
	is_little(&_is_little);
	
	printf("0x%X\n",_is_little);
	return 0;
}