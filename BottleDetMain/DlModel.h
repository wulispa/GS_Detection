#pragma once
#define _CRT_SECURE_NO_DEPRECATE
// tensorRT include
// �����õ�ͷ�ļ�
//#include <NvInfer.h>
// onnx��������ͷ�ļ�
//#include <NvOnnxParser.h>
//#include <NvInferPlugin.h>
// �����õ�����ʱͷ�ļ�
//#include <NvInferRuntime.h>
// cuda include
//#include <cuda_runtime.h>
// system include
#include <stdio.h>
#include <math.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <functional>
//#include <unistd.h>
#include "Shlwapi.h"
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
//#include "dlCrypto.h"
#include <unordered_map>
//#ifndef DLMODEL_H
//#define DLMODEL_H
//
////using namespace cv;
//using namespace std;
//
//class Classification
//{
//public:
//	Classification();
//	~Classification();
//
//	/*---------------------------------------------------����----------------------------------------------------------*/
//	int input_batch;
//	int input_channel;
//	int input_height;
//	int input_width;
//	int input_numel;
//	string model_path;
//	string model_data_path;
//
//	float mean[3] = { 0.406, 0.456, 0.485 };
//	float std[3] = { 0.225, 0.224, 0.229 };
//
//	// ����һ�����򣬷����յĽ��
//	int num_classes = 2;
//	float output_data_host[2];     //�����ڵ�2������2���࣬���������鳤��Ϊ2�Ŀռ��Ž��,������ʱʹ�þ�̬���飡����
//
//	float* input_data_host;
//	float* input_data_device;
//	float* output_data_device;
//
//	cudaStream_t m_stream;
//
//	/*---------------------------------------------------����----------------------------------------------------------*/
//	void init();    // ��ʼ��
//	bool build_trt_model(const char* onnx_path, const char* trt_save_path);    // ����onnx����trtģ�ͣ��ɹ�����true
//	bool load_trt_model(const string& trt_path);		// ����trtģ��
//	vector<unsigned char> load_file(const string& file);    // �����ļ� trt
//	vector<string> load_labels(const char* file);			// ���ر�ǩ�ļ�txt
//	vector<float> inference(cv::Mat& image);
//	std::shared_ptr<nvinfer1::ICudaEngine> engine;	// ����
//	std::shared_ptr<nvinfer1::IExecutionContext> execution_context;	// ����
//};
//
//class ObjectDetection
//{
//public:
//	ObjectDetection();
//	~ObjectDetection();
//	struct Object
//	{
//		cv::Rect_<float> rect;
//		int label;
//		float prob;
//	};
//	/*************************����*******************************/
//	int OBJ_NUM_CLASSES;
//	int INPUT_W;
//	int INPUT_H;
//	int channels;
//	float NMS_THRESH;// �Ǽ���ֵ����
//	vector<float> BBOX_CONF_THRESH;// ���Ŷ�
//	string model_path;
//	string model_data_path;
//	int infer_cost;
//
//	float* prob;
//	int output_size;
//	nvinfer1::ICudaEngine* engine;
//	//nvinfer1::IRuntime* runtime;
//	nvinfer1::IExecutionContext* context;
//
//	/*************************����*******************************/
//public:
//	bool build_trt_model(const char* onnx_path, const char* trt_save_path);
//	bool load_trt_model(const std::string& trt_path, string model_flag);
//	unordered_map<int, vector<cv::Rect>> inference(cv::Mat& image);
//	void doInference(nvinfer1::IExecutionContext& context, float* input, float* output, const int output_size, cv::Size input_shape);
//	cv::Mat static_resize(cv::Mat& img);
//	void decode_outputs(float* prob, std::vector<Object>& objects, float scale, const int img_w, const int img_h);
//};
//
//#endif 