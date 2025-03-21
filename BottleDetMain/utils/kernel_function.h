#pragma once
#include"common_include.h"
//#include"utils.h"

/************************************************************************************************
* cuda check
*************************************************************************************************/
#define checkRuntime(op)  __check_cuda_runtime((op), #op, __FILE__, __LINE__)

bool __check_cuda_runtime(cudaError_t code, const char* op, const char* file, int line);

/************************************************************************************************
* kernel function's interface
*************************************************************************************************/
#define BLOCK_SIZE 8

// math 
float maxFloatDevice(float* src, int size);

float minFloatDevice(float* src, int size);

int maxIntDevice(int* src, int size);

int minIntDevice(int* src, int size);

// overload
void maxFloatDevice(float* src, int size, float* dst);

void minFloatDevice(float* src, int size, float* dst);

void maxIntDevice(int* src, int size, int* dst);

void minIntDevice(int* src, int size, int* dst);

std::pair<float, float> minmaxFloatDevice(float* src, int size);

/************************************************************************************************/
//note: resize rgb with padding
void resizeDevice(const int& batch_size, float* src, int src_width, int src_height,
    float* dst, int dstWidth, int dstHeight,
    float paddingValue, dl_utils::AffineMat matrix);

//overload:resize rgb with padding, but src's type is uin8
void resizeDevice(const int& batch_size, unsigned char* src, int src_width, int src_height,
    float* dst, int dstWidth, int dstHeight,
    float paddingValue, dl_utils::AffineMat matrix);

// overload: resize rgb/gray without padding
void resizeDevice(const int& batchSize, float* src, int srcWidth, int srcHeight,
    float* dst, int dstWidth, int dstHeight,
    dl_utils::ColorMode mode, dl_utils::AffineMat matrix);

void bgr2rgbDevice(const int& batch_size, float* src, int srcWidth, int srcHeight,
    float* dst, int dstWidth, int dstHeight);

void normDevice(const int& batch_size, float* src, int srcWidth, int srcHeight,
    float* dst, int dstWidth, int dstHeight,
    dl_utils::InitParameter norm_param);

void hwc2chwDevice(const int& batch_size, float* src, int srcWidth, int srcHeight,
    float* dst, int dstWidth, int dstHeight);

// for yolo3 yolo5 yolo6 yolo7
void decodeDevice(dl_utils::InitParameter param, float* src, int srcWidth, int srcHeight, int srcLength, float* dst, int dstWidth, int dstHeight);

// nms fast
void nmsDeviceV1(dl_utils::InitParameter param, float* src, int srcWidth, int srcHeight, int srcArea);

// nms sort
void nmsDeviceV2(dl_utils::InitParameter param, float* src, int srcWidth, int srcHeight, int srcArea,
    int* idx, float* conf);