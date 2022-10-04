#include "setting.h"
#include <cstring>
#include <iostream>

template<typename T>
bool compare_array(T* array1,size_t sizeofarray1,T* array2,size_t sizeofarray2){
	if (sizeofarray1!=sizeofarray2)return false;
	for (unsigned i=0;i<sizeofarray1;i++){
		if (array1[i]!=array2[i])return false;
	}
	return true;
}

FILE* secure_open(const char* filename,const char* permission){
	FILE* file=NULL;
	
#if defined(_MSC_VER)
	fopen_s(&file,filename,permission);
#else
	file=fopen(filename,permission);
#endif
	
	return file;
}

bool compare_bytes(const char* array1,const char* array2){
	return strcmp(array1,array2)==0;
}

int main(const int argc,const char** argv){
	
	pktvdp test_ktvdp;
	
	if (!create_ktvdp(&test_ktvdp)){
		std::cerr<<"Failed to create ktvdp!"<<std::endl;
		return 0x1;
	}
	int value=0x41424344;
	const char* testKey="hi everyone how are you peoples";
	const size_t testKeySize=strlen(testKey);
	const char* description="This is a long description about the field and data";
	const short type=FT_INTEGER;
	if (!fill_ktvdp(test_ktvdp,testKey,type,(const void*)&value,description)){
		std::cerr<<"Failed to fill ktvdp!"<<std::endl;
		return 0x2;
	}
	
	if (test_ktvdp->key_size!=testKeySize||test_ktvdp->field_type!=type||strcmp(description,test_ktvdp->description)!=0||test_ktvdp->value.int_val!=value){
		std::cout<<(test_ktvdp->key_size!=testKeySize)<<std::endl;
		std::cout<<(test_ktvdp->field_type!=type)<<std::endl;
		std::cout<<(strcmp(description,test_ktvdp->description)!=0)<<std::endl;
		std::cout<<(test_ktvdp->value.int_val!=value)<<std::endl;
		
		std::cerr<<"ktvdp is not created correctly!"<<std::endl;
		return 0x3;
	}
	
	char* serialized_ktvdp_bytes;
	unsigned serialized_ktvdp_bytes_size;
	if (!serialize_ktvdp(test_ktvdp,&serialized_ktvdp_bytes,&serialized_ktvdp_bytes_size)){
		std::cerr<<"Failed to serialize ktvdp!"<<std::endl;
		return 0x4;
	}
	
	FILE* file=NULL;
	const char* filename="serialized_ktvdp.ktvdp";
	file=secure_open(filename,"w");
	if (file==NULL){
		std::cerr<<"Failed to open file "<<filename<<" for write"<<std::endl;
		return 0x5;
	}
	
	fwrite(serialized_ktvdp_bytes,sizeof(char),serialized_ktvdp_bytes_size,file);
	
	fclose(file);
	
	return 0;
}