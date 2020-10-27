#include <string>
#include <vector>
#include <unistd.h>
#include "Processor.h"

Processor::Processor()
{
  //Write your initialization code
}

Processor::~Processor()
{
  // Write your de-initialization code.
}

void Processor::pushDataForProcessing(DataType dataType, uint64_t timeStamp, unsigned char* data, int length)
{
  // Process the image data
  
  // Execute the callback to return the processed data.
  if(this->handler)
  {
    this->handler(dataType, timeStamp, data, length);
  }  
}

void Processor::setProcessedDataReceiveCallback(ProcessedDataReceiveHandler handler)
{
  this->handler = handler;
}

// Create and destroy the Image processing library instance.
extern "C" {
Processor* create() {
	return new Processor();
}
void destroy(Processor* processor) {
	delete processor;
}
}
