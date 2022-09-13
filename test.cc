#include "setting.h"
#include <stdio.h>

int main(const int argc,const char** argv){
	char buff[4];
	int data=10;
	int_to_bytes(data,buff);
	return 0;
}