This Image processor Plugin Library creates a junction between Smarter AI Device Platform Library and your AI models' preprocessed input image.

# Procedure

1. Complete the stub functions in Processor.cpp.
2. Compile your libimageprocessor.so.
3. Pack your libimageprocessor.so with the AI model and compress the package(.tar).
4. Upload the compressed AI model package to the AnyConnect dashboard and create an AI model entry.
5. Create AI container using the the AI model entry and deploy it to the Smarter AI devices.


# What’s Included

- README		Instructions to complete the Processor.cpp stub functions and compile and use libimageprocessor.so.
- Processor.h		Processor library header file.  This derived class overrides ImageProcessor base class member functions.
- Processor.cpp		Processor library source file.  You must complete the stub functions.
- ImageProcessor.h	These base class member functions are overridden by ImageProcessor derived class.
- CMakeLists.txt		Compiles libimageprocessor.so.
- test/Test.h		Test application header for libimageprocessor.so.
- test/Test.cpp		Test application source for libimageprocessor.so.
- test/Makefile		Compiles the test application.


# What’s Required

### Software packages:
- Linux
- dl library
- pthreads library 
- gcc/g++ version 7.x or higher




# How to complete the Processor.cpp stub functions

- pushDataForProcessing() // Data from the Smarter AI device platform library provided to the plugin library for custom image processing.
- setProcessedDataReceiveCallback() // Set a callback and returns processed image data from the plugin library to the Smarter AI device platform library for the AI model usage.


# How to compile your ImageProcessor Library.

Compile your libimageprocessor.so by typing “cmake . && make all”.


# How to test your ImageProcessor Library.

Compile the test application by typing “cd test/ && make all”.  This will generate a test application called “imageprocessortest”.  Copy the libimageprocessor.so to the test/ directory and run the test application by typing “./imageprocessortest”.  

If successful, the test application will print “Your AnyConnect ImageProcessor Library is loaded!”.  If not successful, the test application will print “Your AnyConnect ImageProcessor Library is not loaded.”.
