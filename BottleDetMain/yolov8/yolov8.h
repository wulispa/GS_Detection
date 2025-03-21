#pragma once
#include"../utils/yolo.h"
#include"../utils/utils.h"


class YOLOV8 : public yolo::YOLO
{
public:
	YOLOV8();
	YOLOV8(const dl_utils::InitParameter& param);
	~YOLOV8();
	virtual bool init(const std::vector<unsigned char>& trtFile);
	virtual bool init(const std::vector<unsigned char>& trtFile, const dl_utils::InitParameter& param);
	virtual void preprocess(const std::vector<cv::Mat>& imgsBatch);
	virtual void preprocess(const std::vector<cv::Mat>& imgsBatch, const dl_utils::InitParameter& param);
	virtual void postprocess(const std::vector<cv::Mat>& imgsBatch);
	virtual void postprocess(const std::vector<cv::Mat>& imgsBatch, const dl_utils::InitParameter& param);

	std::string model_data_path;
private:
	float* m_output_src_transpose_device;
};