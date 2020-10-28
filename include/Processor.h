#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include <functional>
#include <thread>
#include "ImageProcessor.h"

using namespace com::anyconnect::imageprocessor;

class Processor: public ImageProcessor {
public:
  Processor();

  virtual ~Processor();

  void pushDataForProcessing(DataType dataType, uint64_t timeStamp, unsigned char* data, int length);

  void setProcessedDataReceiveCallback(ProcessedDataReceiveHandler handler);
  

private:
  ProcessedDataReceiveHandler handler;
  
};
#endif
