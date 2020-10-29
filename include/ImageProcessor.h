#ifndef _IMAGE_PROCESSOR_H_
#define _IMAGE_PROCESSOR_H_

#include <string>
#include <vector>
#include <functional>

namespace com {
namespace anyconnect {
namespace imageprocessor {

///
/// \brief DataType.
///
/// Supported data types for processing.
///
enum class DataType { 
  JPEG,
  PNG,
  YUV_I420P,
  YUV_NV12,
  YUV_NV21,
  OTHER
};


///
/// Handler for receiving processed data.
///
/// \param[out] dataType - type of the processed data.
/// \param[out] timestamp - timestamp of the data buffer in miliseconds.
/// \param[out] width - width of the processed image data.
/// \param[out] height - height of the processed image data.
/// \param[out] data - processed data buffer.
/// \param[out] length - length of the processed data.
///
typedef std::function<void(DataType dataType, uint64_t &timestamp, int width, int height, unsigned char* data, int &length)> ProcessedDataReceiveHandler;

class ImageProcessor{
public:
  ImageProcessor()
  {
    ;
  }

  ///
  /// API to push data for processing.
  ///
  /// \param[in] dataType - type of the data.
  /// \param[in] timestamp - timestamp of the data buffer in milliseconds.
  /// \param[out] width - width of the provided image data.
  /// \param[out] height - height of the provided image data.
  /// \param[in] data - pushed data buffer.
  /// \param[in] length - length of the data.
  ///
  void pushDataForProcessing(DataType dataType, uint64_t timeStamp, int width, int height, unsigned char* data, int length);
  
  ///
  /// Set a callback for receiving processed data.
  ///
  /// \param[in] ProcessedDataReceiveHandler - Handler function for the processed data.
  ///
  virtual void setProcessedDataReceiveCallback(ProcessedDataReceiveHandler handler) = 0;

  virtual ~ImageProcessor()
  {
    ;
  }
};

}
}
}
#endif
