#include "ImageProcessor.h"
#include <functional>

using namespace com::anyconnect::imageprocessor;

class Test {
void* handle;
ImageProcessor* instance;
ImageProcessor* (*create)();
void (*destroy)(ImageProcessor*);

public:
  Test();
  ~Test();
void loadLib(std::string name);
bool isLoaded();
void setProcessedDataCallback();
 
};

