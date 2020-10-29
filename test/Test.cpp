#include "Test.h"
#include <assert.h>
#include <dlfcn.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>

Test::Test()
{

}

void Test::loadLib(std::string name) 
{
  instance = NULL;
  handle = dlopen(name.c_str(), RTLD_LAZY);
	 
  if (!handle) {
    printf("%s\n", dlerror());
    return;
  }

  create = (ImageProcessor* (*)()) dlsym(handle, "create");
  destroy = (void(*)(ImageProcessor*)) dlsym(handle, "destroy");

  char* error;
  if ((error = dlerror()) != NULL) {
    printf("%s\n", error);
    return;
  }

  instance = create();
}

bool Test::isLoaded() 
{
  return instance != NULL; 
}

void Test::setProcessedDataCallback() 
{
  instance->setProcessedDataReceiveCallback([this](DataType dataType, uint64_t timestamp, int width, int height, unsigned char* data, int &length) {
    if(dataType == DataType::YUV_I420P) {
      std::cout<<"Received with timestamp: "<< timestamp <<" and processed data length: "<<length<<std::endl;
    }
  });
}

Test::~Test() {
  destroy(instance);
  dlclose(handle);
  handle = NULL;
}

Test *pTest = new Test();

int main()
{
  pTest->loadLib("./libimageprocessor.so");

  if(pTest->isLoaded()) {
    printf("Your AnyConnect ImageProcessor Library is loaded!\n");
  }
  else {
    printf("Your AnyConnect ImageProcessor Library is not loaded!\n");
  }  
  pTest->setProcessedDataCallback(); 
  while(1) {
    sleep(3);
  }
  return 0;
}
