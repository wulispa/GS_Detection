#include "pch.h"

//#include"../utils/utils.h"
//#include "../dlCrypto.h"
//
//************************************************************************************************
//* struct
//*************************************************************************************************/
//
//
//************************************************************************************************
//* function
//*************************************************************************************************/
//void dl_utils::saveBinaryFile(float* vec, size_t len, const std::string& file)
//{
//	std::ofstream  out(file, std::ios::out | std::ios::binary);
//	if (!out.is_open())
//		return;
//	out.write((const char*)vec, sizeof(float) * len);
//	out.close();
//}
//
//std::vector<uint8_t> dl_utils::readBinaryFile(const std::string& file)
//{
//
//	std::ifstream in(file, std::ios::in | std::ios::binary);
//	if (!in.is_open())
//		return {};
//
//	in.seekg(0, std::ios::end);
//	size_t length = in.tellg();
//
//	std::vector<uint8_t> data;
//	if (length > 0) {
//		in.seekg(0, std::ios::beg);
//		data.resize(length);
//
//		in.read((char*)&data[0], length);
//	}
//	in.close();
//	return data;
//}
//
//
////std::vector<unsigned char> dl_utils::loadModel(const std::string& file)
////{
////    std::ifstream in(file, std::ios::in | std::ios::binary);
////    if (!in.is_open())
////    {
////        return {};
////    }
////    in.seekg(0, std::ios::end);
////    size_t length = in.tellg();
////
////    std::vector<uint8_t> data;
////    if (length > 0)
////    {
////        in.seekg(0, std::ios::beg);
////        data.resize(length);
////        in.read((char*)&data[0], length);
////    }
////    in.close();
////    return data;
////}
////
////std::vector<unsigned char> dl_utils::loadEncryptModel(const std::string& file)
////{
////	std::string file_tmp = file;
////	if (1) {
////		initKV();
////		file_tmp = "decrypt_file_2_del";
////		decrypt_file(file, file_tmp);
////	}
////	// create a model using the API directly and serialize it to a stream
////	char* trtModelStream{ nullptr };
////	size_t size{ 0 };
////
////	std::ifstream in(file_tmp, std::ios::binary);
////	//读取engine文件检测是否符合
////	if (in.good()) {
////		in.seekg(0, in.end);
////		size = in.tellg();
////		in.seekg(0, in.beg);
////		trtModelStream = new char[size];
////		assert(trtModelStream);
////		in.read(trtModelStream, size);
////		in.close();
////	}
////	_CSTD remove(file_tmp.c_str());
////	std::vector<unsigned char> data(trtModelStream, trtModelStream + size);
////
////	return data;
////}
//
////std::string getSystemTimeStr()
////{
////	SYSTEMTIME st = { 0 };
////	GetLocalTime(&st);
////	/*std::string t = (st.wYear) + st.wMonth + st.wDay + st.wHour + st.wMinute + st.wMilliseconds;*/
////	std::string t =
////		std::to_string(st.wYear) + "." +
////		std::to_string(st.wMonth) + "." +
////		std::to_string(st.wDay) + "." +
////		std::to_string(st.wHour) + "." +
////		std::to_string(st.wMinute) + "." +
////		std::to_string(st.wSecond) + "." +
////		std::to_string(st.wMilliseconds);
////
////	return t;
////}
//
//std::string dl_utils::getSystemTimeStr()
//{
//	return std::to_string(std::rand()); 
//}
//
//bool dl_utils::setInputStream(const dl_utils::InputStream& source, const std::string& imagePath, const std::string& videoPath, const int& cameraID,
//	cv::VideoCapture& capture, int& totalBatches, int& delayTime, dl_utils::InitParameter& param)
//{
//	int total_frames = 0;
//	std::string img_format;
//	switch (source)
//	{
//	case dl_utils::InputStream::IMAGE:
//		img_format = imagePath.substr(imagePath.size()-4, 4);
//		if (img_format == ".png" || img_format == ".PNG")
//		{
//			/*sample::gLogWarning << "+-----------------------------------------------------------+" << std::endl;
//			sample::gLogWarning << "| If you use PNG format pictures, the file name must be eg: |" << std::endl;
//			sample::gLogWarning << "| demo0.png, demo1.png, demo2.png ......, but not demo.png. |" << std::endl;
//			sample::gLogWarning << "| The above rules are determined by OpenCV.					|" << std::endl;
//			sample::gLogWarning << "+-----------------------------------------------------------+" << std::endl;*/
//		}
//		capture.open(imagePath); //cv::CAP_IMAGES : !< OpenCV Image Sequence (e.g. img_%02d.jpg)
//		param.batch_size = 1;
//		total_frames = 1;
//		totalBatches = 1;
//		delayTime = 0;
//		break;
//	case dl_utils::InputStream::VIDEO:
//		capture.open(videoPath);
//		total_frames = capture.get(cv::CAP_PROP_FRAME_COUNT);
//		totalBatches = (total_frames % param.batch_size == 0) ?
//			(total_frames / param.batch_size) : (total_frames / param.batch_size + 1);
//		break;
//	case dl_utils::InputStream::CAMERA:
//		capture.open(cameraID);
//		total_frames = INT_MAX;
//		totalBatches = INT_MAX;
//		break;
//	default:
//		break;
//	}
//	param.src_h = capture.get(cv::CAP_PROP_FRAME_HEIGHT);
//	param.src_w = capture.get(cv::CAP_PROP_FRAME_WIDTH);
//
//	return capture.isOpened();
//}
//
//void dl_utils::show(const std::vector<std::vector<dl_utils::Box>>& objectss, const std::vector<std::string>& classNames,
//	const int& cvDelayTime, std::vector<cv::Mat>& imgsBatch)
//{
//	// todo
//	std::string windows_title = "image";
//	if(!imgsBatch[0].empty())
//	{
//		cv::namedWindow(windows_title, cv::WINDOW_NORMAL | cv::WINDOW_KEEPRATIO);  // allow window resize(Linux)
//
//		int max_w = 1280;
//		int max_h = 1024;
//		/*int max_w = 720;
//		int max_h = 405;*/
//		if (imgsBatch[0].rows > max_h || imgsBatch[0].cols > max_w)
//		{
//			cv::resizeWindow(windows_title, max_w, imgsBatch[0].rows * max_w / imgsBatch[0].cols );
//		}
//	}
//	
//	// vis
//	cv::Scalar color = cv::Scalar(0, 255, 0);
//	cv::Point bbox_points[1][4];
//	const cv::Point* bbox_point0[1] = { bbox_points[0] };
//	int num_points[] = { 4 };
//	//for (size_t bi = 0; bi < objectss.size(); bi++)
//	for (size_t bi = 0; bi < imgsBatch.size(); bi++)
//	{
//		if (!objectss.empty())
//		{
//			//for (auto& box : objectss[bi])
//			for (int i = 0; i < objectss[bi].size(); i++)
//			{
//				auto box = objectss[bi][i];
//				if (classNames.size() == 91) // coco91
//				{
//					color = Colors::color91[box.label];
//				}
//				if (classNames.size() == 80) // coco80
//				{
//					color = Colors::color80[box.label];
//				}
//				if (classNames.size() == 20) // voc20
//				{
//					color = Colors::color80[box.label];
//				}
//				if (classNames.size() == 1) // bottle1
//				{
//					color = Colors::color1[0];
//				}
//				cv::rectangle(imgsBatch[bi], cv::Point(box.left, box.top), cv::Point(box.right, box.bottom), color, 2, cv::LINE_AA);
//				// cv::putText(imgsBatch[bi], cv::format("%.4f", box.confidence), cv::Point(box.left, box.top - 3), cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
//				// cv::putText(imgsBatch[bi], classNames[box.label], cv::Point(box.left, box.top + 12), cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
//				cv::String a = classNames[box.label] + " ";
//				cv::String b = std::to_string(box.confidence).substr(0, 6);
//				cv::String det_info = a + b;
//				//cv::String det_info = classNames[box.label] + " " + cv::format("%.4f", box.confidence);
//				bbox_points[0][0] = cv::Point(box.left, box.top);
//				bbox_points[0][1] = cv::Point(box.left + det_info.size() * 11, box.top);
//				bbox_points[0][2] = cv::Point(box.left + det_info.size() * 11, box.top - 15);
//				bbox_points[0][3] = cv::Point(box.left, box.top - 15);
//				cv::fillPoly(imgsBatch[bi], bbox_point0, num_points, 1, color);
//				cv::putText(imgsBatch[bi], det_info, bbox_points[0][0], cv::FONT_HERSHEY_DUPLEX, 0.6, cv::Scalar(255, 255, 255), 1, cv::LINE_AA);
//
//				if (!box.land_marks.empty()) // for facial landmarks
//				{
//					for (auto& pt:box.land_marks)
//					{
//						cv::circle(imgsBatch[bi], pt, 1, cv::Scalar(255, 255, 255), 1, cv::LINE_AA, 0);
//					}
//				}
//			}
//		}
//		
//		//cv::Mat img = imgsBatch[bi];
//		cv::imshow(windows_title, imgsBatch[bi]);
//		cv::waitKey();
//	}
//
//}
//
//void dl_utils::save(const std::vector<std::vector<Box>>& objectss, const std::vector<std::string>& classNames,
//	const std::string& savePath, std::vector<cv::Mat>& imgsBatch, const int& batchSize, const int& batchi)
//{
//	cv::Scalar color = cv::Scalar(0, 255, 0);
//	cv::Point bbox_points[1][4];
//	const cv::Point* bbox_point0[1] = { bbox_points[0] };
//	int num_points[] = { 4 };
//	//for (size_t bi = 0; bi < objectss.size(); bi++)
//	for (size_t bi = 0; bi < imgsBatch.size(); bi++)
//	{
//		if (!objectss.empty())
//		{
//			for (auto& box : objectss[bi])
//			{
//				if (classNames.size() == 91) // coco91
//				{
//					color = Colors::color91[box.label];
//				}
//				if (classNames.size() == 80) // coco80
//				{
//					color = Colors::color80[box.label];
//				}
//				if (classNames.size() == 20) // voc20
//				{
//					color = Colors::color80[box.label];
//				}
//				cv::rectangle(imgsBatch[bi], cv::Point(box.left, box.top), cv::Point(box.right, box.bottom), color, 2, cv::LINE_AA);
//				// cv::putText(imgsBatch[bi], cv::format("%.4f", box.confidence), cv::Point(box.left, box.top - 3), cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
//				// cv::putText(imgsBatch[bi], classNames[box.label], cv::Point(box.left, box.top + 12), cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
//				cv::String det_info = classNames[box.label] + " " + cv::format("%.4f", box.confidence);
//				bbox_points[0][0] = cv::Point(box.left, box.top);
//				bbox_points[0][1] = cv::Point(box.left + det_info.size() * 11, box.top);
//				bbox_points[0][2] = cv::Point(box.left + det_info.size() * 11, box.top - 15);
//				bbox_points[0][3] = cv::Point(box.left, box.top - 15);
//				cv::fillPoly(imgsBatch[bi], bbox_point0, num_points, 1, color);
//				cv::putText(imgsBatch[bi], det_info, bbox_points[0][0], cv::FONT_HERSHEY_DUPLEX, 0.6, cv::Scalar(255, 255, 255), 1, cv::LINE_AA);
//				
//				if (!box.land_marks.empty())
//				{
//					for (auto& pt : box.land_marks)
//					{
//						cv::circle(imgsBatch[bi], pt, 1, cv::Scalar(255, 255, 255), 1, cv::LINE_AA, 0);
//					}
//				}
//			}
//		}
//		
//		int imgi = batchi * batchSize + bi;
//		cv::imwrite(savePath + "_" + std::to_string(imgi) + ".jpg", imgsBatch[bi]);
//		cv::waitKey(1); // waitting for writting imgs 
//	}
//}
//
//************************************************************************************************
//* class
//*************************************************************************************************/
//dl_utils::HostTimer::HostTimer()
//{
//    t1 = std::chrono::steady_clock::now();
//}
//
//float dl_utils::HostTimer::getUsedTime()
//{
//    t2 = std::chrono::steady_clock::now();
//    std::chrono::duration<double> time_used = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
//    return(1000 * time_used.count()); // ms
//}
//
//dl_utils::HostTimer::~HostTimer()
//{
//}
//
//dl_utils::DeviceTimer::DeviceTimer()
//{
//	cudaEventCreate(&start);
//	cudaEventCreate(&end);
//	cudaEventRecord(start);
//}
//
//float dl_utils::DeviceTimer::getUsedTime()
//{
//	cudaEventRecord(end);
//	cudaEventSynchronize(end);
//	float total_time;
//	cudaEventElapsedTime(&total_time, start, end);
//	return total_time;
//}
//
//dl_utils::DeviceTimer::DeviceTimer(cudaStream_t stream)
//{
//	cudaEventCreate(&start);
//	cudaEventCreate(&end);
//	cudaEventRecord(start, stream);
//}
//
//float dl_utils::DeviceTimer::getUsedTime(cudaStream_t stream)
//{
//	cudaEventRecord(end, stream);
//	cudaEventSynchronize(end);
//	float total_time;
//	cudaEventElapsedTime(&total_time, start, end);
//	return total_time;
//}
//
//dl_utils::DeviceTimer::~DeviceTimer()
//{
//	cudaEventDestroy(start);
//	cudaEventDestroy(end);
//}