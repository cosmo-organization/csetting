#include "setting.h"
#include <iostream>

int main(const int argc,const char** argv){
	char buff[4];
	int data=10;
	int_to_bytes(data,buff);
	std::cout<<(short)buff[0]<<std::endl;
	std::cout<<(short)buff[1]<<std::endl;
	std::cout<<(short)buff[2]<<std::endl;
	std::cout<<(short)buff[3]<<std::endl;
	return 0;
}