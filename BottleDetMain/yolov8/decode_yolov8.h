#pragma once
#include"../utils/utils.h"
#include"../utils/kernel_function.h"

namespace yolov8
{
	void decodeDevice(dl_utils::InitParameter param, float* src, int srcWidth, int srcHeight, int srcLength, float* dst, int dstWidth, int dstHeight);
	void transposeDevice(dl_utils::InitParameter param, float* src, int srcWidth, int srcHeight, int srcArea, float* dst, int dstWidth, int dstHeight);
}
