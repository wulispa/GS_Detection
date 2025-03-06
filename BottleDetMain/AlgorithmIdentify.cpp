#include "pch.h"
//#include "AlgorithmIdentify.h"
//#include "MyXml.h"
////DWORD WINAPI AICheckFun(LPVOID pthread);
////DWORD WINAPI TraditionCheckFun(LPVOID pthread);
//
//AlgorithmIdentify::AlgorithmIdentify()
//{
//	result = 1;
//	//m_Exit = false;
//	//InitThread();
//}
//
//AlgorithmIdentify::AlgorithmIdentify(DataManager* pdata)
//	:m_pData(pdata)
//{
//	result = 1;
//	bottle_type = "NULL";
//}
//
//AlgorithmIdentify::AlgorithmIdentify(const AlgorithmIdentify& obj)
//{
//	this->m_pData = obj.m_pData;
//	result = 1;
//	//m_Exit = false;
//}
//
//AlgorithmIdentify& AlgorithmIdentify::operator=(const AlgorithmIdentify& obj)
//{
//	// TODO: 在此处插入 return 语句
//	if (this == &obj) {
//		return *this;
//	}
//	this->m_pData = obj.m_pData;
//
//	return *this;
//}
//
//AlgorithmIdentify::~AlgorithmIdentify()
//{
//	//RelaseThread();
//	
//}
//
//int AlgorithmIdentify::GetCheckResult()
//{
//	//if (model == bottle_type)
//	TargetID = Str2Vec(m_pData->GetBottleDetParam()->SelectedMold);
//	int detect_id = str2int(bottle_type);
//	if (find(TargetID.begin(), TargetID.end(), detect_id) != TargetID.end()
//		&&m_pData->GetBottleDetParam()->MoldRecognition == "MOLDON")
//	{
//		result = 1;
//	}
//	else
//	{
//		result = -1;
//	}
//	return result;
//}
//
//vector<cv::Rect> AlgorithmIdentify::GetDetRects()
//{
//	return result_rect_vec;
//}
//
//cv::Mat AlgorithmIdentify::GetObjDetResultImg()
//{
//	return this->result_img;
//}
//
//int AlgorithmIdentify::GetDetCostTime()
//{
//	return this->infer_time;
//}
//
//int AlgorithmIdentify::LoadAlgorithmParam()
//{
//	//string tmp_model_path;
//	//int tmp_batch;
//	//int tmp_channel;
//	//int tmp_height;
//	//int tmp_width;
//	//int tmp_model_type_flag;
//	//string tmp_txt_order;
//	//// 根据配置文件加载模型参数
//	////string tmp_txt_path = (m_pData->GetBottleDetParam()->MoldModel_Path).c_str();
//	//string tmp_txt_path = (m_pData->GetBottleDetParam()->MoldProfile_Path).c_str();
//	//ifstream readfile(tmp_txt_path);
//	//readfile >> tmp_model_path;
//	//readfile >> tmp_batch;
//	//readfile >> tmp_channel;
//	//readfile >> tmp_height;
//	//readfile >> tmp_width;
//	//readfile >> tmp_model_type_flag;
//	//readfile >> tmp_txt_order;
//	//readfile.close();
//
//	//if (tmp_txt_order == cur_txt_order) return -1;  // 序列号一致说明配置文件没改变，不用更新模型，直接返回
//	///******************************************* 开始更新参数 *****************************************************/
//	//string model_data_path = tmp_model_path.substr(0, tmp_model_path.find_last_of("/\\")) + "/" + tmp_txt_order + ".data";
//	//cur_model_type_flag = tmp_model_type_flag;
//	////cur_txt_order = tmp_txt_order;
//	//if (cur_model_type_flag == 0) {
//	//	cls_model.model_path = tmp_model_path;
//	//	cls_model.input_batch = tmp_batch;
//	//	cls_model.input_channel = tmp_channel;
//	//	cls_model.input_height = tmp_height;
//	//	cls_model.input_width = tmp_width;
//	//	cls_model.model_data_path = model_data_path;
//	//}
//	//else {
//	//	obj_model.model_path = tmp_model_path;
//	//	obj_model.channels = tmp_channel;
//	//	obj_model.INPUT_H = tmp_height;
//	//	obj_model.INPUT_W = tmp_width;
//	//	obj_model.model_data_path = model_data_path;
//
//	//	// 读取xml文件中的阈值参数，类别置信度读两个，暂时只用两个
//	//	//obj_model.NMS_THRESH = m_pData->GetBottleDetParam()->NMSThreshVal;    //0.25
//	//	obj_model.NMS_THRESH = 0.25;
//	//	//obj_model.BBOX_CONF_THRESH.push_back(m_pData->GetBottleDetParam()->ConfidenceVal1);   //0.1
//	//	obj_model.BBOX_CONF_THRESH.push_back(0.5);   //0.1
//	//	//obj_model.BBOX_CONF_THRESH.push_back(m_pData->GetBottleDetParam()->ConfidenceVal2);     //0.5
//	//	obj_model.BBOX_CONF_THRESH.push_back(0.5);     //0.5
//	//}
//	return 0;
//}
//
//int AlgorithmIdentify::LoadAlgorithmModel()
//{
//	if (cur_model_type_flag == 0) {
//		// 分类模型
//		cls_model.init();
//		if (cls_model.build_trt_model(cls_model.model_path.c_str(), cls_model.model_data_path.c_str())) {
//			return -1;
//		}
//		if (cls_model.load_trt_model(cls_model.model_data_path.c_str())) {
//			return -1;
//		}
//	}
//	else {
//		// 目标检测模型
//		if (!obj_model.build_trt_model(obj_model.model_path.c_str(), obj_model.model_data_path.c_str())) {
//			return -1;
//		}
//		if (!obj_model.load_trt_model(obj_model.model_data_path.c_str(), "2")) {
//			return -1;
//		}
//	}
//
//	return 0;
//}
//
//void AlgorithmIdentify::DoJob(Mat& image)
//{
//	this->result = 1;
//	auto start_time = std::chrono::system_clock::now();
//	//cv::Mat Product_Image = image;
//
//	if (cur_model_type_flag == 1) {
//		// 目标检测模型推理
//		if (image.channels() != 3) {
//			cv::cvtColor(image, image_bgr, cv::COLOR_GRAY2BGR);
//		}
//		else {
//			image_bgr = image.clone();
//		}
//		//this->result_rect_vec = obj_model.inference(image_bgr);   // 输出矩形框
//		//this->result = this->result_rect_vec.size() > 0 ? -1 : 1;   // 分类结果
//		//FilterResult(image, obj_model.inference(image));
//		AI_result_rect_table = obj_model.inference(image_bgr);
//
//		// 计算编码
//		bottle_type = "NULL";
//		if (AI_result_rect_table[0].size() == 9) {
//			vector<pair<int, int>> points;
//			for (cv::Rect& i : AI_result_rect_table[0]) {
//				points.push_back(pair<int, int>(i.x, i.y));
//			}
//			string bottle_type_temp = bottle_xml.Coordinate2Code(points, false);
//			bottle_type_temp.erase(bottle_type_temp.begin());
//			bottle_type = bottle_type_temp;
//			//bottle_type = sub(bottle_type_temp, "S");
//		}
//	}
//	auto end_time = std::chrono::system_clock::now();
//	this->infer_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
//}
//
//void AlgorithmIdentify::DoJob(vector<Mat>& images, int num)
//{
//	for (int i = 0; i < images.size(); i++) {
//		DoJob(images[i]);
//		if (bottle_type != "NULL") {
//			break;
//		}
//	}
//	//cout << "this is DoJobs" << endl;
//}
//
//bool AlgorithmIdentify::UpdateAlgorithm()
//{
//	if (LoadAlgorithmParam() == 0) {
//		LoadAlgorithmModel();
//	}
//
//	bottle_xml.Read_Code(CString("Bottle.xml"));
//	return false;
//}
//
//string AlgorithmIdentify::sub(string s1, string s2)
//{
//	bool minus = false;
//	if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2)) {
//		swap(s1, s2);
//		minus = true;
//	}
//	int i = s1.size() - 1;
//	int j = s2.size() - 1;
//	int flag = 0;
//	string ans = "";
//	while (i >= 0 && j >= 0) {
//		int tmp = 0;
//		if (s1[i] >= s2[j]) {
//			tmp = s1[i] - s2[j];
//			tmp = tmp - flag;
//			ans += to_string(tmp);
//			flag = 0;
//		}
//		else {
//			tmp = s1[i] - s2[j] + 10;
//			tmp = tmp - flag;
//			ans += to_string(tmp);
//			flag = 1;
//		}
//		i--;
//		j--;
//	}
//	// 处理较大数的剩余部分 
//	while (i >= 0) {
//		if (flag == 0) {
//			ans += s1[i];
//		}
//		else {
//			int tmp = s1[i] - '0' - flag;
//			ans += to_string(tmp);
//			flag = 0;
//		}
//		i--;
//	}
//	// 翻转 
//	reverse(ans.begin(), ans.end());
//	//去除前导 0 
//	int k = 0;
//	while (k < ans.size() && ans[k] == '0') k++;
//	if (k == ans.size()) {
//		ans = "0";
//	}
//	else ans = ans.substr(k);
//	// 结果是否为负 
//	return minus ? "-" + ans : ans;
//}
//
//vector<int> AlgorithmIdentify::Str2Vec(string str)
//{
//	int start = 0;
//	int num = 0;
//	vector<int> nums;
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == ',') {
//			string temp = str.substr(start, i - start);
//			nums.push_back(atoi(temp.c_str()));
//			num++;
//			start = i + 1;
//		}
//	}
//	string temp = str.substr(start, str.size() - start + 1);
//	nums.push_back(atoi(temp.c_str()));
//	return nums;
//}
//
//int AlgorithmIdentify::str2int(string str)
//{
//	stringstream stream;     //声明一个stringstream变量
//	int n;
//	//string转int
//	stream << str;     //向stream中插入字符串
//	stream >> n;
//	return n;
//}
//
