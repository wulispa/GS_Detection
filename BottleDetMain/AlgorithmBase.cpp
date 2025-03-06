#include "pch.h"
#include <chrono>
#include "AlgorithmBase.h"
#include "myLogger.h"

using namespace cv;

//
DWORD WINAPI AICheckFun(LPVOID pthread);
DWORD WINAPI TraditionCheckFun(LPVOID pthread);
//DWORD WINAPI IdentifyCheckFun(LPVOID pthread);

//VOID CallBackAI(WPARAM wparam, LPARAM lparam);

VOID CallBackTradition(WPARAM wparam, LPARAM lparam);

VOID CallBackIdentifi(WPARAM wparam, LPARAM lparam);

char* MyW2A2(const CString& str) {
	int n = str.GetLength();
	int len = WideCharToMultiByte(CP_ACP, 0, str, n, NULL, 0, NULL, NULL);
	char* strchar = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, str, n + 1, strchar, len + 1, NULL, NULL);
	strchar[len] = '\0';
	return strchar;
}

bool isFileExists_fopen(string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

AlgorithmBase::AlgorithmBase()
{
	result = 1;
	m_Exit = false;
	ho_MaskImage.clear();
	ReadImage(&ho_SingleMaskImage, ".\\mask0.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask1.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask2.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask3.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_MaskImage, ".\\mask.bmp");
	//mpara = new TraditionPara;
	//setParameters(param);
	//yolo = new YOLOV8(param);

}

AlgorithmBase::AlgorithmBase(DataManager* pdata)
	:m_pData(pdata),
	m_AIthreadPool(MUTIL_NUM), //初始化线程池大小
	m_TraditionThreadPool(MUTIL_NUM),  //初始化线程池大小
	m_AIthreadPool_test(MUTIL_NUM),
	m_TraditionThreadPool_test(MUTIL_NUM)
{
	result = 1;
	m_Exit = false;
	InitThread();
	MutilFlag = true;
	ho_MaskImage.clear();
	//ReadImage(&ho_SingleMaskImage, ".\\mask0.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_SingleMaskImage, ".\\mask1.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_SingleMaskImage, ".\\mask2.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_SingleMaskImage, ".\\mask3.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	////setParameters(param);
	////yolo = new YOLOV8(param);
	//for (int i = 0; i < MUTIL_NUM; i++)
	//{
	//	ho_MaskImages.push_back(ho_MaskImage);
	//	//ReadImage(&image, ".\\mask.bmp");
	//	//ho_MaskImages.push_back(image);
	//}
	//mpara = new TraditionPara;

}

AlgorithmBase::AlgorithmBase(const AlgorithmBase& obj)
{
	this->m_pData = obj.m_pData;
	//this->model2 = obj.model2;
	//this->obj_models[0] = obj.obj_models[0];
	//this->cur_txt_order = obj.cur_txt_order;
	result = 1;
	m_Exit = false;	
	InitThread();
	MutilFlag = true;
	ho_MaskImage.clear();
	ReadImage(&ho_SingleMaskImage, ".\\mask0.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask1.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask2.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask3.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	for (int i = 0; i < MUTIL_NUM; i++)
	{
		ho_MaskImages.push_back(ho_MaskImage);
		//ReadImage(&image, ".\\mask.bmp");
		//ho_MaskImages.push_back(image);
	}
	//setParameters(param);
	//yolo = new YOLOV8(param);

}

AlgorithmBase& AlgorithmBase::operator=(const AlgorithmBase& obj)
{
	// TODO: 在此处插入 return 语句
	if (this == &obj) {
		return *this;
	}
	//mpara = new TraditionPara;
	this->m_pData = obj.m_pData;
	this->m_Exit = obj.m_Exit;
	ho_MaskImage.clear();
	ReadImage(&ho_SingleMaskImage, ".\\mask0.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask1.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask2.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask3.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_MaskImage, ".\\mask.bmp");
	//setParameters(param);
	//yolo = new YOLOV8(param);
	return *this;
}

AlgorithmBase::~AlgorithmBase()
{
	RelaseThread();	
	//vector<HObject>().swap(ho_MaskImages);
	vector<vector<HObject>>().swap(ho_MaskImages);
}

bool exists(const string& path) {

#ifdef _WIN32
	return ::PathFileExistsA(path.c_str());
#else
	return access(path.c_str(), R_OK) == 0;
#endif
}
//class TRTLogger : public nvinfer1::ILogger {
//public:
//	virtual void log(Severity severity, nvinfer1::AsciiChar const* msg) noexcept override {
//		if (severity <= Severity::kINFO) {
//			// 打印带颜色的字符，格式如下：
//			// printf("\033[47;33m打印的文本\033[0m");
//			// 其中 \033[ 是起始标记
//			//      47    是背景颜色
//			//      ;     分隔符
//			//      33    文字颜色
//			//      m     开始标记结束
//			//      \033[0m 是终止标记
//			// 其中背景颜色或者文字颜色可不写
//			// 部分颜色代码 https://blog.csdn.net/ericbar/article/details/79652086
//			if (severity == Severity::kWARNING) {
//				//printf("\033[33m%s: %s\033[0m\n", severity_string(severity), msg);
//			}
//			else if (severity <= Severity::kERROR) {
//				//printf("\033[31m%s: %s\033[0m\n", severity_string(severity), msg);
//			}
//			else {
//				//printf("%s: %s\n", severity_string(severity), msg);
//			}
//		}
//	}
//} logger;
//inline const char* severity_string(nvinfer1::ILogger::Severity t) {
//	switch (t) {
//	case nvinfer1::ILogger::Severity::kINTERNAL_ERROR: return "internal_error";
//	case nvinfer1::ILogger::Severity::kERROR:   return "error";
//	case nvinfer1::ILogger::Severity::kWARNING: return "warning";
//	case nvinfer1::ILogger::Severity::kINFO:    return "info";
//	case nvinfer1::ILogger::Severity::kVERBOSE: return "verbose";
//	default: return "unknow";
//	}
//}


//bool AlgorithmBase::build_trt_model(const char* onnx_path, const char* trt_save_path)
//{
//	if (exists(trt_save_path)) {
//		std::cout << trt_save_path << "has exists." << std::endl;
//		return true;
//	}
//	//TRTLogger logger;
//	// 这是基本需要的组件
//	auto builder = nvinfer1::createInferBuilder(logger);
//	auto config = builder->createBuilderConfig();
//	auto network = builder->createNetworkV2(1);
//	decry_onnx(onnx_path);
//	onnx_path = "tmp_onnx.onnx";
//	// 通过onnxparser解析器解析的结果会填充到network中，类似addConv的方式添加进去
//	auto parser = nvonnxparser::createParser(*network, logger);
//	if (!parser->parseFromFile(onnx_path, 1)) {
//		printf("Failed to parse your model.onnx\n");
//
//		// 注意这里的几个指针还没有释放，是有内存泄漏的，后面考虑更优雅的解决
//		return false;
//	}
//	// 设置fp16精度！！！！
//	/*if (builder->platformHasFastFp16()) {
//		config->setFlag(nvinfer1::BuilderFlag::kFP16);
//	}*/
//	int maxBatchSize = 1;
//	printf("Workspace Size = %.2f MB\n", (1 << 28) / 1024.0f / 1024.0f);
//	config->setMaxWorkspaceSize(1 << 28);
//	// 如果模型有多个输入，则必须多个profile
//	auto profile = builder->createOptimizationProfile();
//	auto input_tensor = network->getInput(0);
//	auto input_dims = input_tensor->getDimensions();
//	engine = builder->buildEngineWithConfig(*network, *config);
//	//engine_temp = engine;
//	if (engine == nullptr) {
//		printf("Build engine failed.\n");
//		return false;
//	}
//	// 将模型序列化，并储存为文件
//	string tmp_path = "tmp_2_del.trtmodel";
//	auto model_data = engine->serialize();
//	FILE* f = fopen(tmp_path.c_str(), "wb");
//	fwrite(model_data->data(), 1, model_data->size(), f);
//	fclose(f);
//	if (1) {
//		initKV();
//		encrypt_file(tmp_path, trt_save_path, onnx_path);
//	}
//	// 卸载顺序按照构建顺序倒序
//	_CSTD remove(tmp_path.c_str());
//	printf("Done.\n");
//	return true;
//}
//
//void AlgorithmBase::setParameters(dl_utils::InitParameter& initParameters)
//{
//	initParameters.class_names = dl_utils::dataSets::bottle_top;
//	//initParameters.num_class = 2; // 
//	initParameters.num_class = 6; // 
//
//	initParameters.dynamic_batch = false;
//	initParameters.batch_size = 1; // should be the same as the val while compling the onnx
//
//	// n, s, m, l
//	initParameters.src_h = 1440;
//	initParameters.src_w = 1080;
//	initParameters.dst_h = 480;
//	initParameters.dst_w = 480;
//	//initParameters.dst_h = 640;
//	//initParameters.dst_w = 512;
//
//	initParameters.input_output_names = { "images",  "output0" };
//
//	initParameters.conf_thresh = 0.2f;
//	initParameters.iou_thresh = 0.45f;
//	initParameters.save_path = "";
//
//}
//
//unordered_map<int, vector<Rect>> AlgorithmBase::task(YOLOV8& yolo, const dl_utils::InitParameter& param, std::vector<cv::Mat>& imgsBatch, const int& delayTime, const int& batchi, const bool& isShow, const bool& isSave, float ThreshValue)
//{
//	dl_utils::DeviceTimer d_t0; yolo.copy(imgsBatch);	      float t0 = d_t0.getUsedTime();
//	//dl_utils::DeviceTimer d_t1; yolo.preprocess(imgsBatch);  float t1 = d_t1.getUsedTime();
//	dl_utils::DeviceTimer d_t1; yolo.preprocess(imgsBatch, param);  float t1 = d_t1.getUsedTime();
//	dl_utils::DeviceTimer d_t2; yolo.infer();				  float t2 = d_t2.getUsedTime();
//	//dl_utils::DeviceTimer d_t3; yolo.postprocess(imgsBatch); float t3 = d_t3.getUsedTime();
//	dl_utils::DeviceTimer d_t3; yolo.postprocess(imgsBatch, param); float t3 = d_t3.getUsedTime();
//	std::vector<std::vector<dl_utils::Box>> v8_results = yolo.getObjectss();
//	/*Rect(20, 20, 80, 80);*/
//	unordered_map<int, vector<Rect>> res;
//	for (int i = 0; i < v8_results[0].size(); i++) {
//		if (v8_results[0][i].confidence > ThreshValue) {
//			Rect rect1;
//			rect1.x = v8_results[0][i].left;
//			rect1.y = v8_results[0][i].top;
//			rect1.width = v8_results[0][i].right - v8_results[0][i].left;
//			rect1.height = v8_results[0][i].bottom - v8_results[0][i].top;
//
//			res[v8_results[0][i].label].push_back(rect1);
//		}
//	}
//	//yolo.reset();
//	return res;
//}
//
//unordered_map<int, vector<Rect>> AlgorithmBase::task(YOLOV8* yolo, const dl_utils::InitParameter& param, std::vector<cv::Mat>& imgsBatch, const int& delayTime, const int& batchi, const bool& isShow, const bool& isSave, float ThreshValue)
//{
//	dl_utils::DeviceTimer d_t0; yolo->copy(imgsBatch);	      float t0 = d_t0.getUsedTime();
//	//dl_utils::DeviceTimer d_t1; yolo->preprocess(imgsBatch);  float t1 = d_t1.getUsedTime();
//	dl_utils::DeviceTimer d_t1; yolo->preprocess(imgsBatch, param);  float t1 = d_t1.getUsedTime();
//	dl_utils::DeviceTimer d_t2; yolo->infer();				  float t2 = d_t2.getUsedTime();
//	//dl_utils::DeviceTimer d_t3; yolo->postprocess(imgsBatch); float t3 = d_t3.getUsedTime();
//	dl_utils::DeviceTimer d_t3; yolo->postprocess(imgsBatch, param); float t3 = d_t3.getUsedTime();
//	std::vector<std::vector<dl_utils::Box>> v8_results = yolo->getObjectss();
//	unordered_map<int, vector<Rect>> res;
//	for (int i = 0; i < v8_results[0].size(); i++) {
//		if (v8_results[0][i].confidence > ThreshValue) {
//			Rect rect1;
//			rect1.x = v8_results[0][i].left;
//			rect1.y = v8_results[0][i].top;
//			rect1.width = v8_results[0][i].right - v8_results[0][i].left;
//			rect1.height = v8_results[0][i].bottom - v8_results[0][i].top;
//
//			res[v8_results[0][i].label].push_back(rect1);
//		}
//	}
//	yolo->reset();
//	return res;
//}

int AlgorithmBase::GetCheckResult()
{
	return result;
}

int AlgorithmBase::GetCheckResult(bool test)
{
	return test_result;
}

int AlgorithmBase::GetIDResult()
{
	vector<int> TargetID = Str2Vec1(m_pData->GetBottleDetParam()->SelectedMold);
	int detect_id = str2int1(bottle_type);
	if (find(TargetID.begin(), TargetID.end(), detect_id) != TargetID.end()
		&& m_pData->GetBottleDetParam()->MoldRecognition == "MOLDON")
	{
		IDresult = 1;
	}
	else
	{
		IDresult = -1;
	}
	return IDresult;

}

vector<cv::Rect> AlgorithmBase::GetDetRects()
{
	return result_rect_vec;
}

cv::Mat AlgorithmBase::GetObjDetResultImg()
{
	return this->result_img;
}

int AlgorithmBase::GetDetCostTime()
{
	return this->infer_time;
}

//int AlgorithmBase::LoadAlgorithmParam()
//{
//	string tmp_model_path;
//	int tmp_batch;
//	int tmp_channel;
//	int tmp_height;
//	int tmp_width;
//	int tmp_model_type_flag;
//	string tmp_txt_order;
//	// 根据配置文件加载模型参数
//	ifstream readfile(m_pData->GetBottleDetParam()->Profile_Path);
//	readfile >> tmp_model_path;
//	readfile >> tmp_batch;
//	readfile >> tmp_channel;
//	readfile >> tmp_height;
//	readfile >> tmp_width;
//	readfile >> tmp_model_type_flag;
//	readfile >> tmp_txt_order;
//	readfile.close();
//	if (tmp_model_path.empty()) return 1;//路径无模型的情况
//	if (tmp_txt_order == cur_txt_order) return -1;  // 序列号一致说明配置文件没改变，不用更新模型，直接返回
//	/******************************************* 开始更新参数 *****************************************************/
//	string model_data_path = tmp_model_path.substr(0, tmp_model_path.find_last_of("/\\")) + "/" + tmp_txt_order + ".data";
//	//cur_model_type_flag = tmp_model_type_flag;
//	//cur_txt_order = tmp_txt_order;
//	////setParameters(param);
//	//build_trt_model(tmp_model_path.c_str(), model_data_path.c_str());
//	//yolo->model_data_path = model_data_path;
//
//	return 0;
//}
//int AlgorithmBase::LoadAlgorithmParam(bool test) {
//	string tmp_model_path;
//	int tmp_batch;
//	int tmp_channel;
//	int tmp_height;
//	int tmp_width;
//	int tmp_model_type_flag;
//	string tmp_txt_order;
//	// 根据配置文件加载模型参数
//	ifstream readfile(m_pData->GetBottleDetParam()->Profile_Path);
//	readfile >> tmp_model_path;
//	readfile >> tmp_batch;
//	readfile >> tmp_channel;
//	readfile >> tmp_height;
//	readfile >> tmp_width;
//	readfile >> tmp_model_type_flag;
//	readfile >> tmp_txt_order;
//	readfile.close();
//	if (tmp_model_path.empty()) return 1;//路径无模型的情况
//	if (tmp_txt_order == cur_txt_order) return -1;  // 序列号一致说明配置文件没改变，不用更新模型，直接返回
//	/******************************************* 开始更新参数 *****************************************************/
//	string model_data_path = tmp_model_path.substr(0, tmp_model_path.find_last_of("/\\")) + "/" + tmp_txt_order + ".data";
//	cur_model_type_flag = tmp_model_type_flag;
//	cur_txt_order = tmp_txt_order;
//	//setParameters(param);
//	build_trt_model(tmp_model_path.c_str(), model_data_path.c_str());
//	yolo->model_data_path = model_data_path;
//	return 0;
//
//}

int AlgorithmBase::LoadIdentifyAlgorithmParam()
{
	//string tmp_model_path;
	//int tmp_batch;
	//int tmp_channel;
	//int tmp_height;
	//int tmp_width;
	//int tmp_model_type_flag;
	//string tmp_txt_order;
	//// 根据配置文件加载模型参数
	//ifstream readfile(m_pData->GetBottleDetParam()->MoldProfile_Path);
	//readfile >> tmp_model_path;
	//readfile >> tmp_batch;
	//readfile >> tmp_channel;
	//readfile >> tmp_height;
	//readfile >> tmp_width;
	//readfile >> tmp_model_type_flag;
	//readfile >> tmp_txt_order;
	//readfile.close();
	//if (tmp_txt_order == cur_txt_order) return -1;  // 序列号一致说明配置文件没改变，不用更新模型，直接返回
	///******************************************* 开始更新参数 *****************************************************/
	//string model_data_path = tmp_model_path.substr(0, tmp_model_path.find_last_of("/\\")) + "/" + tmp_txt_order + ".data";
	//cur_model_type_flag = tmp_model_type_flag;
	////cur_txt_order = tmp_txt_order;
	//if (cur_model_type_flag == 0) {
	//	cls_model.model_path = tmp_model_path;
	//	cls_model.input_batch = tmp_batch;
	//	cls_model.input_channel = tmp_channel;
	//	cls_model.input_height = tmp_height;
	//	cls_model.input_width = tmp_width;
	//	cls_model.model_data_path = model_data_path;
	//}
	//else {
	//	if (!MutilFlag)
	//	{
	//		Identify_model.model_path = tmp_model_path;
	//		Identify_model.channels = tmp_channel;
	//		Identify_model.INPUT_H = tmp_height;
	//		Identify_model.INPUT_W = tmp_width;
	//		Identify_model.model_data_path = model_data_path;
	//		// 读取xml文件中的阈值参数，类别置信度读两个，暂时只用两个
	//		Identify_model.NMS_THRESH = m_pData->GetBottleDetParam()->NMSThreshVal;    //0.25
	//		Identify_model.BBOX_CONF_THRESH.push_back(m_pData->GetBottleDetParam()->ConfidenceVal1);   //0.1
	//		Identify_model.BBOX_CONF_THRESH.push_back(m_pData->GetBottleDetParam()->ConfidenceVal2);     //0.5
	//	}
	//	else
	//	{
	//		for (int index = 0; index < MUTIL_NUM; index++)
	//		{
	//			Identify_models[index].model_path = tmp_model_path;
	//			Identify_models[index].channels = tmp_channel;
	//			Identify_models[index].INPUT_H = tmp_height;
	//			Identify_models[index].INPUT_W = tmp_width;
	//			Identify_models[index].model_data_path = model_data_path;
	//			// 读取xml文件中的阈值参数，类别置信度读两个，暂时只用两个
	//			Identify_models[index].NMS_THRESH = m_pData->GetBottleDetParam()->NMSThreshVal;    //0.25
	//			Identify_models[index].BBOX_CONF_THRESH.push_back(m_pData->GetBottleDetParam()->ConfidenceVal1);   //0.1
	//			Identify_models[index].BBOX_CONF_THRESH.push_back(m_pData->GetBottleDetParam()->ConfidenceVal2);     //0.5
	//		}
	//	}
	//}
	return 0;
}

//int AlgorithmBase::LoadAlgorithmModel()
//{
//	std::vector<unsigned char> trt_file = dl_utils::loadEncryptModel(yolo->model_data_path);
//	if (trt_file.empty())
//	{
//		sample::gLogError << "trt_file is empty!" << std::endl;
//		return -1;
//	}
//	// 初始化模型
//	//if (!yolo.init(trt_file))
//	if (!yolo->init(trt_file, param))
//	{
//		sample::gLogError << "initEngine() ocur errors!" << std::endl;
//		return -1;
//	}
//	yolo->check();
//	return 0;
//}
//
//int AlgorithmBase::LoadAlgorithmModel(bool test)
//{
//	std::vector<unsigned char> trt_file = dl_utils::loadEncryptModel(yolo->model_data_path);
//	if (trt_file.empty())
//	{
//		sample::gLogError << "trt_file is empty!" << std::endl;
//		return -1;
//	}
//	// 初始化模型
//	//if (!yolo.init(trt_file))
//	if (!yolo->init(trt_file, param))
//	{
//		sample::gLogError << "initEngine() ocur errors!" << std::endl;
//		return -1;
//	}
//	yolo->check();
//	return 0;
//}

int AlgorithmBase::LoadIdentifyAlgorithmModel()
{
	//if (cur_model_type_flag == 0) {
	//	// 分类模型
	//	cls_model.init();
	//	if (cls_model.build_trt_model(cls_model.model_path.c_str(), cls_model.model_data_path.c_str())) {
	//		return -1;
	//	}
	//	if (cls_model.load_trt_model(cls_model.model_data_path.c_str())) {
	//		return -1;
	//	}
	//}
	//else {
	//	// 目标检测模型
	//	if (!MutilFlag)
	//	{
	//		if (!Identify_model.build_trt_model(Identify_model.model_path.c_str(), Identify_model.model_data_path.c_str())) {
	//			return -1;
	//		}
	//		if (!Identify_model.load_trt_model(Identify_model.model_data_path.c_str(), "2")) {
	//			return -1;
	//		}
	//	}
	//	else
	//	{
	//		for (int index = 0; index < MUTIL_NUM; index++)
	//		{
	//			if (!Identify_models[index].build_trt_model(Identify_models[index].model_path.c_str(), Identify_models[index].model_data_path.c_str())) {
	//				return -1;
	//			}
	//			if (!Identify_models[index].load_trt_model(Identify_models[index].model_data_path.c_str(), "2")) {
	//				return -1;
	//			}
	//		}
	//	}
	//}
	return 0;
}

//主界面使用
void AlgorithmBase::DoJob(Mat& image)
{

	vector<Mat>().swap(Images);
	Image = image.clone();
	Images.push_back(image);

	SetEvent(CHECK_TRADITION_EVENT);
	WaitForSingleObject(COMPLETE_TRADITION_EVENT, INFINITE);//等待检测完成
	if (SQL.Connect_MySQL())
	{
		if (WriteProductBatch == ReadProductBatch)
		{
		
		}
		SYSTEMTIME st;
		GetLocalTime(&st);
		CString tempPrintTime;
		tempPrintTime.Format(TEXT("%2d:%2d:%2d:%2d:%2d:%2d"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
		string strPrintTime = CT2A(tempPrintTime.GetString());
		SQL.Add_Info(DateInfo(strPrintTime, WriteProductBatch, Deadline, UpCode, DownCode, UpNumber, DownNumber, UpResult, PersonUse, isOkSignal));//插入数据库
	
	};
	AI_result_rect_table[1] = vector<cv::Rect>();

	string name = "show";
	res_name = FilterResult(Image, AI_check[0], name);

	return;
}

//int AlgorithmBase::DoJob(vector<Mat>& images, int num)
//{
//	int i;
//	for (i = 0; i < num; i++) {
//
//		DoJob(images[i]);
//		if (result_rect_vec.size() > 0) {
//			break;
//		}
//	}
//	return i;
//	//vector<	Mat>().swap(images);
//
//	//cout << "this is DoJobs" << endl;
//}

// 检测有使用
int AlgorithmBase::DoJob(vector<Mat>& images, int num)
{
	//SYSTEMTIME st;
	//CString strDate, strTime;
	//const char* cstr;
	//GetLocalTime(&st);
	//strTime.Format(TEXT("检测开始：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//cstr = MyW2A2(strTime);
	//LOG(0, cstr);
	//unordered_map<int, vector<cv::Rect>>().swap(Tradition_check);
	//ReadImage(&ho_MaskImage, ".\\mask.bmp");
	int res = 0;
	if (!CImages.empty()) {
		vector<Mat>().swap(CImages);
	}
	Images = images;
	for (int i = 0; i < Images.size(); i++) {
		CImages.push_back(Images[i](Rect(150, 280, 896, 716)));
	}

	if (ChoseModel == "AI&AI")
	{
		////m_AIthreadPool.PushJob((TJobFun)CallBackAI, (WPARAM)this, (LPARAM)1, NULL);
		//m_IdentifyThreadPool.PushJob((TJobFun)CallBackIdentifi, (WPARAM)this, (LPARAM)1, NULL);
		////WaitForSingleObject(AI_COMPLETE_EVENT[0], INFINITE);//等待缺陷检测
		//WaitForSingleObject(IDENTIFY_COMPLETE_EVENT[0], INFINITE);//等待模号检测
		////for (int j = 0; j < images.size(); j++) {
		//	//if (!AI_RESULT[j].empty()) {
		//		//res = j;
		//		//FilterResult(images[j], AI_RESULT[j]);
		//		//break;
		//	//}
		////}
		//for (int m = 0; m < images.size(); m++) {
		//	string ID = FilterID(AID_RESULT[m]);
		//	if (ID != "NULL") {
		//		break;
		//	}
		//}
		//SYSTEMTIME st;
		//CString strDate, strTime;
		//const char* cstr;
		//GetLocalTime(&st);
		//strTime.Format(TEXT("线程开始：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond,st.wMilliseconds);
		//cstr = MyW2A2(strTime);
		//LOG(0, cstr);
		//for (int i = 0; i < images.size(); i++)
		//{
		//	m_AIthreadPool.PushJob((TJobFun)CallBackAI, (WPARAM)this, (LPARAM)i, NULL);
		//	//m_IdentifyThreadPool.PushJob((TJobFun)CallBackIdentifi, (WPARAM)this, (LPARAM)i, NULL);
		//}
		//GetLocalTime(&st);
		//strTime.Format(TEXT("检测时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		//cstr = MyW2A2(strTime);
		//LOG(0, cstr);
		WaitForMultipleObjects(Images.size(), AI_COMPLETE_EVENT, TRUE, INFINITE);
		//WaitForMultipleObjects(Images.size(), IDENTIFY_COMPLETE_EVENT, TRUE, INFINITE);
		//GetLocalTime(&st);
		//strTime.Format(TEXT("检测时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		//cstr = MyW2A2(strTime);
		//LOG(0, cstr);
		for (int j = 0; j < images.size(); j++) {
			if (!AI_check[j][0].empty() ||
				!AI_check[j][1].empty() ||
				!AI_check[j][2].empty()) {
				res = j;
				//FilterResult(images[j], AI_check[j]);
				string name = "show";
				res_name = FilterResult(images[j], AI_check[j], name);
				break;
			}
		}
		for (int k = 0; k < images.size(); k++) {
			string ID = FilterID(AI_check[k][3]);
			if (ID != "0" && ID != "") {
				break;
			}
		}
		//for (int m = 0; m < images.size(); m++) {
		//	string ID = FilterID(ID_check[m]);
		//	if (ID != "NULL") {
		//		break;
		//	}
		//}
		//GetLocalTime(&st);
		//strTime.Format(TEXT("检测结束：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		//cstr = MyW2A2(strTime);
		//LOG(0, cstr);
	}
	//else if (ChoseModel == "AI&AI" && m_pData->GetBottleDetParam()->MoldRecognition == "MOLDOFF")
	//{
	//	for (int i = 0; i < images.size(); i++)
	//	{
	//		m_AIthreadPool.PushJob((TJobFun)CallBackAI, (WPARAM)this, (LPARAM)i, NULL);
	//	}
	//	WaitForMultipleObjects(Images.size(), AI_COMPLETE_EVENT, TRUE, INFINITE);
	//	for (int j = 0; j < images.size(); j++) {
	//		if (!AI_check[j].empty()) {
	//			FilterResult(images[j], AI_check[j]);
	//			break;
	//		}
	//	}
	//}
	//else if (ChoseModel == "AI&TRA")
	//{
	//	//ReadImage(&ho_MaskImage, ".\\mask.bmp");
	//	for (int i = 0; i < images.size(); i++)
	//	{
	//		if (i == 0) {
	//			m_AIthreadPool.PushJob((TJobFun)CallBackAI, (WPARAM)this, (LPARAM)i, NULL);
	//			m_TraditionThreadPool.PushJob((TJobFun)CallBackTradition, (WPARAM)this, (LPARAM)i, NULL);
	//		}
	//		else {
	//			m_AIthreadPool.PushJob((TJobFun)CallBackAI, (WPARAM)this, (LPARAM)i, NULL);
	//		}
	//		//m_IdentifyThreadPool.PushJob((TJobFun)CallBackIdentifi, (WPARAM)this, (LPARAM)i, NULL);
	//	}
	//	WaitForMultipleObjects(Images.size(), AI_COMPLETE_EVENT, TRUE, INFINITE);
	//	//WaitForMultipleObjects(Images.size(), Tradition_COMPLETE_EVENT, TRUE, INFINITE);
	//	WaitForSingleObject(Tradition_COMPLETE_EVENT[0], INFINITE);
	//	//WaitForMultipleObjects(Images.size(), IDENTIFY_COMPLETE_EVENT, TRUE, INFINITE);
	//	for (int j = 0; j < images.size(); j++) {
	//		if (!AI_check[j].empty() && !Tradition_check[j].empty()) {
	//			res = j;
	//			AI_check[j][4] = Tradition_check[j];
	//			string name = "show";
	//			res_name = FilterResult(images[j], AI_check[j], name);
	//			break;
	//		}
	//	}
	//	//for (int m = 0; m < images.size(); m++) {
	//	//	string ID = FilterID(ID_check[m]);
	//	//	if (ID != "0") {
	//	//		break;
	//	//	}
	//	//}
	//	for (int k = 0; k < images.size(); k++) {
	//		string ID = FilterID(AI_check[k][3]);
	//		if (ID != "0" && ID != "") {
	//			break;
	//		}
	//	}
	//	//FilterResult(images[0], AI_check[0]);
	//}
	//else if (ChoseModel == "NONE&AI")
	//{
	//	for (int i = 0; i < images.size(); i++)
	//	{
	//		m_AIthreadPool.PushJob((TJobFun)CallBackAI, (WPARAM)this, (LPARAM)i, NULL);
	//		//m_IdentifyThreadPool.PushJob((TJobFun)CallBackIdentifi, (WPARAM)this, (LPARAM)i, NULL);
	//	}
	//	WaitForMultipleObjects(Images.size(), AI_COMPLETE_EVENT, TRUE, INFINITE);
	//	//WaitForMultipleObjects(Images.size(), IDENTIFY_COMPLETE_EVENT, TRUE, INFINITE);
	//	for (int j = 0; j < images.size(); j++) {
	//		if (!AI_check[j][0].empty() || 
	//			!AI_check[j][1].empty() ||
	//			!AI_check[j][2].empty()) {
	//			res = j;
	//			AI_check[j][4] = vector<cv::Rect>();
	//			//FilterResult(images[j], AI_check[j]);
	//			string name = "show";
	//			res_name = FilterResult(images[j], AI_check[j], name);
	//			break;
	//		}
	//	}
	//	//for (int m = 0; m < images.size(); m++) {
	//	//	string ID = FilterID(ID_check[m]);
	//	//	if (ID != "0") {
	//	//		break;
	//	//	}
	//	//}
	//	for (int k = 0; k < images.size(); k++) {
	//		string ID = FilterID(AI_check[k][3]);
	//		if (ID != "0" && ID != "") {
	//			break;
	//		}
	//	}
	//	//FilterResult(images[0], AI_check[0]);
	//}
	else if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDOFF" && ChoseModel == "NONE&TRA") 
{
	for (int i = 0; i < 1; i++)
	{
		m_TraditionThreadPool.PushJob((TJobFun)CallBackTradition, (WPARAM)this, (LPARAM)i, NULL);
	}
	//WaitForMultipleObjects(Images.size(), Tradition_COMPLETE_EVENT, TRUE, INFINITE);
	WaitForSingleObject(Tradition_COMPLETE_EVENT[0], INFINITE);
	//GetLocalTime(&st);
	//strTime.Format(TEXT("过滤时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//cstr = MyW2A2(strTime);
	//LOG(0, cstr);
	for (int j = 0; j < images.size(); j++) {
		if (!Tradition_check[j].empty()) {
			res = j;
			AI_check[j][0] = vector<cv::Rect>();
			AI_check[j][1] = vector<cv::Rect>();
			AI_check[j][2] = vector<cv::Rect>();
			AI_check[j][4] = Tradition_check[j];
			FilterResult(images[j], AI_check[j]);
			res_name = "混合缺陷";
			break;
		}
	}
	if (res_name != "混合缺陷") {
		res_name = "良品";
	}
	bottle_type = "0";
	for (int k = 0; k < images.size(); k++) {
		string ID = FilterID(AI_check[k][3]);
		if (ID != "0" && ID != "") {
			break;
		}
	}
	}
	else if (ChoseModel == "NONE&TRA")
	{
		//ReadImage(&ho_MaskImage, ".\\mask.bmp");
		for (int i = 0; i < images.size(); i++)
		{
			if (i == 0) {
				m_TraditionThreadPool.PushJob((TJobFun)CallBackTradition, (WPARAM)this, (LPARAM)i, NULL);
				//m_AIthreadPool.PushJob((TJobFun)CallBackAI, (WPARAM)this, (LPARAM)i, NULL);
			}
			else {
				//m_AIthreadPool.PushJob((TJobFun)CallBackAI, (WPARAM)this, (LPARAM)i, NULL);
			}
			//m_IdentifyThreadPool.PushJob((TJobFun)CallBackIdentifi, (WPARAM)this, (LPARAM)i, NULL);
		}
		//WaitForMultipleObjects(Images.size(), Tradition_COMPLETE_EVENT, TRUE, INFINITE);
		WaitForSingleObject(Tradition_COMPLETE_EVENT[0], INFINITE);
		//WaitForMultipleObjects(Images.size(), AI_COMPLETE_EVENT, TRUE, INFINITE);
		//WaitForMultipleObjects(Images.size(), IDENTIFY_COMPLETE_EVENT, TRUE, INFINITE);
		for (int j = 0; j < images.size(); j++) {
			if (!Tradition_check[j].empty()) {
				res = j;
				AI_check[j][0] = vector<cv::Rect>();
				AI_check[j][1] = vector<cv::Rect>();
				AI_check[j][2] = vector<cv::Rect>();
				AI_check[j][4] = Tradition_check[j];
				FilterResult(images[j], AI_check[j]);
				res_name = "混合缺陷";
				break;
			}
		}
		if (res_name != "混合缺陷") {
			res_name = "良品";
		}
		//for (int m = 0; m < images.size(); m++) {
		//	string ID = FilterID(ID_check[m]);
		//	if (ID != "0") {
		//		break;
		//	}
		//}
		bottle_type = "0";
		for (int k = 0; k < images.size(); k++) 
		{
			string ID = FilterID(AI_check[k][3]);
			if (ID != "0" && ID != "") 
			{
				break;
			}
		}
	}
	return res;
}
// Test有使用
int AlgorithmBase::DoJob(vector<Mat>& images, int num, bool test)
{

		CheckByTraditionAlgorithm(images[0]);
		

	return 0;
}

//void AlgorithmBase::UpdateAImodel()
//{
//	int res = LoadAlgorithmParam();
//	if (res == 0) {
//		LoadAlgorithmModel();
//	}
//	else if(res == 1)
//	{
//		AfxMessageBox(TEXT("未找到AI模型，请检查模型路径"));
//	}
//}
//
//void AlgorithmBase::UpdateAImodel(bool test)
//{
//	//if (LoadAlgorithmParam(TRUE) == 0) {
//	//	LoadAlgorithmModel();
//	//}
//	LoadAlgorithmParam(TRUE);
//	LoadAlgorithmModel(TRUE);
//
//}
//
vector<int> AlgorithmBase::Str2Vec(string str)
{
	//string s = CT2A(CS.GetString()); 
	int start = 0;
	int num = 0;
	vector<int> nums;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			string temp = str.substr(start, i - start);
			nums.push_back(atoi(temp.c_str()));
			num++;
			start = i + 1;
		}
	}
	string temp = str.substr(start, str.size() - start + 1);
	nums.push_back(atoi(temp.c_str()));
	return nums;
}

bool AlgorithmBase::UpdateAlgorithm()
{
	//if (LoadAlgorithmParam() == 0) {
	//	LoadAlgorithmModel();
	//}
	//m_pData->GetBottleDetParam()->
	bottle_xml.Read_Code(CString("Bottle.xml"));

	ThreadArea = m_pData->GetBottleDetParam()->ThreadValue;
	ThreadLBW = m_pData->GetBottleDetParam()->ThreadValueLW;
	ThreadModel = m_pData->GetBottleDetParam()->ThreadModel;
	GrayValue = m_pData->GetBottleDetParam()->GrayValue;
	GrayModel = m_pData->GetBottleDetParam()->GrayModel;
	ChoseModel = m_pData->GetBottleDetParam()->ChoseModel;

	//定义传统算法参数
	outer_radius = m_pData->GetBottleDetParam()->outer_radius;
	//瓶底内圆半径（默认270pix）
	inner_radius = m_pData->GetBottleDetParam()->inner_radius;
	//动态阈值，值越小，越会检测出对比度低不明显的缺陷（默认10）
	dyn_threshold_val = Str2Vec(m_pData->GetBottleDetParam()->contra_val);
	//缺陷面积阈值，面积小于该值的缺陷区域不会被检测到（默认150）
	area_threshold_val = Str2Vec(m_pData->GetBottleDetParam()->area_val);
	ThreadArea1 = area_threshold_val;
	return false;
}
bool AlgorithmBase::UpdateAlgorithm(vector<int> contra_val_vec, vector<int> area_val_vec, vector<int> gray_val_vec)
{
	bottle_xml.Read_Code(CString("Bottle.xml"));
	ThreadModel = m_pData->GetBottleDetParam()->ThreadModel;
	GrayModel = m_pData->GetBottleDetParam()->GrayModel;

	ChoseModel = m_pData->GetBottleDetParam()->ChoseModel;
	//定义传统算法参数
	outer_radius = m_pData->GetBottleDetParam()->outer_radius;
	//瓶底内圆半径（默认270pix）
	inner_radius = m_pData->GetBottleDetParam()->inner_radius;
	//动态阈值，值越小，越会检测出对比度低不明显的缺陷（默认10）
	dyn_threshold_val = contra_val_vec;
	//缺陷面积阈值，面积小于该值的缺陷区域不会被检测到（默认150）
	area_threshold_val = area_val_vec;
	ThreadArea1 = area_threshold_val;

	//if (area_threshold_val[0] > 0) {
	//	ThreadModel = "AREA";
	//}
	GrayValue = gray_val_vec[0];
	if (GrayValue > 0) {
		GrayModel = "TRUE";
	}
	else {
		GrayModel = "FALSE";
	}
	return false;
}

bool AlgorithmBase::UpdateAlgorithm(vector<int> contra_val_vec, vector<int> area_val_vec, 
	vector<int> gray_val_vec, CString choosemodel)
{
	bottle_xml.Read_Code(CString("Bottle.xml"));
	ThreadModel = m_pData->GetBottleDetParam()->ThreadModel;
	GrayModel = m_pData->GetBottleDetParam()->GrayModel;
	test_ChoseModel = CW2A(choosemodel.GetString());
	//ChoseModel = choosemodel;
	//定义传统算法参数
	outer_radius = m_pData->GetBottleDetParam()->outer_radius;
	//瓶底内圆半径（默认270pix）
	inner_radius = m_pData->GetBottleDetParam()->inner_radius;
	//动态阈值，值越小，越会检测出对比度低不明显的缺陷（默认10）
	dyn_threshold_val = contra_val_vec;
	//缺陷面积阈值，面积小于该值的缺陷区域不会被检测到（默认150）
	area_threshold_val = area_val_vec;
	ThreadArea1 = area_threshold_val;

	//if (area_threshold_val[0] > 0) {
	//	ThreadModel = "AREA";
	//}
	GrayValue = gray_val_vec[0];
	if (GrayValue > 0) {
		GrayModel = "TRUE";
	}
	else {
		GrayModel = "FALSE";
	}
	return false;
}


void AlgorithmBase::FilterResult(vector<cv::Rect> mrect)
{
	//良品直接return
	vector<cv::Rect>().swap(this->result_rect_vec);
	if (mrect.size() == 0)
	{
		this->result = 1;
		this->result_rect_vec = vector<cv::Rect>();
		return;
	}
	//次品对结果进行筛选

	for (int index = 0; index < mrect.size(); index++)
	{
		ThreadArea = area_threshold_val[0];
		int area = mrect[index].area();
		double LBW = max((double)mrect[index].height / (double)mrect[index].width, (double)mrect[index].width / (double)mrect[index].height);
		if (ThreadModel == "AREA")
		{
			if (area > ThreadArea)
			{
				this->result_rect_vec.push_back(mrect[index]);
			}
		}
		else if (ThreadModel == "LW")
		{
			if (LBW > ThreadLBW)
			{
				this->result_rect_vec.push_back(mrect[index]);
			}
		}
		else if (ThreadModel == "BOTH")
		{
			if (area > ThreadArea && LBW > ThreadLBW)
			{
				this->result_rect_vec.push_back(mrect[index]);
			}
		}
		else
		{
			this->result_rect_vec = mrect;
		}
	}
	this->result = this->result_rect_vec.size() > 0 ? -1 : 1;
	return;
}

void AlgorithmBase::FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect)
{
	//良品直接return
	vector<cv::Rect>().swap(this->result_rect_vec);
	if (mrect.size() == 0)
	{
		this->result = 1;
		this->result_rect_vec = vector<cv::Rect>();
		return;
	}
	//次品对结果进行筛选
	int num = mrect.size();
	//if (num == 3) {
	//	num = 2;
	//}
	for (int clas = 0; clas < num; clas++)
	{
		ThreadArea = area_threshold_val[0];

		if (clas != 4) {
			//Rect().offset
			mrect[clas];
			for (int index = 0; index < mrect[clas].size(); index++)
			{
				mrect[clas][index].x = mrect[clas][index].x + 150;
				//mrect[clas][index].width;
				mrect[clas][index].y = mrect[clas][index].y + 280;
				//150, 280;
				//面积筛选、、长宽比筛选
				int area;
				double LBW;
				bool graypass = true;
				//灰度阈值检测
				//if ((GrayModel == "TRUE" && clas == 0)) {
				//	graypass = GrayFilter(img, mrect[clas][index], true);
				//}
				//面积、、长宽比筛选
				if (graypass)
				{
					if (ThreadModel == "AREA")
					{
						area = mrect[clas][index].area();
						if (area > ThreadArea)
						{
							this->result_rect_vec.push_back(mrect[clas][index]);
						}
					}
					else if (ThreadModel == "LW")
					{
						LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
						if (LBW > ThreadLBW)
						{
							this->result_rect_vec.push_back(mrect[clas][index]);
						}
					}
					else if (ThreadModel == "BOTH")
					{
						area = mrect[clas][index].area();
						LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
						if (area > ThreadArea && LBW > ThreadLBW)
						{
							this->result_rect_vec.push_back(mrect[clas][index]);
						}
					}
					else
					{
						this->result_rect_vec.push_back(mrect[clas][index]);
					}
				}
			}
		}
		//else if(clas == 2) {
		//	for (int index = 0; index < mrect[clas].size(); index++)
		//	{
		//		mrect[clas][index].x = mrect[clas][index].x + 150;
		//		mrect[clas][index].y = mrect[clas][index].y + 280;
		//		//面积筛选、、长宽比筛选
		//		int area;
		//		double LBW;
		//		bool graypass = true;
		//		//灰度阈值检测
		//		if ((GrayModel == "TRUE" && clas == 0)) {
		//			graypass = GrayFilter(img, mrect[clas][index], true);
		//		}
		//		//面积、、长宽比筛选
		//		if (graypass)
		//		{
		//			if (ThreadModel == "AREA")
		//			{
		//				area = mrect[clas][index].area();
		//				if (area > ThreadArea)
		//				{
		//					this->result_rect_vec.push_back(mrect[clas][index]);
		//				}
		//			}
		//			else if (ThreadModel == "LW")
		//			{
		//				LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
		//				if (LBW > ThreadLBW)
		//				{
		//					this->result_rect_vec.push_back(mrect[clas][index]);
		//				}
		//			}
		//			else if (ThreadModel == "BOTH")
		//			{
		//				area = mrect[clas][index].area();
		//				LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
		//				if (area > ThreadArea && LBW > ThreadLBW)
		//				{
		//					this->result_rect_vec.push_back(mrect[clas][index]);
		//				}
		//			}
		//			else
		//			{
		//				this->result_rect_vec.push_back(mrect[clas][index]);
		//			}
		//		}
		//	}
		//}
		else {
			for (int index = 0; index < mrect[clas].size(); index++)
			{
				//面积筛选、、长宽比筛选
				int area;
				double LBW;
				bool graypass = true;
				//灰度阈值检测
				//if ((GrayModel == "TRUE" && clas == 0)) {
				//	graypass = GrayFilter(img, mrect[clas][index], true);
				//}
				//面积、、长宽比筛选
				if (graypass)
				{
					if (ThreadModel == "AREA")
					{
						area = mrect[clas][index].area();
						if (area > ThreadArea)
						{
							this->result_rect_vec.push_back(mrect[clas][index]);
						}
					}
					else if (ThreadModel == "LW")
					{
						LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
						if (LBW > ThreadLBW)
						{
							this->result_rect_vec.push_back(mrect[clas][index]);
						}
					}
					else if (ThreadModel == "BOTH")
					{
						area = mrect[clas][index].area();
						LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
						if (area > ThreadArea && LBW > ThreadLBW)
						{
							this->result_rect_vec.push_back(mrect[clas][index]);
						}
					}
					else
					{
						this->result_rect_vec.push_back(mrect[clas][index]);
					}
				}
			}
		}
	}
	this->result = this->result_rect_vec.size() > 0 ? -1 : 1;
	return;
}

string AlgorithmBase::FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect, string Show)
{
	//良品直接return
	vector<cv::Rect>().swap(this->result_rect_vec);
	string res, res1, res2, res3;
	if (mrect.size() == 0)
	{
		this->result = 1;
		this->result_rect_vec = vector<cv::Rect>();
		res = "良品";
		return res;
	}
	else {
		//次品对结果进行筛选
		int num = mrect.size();
		for (int clas = 0; clas < num; clas++)
		{
			ThreadArea = ThreadArea1[0];
			if (clas != 4) {
				if (mrect[clas].size() !=0 && clas != 3) {
					res1.push_back('1');
				}
				else {
					res1.push_back('0');
				}
				for (int index = 0; index < mrect[clas].size(); index++)
				{
					mrect[clas][index].x = mrect[clas][index].x + 150;
					//mrect[clas][index].width;
					mrect[clas][index].y = mrect[clas][index].y + 280;
					//150, 280;
					//面积筛选、、长宽比筛选
					int area;
					double LBW;
					bool graypass = true;
					//灰度阈值检测
					//if ((GrayModel == "TRUE" && clas == 0)) {
					//	graypass = GrayFilter(img, mrect[clas][index], true);
					//}
					//面积、、长宽比筛选
					if (graypass)
					{
						if (ThreadModel == "AREA")
						{
							area = mrect[clas][index].area();
							if (area > ThreadArea)
							{
								this->result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else if (ThreadModel == "LW")
						{
							LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
							if (LBW > ThreadLBW)
							{
								this->result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else if (ThreadModel == "BOTH")
						{
							area = mrect[clas][index].area();
							LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
							if (area > ThreadArea && LBW > ThreadLBW)
							{
								this->result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else
						{
							this->result_rect_vec.push_back(mrect[clas][index]);
						}
					}
				}
			}
			else {
				for (int index = 0; index < mrect[clas].size(); index++)
				{
					//面积筛选、、长宽比筛选
					int area;
					double LBW;
					bool graypass = true;
					//灰度阈值检测
					//if ((GrayModel == "TRUE" && clas == 0)) {
					//	graypass = GrayFilter(img, mrect[clas][index], true);
					//}
					//面积、、长宽比筛选
					if (graypass)
					{
						if (ThreadModel == "AREA")
						{
							area = mrect[clas][index].area();
							if (area > ThreadArea)
							{
								this->result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else if (ThreadModel == "LW")
						{
							LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
							if (LBW > ThreadLBW)
							{
								this->result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else if (ThreadModel == "BOTH")
						{
							area = mrect[clas][index].area();
							LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
							if (area > ThreadArea && LBW > ThreadLBW)
							{
								this->result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else
						{
							this->result_rect_vec.push_back(mrect[clas][index]);
						}
					}
				}
			}
		}
		this->result = this->result_rect_vec.size() > 0 ? -1 : 1;
		if (res1 == "0000" || res1 == "000") {
			res = "良品";
		}
		else if (res1 == "1000" || res1 == "100") {
			res = "点状缺陷";
		}
		else if (res1 == "0100" || res1 == "010") {
			res = "污渍缺陷";
		}
		else if (res1 == "0010" || res1 == "001") {
			res = "划痕缺陷";
		}
		else
		{
			res = "混合缺陷";
		}
	}
	res1 = "";
	return res;
}

string AlgorithmBase::FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect, string Show, bool test)
{
	//良品直接return
	vector<cv::Rect>().swap(this->test_result_rect_vec);
	string res, res1, res2, res3;
	if (mrect.size() == 0)
	{
		this->test_result = 1;
		this->test_result_rect_vec = vector<cv::Rect>();
		res = "良品";
		return res;
	}
	else {
		//次品对结果进行筛选
		int num = mrect.size();
		for (int clas = 0; clas < num; clas++)
		{
			ThreadArea = ThreadArea1[0];
			if (clas != 4) {
				if (mrect[clas].size() != 0 && clas != 3) {
					res1.push_back('1');
				}
				else {
					res1.push_back('0');
				}
				for (int index = 0; index < mrect[clas].size(); index++)
				{
					mrect[clas][index].x = mrect[clas][index].x + 150;
					//mrect[clas][index].width;
					mrect[clas][index].y = mrect[clas][index].y + 280;
					//150, 280;
					//面积筛选、、长宽比筛选
					int area;
					double LBW;
					bool graypass = true;
					//灰度阈值检测
					//if ((GrayModel == "TRUE" && clas == 0)) {
					//	graypass = GrayFilter(img, mrect[clas][index], true);
					//}
					//面积、、长宽比筛选
					if (graypass)
					{
						if (ThreadModel == "AREA")
						{
							area = mrect[clas][index].area();
							if (area > ThreadArea)
							{
								this->test_result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else if (ThreadModel == "LW")
						{
							LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
							if (LBW > ThreadLBW)
							{
								this->test_result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else if (ThreadModel == "BOTH")
						{
							area = mrect[clas][index].area();
							LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
							if (area > ThreadArea && LBW > ThreadLBW)
							{
								this->test_result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else
						{
							this->test_result_rect_vec.push_back(mrect[clas][index]);
						}
					}
				}
			}
			else {
				for (int index = 0; index < mrect[clas].size(); index++)
				{
					//面积筛选、、长宽比筛选
					int area;
					double LBW;
					bool graypass = true;
					//灰度阈值检测
					//if ((GrayModel == "TRUE" && clas == 0)) {
					//	graypass = GrayFilter(img, mrect[clas][index], true);
					//}
					//面积、、长宽比筛选
					if (graypass)
					{
						if (ThreadModel == "AREA")
						{
							area = mrect[clas][index].area();
							if (area > ThreadArea)
							{
								this->test_result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else if (ThreadModel == "LW")
						{
							LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
							if (LBW > ThreadLBW)
							{
								this->test_result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else if (ThreadModel == "BOTH")
						{
							area = mrect[clas][index].area();
							LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
							if (area > ThreadArea && LBW > ThreadLBW)
							{
								this->test_result_rect_vec.push_back(mrect[clas][index]);
							}
						}
						else
						{
							this->test_result_rect_vec.push_back(mrect[clas][index]);
						}
					}
				}
			}
		}
		this->test_result = this->test_result_rect_vec.size() > 0 ? -1 : 1;
		if (res1 == "0000" || res1 == "000") {
			res = "良品";
		}
		else if (res1 == "1000" || res1 == "100") {
			res = "点状缺陷";
		}
		else if (res1 == "0100" || res1 == "010") {
			res = "污渍缺陷";
		}
		else if (res1 == "0010" || res1 == "001") {
			res = "划痕缺陷";
		}
		else
		{
			res = "混合缺陷";
		}
	}
	res1 = "";
	return res;
} 

void AlgorithmBase::AIFilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect, int step)
{
	vector<cv::Rect>().swap(this->AI_result_rect_vec[step]);
	vector<string> det_name = { "一", "二", "三","四", "五", "六","七", "八", "九","十", "一", "二" };

	if (mrect.size() == 0)
	{
		this->results[step] = 1;
		this->AI_result_rect_vec[step] = vector<cv::Rect>();
		this->res_names[step] = "良品";
		return;
	}
	for (int clas = 0; clas < mrect.size(); clas++)
	{
		ThreadArea = area_threshold_val[step];
		for (int index = 0; index < mrect[clas].size(); index++)
		{
			this->res_names[step] = det_name[clas];
			//面积筛选、、长宽比筛选
			int area;
			double LBW;
			if (ThreadModel == "AREA")
			{
				area = mrect[clas][index].area();
				if (area > ThreadArea)
				{
					this->AI_result_rect_vec[step].push_back(mrect[clas][index]);
				}
			}

			else
			{
				this->AI_result_rect_vec[step].push_back(mrect[clas][index]);
			}
		}
	}
	this->results[step] = this->AI_result_rect_vec[step].size() > 0 ? -1 : 1;
	return;

}


// 有使用
void AlgorithmBase::FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect, bool Test)
{
	//良品直接return
	vector<cv::Rect>().swap(this->test_result_rect_vec);
	if (mrect.size() == 0)
	{
		this->test_result = 1;
		this->test_result_rect_vec = vector<cv::Rect>();
		return;
	}
	//次品对结果进行筛选
	int num = mrect.size();
	if (Test) {
		for (int clas = 0; clas < num; clas++)
		{
			ThreadArea = ThreadArea1[0];
			for (int index = 0; index < mrect[clas].size(); index++)
			{
				//面积筛选、、长宽比筛选
				int area;
				double LBW;
				bool graypass = true;
				//灰度阈值检测
				//if ((GrayModel == "TRUE" && clas == 0)) {
				//	graypass = GrayFilter(img, mrect[clas][index], true);
				//}
				//面积、、长宽比筛选
				if (graypass)
				{
					if (ThreadModel == "AREA")
					{
						area = mrect[clas][index].area();
						if (area > ThreadArea)
						{
							this->test_result_rect_vec.push_back(mrect[clas][index]);
						}
					}
					else if (ThreadModel == "LW")
					{
						LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
						if (LBW > ThreadLBW)
						{
							this->test_result_rect_vec.push_back(mrect[clas][index]);
						}
					}
					else if (ThreadModel == "BOTH")
					{
						area = mrect[clas][index].area();
						LBW = max(mrect[clas][index].height / mrect[clas][index].width, mrect[clas][index].width / mrect[clas][index].height);
						if (area > ThreadArea && LBW > ThreadLBW)
						{
							this->test_result_rect_vec.push_back(mrect[clas][index]);
						}
					}
					else
					{
						this->test_result_rect_vec.push_back(mrect[clas][index]);
					}
				}
			}
		}
		this->test_result = this->test_result_rect_vec.size() > 0 ? -1 : 1;
	}
}

string AlgorithmBase::FilterID(unordered_map<int, vector<cv::Rect>> mrect)
{
	//bottle_xml.Read_Code(CString("Bottle.xml"));
	bottle_type = "0";
	if (mrect[0].size() == 9) {
		vector<pair<int, int>> points;
		for (cv::Rect& i : mrect[0]) {
			points.push_back(pair<int, int>(i.x, i.y));
		}
		string bottle_type_temp = bottle_xml.Coordinate2Code(points, false);
		bottle_type_temp.erase(bottle_type_temp.begin());
		bottle_type = bottle_type_temp;
		//bottle_type = sub(bottle_type_temp, "S");
	}
	return bottle_type;
}

string AlgorithmBase::FilterID(vector<cv::Rect> mrect)
{
	bottle_type = "0";
	if (mrect.size() == 9) {
		vector<pair<int, int>> points;
		for (cv::Rect& i : mrect) {
			points.push_back(pair<int, int>(i.x, i.y));
		}
		string bottle_type_temp = bottle_xml.Coordinate2Code(points, false);
		bottle_type_temp.erase(bottle_type_temp.begin());
		bottle_type = bottle_type_temp;
		//bottle_type = sub(bottle_type_temp, "S");
	}
	return bottle_type;
}

string AlgorithmBase::FilterID(vector<cv::Rect> mrect, bool test)
{
	test_bottle_type = "0";
	if (mrect.size() == 9) {
		vector<pair<int, int>> points;
		for (cv::Rect& i : mrect) {
			points.push_back(pair<int, int>(i.x, i.y));
		}
		string bottle_type_temp = bottle_xml.Coordinate2Code(points, false);
		bottle_type_temp.erase(bottle_type_temp.begin());
		test_bottle_type = bottle_type_temp;
		//bottle_type = sub(bottle_type_temp, "S");
	}
	return test_bottle_type;
}

bool AlgorithmBase::GrayFilter(Mat& mimg, cv::Rect mrect, bool areaFlag)
{
	Mat img(mimg, mrect);
	int value = GrayValue;

	if (img.channels() == 3) {
		cv::cvtColor(img, img, CV_BGR2GRAY);
	}
	Mat dst;
	//vector<vector<Point>> contours;
	std::vector<std::vector<cv::Point>> contours(1000, std::vector<cv::Point>(1000));
	vector<Vec4i>hierarchy(10000);
	cv::threshold(img, dst, value, 255, THRESH_BINARY);
	//string name = "model.jpg";
	//imwrite(name, dst);
	//findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	//if (areaFlag)
	//{
	//	for (size_t t = 0; t < contours.size(); t++) {
	//		//面积过滤
	//		double area = contourArea(contours[t]);
	//		if (area > 150) {
	//			return true;
	//		}
	//	}
	//}
	//else
	//{
		if(contours.size()>0)
		{
			return true;
		}
	//}
	return false;
}

bool AlgorithmBase::InitThread()
{
	AIThread=CreateThread(NULL, 0, AICheckFun, this, 0, NULL);
	TraditionThread = CreateThread(NULL, 0, TraditionCheckFun, this, 0, NULL);
	//IdentifyThread= CreateThread(NULL, 0, IdentifyCheckFun, this, 0, NULL);

	CHECK_AI_EVENT= CreateEventW(NULL, FALSE, FALSE, NULL);
	COMPLETE_AI_EVENT= CreateEventW(NULL, FALSE, FALSE, NULL);
	CHECK_TRADITION_EVENT= CreateEventW(NULL, FALSE, FALSE, NULL);
	COMPLETE_TRADITION_EVENT= CreateEventW(NULL, FALSE, FALSE, NULL);
	//CHECK_IDENTIFY_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	//COMPLETE_IDENTIFY_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	

	for (int i = 0; i < MUTIL_NUM; i++)
	{
		AI_COMPLETE_EVENT[i] = CreateEventW(NULL, FALSE, FALSE, NULL);
		Tradition_COMPLETE_EVENT[i] = CreateEventW(NULL, FALSE, FALSE, NULL);
		IDENTIFY_COMPLETE_EVENT[i]= CreateEventW(NULL, FALSE, FALSE, NULL);
		AI_COMPLETE_EVENT_TEST[i] = CreateEventW(NULL, FALSE, FALSE, NULL);
		Tradition_COMPLETE_EVENT_TEST[i] = CreateEventW(NULL, FALSE, FALSE, NULL);
	}
	return true;
}

void AlgorithmBase::RelaseThread()
{
	m_Exit = true;
	SetEvent(CHECK_AI_EVENT);
	SetEvent(CHECK_TRADITION_EVENT);
	//SetEvent(CHECK_IDENTIFY_EVENT);
	WaitForSingleObject(AIThread, INFINITE);
	WaitForSingleObject(TraditionThread, INFINITE);
	//WaitForSingleObject(IdentifyThread, INFINITE);
	CloseHandle(CHECK_AI_EVENT);
	CloseHandle(CHECK_TRADITION_EVENT);
	//CloseHandle(CHECK_IDENTIFY_EVENT);
	CloseHandle(AIThread);
	CloseHandle(TraditionThread);
	//CloseHandle(IdentifyThread);

	for (int i = 0; i < MUTIL_NUM; i++)
	{
		CloseHandle(AI_COMPLETE_EVENT[i]);
		CloseHandle(Tradition_COMPLETE_EVENT[i]);
	}
}

//VOID CallBackAI(WPARAM wparam, LPARAM lparam)
//{
//	AlgorithmBase* m_Algorithm = (AlgorithmBase*)wparam;
//	int index = (int)lparam;
//	m_Algorithm->CheckByAIAlgorithm((m_Algorithm->CImages)[index], index);
//	SetEvent(m_Algorithm->AI_COMPLETE_EVENT[index]);
//	//m_Algorithm->CheckByAIAlgorithm((m_Algorithm->Images));
//	//SetEvent(m_Algorithm->AI_COMPLETE_EVENT[0]);
//
//}

VOID CallBackTradition(WPARAM wparam, LPARAM lparam)
{
	AlgorithmBase* m_Algorithm = (AlgorithmBase*)wparam;
	int index = (int)lparam;
	m_Algorithm->CheckByTraditionAlgorithm((m_Algorithm->Images)[index], index);
	SetEvent(m_Algorithm->Tradition_COMPLETE_EVENT[index]);
}

VOID CallBackIdentifi(WPARAM wparam, LPARAM lparam)
{
	AlgorithmBase* m_Algorithm = (AlgorithmBase*)wparam;
	int index = (int)lparam;
	m_Algorithm->CheckByIdentifyAlgorithm((m_Algorithm->Images)[index], index);
	SetEvent(m_Algorithm->IDENTIFY_COMPLETE_EVENT[index]);
	//m_Algorithm->CheckByIdentifyAlgorithm((m_Algorithm->Images));
	//SetEvent(m_Algorithm->IDENTIFY_COMPLETE_EVENT[0]);

}

DWORD WINAPI AICheckFun(LPVOID pthread)
{
	AlgorithmBase* m_algorithm = (AlgorithmBase*)pthread;
	while (true)
	{
		WaitForSingleObject(m_algorithm->CHECK_AI_EVENT, INFINITE);
		if (m_algorithm->m_Exit) {
			break;
		}
		m_algorithm->CheckByAIAlgorithm(m_algorithm->Image);
		//m_algorithm->CheckByAIAlgorithm((m_algorithm->Images)[0]);
		//ResetEvent(m_algorithm->CHECK_AI_EVENT);
		SetEvent(m_algorithm->COMPLETE_AI_EVENT);
	}
	return 0;
}

DWORD WINAPI TraditionCheckFun(LPVOID pthread)
{
	AlgorithmBase* m_algorithm = (AlgorithmBase*)pthread;
	while (true)
	{
		WaitForSingleObject(m_algorithm->CHECK_TRADITION_EVENT, INFINITE);
		if (m_algorithm->m_Exit) {
			break;
		}
		m_algorithm->CheckByTraditionAlgorithm((m_algorithm->Image));
		//ResetEvent(m_algorithm->CHECK_AI_EVENT);
		SetEvent(m_algorithm->COMPLETE_TRADITION_EVENT);
	}
	return 0;
}



void AlgorithmBase::CheckByAIAlgorithm(Mat& image)
{
	//if (image.empty()) return;
	//this->result = 1;
	//auto start_time = std::chrono::system_clock::now();
	////cv::Mat Product_Image = image;
	//if (cur_model_type_flag == 0) {
	//	// 分类模型推理
	//	vector<float> result_lable_confidence;
	//	result_lable_confidence = cls_model.inference(image);
	//	if (result_lable_confidence[0] == 1) {
	//		this->result = -1;
	//	}
	//}
	//else {
	//	// 目标检测模型推理
	//	if (image.channels() != 3) {
	//		cv::cvtColor(image, image, cv::COLOR_GRAY2BGR);
	//	}
	//	//this->result_rect_vec = obj_model.inference(image);   // 输出矩形框
	//	//this->result = this->result_rect_vec.size() > 0 ? -1 : 1;   // 分类结果
	//	//FilterResult(image, obj_model.inference(image));
	//	//AI_result_rect_table = obj_models[0].inference(image);
	//	AI_check[0] = obj_models[0].inference(image);
	//	FilterID(AI_check[0][2]);
	//	//FilterID(AI_result_rect_table[2]);
	//}
	//auto end_time = std::chrono::system_clock::now();
	//this->infer_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

}

void AlgorithmBase::CheckByTraditionAlgorithm(Mat& image)
{

	TraditionPara mpara;
	vector<int>().swap(mpara.inner_radius);
	mpara.inner_radius.push_back(inner_radius);
	mpara.outer_radius = outer_radius;
	mpara.dyn_threshold_val = dyn_threshold_val;
	mpara.area_threshold_val = area_threshold_val;
	//Mat a;
	//cv::rotate(image, a, cv::ROTATE_90_COUNTERCLOCKWISE);
	HObject	ho_Image = Mat2HObject(image);
	int width = image.cols;
	int height = image.rows;
	mpara.ho_mask = ho_MaskImage;
	vector<cv::Rect>().swap(Tradition_result_rect);///存放检测结果
	//先加载生产批次
	m_pData->LoadProductData();
	m_pData->LoadBottleDetParam();
	WriteProductBatch=m_pData->GetBottleDetParam()->ProductData;
	PersonUse= m_pData->GetBottleDetParam()->PersonUse;
	

#pragma region new
	// Local iconic variables
	try {
		// Local iconic variables
		HObject  ho_GrayImage, ho_Regions4;
		HObject  ho_Rectangle10, ho_ImageReduced9, ho_Regions5, ho_ConnectedRegions;
		HObject  ho_SelectedRegions1, ho_RegionUnion2, ho_Rectangle5;
		HObject  ho_SelectedRegions3, ho_RegionErosion, ho_Rectangle;
		HObject  ho_RegionIntersection, ho_Rectangle3, ho_ImageReduced3;
		HObject  ho_Regions3, ho_ConnectedRegions4, ho_RegionClosing;
		HObject  ho_SelectedRegions4, ho_Rectangle6, ho_ImageReduced;
		HObject  ho_ImageScaled3, ho_Regions2, ho_ConnectedRegions5;
		HObject  ho_SelectedRegions7, ho_RegionUnion, ho_Rectangle1;
		HObject  ho_ImageReduced1, ho_ImageZoomed4, ho_Characters2;
		HObject  ho_Rectangle2, ho_ImageReduced2, ho_Rectangle9;
		HObject  ho_ImageReduced8, ho_ImageZoomed, ho_SelectedRegions;
		HObject  ho_RegionDilation2, ho_Rectangle4, ho_ImageReduced6;
		HObject  ho_ImageZoom, ho_ImageScaled, ho_SymbolRegions;
		HObject  ho_RegionDilation, ho_ImageReduced7, ho_Rectangle7;
		HObject  ho_ImageReduced4, ho_ImageZoomed7, ho_ImageMean;
		HObject  ho_ImageScaled1, ho_Regions, ho_Characters, ho_Rectangle8;
		HObject  ho_ImageReduced5, ho_ImageZoomed1, ho_Regions1;
		HObject  ho_ConnectedRegions1, ho_SelectedRegions2, ho_Characters1;

		// Local control variables
		HTuple  hv_ImageFiles, hv_Index, hv_WindowHandle;
		HTuple  hv_Width3, hv_Height3, hv_Row18, hv_Column18, hv_Row28;
		HTuple  hv_Column28, hv_Row16, hv_Column16, hv_Row26, hv_Column26;
		HTuple  hv_Row1, hv_Column1, hv_Row2, hv_Column2, hv_Row17;
		HTuple  hv_Column17, hv_Row27, hv_Column27, hv_RowCenter;
		HTuple  hv_Row19, hv_Column19, hv_Row29, hv_Column29, hv_Row11;
		HTuple  hv_Column11, hv_Row21, hv_Column21, hv_TextModel;
		HTuple  hv_TextResultID3, hv_fanhao, hv_ResultValue3, hv_Index8;
		HTuple  hv_Row12, hv_Column12, hv_Row22, hv_Column22, hv_riqi;
		HTuple  hv_TextModel2, hv_TextResultID4, hv_ResultValue;
		HTuple  hv_Index7, hv_WindowHandle1, hv_Row15, hv_Column15;
		HTuple  hv_Row25, hv_Column25, hv_BarCodeHandle, hv_DecodedDataStrings;
		HTuple  hv_DecodedStrings1, hv_CompositeStrings, hv_Row13;
		HTuple  hv_Column13, hv_Row23, hv_Column23, hv_TextModel1;
		HTuple  hv_TextResultID1, hv_ResultValue1, hv_Replaced;
		HTuple  hv_Replaced1, hv_Replaced2, hv_Replaced3, hv_index2;
		HTuple  hv_Row14, hv_Column14, hv_Row24, hv_Column24, hv_TextResultID;
		HTuple  hv_ResultValue2, hv_Replaced4, hv_Replaced5, hv_index3;
		HTuple  hv_shanghang, hv_index4, hv_xiahang, hv_index5, hv_index6;

		//Image Acquisition 01: Code generated by Image Acquisition 01
		GetImageSize(ho_Image, &hv_Width3, &hv_Height3);
		Rgb1ToGray(ho_Image, &ho_GrayImage);
		

		//
		Threshold(ho_GrayImage, &ho_Regions4, 66, 255);
		SmallestRectangle1(ho_Regions4, &hv_Row18, &hv_Column18, &hv_Row28, &hv_Column28);
		GenRectangle1(&ho_Rectangle10, hv_Row18, hv_Column18, hv_Row28, hv_Column28);
		ReduceDomain(ho_GrayImage, ho_Rectangle10, &ho_ImageReduced9);
		Threshold(ho_ImageReduced9, &ho_Regions5, 9, 104);


		//日期番号OCR
		Connection(ho_Regions5, &ho_ConnectedRegions);
		SelectShape(ho_ConnectedRegions, &ho_SelectedRegions1, "area", "and", 123320,
			500000);
		Union1(ho_SelectedRegions1, &ho_RegionUnion2);
		SmallestRectangle1(ho_RegionUnion2, &hv_Row16, &hv_Column16, &hv_Row26, &hv_Column26);
		GenRectangle1(&ho_Rectangle5, hv_Row16, hv_Column16, hv_Row26, hv_Column26 + hv_Width3);
		SelectShape(ho_ConnectedRegions, &ho_SelectedRegions3, "area", "and", 221537,
			500000);
		ErosionCircle(ho_SelectedRegions3, &ho_RegionErosion, 5);
		SmallestRectangle1(ho_RegionErosion, &hv_Row1, &hv_Column1, &hv_Row2, &hv_Column2);
		GenRectangle1(&ho_Rectangle, hv_Row1, hv_Column1, hv_Row2, hv_Column2);
		Intersection(ho_Rectangle5, ho_Rectangle, &ho_RegionIntersection);
		SmallestRectangle1(ho_RegionIntersection, &hv_Row17, &hv_Column17, &hv_Row27,
			&hv_Column27);

		//取中间这块黑的分成上下两部分
		hv_RowCenter = (hv_Row17 + hv_Row27) / 2;
		GenRectangle1(&ho_Rectangle3, hv_RowCenter + 90, hv_Column17 + 80, hv_Row2, hv_Column2);
		ReduceDomain(ho_GrayImage, ho_Rectangle3, &ho_ImageReduced3);

		//改动
		Threshold(ho_ImageReduced3, &ho_Regions3, 72, 255);
		Connection(ho_Regions3, &ho_ConnectedRegions4);
		ClosingCircle(ho_ConnectedRegions4, &ho_RegionClosing, 5);
		SelectShape(ho_RegionClosing, &ho_SelectedRegions4, "area", "and", 12130.4, 32560.5);
		SmallestRectangle1(ho_SelectedRegions4, &hv_Row19, &hv_Column19, &hv_Row29, &hv_Column29);

		//番号
		GenRectangle1(&ho_Rectangle6, hv_Row19 - 320, hv_Column17 + 80, hv_Row19 - 200, hv_Column27 - 290);
		ReduceDomain(ho_GrayImage, ho_Rectangle6, &ho_ImageReduced);
		ScaleImage(ho_ImageReduced, &ho_ImageScaled3, 2.3, -50);

		Threshold(ho_ImageScaled3, &ho_Regions2, 140, 255);
		Connection(ho_Regions2, &ho_ConnectedRegions5);
		//改动
		SelectShape(ho_ConnectedRegions5, &ho_SelectedRegions7, "area", "and", 72.82,
			357.38);
		Union1(ho_SelectedRegions7, &ho_RegionUnion);
		SmallestRectangle1(ho_RegionUnion, &hv_Row11, &hv_Column11, &hv_Row21, &hv_Column21);
		GenRectangle1(&ho_Rectangle1, hv_Row11 - 5, hv_Column11 - 10, hv_Row21, hv_Column21 + 3);
		ReduceDomain(ho_ImageScaled3, ho_Rectangle1, &ho_ImageReduced1);
		ZoomImageFactor(ho_ImageReduced1, &ho_ImageZoomed4, 3, 5.3, "constant");

		//番号识别
		CreateTextModelReader("auto", "Document_0-9A-Z_Rej.omc", &hv_TextModel);
		FindText(ho_ImageZoomed4, hv_TextModel, &hv_TextResultID3);
		hv_fanhao = "";
		GetTextResult(hv_TextResultID3, "class", &hv_ResultValue3);
		GetTextObject(&ho_Characters2, hv_TextResultID3, "all_lines");
		{
			HTuple end_val48 = hv_ResultValue3.TupleLength();
			HTuple step_val48 = 1;
			for (hv_Index8 = 1; hv_Index8.Continue(end_val48, step_val48); hv_Index8 += step_val48)
			{
				hv_fanhao += HTuple(hv_ResultValue3[hv_Index8 - 1]);
			}
		}

		//日期
		GenRectangle1(&ho_Rectangle2, hv_Row19 - 200, hv_Column17 + 80, hv_Row19 - 100, hv_Column27 - 280);
		ReduceDomain(ho_GrayImage, ho_Rectangle2, &ho_ImageReduced2);
		ScaleImage(ho_ImageReduced2, &ho_ImageScaled3, 2.8, -50);
		Threshold(ho_ImageScaled3, &ho_Regions2, 140, 255);
		SmallestRectangle1(ho_Regions2, &hv_Row12, &hv_Column12, &hv_Row22, &hv_Column22);
		GenRectangle1(&ho_Rectangle9, hv_Row12, hv_Column12, hv_Row22, hv_Column22);
		ReduceDomain(ho_ImageScaled3, ho_Rectangle9, &ho_ImageReduced8);
		ZoomImageFactor(ho_ImageScaled3, &ho_ImageZoomed, 3.5, 6, "constant");

		hv_riqi = "";
		CreateTextModelReader("auto", "Industrial_0-9+_Rej.omc", &hv_TextModel2);
		FindText(ho_ImageZoomed, hv_TextModel2, &hv_TextResultID4);
		GetTextResult(hv_TextResultID4, "class", &hv_ResultValue);
		{
			HTuple end_val65 = hv_ResultValue.TupleLength();
			HTuple step_val65 = 1;
			for (hv_Index7 = 1; hv_Index7.Continue(end_val65, step_val65); hv_Index7 += step_val65)
			{
				hv_riqi += HTuple(hv_ResultValue[hv_Index7 - 1]);
			}
		}
		//界面显示
		ReadProductBatch = HTupleToString(hv_fanhao);
		Deadline = HTupleToString(hv_riqi);


		//条形码
		GenRectangle1(&ho_Rectangle3, hv_RowCenter + 90, hv_Column17 + 80, hv_Row2, hv_Column2);
		ReduceDomain(ho_GrayImage, ho_Rectangle3, &ho_ImageReduced3);
		Threshold(ho_ImageReduced3, &ho_Regions3, 72, 255);
		Connection(ho_Regions3, &ho_ConnectedRegions4);
		ClosingCircle(ho_ConnectedRegions4, &ho_RegionClosing, 5);
		SelectShape(ho_RegionClosing, &ho_SelectedRegions, "area", "and", 16901.9, 36189.5);
		DilationRectangle1(ho_SelectedRegions, &ho_RegionDilation2, 11, 1);
		Union1(ho_RegionDilation2, &ho_RegionUnion);
		SmallestRectangle1(ho_RegionUnion, &hv_Row15, &hv_Column15, &hv_Row25, &hv_Column25);
		GenRectangle1(&ho_Rectangle4, hv_Row15 - 2, hv_Column15, hv_Row25 + 5, hv_Column25);
		ReduceDomain(ho_GrayImage, ho_Rectangle4, &ho_ImageReduced6);
		ZoomImageSize(ho_ImageReduced6, &ho_ImageZoom, 4700, 3700, "constant");
		ScaleImage(ho_ImageZoom, &ho_ImageScaled, 4, -250);
		//--------
		CreateBarCodeModel(HTuple(), HTuple(), &hv_BarCodeHandle);
		SetBarCodeParam(hv_BarCodeHandle, "composite_code", "CC-A/B");
		//识别
		FindBarCode(ho_ImageScaled, &ho_SymbolRegions, hv_BarCodeHandle, "auto", &hv_DecodedDataStrings);
		GetBarCodeResult(hv_BarCodeHandle, "all", "decoded_strings", &hv_DecodedStrings1);
		GetBarCodeResult(hv_BarCodeHandle, "all", "composite_strings", &hv_CompositeStrings);
		//界面显示
		UpCode = HTupleToString(hv_CompositeStrings);
		DownCode = HTupleToString(hv_DecodedStrings1);
		ClearBarCodeModel(hv_BarCodeHandle);

		//条形码上方字符
		GenRectangle1(&ho_Rectangle7, hv_Row15 - 50, hv_Column17 + 80, hv_Row15 - 0, hv_Column2);
		ReduceDomain(ho_GrayImage, ho_Rectangle7, &ho_ImageReduced4);
		ZoomImageFactor(ho_ImageReduced4, &ho_ImageZoomed7, 2, 2, "constant");
		MeanImage(ho_ImageZoomed7, &ho_ImageMean, 2, 2);
		ScaleImage(ho_ImageMean, &ho_ImageScaled1, 4, -200);

		Threshold(ho_ImageScaled1, &ho_Regions, 147, 255);
		SmallestRectangle1(ho_Regions, &hv_Row13, &hv_Column13, &hv_Row23, &hv_Column23);
		CreateTextModelReader("auto", "Document_0-9A-Z_Rej.omc", &hv_TextModel1);
		FindText(ho_ImageScaled1, hv_TextModel1, &hv_TextResultID1);
		GetTextResult(hv_TextResultID1, "class", &hv_ResultValue1);
		GetTextObject(&ho_Characters, hv_TextResultID1, "all_lines");
		TupleReplace(hv_ResultValue1, 0, "(", &hv_Replaced);
		TupleReplace(hv_Replaced, 3, ")", &hv_Replaced1);
		TupleReplace(hv_Replaced1, 10, "(", &hv_Replaced2);
		TupleReplace(hv_Replaced2, 13, ")", &hv_Replaced3);
		{
			HTuple end_val138 = hv_ResultValue1.TupleLength();
			HTuple step_val138 = 1;
			//for (hv_index2 = 1; hv_index2.Continue(end_val138, step_val138); hv_index2 += step_val138)
			//{
			//	disp_message(hv_WindowHandle, HTuple(hv_Replaced3[hv_index2 - 1]), "image", hv_Row13,
			//		hv_Column13 + (65 * hv_index2), "black", "true");
			//}
		}

		//条形码下方
		GenRectangle1(&ho_Rectangle8, hv_Row25 - 3, hv_Column17 + 80, hv_Row2, hv_Column2);
		ReduceDomain(ho_GrayImage, ho_Rectangle8, &ho_ImageReduced5);
		ZoomImageFactor(ho_ImageReduced5, &ho_ImageZoomed1, 2, 2, "constant");
		MeanImage(ho_ImageZoomed1, &ho_ImageMean, 2, 2);
		ScaleImage(ho_ImageMean, &ho_ImageScaled1, 5, -250);

		Threshold(ho_ImageScaled1, &ho_Regions1, 70, 255);
		DilationRectangle1(ho_Regions1, &ho_RegionDilation, 25, 5);
		Connection(ho_RegionDilation, &ho_ConnectedRegions1);

		SelectShape(ho_ConnectedRegions1, &ho_SelectedRegions2, "area", "and", 20369.1,
			38422.8);

		ReduceDomain(ho_ImageScaled1, ho_SelectedRegions2, &ho_ImageReduced7);

		SmallestRectangle1(ho_Regions1, &hv_Row14, &hv_Column14, &hv_Row24, &hv_Column24);
		FindText(ho_ImageReduced7, hv_TextModel1, &hv_TextResultID);
		GetTextResult(hv_TextResultID, "class", &hv_ResultValue2);
		GetTextObject(&ho_Characters1, hv_TextResultID, "all_lines");
		TupleReplace(hv_ResultValue2, 0, "(", &hv_Replaced4);
		TupleReplace(hv_Replaced4, 3, ")", &hv_Replaced5);
		{
			HTuple end_val187 = (hv_Replaced5.TupleLength()) - 1;
			HTuple step_val187 = 1;
			for (hv_index6 = 0; hv_index6.Continue(end_val187, step_val187); hv_index6 += step_val187)
			{
				if (0 != (int(HTuple(hv_Replaced5[hv_index6]) == HTuple("O"))))
				{
					TupleReplace(hv_Replaced5, hv_index6, "0", &hv_Replaced5);
				}
			}
			//for (hv_index3 = 1; hv_index3.Continue(end_val162, step_val162); hv_index3 += step_val162)
			//{
			//	disp_message(hv_WindowHandle, HTuple(hv_Replaced5[hv_index3 - 1]), "image", hv_Row14,
			//		hv_Column14 + (60 * hv_index3), "black", "true");
			//}
		}

		hv_shanghang = "";
		{
			HTuple end_val166 = hv_Replaced3.TupleLength();
			HTuple step_val166 = 1;
			for (hv_index4 = 1; hv_index4.Continue(end_val166, step_val166); hv_index4 += step_val166)
			{
				hv_shanghang += HTuple(hv_Replaced3[hv_index4 - 1]);
				//界面显示
				UpNumber = HTupleToString(hv_shanghang);
			}
		}
		hv_xiahang = "";
		{
			HTuple end_val170 = hv_Replaced5.TupleLength();
			HTuple step_val170 = 1;
			for (hv_index5 = 1; hv_index5.Continue(end_val170, step_val170); hv_index5 += step_val170)
			{
				hv_xiahang += HTuple(hv_Replaced5[hv_index5 - 1]);
				//界面显示
				DownNumber = HTupleToString(hv_xiahang);
			}
		}


		if (0 != (int(hv_CompositeStrings == hv_shanghang)) && (WriteProductBatch == ReadProductBatch))
		{
			//disp_message(hv_WindowHandle, //'上行没有错误'
			//	"\311\317\320\320\303\273\323\320\264\355\316\363",
			//	"window", 0, 0, "black", "true");
			UpResult = "上层条码比对成功！";
		}
		else if (WriteProductBatch == ReadProductBatch)
		{
			UpResult = "上层条码比对失败！";

		}
		else
		{
			UpResult = "批次异常！";
		}

		if (0 != (int(hv_DecodedStrings1 == hv_xiahang)) && (WriteProductBatch == ReadProductBatch))
		{
			//disp_message(hv_WindowHandle, //'下行没有错误'
			//	"\317\302\320\320\303\273\323\320\264\355\316\363",
			//	"image", 3000, 0, "black", "true");
			DownResult = "下层条码比对成功！";
		}
		else if (WriteProductBatch == ReadProductBatch)
		{
			DownResult = "下层条码比对失败！";
		}
		else
		{
			//disp_message(hv_WindowHandle, //'下行有错误'
			//	"\317\302\320\320\323\320\264\355\316\363",
			//	"image", 3000, 0, "black", "true");
			DownResult = "批次异常！";
		}

		if (UpResult == "上层条码比对成功！" && DownResult == "下层条码比对成功！")
		{
			isOkSignal = "OK";

		}
		else
		{
			isOkSignal = "NG";
		}




	}
	catch (HException& exception) 
	{
		Deadline = "0";
		UpCode = "0";
		DownCode = "0";
		UpNumber = "0";
		DownNumber = "0";
		UpResult = "图像异常！";
		DownResult = "图像异常！";
		ofstream outfile;
		outfile.open("data.txt", ios::binary | ios::app | ios::in | ios::out);
		//注意，里面有iOS：：app，表示打开文件后，在写入的文件不会覆盖原文件中的内容，也就是原来文件中的数据会得到保存。
		outfile << "Error: " << exception.ErrorMessage() << "\n";
	}
	ofstream outfile;
	outfile.open("data.txt", ios::binary | ios::app | ios::in | ios::out);
	//注意，里面有iOS：：app，表示打开文件后，在写入的文件不会覆盖原文件中的内容，也就是原来文件中的数据会得到保存。
	outfile << "Deadline: " << Deadline << "\n";
	outfile << "UpCode: " << UpCode << "\n";
	outfile << "DownCode: " << DownCode << "\n";
	outfile << "UpNumber: " << UpNumber << "\n";
	outfile << "DownNumber: " << DownNumber << "\n";
	outfile << "UpResult: " << UpResult << "\n";
	outfile << "DownResult: " << DownResult << "\n";
			
	

	//*****************************************************************
}

//void AlgorithmBase::CheckByAIAlgorithm(Mat& image, int index)
//{
//	////SYSTEMTIME st;
//	////CString strDate, strTime;
//	////const char* cstr;
//	////GetLocalTime(&st);
//	////strTime.Format(TEXT("检测开始：%d%2d:%2d:%2d:%4d"), index,st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
//	////cstr = MyW2A2(strTime);
//	////LOG(0, cstr);
//	//if (image.empty()) return;
//	//this->result = 1;
//	//auto start_time = std::chrono::system_clock::now();
//	////cv::Mat Product_Image = image;
//	////if (cur_model_type_flag == 0) {
//	////	// 分类模型推理
//	////	vector<float> result_lable_confidence;
//	////	result_lable_confidence = cls_model.inference(image);
//	////	if (result_lable_confidence[0] == 1) {
//	////		this->result = -1;
//	////	}
//	////}
//	////else {
//	//// 目标检测模型推理
//	//if (image.channels() != 3) {
//	//	cv::cvtColor(image, image, cv::COLOR_GRAY2BGR);
//	//}
//	//AI_check[index] = obj_models[index].inference(image);
//	////}
//	//auto end_time = std::chrono::system_clock::now();
//	////GetLocalTime(&st);
//	////strTime.Format(TEXT("检测结束：%d%2d:%2d:%2d:%4d"), index, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
//	////cstr = MyW2A2(strTime);
//	////LOG(0, cstr);
//	//this->infer_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
//
//	if (image.empty()) return;
//	this->result = 1;
//	this->AI_result_rect_vec[index] = vector<cv::Rect>();
//	this->res_names[index] = "良品";
//	//auto start_time = std::chrono::system_clock::now();
//	//cv::Mat Product_Image = image;
//	if (cur_model_type_flag == 0) {
//		//// 分类模型推理
//		//vector<float> result_lable_confidence;
//		//result_lable_confidence = cls_model.inference(image);
//		//if (result_lable_confidence[0] == 1) {
//		//	this->result = -1;
//		//}
//	}
//	else {
//		// 目标检测模型推理
//		if (image.channels() != 3) {
//			cv::cvtColor(image, image, cv::COLOR_GRAY2BGR);
//		}
//		std::vector<cv::Mat> imgs_batch;
//		imgs_batch.emplace_back(image.clone());
//		AI_check[index] = task(yolo[index], param, imgs_batch, 1, 0, false, false, 0.2);
//	}
//	AIFilterResult(image, AI_check[index], index);
//}

void AlgorithmBase::CheckByIdentifyAlgorithm(Mat& image, int index)
{

	//if (image.empty()) return;
	//this->result = 1;
	//auto start_time = std::chrono::system_clock::now();
	////cv::Mat Product_Image = image;
	//Mat imagergb;
	//if (cur_model_type_flag == 0) {
	//	// 分类模型推理
	//	vector<float> result_lable_confidence;
	//	result_lable_confidence = cls_model.inference(image);
	//	if (result_lable_confidence[0] == 1) {
	//		this->result = -1;
	//	}
	//}
	//else {
	//	// 目标检测模型推理
	//	if (image.channels() != 3) {
	//		cv::cvtColor(image, imagergb, cv::COLOR_GRAY2BGR);
	//	}
	//	else
	//	{
	//		imagergb = image.clone();
	//	}
	//	Mat imagecrop = imagergb(Rect(180, 100, 832, 665));
	//	//Identify_models[index].inference(imagecrop);
	//}
	//auto end_time = std::chrono::system_clock::now();	
	//this->infer_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
}

void AlgorithmBase::CheckByAIAlgorithm(vector<Mat>& images)
{
	//if (images.empty()) return;
	//this->result = 1;
	//auto start_time = std::chrono::system_clock::now();
	////cv::Mat Product_Image = image;
	//if (cur_model_type_flag == 0) {
	//	// 分类模型推理
	//	vector<float> result_lable_confidence;
	//	result_lable_confidence = cls_model.inference(images[0]);
	//	if (result_lable_confidence[0] == 1) {
	//		this->result = -1;
	//	}
	//}
	//else {
	//	// 目标检测模型推理
	//	if (images[0].channels() != 3) {
	//		for (int i = 0; i < images.size(); i++) {
	//			cv::cvtColor(images[i], images[i], cv::COLOR_GRAY2BGR);
	//		}
	//	}
	//	//AI_RESULT = obj_model.inference(images);
	//}
	//auto end_time = std::chrono::system_clock::now();
	//this->infer_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

}

void AlgorithmBase::CheckByTraditionAlgorithm(Mat image, int index)
{
	//SYSTEMTIME st;
	//CString strDate, strTime;
	//const char* cstr;
	//GetLocalTime(&st);
	//strTime.Format(TEXT("算法开始：%d%2d:%2d:%2d:%4d"), index,st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//cstr = MyW2A2(strTime);
	//LOG(0, cstr);

	auto start_time = std::chrono::system_clock::now();

	TraditionPara mpara;
	vector<int>().swap(mpara.inner_radius);
	for (int i = 0; i < 5; i++) {
		mpara.inner_radius.push_back(inner_radius);
	}
	//mpara.inner_radius[index] = inner_radius;
	mpara.outer_radius = outer_radius;
	mpara.dyn_threshold_val = dyn_threshold_val;
	mpara.area_threshold_val = area_threshold_val;
	HObject	ho_Image = Mat2HObject(image);
	mpara.ho_mask = ho_MaskImages[index];
	//vector<cv::Rect>().swap(Tradition_result_rect);///存放检测结果
	//vector<cv::Rect>Tradition_result_rect;
	//Tradition_result_rect = TraditionAlgorithm(ho_Image, mpara, Tradition_result_rect);
	//vector<cv::Rect>().swap(Tradition_result_rect);

	vector<cv::Rect>Tradition_result_rect1;
	//从xml文件提取参数
	//瓶底外圆半径（默认350pix）
	HObject	ho_Edges, ho_SelectedXLD, ho_ContoursSplit;
	HObject  ho_ObjectSelected, ho_ContoursSelected, ho_Circle;
	HObject  ho_Circle1, ho_Region, ho_RegionFillUp, ho_RegionClosing;
	HObject  ho_RegionIntersection, ho_ImageReduced, ho_ImageMedian;
	HObject  ho_RegionDynThresh, ho_ConnectedRegions, ho_RegionClosing1;
	HObject  ho_SelectedRegions, ho_Rectangle, ho_Mask, ho_ROI, ho_EmptyRegion;
	// Local control variables
	HTuple  hv_Index, hv_Number, hv_Number1, hv_CircleIndex, hv_i, hv_I;
	HTuple  hv_Attrib, hv_Row, hv_Column, hv_Radius, hv_StartPhi;
	HTuple  hv_EndPhi, hv_PointOrder, hv_RowSelected, hv_ColumnSelected;
	HTuple  hv_RadiusSelected, hv_Index1, hv_RowMedian, hv_ColumnMedian;
	HTuple  hv_UsedThreshold, hv_Row1, hv_Column1, hv_Row2;
	HTuple  hv_Column2, hv_Index2, hv_y, hv_x, hv_height, hv_width;
	Rect rect;
	HTuple  hv_outer_radius = mpara.outer_radius;
	HTuple  hv_inner_radius = mpara.inner_radius[index];
	HTuple  hv_dyn_threshold_val, hv_area_threshold_val;
	//HTuple  hv_dyn_threshold_val = mpara.dyn_threshold_val;
	//HTuple  hv_area_threshold_val = mpara.area_threshold_val;
	//GetLocalTime(&st);
	//strTime.Format(TEXT("算法定义：%d:%2d:%2d:%2d:%4d"), index, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//cstr = MyW2A2(strTime);
	//LOG(0, cstr);

	//去除外界遮挡区域，基于光照合适的区域检测缺陷
	BinaryThreshold(ho_Image, &ho_Region, "max_separability", "light", &hv_UsedThreshold);
	FillUp(ho_Region, &ho_RegionFillUp);
	ClosingCircle(ho_RegionFillUp, &ho_RegionClosing, 100);
	//GetLocalTime(&st);
	//strTime.Format(TEXT("算法定义：%d:%2d:%2d:%2d:%4d"), index, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//cstr = MyW2A2(strTime);
	//LOG(0, cstr);

	for (int i = 0; i < mpara.ho_mask.size(); i++) {
		Rgb1ToGray(mpara.ho_mask[i], &ho_Mask);
		Threshold(ho_Mask, &ho_ROI, 128, 255);
		GenEmptyRegion(&ho_EmptyRegion);
		if (0 != (ho_ROI == ho_EmptyRegion))
		{
			continue;
		}
		Intersection(ho_ROI, ho_RegionClosing, &ho_RegionIntersection);
		ReduceDomain(ho_Image, ho_RegionIntersection, &ho_ImageReduced);
		//GetLocalTime(&st);
		//strTime.Format(TEXT("处理前时：%d:%2d:%2d:%2d:%4d"), index, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		//cstr = MyW2A2(strTime);
		//LOG(0, cstr);

		//动态阈值截取可能的缺陷区域
		//MedianImage(ho_ImageReduced, &ho_ImageMedian, "square", hv_inner_radius / 3, "continued");
		MedianImage(ho_ImageReduced, &ho_ImageMedian, "square", mpara.inner_radius[index] / 3, "continued");

		//GetLocalTime(&st);
		//strTime.Format(TEXT("处理后时：%d:%2d:%2d:%2d:%4d"), index, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		//cstr = MyW2A2(strTime);
		//LOG(0, cstr);

		hv_dyn_threshold_val = mpara.dyn_threshold_val[i];
		DynThreshold(ho_ImageReduced, ho_ImageMedian, &ho_RegionDynThresh, hv_dyn_threshold_val, "dark");
		Connection(ho_RegionDynThresh, &ho_ConnectedRegions);
		//GetLocalTime(&st);
		//strTime.Format(TEXT("算法处理3：%d:%d:%2d:%2d:%2d:%4d"), index, i, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		//cstr = MyW2A2(strTime);
		//LOG(0, cstr);
		ClosingCircle(ho_ConnectedRegions, &ho_RegionClosing1, 3.5);
		hv_area_threshold_val = mpara.area_threshold_val[i];
		//SelectShape(ho_RegionClosing1, &ho_SelectedRegions, "area", "and", hv_area_threshold_val, 1000000);
		SelectShape(ho_RegionClosing1, &ho_SelectedRegions, "area", "and", mpara.area_threshold_val[i], 1000000);
		//生成矩形框
		CountObj(ho_SelectedRegions, &hv_Number1);
		if (0 != (hv_Number1 > 0))
		{
			SmallestRectangle1(ho_SelectedRegions, &hv_Row1, &hv_Column1, &hv_Row2, &hv_Column2);
			{
				HTuple end_val118 = (hv_Row1.TupleLength()) - 1;
				HTuple step_val118 = 1;
				for (hv_Index2 = 0; hv_Index2.Continue(end_val118, step_val118); hv_Index2 += step_val118)
				{
					hv_y = HTuple(hv_Row1[hv_Index2]);
					hv_x = HTuple(hv_Column1[hv_Index2]);
					hv_height = HTuple(hv_Row2[hv_Index2]) - HTuple(hv_Row1[hv_Index2]);
					hv_width = HTuple(hv_Column2[hv_Index2]) - HTuple(hv_Column1[hv_Index2]);
					rect.y = hv_y.I();
					rect.x = hv_x.I();
					rect.height = hv_height.I();
					rect.width = hv_width.I();
					Tradition_result_rect1.push_back(rect);
					//Tradition_check[index].push_back(rect);
				}
			}
		}
	}
	Tradition_check[index] = Tradition_result_rect1;
	//if (result_rect.size() != 0)
	//{
	//	Tradition_check[index] = result_rect;
	//}
	auto end_time = std::chrono::system_clock::now();
	this->infer_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
	//GetLocalTime(&st);
	//strTime.Format(TEXT("算法结束%d:%2d:%2d:%2d:%4d"), index, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//cstr = MyW2A2(strTime);
	//LOG(0, cstr);


}

string AlgorithmBase::HTupleToString(const HTuple& hTuple)
{
	// 如果HTuple存储的是字符串，直接转换
	//HTuple length;
	//TupleLength(hTuple, &length);
	//if (length!=0)
	//{
		return hTuple.S().Text();
	//}
	//else
	//{
	//	return "0";
	//}
}

HObject AlgorithmBase::Mat2HObject(cv::Mat& cv_img)
{
	HalconCpp::HObject H_img;

	if (cv_img.channels() == 1)
	{
		int height = cv_img.rows, width = cv_img.cols;
		int size = height * width;
		uchar* temp = new uchar[size];

		memcpy(temp, cv_img.data, size);
		HalconCpp::GenImage1(&H_img, "byte", width, height, (Hlong)(temp));

		delete[] temp;
	}
	else if (cv_img.channels() == 3)
	{
		int height = cv_img.rows, width = cv_img.cols;
		int size = height * width;
		uchar* B = new uchar[size];
		uchar* G = new uchar[size];
		uchar* R = new uchar[size];

		for (int i = 0; i < height; i++)
		{
			uchar* p = cv_img.ptr<uchar>(i);
			for (int j = 0; j < width; j++)
			{
				B[i * width + j] = p[3 * j];
				G[i * width + j] = p[3 * j + 1];
				R[i * width + j] = p[3 * j + 2];
			}
		}
		HalconCpp::GenImage3(&H_img, "byte", width, height, (Hlong)(R), (Hlong)(G), (Hlong)(B));

		delete[] R;
		delete[] G;
		delete[] B;
	}
	return H_img;
}

void AlgorithmBase::CheckByIdentifyAlgorithm(vector<Mat>& images)
{
	//if (images.empty()) return;
	//this->result = 1;
	//auto start_time = std::chrono::system_clock::now();
	//Mat imagergb;
	//vector<Mat> imagergb1;
	//if (cur_model_type_flag == 0) {
	//	// 分类模型推理
	//	vector<float> result_lable_confidence;
	//	result_lable_confidence = cls_model.inference(images[0]);
	//	if (result_lable_confidence[0] == 1) {
	//		this->result = -1;
	//	}
	//}
	//else {
	//	// 目标检测模型推理
	//	if (images[0].channels() != 3) {
	//		for (int j = 0; j < images.size(); j++) {
	//			cv::cvtColor(images[j], images[j], cv::COLOR_GRAY2BGR);
	//			//imagergb1.push_back(imagergb);
	//		}
	//	}
	//	/*else
	//	{
	//		for (int k = 0; k < images.size(); k++) {
	//			imagergb1[k] = images[k].clone();
	//		}
	//	}*/
	//	//AID_RESULT = Identify_model.inference(images);
	//}
	//auto end_time = std::chrono::system_clock::now();
	//this->infer_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

}

void AlgorithmBase::CheckByModeAlgorithm(Mat& image)
{
	Mat img = image.clone();
	bottle_type = "0";
}

vector<int> AlgorithmBase::Str2Vec1(string str)
{
	int start = 0;
	int num = 0;
	vector<int> nums;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			string temp = str.substr(start, i - start);
			nums.push_back(atoi(temp.c_str()));
			num++;
			start = i + 1;
		}
	}
	string temp = str.substr(start, str.size() - start + 1);
	nums.push_back(atoi(temp.c_str()));
	return nums;
}

int AlgorithmBase::str2int1(string str)
{
	stringstream stream;     //声明一个stringstream变量
	int n;
	//string转int
	stream << str;     //向stream中插入字符串
	stream >> n;
	return n;
}