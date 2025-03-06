#include "pch.h"
//#include "dlModel.h"
//#include <cstdio>
//
//#pragma warning(disable:4996);
//
//#define checkRuntime(op)  __check_cuda_runtime((op), #op, __FILE__, __LINE__)
//
//bool __check_cuda_runtime(cudaError_t code, const char* op, const char* file, int line) {
//    if (code != cudaSuccess) {
//        const char* err_name = cudaGetErrorName(code);
//        const char* err_message = cudaGetErrorString(code);
//        printf("runtime error %s:%d  %s failed. \n  code = %s, message = %s\n", file, line, op, err_name, err_message);
//        return false;
//    }
//    return true;
//}
//
//inline const char* severity_string(nvinfer1::ILogger::Severity t) {
//    switch (t) {
//    case nvinfer1::ILogger::Severity::kINTERNAL_ERROR: return "internal_error";
//    case nvinfer1::ILogger::Severity::kERROR:   return "error";
//    case nvinfer1::ILogger::Severity::kWARNING: return "warning";
//    case nvinfer1::ILogger::Severity::kINFO:    return "info";
//    case nvinfer1::ILogger::Severity::kVERBOSE: return "verbose";
//    default: return "unknow";
//    }
//}
//
//class TRTLogger : public nvinfer1::ILogger {
//public:
//    virtual void log(Severity severity, nvinfer1::AsciiChar const* msg) noexcept override {
//        if (severity <= Severity::kINFO) {
//            // 打印带颜色的字符，格式如下：
//            // printf("\033[47;33m打印的文本\033[0m");
//            // 其中 \033[ 是起始标记
//            //      47    是背景颜色
//            //      ;     分隔符
//            //      33    文字颜色
//            //      m     开始标记结束
//            //      \033[0m 是终止标记
//            // 其中背景颜色或者文字颜色可不写
//            // 部分颜色代码 https://blog.csdn.net/ericbar/article/details/79652086
//            if (severity == Severity::kWARNING) {
//                printf("\033[33m%s: %s\033[0m\n", severity_string(severity), msg);
//            }
//            else if (severity <= Severity::kERROR) {
//                printf("\033[31m%s: %s\033[0m\n", severity_string(severity), msg);
//            }
//            else {
//                printf("%s: %s\n", severity_string(severity), msg);
//            }
//        }
//    }
//} logger;
//
//// 通过智能指针管理nv返回的指针参数
//// 内存自动释放，避免泄漏
//template<typename _T>
//shared_ptr<_T> make_nvshared(_T* ptr) {
//    return shared_ptr<_T>(ptr, [](_T* p) {p->destroy(); });
//}
//
//bool exists(const string& path) {
//
//#ifdef _WIN32
//    return ::PathFileExistsA(path.c_str());
//#else
//    return access(path.c_str(), R_OK) == 0;
//#endif
//}
//
///************************************** TensorRT 分类模型 ***********************************************/
//Classification::Classification() :
//    m_stream(nullptr),
//    input_data_device(nullptr),
//    input_data_host(nullptr)
//{
//    //init();
//}
//
//void Classification::init() {
//    input_numel = input_batch * input_channel * input_height * input_width;
//    // 创建内存，数据要放到cuda上必须先放到锁定内存区域上，再放到cuda上，所以下面创建了一个暂存区域host和一个cuda区域
//    checkRuntime(cudaMallocHost(&input_data_host, input_numel * sizeof(float)));
//    checkRuntime(cudaMalloc(&input_data_device, input_numel * sizeof(float)));
//    checkRuntime(cudaMalloc(&output_data_device, sizeof(output_data_host)));  // 申请一块区域，放最终的结果
//
//}
//
//Classification::~Classification()
//{
//    // 释放内存
//    checkRuntime(cudaStreamDestroy(m_stream));
//    checkRuntime(cudaFreeHost(input_data_host));
//    checkRuntime(cudaFree(input_data_device));
//    checkRuntime(cudaFree(output_data_device));
//}
//
//// 创建trt模型，如果存在了就直接返回，注意这里的模型路径
//bool Classification::build_trt_model(const char* onnx_path, const char* trt_save_path) {
//    if (exists(trt_save_path)) {
//        cout << trt_save_path << "has exists." << endl;
//        return true;
//    }
//
//    TRTLogger logger;
//
//    // 这是基本需要的组件
//    auto builder = make_nvshared(nvinfer1::createInferBuilder(logger));
//    auto config = make_nvshared(builder->createBuilderConfig());
//    auto network = make_nvshared(builder->createNetworkV2(1));
//
//    // onnx解密并保存
//    //decry_onnx(onnx_path);
//    //onnx_path = "tmp_onnx.onnx"
//    // 通过onnxparser解析器解析的结果会填充到network中，类似addConv的方式添加进去
//    auto parser = make_nvshared(nvonnxparser::createParser(*network, logger));
//    if (!parser->parseFromFile(onnx_path, 1)) {
//        printf("Failed to parse your model.onnx\n");
//        // 注意这里的几个指针还没有释放，是有内存泄漏的，后面考虑更优雅的解决
//        return false;
//    }
//
//    int maxBatchSize = 10;
//    printf("Workspace Size = %.2f MB\n", (1 << 28) / 1024.0f / 1024.0f);
//    config->setMaxWorkspaceSize(1 << 28);
//
//    // 如果模型有多个输入，则必须多个profile
//    auto profile = builder->createOptimizationProfile();
//    auto input_tensor = network->getInput(0);
//    auto input_dims = input_tensor->getDimensions();
//
//    // 配置最小、最优、最大范围
//    input_dims.d[0] = 1;
//    profile->setDimensions(input_tensor->getName(), nvinfer1::OptProfileSelector::kMIN, input_dims);
//    profile->setDimensions(input_tensor->getName(), nvinfer1::OptProfileSelector::kOPT, input_dims);
//    input_dims.d[0] = maxBatchSize;
//    profile->setDimensions(input_tensor->getName(), nvinfer1::OptProfileSelector::kMAX, input_dims);
//    config->addOptimizationProfile(profile);
//    // 设置fp16精度！！！！
//    /*if (builder->platformHasFastFp16()) {
//        config->setFlag(nvinfer1::BuilderFlag::kFP16);
//    }*/
//    auto engine = make_nvshared(builder->buildEngineWithConfig(*network, *config));
//    if (engine == nullptr) {
//        printf("Build engine failed.\n");
//        return false;
//    }
//
//    // 将模型序列化，并储存为文件
//    string tmp_path = "tmp_2_del.trtmodel";
//    auto model_data = make_nvshared(engine->serialize());
//    FILE* f = fopen(tmp_path.c_str(), "wb");
//    fwrite(model_data->data(), 1, model_data->size(), f);
//    fclose(f);
//    if (0) {
//        initKV();
//        encrypt_file(tmp_path, trt_save_path, "");
//    }
//    // 卸载顺序按照构建顺序倒序
//    _CSTD remove(tmp_path.c_str());
//    printf("Done.\n");
//    return true;
//}
//
//vector<unsigned char> Classification::load_file(const string& file) {
//    //-----------------------------------------------------------------------------
//    string file_tmp = file;
//    if (0) {
//        initKV();
//        file_tmp = "decrypt_file";
//        decrypt_file(file, file_tmp);
//    }
//    ifstream in(file_tmp, ios::in | ios::binary);
//    if (!in.is_open())
//        return {};
//
//    in.seekg(0, ios::end);
//    size_t length = in.tellg();
//
//    std::vector<uint8_t> data;
//    if (length > 0) {
//        in.seekg(0, ios::beg);
//        data.resize(length);
//
//        in.read((char*)&data[0], length);
//    }
//    in.close();
//    return data;
//}
//
//vector<string> Classification::load_labels(const char* file) {
//    vector<string> lines;
//
//    ifstream in(file, ios::in | ios::binary);
//    if (!in.is_open()) {
//        printf("open %d failed.\n", file);
//        return lines;
//    }
//
//    string line;
//    while (getline(in, line)) {
//        lines.push_back(line);
//    }
//    in.close();
//    return lines;
//}
//
//bool Classification::load_trt_model(const string& trt_path) {
//    TRTLogger logger;
//    auto engine_data = load_file(trt_path);  // 加载trt模型
//    auto runtime = make_nvshared(nvinfer1::createInferRuntime(logger));    // 创建一个iruntime实例，用iruntime的反序列化方法创建引擎engine
//    //initLibNvInferPlugins(&logger, "");
//    engine = make_nvshared(runtime->deserializeCudaEngine(engine_data.data(), engine_data.size()));   // 这里就是反序列化
//    checkRuntime(cudaStreamCreate(&m_stream));
//    execution_context = make_nvshared(engine->createExecutionContext());  // 创建上下文管理器，每一个engine都至少得有一个
//    if (engine == nullptr) {
//        printf("Deserialize cuda engine failed.\n");
//        runtime->destroy();
//        return false;
//    }
//    return true;
//}
//
//vector<float> Classification::inference(cv::Mat& image) {
//    // 对应于pytorch的代码部分
//    //auto image = cv::imread(img_path);
//    cv::resize(image, image, cv::Size(input_width, input_height));
//    int image_area = image.cols * image.rows;    // 一张图片所占的空间大小
//    unsigned char* pimage = image.data;
//    unsigned char* pimage1 = image.data;
//    unsigned char* pimage2 = image.data;
//    unsigned char* pimage3 = image.data;
//    float* phost_b = input_data_host + image_area * 0;      // 因为是3通道的，所以计算三个内存的首地址
//    float* phost_g = input_data_host + image_area * 1;
//    float* phost_r = input_data_host + image_area * 2;
//    for (int i = 0; i < image_area; ++i, pimage += 3) {    // 遍历图片每个位置的数据（是3维的）
//        // 注意这里的顺序rgb调换了
//        *phost_r++ = (pimage[0] / 255.0f - mean[0]) / std[0];
//        *phost_g++ = (pimage[1] / 255.0f - mean[1]) / std[1];
//        *phost_b++ = (pimage[2] / 255.0f - mean[2]) / std[2];
//    }
//    // 这里就是把host的数据放到cuda上
//    checkRuntime(cudaMemcpyAsync(input_data_device, input_data_host, input_numel * sizeof(float), cudaMemcpyHostToDevice, m_stream));
//
//    // 明确当前推理时，使用的数据输入大小
//    auto input_dims = execution_context->getBindingDimensions(0);   // Binding(节点)获取节点维度，这里0表示输入节点索引，1表示输出的
//    input_dims.d[0] = input_batch;
//
//    // 设置当前推理时，input大小
//    execution_context->setBindingDimensions(0, input_dims);   // 第0个索引也就是输入维度
//    float* bindings[] = { input_data_device, output_data_device };
//
//    bool success = execution_context->enqueueV2((void**)bindings, m_stream, nullptr);
//    checkRuntime(cudaMemcpyAsync(output_data_host, output_data_device, sizeof(output_data_host), cudaMemcpyDeviceToHost, m_stream));
//    checkRuntime(cudaStreamSynchronize(m_stream));
//
//    float* prob = output_data_host;
//    //cout << *prob << ", " << *(prob + 1) << endl;
//    int predict_label = std::max_element(prob, prob + num_classes) - prob;  // 确定预测类别的下标
//    //auto labels = load_labels("./model/label_ok_ng.txt");
//    //auto predict_name = labels[predict_label];
//    float confidence = prob[predict_label];    // 获得预测值的置信度
//    //printf("Predict: %s, confidence = %f, label = %d\n", predict_name.c_str(), confidence, predict_label);
//    return vector<float>{(float)predict_label, confidence};
//    //return vector<float>{(float)1.0, 1.0};
//}
//
//
///************************************** TensorRT 目标检测模型 ********************************************/
//const char* INPUT_BLOB_NAME = "input";
//const char* OUTPUT_BLOB_NAME = "output";
//#define CHECK(status) \
//    do\
//    {\
//        auto ret = (status);\
//        if (ret != 0)\
//        {\
//            std::cerr << "Cuda failure: " << ret << std::endl;\
//            abort();\
//        }\
//    } while (0)
//#define DEVICE 0  // GPU id
//
//cv::Mat ObjectDetection::static_resize(cv::Mat& img) {
//
//    float r = std::min(INPUT_W / (img.cols * 1.0), INPUT_H / (img.rows * 1.0)); //找出长宽缩放比例中最小的
//    // r = std::min(r, 1.0f);
//    int unpad_w = r * img.cols;  // 原图乘以缩放因子进行缩放
//    int unpad_h = r * img.rows;
//    cv::Mat re(unpad_h, unpad_w, CV_8UC3); // 声明一张缩放后大小的图片
//    cv::resize(img, re, re.size()); //resize
//    cv::Mat out(INPUT_H, INPUT_W, CV_8UC3, cv::Scalar(114, 114, 114)); //将图片置灰
//    re.copyTo(out(cv::Rect(0, 0, re.cols, re.rows))); // 复制
//    return out;
//}
//
//float* blobFromImage(cv::Mat& img) {
//   /* cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
//
//    float* blob = new float[img.total() * 3];
//    int channels = 3;
//    int img_h = img.rows;
//    int img_w = img.cols;
//    std::vector<float> mean = { 0.485, 0.456, 0.406 };
//    std::vector<float> std = { 0.229, 0.224, 0.225 };
//    for (size_t c = 0; c < channels; c++)
//    {
//        for (size_t h = 0; h < img_h; h++)
//        {
//            for (size_t w = 0; w < img_w; w++)
//            {
//                blob[c * img_w * img_h + h * img_w + w] =
//                    (((float)img.at<cv::Vec3b>(h, w)[c]) / 255.0f - mean[c]) / std[c];
//            }
//        }
//    }*/
//    
//
//    ///2
//    float* blob = new float[img.total() * 3 * 1];
//    std::vector<float> mean = { 0.485, 0.456, 0.406 };
//    std::vector<float> std = { 0.229, 0.224, 0.225 };
//    int image_area = img.rows * img.cols;    // 一张图片所占的空间大小
//    unsigned char* pimage = img.data;
//    float* phost_b = blob + image_area * 0;      // 因为是3通道的，所以计算三个内存的首地址
//    float* phost_g = blob + image_area * 1;
//    float* phost_r = blob + image_area * 2;
//    for (int i = 0; i < image_area; ++i, pimage += 3) {    // 遍历图片每个位置的数据（是3维的）
//        // 注意这里的顺序rgb调换了
//        *phost_r++ = (pimage[0] / 255.0f - mean[0]) / std[0];
//        *phost_g++ = (pimage[1] / 255.0f - mean[1]) / std[1];
//        *phost_b++ = (pimage[2] / 255.0f - mean[2]) / std[2];
//    }
//
//    /*cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
//    float* blob = new float[img.total() * 3 * 1];
//    //int single_image_size = img.total() * 3;
//    int channels = 3;
//    int img_h = img.rows;
//    int img_w = img.cols;
//    std::vector<float> mean = { 0.485, 0.456, 0.406 };
//    std::vector<float> std = { 0.229, 0.224, 0.225 };
//    uchar* img_ptr = img.data;
//    float* blob_ptr = blob;
//    for (int c = 0; c < channels; ++c) {
//        float mean_val = mean[c];
//        float std_val = std[c];
//        for (int h = 0; h < img_h; ++h) {
//            for (int w = 0; w < img_w; ++w) {
//                *blob_ptr = (((float)(*img_ptr)) / 255.0f - mean_val) / std_val;
//                ++blob_ptr;
//                ++img_ptr;
//            }
//        }
//    }*/
//
//    return blob;
//}
//
//struct GridAndStride
//{
//    int grid0;
//    int grid1;
//    int stride;
//};
//
////static void generate_grids_and_stride(const int target_size, std::vector<int>& strides, std::vector<GridAndStride>& grid_strides)
////{
////    GridAndStride temp;
////    for (auto stride : strides)
////    {
////        int num_grid = target_size / stride;
////        for (int g1 = 0; g1 < num_grid; g1++)
////        {
////            for (int g0 = 0; g0 < num_grid; g0++)
////            {
////                temp.grid0 = g0;
////                temp.grid1 = g1;
////                temp.stride = stride;
////                grid_strides.push_back(temp);
////            }
////        }
////    }
////}
//
//static void generate_grids_and_stride(const int INPUT_W, const int INPUT_H, std::vector<int>& strides, std::vector<GridAndStride>& grid_strides)
//{
//    GridAndStride temp;
//    for (auto stride : strides)
//    {
//        int num_grid_y = INPUT_H / stride;
//        int num_grid_x = INPUT_W / stride;
//        for (int g1 = 0; g1 < num_grid_y; g1++)
//        {
//            for (int g0 = 0; g0 < num_grid_x; g0++)
//            {
//                temp.grid0 = g0;
//                temp.grid1 = g1;
//                temp.stride = stride;
//                grid_strides.push_back(temp);
//            }
//        }
//    }
//}
//static inline float intersection_area(const ObjectDetection::Object& a, const ObjectDetection::Object& b)
//{
//    cv::Rect_<float> inter = a.rect & b.rect;
//    return inter.area();
//}
//
//static void qsort_descent_inplace(std::vector<ObjectDetection::Object>& faceobjects, int left, int right)
//{
//    int i = left;
//    int j = right;
//    float p = faceobjects[(left + right) / 2].prob;
//
//    while (i <= j)
//    {
//        while (faceobjects[i].prob > p)
//            i++;
//
//        while (faceobjects[j].prob < p)
//            j--;
//
//        if (i <= j)
//        {
//            // swap
//            std::swap(faceobjects[i], faceobjects[j]);
//
//            i++;
//            j--;
//        }
//    }
//
//#pragma omp parallel sections
//    {
//#pragma omp section
//        {            if (left < j) qsort_descent_inplace(faceobjects, left, j);
//        }
//#pragma omp section
//        {
//            if (i < right) qsort_descent_inplace(faceobjects, i, right);
//        }
//    }
//}
//
//static void qsort_descent_inplace(std::vector<ObjectDetection::Object>& objects)
//{
//    if (objects.empty())
//        return;
//
//    qsort_descent_inplace(objects, 0, objects.size() - 1);
//}
//
//static void nms_sorted_bboxes(const std::vector<ObjectDetection::Object>& faceobjects, std::vector<int>& picked, float nms_threshold)
//{
//    picked.clear();
//
//    const int n = faceobjects.size();
//
//    std::vector<float> areas(n);
//    for (int i = 0; i < n; i++)
//    {
//        areas[i] = faceobjects[i].rect.area();
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        const ObjectDetection::Object& a = faceobjects[i];
//
//        int keep = 1;
//        for (int j = 0; j < (int)picked.size(); j++)
//        {
//            const ObjectDetection::Object& b = faceobjects[picked[j]];
//
//            // intersection over union
//            float inter_area = intersection_area(a, b);
//            float union_area = areas[i] + areas[picked[j]] - inter_area;
//            // float IoU = inter_area / union_area
//            if (inter_area / union_area > nms_threshold)
//                keep = 0;
//        }
//
//        if (keep)
//            picked.push_back(i);
//    }
//}
//
//static void generate_yolox_proposals(std::vector<GridAndStride> grid_strides, float* feat_blob, vector<float> prob_threshold, std::vector<ObjectDetection::Object>& objects, const int num_class)
//{
//    //const int num_class = 1;
//
//    const int num_anchors = grid_strides.size();
//
//    for (int anchor_idx = 0; anchor_idx < num_anchors; anchor_idx++)
//    {
//        const int grid0 = grid_strides[anchor_idx].grid0;
//        const int grid1 = grid_strides[anchor_idx].grid1;
//        const int stride = grid_strides[anchor_idx].stride;
//
//        const int basic_pos = anchor_idx * (num_class + 5);
//
//        // yolox/models/yolo_head.py decode logic
//        float x_center = (feat_blob[basic_pos + 0] + grid0) * stride;
//        float y_center = (feat_blob[basic_pos + 1] + grid1) * stride;
//        float w = exp(feat_blob[basic_pos + 2]) * stride;
//        float h = exp(feat_blob[basic_pos + 3]) * stride;
//        float x0 = x_center - w * 0.5f;
//        float y0 = y_center - h * 0.5f;
//
//        float box_objectness = feat_blob[basic_pos + 4];
//        for (int class_idx = 0; class_idx < num_class; class_idx++)
//        {
//            float box_cls_score = feat_blob[basic_pos + 5 + class_idx];
//            float box_prob = box_objectness * box_cls_score;
//            // 置信度阈值暂时使用两个，支持二分类，如果有第三个类别则多余的类别以第一个类别的为准
//            float confidence_thre = class_idx < 2 ? prob_threshold[class_idx] : prob_threshold[0];
//            if (box_prob > confidence_thre) {
//                ObjectDetection::Object obj;
//                obj.rect.x = x0;
//                obj.rect.y = y0;
//                obj.rect.width = w;
//                obj.rect.height = h;
//                obj.label = class_idx;
//                obj.prob = box_prob;
//
//                objects.push_back(obj);
//            }
//
//        } // class loop
//
//    } // point anchor loop
//}
//
//void ObjectDetection::decode_outputs(float* prob, std::vector<Object>& objects, float scale, const int img_w, const int img_h) {
//    std::vector<Object> proposals;
//    std::vector<int> strides = { 8, 16, 32 };
//    std::vector<GridAndStride> grid_strides;
//    generate_grids_and_stride(INPUT_W, INPUT_H, strides, grid_strides);
//    generate_yolox_proposals(grid_strides, prob, BBOX_CONF_THRESH, proposals, OBJ_NUM_CLASSES);
//    std::cout << "num of boxes before nms: " << proposals.size() << std::endl;
//
//    qsort_descent_inplace(proposals);
//
//    std::vector<int> picked;
//    nms_sorted_bboxes(proposals, picked, NMS_THRESH);
//
//
//    int count = picked.size();
//    std::cout << "num of boxes: " << count << std::endl;
//
//    objects.resize(count);
//    for (int i = 0; i < count; i++)
//    {
//        objects[i] = proposals[picked[i]];
//
//        // adjust offset to original unpadded
//        float x0 = (objects[i].rect.x) / scale;
//        float y0 = (objects[i].rect.y) / scale;
//        float x1 = (objects[i].rect.x + objects[i].rect.width) / scale;
//        float y1 = (objects[i].rect.y + objects[i].rect.height) / scale;
//
//        // clip
//        x0 = std::max(std::min(x0, (float)(img_w - 1)), 0.f);
//        y0 = std::max(std::min(y0, (float)(img_h - 1)), 0.f);
//        x1 = std::max(std::min(x1, (float)(img_w - 1)), 0.f);
//        y1 = std::max(std::min(y1, (float)(img_h - 1)), 0.f);
//
//        objects[i].rect.x = x0;
//        objects[i].rect.y = y0;
//        objects[i].rect.width = x1 - x0;
//        objects[i].rect.height = y1 - y0;
//    }
//}
//
//const float color_list[80][3] =
//{
//    {0.000, 0.447, 0.741},
//    {0.850, 0.325, 0.098},
//    {0.929, 0.694, 0.125},
//    {0.494, 0.184, 0.556},
//    {0.466, 0.674, 0.188},
//    {0.301, 0.745, 0.933},
//    {0.635, 0.078, 0.184},
//    {0.300, 0.300, 0.300},
//    {0.600, 0.600, 0.600},
//    {1.000, 0.000, 0.000},
//    {1.000, 0.500, 0.000},
//    {0.749, 0.749, 0.000},
//    {0.000, 1.000, 0.000},
//    {0.000, 0.000, 1.000},
//    {0.667, 0.000, 1.000},
//    {0.333, 0.333, 0.000},
//    {0.333, 0.667, 0.000},
//    {0.333, 1.000, 0.000},
//    {0.667, 0.333, 0.000},
//    {0.667, 0.667, 0.000},
//    {0.667, 1.000, 0.000},
//    {1.000, 0.333, 0.000},
//    {1.000, 0.667, 0.000},
//    {1.000, 1.000, 0.000},
//    {0.000, 0.333, 0.500},
//    {0.000, 0.667, 0.500},
//    {0.000, 1.000, 0.500},
//    {0.333, 0.000, 0.500},
//    {0.333, 0.333, 0.500},
//    {0.333, 0.667, 0.500},
//    {0.333, 1.000, 0.500},
//    {0.667, 0.000, 0.500},
//    {0.667, 0.333, 0.500},
//    {0.667, 0.667, 0.500},
//    {0.667, 1.000, 0.500},
//    {1.000, 0.000, 0.500},
//    {1.000, 0.333, 0.500},
//    {1.000, 0.667, 0.500},
//    {1.000, 1.000, 0.500},
//    {0.000, 0.333, 1.000},
//    {0.000, 0.667, 1.000},
//    {0.000, 1.000, 1.000},
//    {0.333, 0.000, 1.000},
//    {0.333, 0.333, 1.000},
//    {0.333, 0.667, 1.000},
//    {0.333, 1.000, 1.000},
//    {0.667, 0.000, 1.000},
//    {0.667, 0.333, 1.000},
//    {0.667, 0.667, 1.000},
//    {0.667, 1.000, 1.000},
//    {1.000, 0.000, 1.000},
//    {1.000, 0.333, 1.000},
//    {1.000, 0.667, 1.000},
//    {0.333, 0.000, 0.000},
//    {0.500, 0.000, 0.000},
//    {0.667, 0.000, 0.000},
//    {0.833, 0.000, 0.000},
//    {1.000, 0.000, 0.000},
//    {0.000, 0.167, 0.000},
//    {0.000, 0.333, 0.000},
//    {0.000, 0.500, 0.000},
//    {0.000, 0.667, 0.000},
//    {0.000, 0.833, 0.000},
//    {0.000, 1.000, 0.000},
//    {0.000, 0.000, 0.167},
//    {0.000, 0.000, 0.333},
//    {0.000, 0.000, 0.500},
//    {0.000, 0.000, 0.667},
//    {0.000, 0.000, 0.833},
//    {0.000, 0.000, 1.000},
//    {0.000, 0.000, 0.000},
//    {0.143, 0.143, 0.143},
//    {0.286, 0.286, 0.286},
//    {0.429, 0.429, 0.429},
//    {0.571, 0.571, 0.571},
//    {0.714, 0.714, 0.714},
//    {0.857, 0.857, 0.857},
//    {0.000, 0.447, 0.741},
//    {0.314, 0.717, 0.741},
//    {0.50, 0.5, 0}
//};
//
//static cv::Mat draw_objects(const cv::Mat& bgr, const std::vector<ObjectDetection::Object>& objects)
//{
//    static const char* class_names[] = {
//        "ng"
//    };
//
//    cv::Mat image = bgr.clone();
//
//    for (size_t i = 0; i < objects.size(); i++)
//    {
//        const ObjectDetection::Object& obj = objects[i];
//
//        fprintf(stderr, "%d = %.5f at %.2f %.2f %.2f x %.2f\n", obj.label, obj.prob,
//            obj.rect.x, obj.rect.y, obj.rect.width, obj.rect.height);
//
//        //cv::Scalar color = cv::Scalar(color_list[obj.label][0], color_list[obj.label][1], color_list[obj.label][2]);
//        cv::Scalar color = cv::Scalar(0, 0, 1);
//        float c_mean = cv::mean(color)[0];
//        cv::Scalar txt_color;
//        if (c_mean > 0.5) {
//            txt_color = cv::Scalar(0, 0, 0);
//        }
//        else {
//            txt_color = cv::Scalar(255, 255, 255);
//        }
//
//        cv::rectangle(image, obj.rect, color * 255, 2);
//
//        char text[256];
//        sprintf_s(text, "%s %.1f%%", class_names[obj.label], obj.prob * 100);
//
//        int baseLine = 0;
//        cv::Size label_size = cv::getTextSize(text, cv::FONT_HERSHEY_SIMPLEX, 0.4, 1, &baseLine);
//
//        cv::Scalar txt_bk_color = color * 0.7 * 255;
//
//        int x = obj.rect.x;
//        int y = obj.rect.y + 1;
//        //int y = obj.rect.y - label_size.height - baseLine;
//        if (y > image.rows)
//            y = image.rows;
//        //if (x + label_size.width > image.cols)
//            //x = image.cols - label_size.width;
//        
//        /*cv::rectangle(image, cv::Rect(cv::Point(x, y), cv::Size(label_size.width, label_size.height + baseLine)),
//            txt_bk_color, -1);
//
//        cv::putText(image, text, cv::Point(x, y + label_size.height),
//            cv::FONT_HERSHEY_SIMPLEX, 0.4, txt_color, 1);*/
//    }
//
//    cv::imwrite("det_res.jpg", image);
//    fprintf(stderr, "save vis file\n");
//    /* cv::imshow("image", image); */
//    /* cv::waitKey(0); */
//    return image;
//}
//
//ObjectDetection::ObjectDetection()
//{
//    OBJ_NUM_CLASSES = 1;
//    /*NMS_THRESH = 0.25;
//    BBOX_CONF_THRESH = 0.1;*/
//    this->infer_cost = 0;
//}
//
//ObjectDetection::~ObjectDetection()
//{
//   // delete this->prob;
//    //engine->destroy();
//    //context->destroy();
//}
//
//bool ObjectDetection::build_trt_model(const char* onnx_path, const char* trt_save_path)
//{
//
//    if (exists(trt_save_path)) {
//        std::cout << trt_save_path << "has exists." << std::endl;
//        return true;
//    }
//    //TRTLogger logger;
//
//    // 这是基本需要的组件
//    auto builder = nvinfer1::createInferBuilder(logger);
//    auto config = builder->createBuilderConfig();
//    auto network = builder->createNetworkV2(1);
//
//    decry_onnx(onnx_path);
//    onnx_path = "tmp_onnx.onnx";
//    // 通过onnxparser解析器解析的结果会填充到network中，类似addConv的方式添加进去
//    auto parser = nvonnxparser::createParser(*network, logger);
//    if (!parser->parseFromFile(onnx_path, 1)) {
//        printf("Failed to parse your model.onnx\n");
//
//        // 注意这里的几个指针还没有释放，是有内存泄漏的，后面考虑更优雅的解决
//        return false;
//    }
//    // 设置fp16精度！！！！
//    /*if (builder->platformHasFastFp16()) {
//        config->setFlag(nvinfer1::BuilderFlag::kFP16);
//    }*/
//    int maxBatchSize = 1;
//    printf("Workspace Size = %.2f MB\n", (1 << 28) / 1024.0f / 1024.0f);
//    config->setMaxWorkspaceSize(1 << 28);
//
//    // 如果模型有多个输入，则必须多个profile
//    auto profile = builder->createOptimizationProfile();
//    auto input_tensor = network->getInput(0);
//    auto input_dims = input_tensor->getDimensions();
//
//    engine = builder->buildEngineWithConfig(*network, *config);
//    //engine_temp = engine;
//    if (engine == nullptr) {
//        printf("Build engine failed.\n");
//        return false;
//    }
//
//    // 将模型序列化，并储存为文件
//    string tmp_path = "tmp_2_del.trtmodel";
//    auto model_data = engine->serialize();
//    FILE* f = fopen(tmp_path.c_str(), "wb");
//    fwrite(model_data->data(), 1, model_data->size(), f);
//    fclose(f);
//    if (1) {
//        initKV();
//        encrypt_file(tmp_path, trt_save_path, onnx_path);
//    }
//    // 卸载顺序按照构建顺序倒序
//    _CSTD remove(tmp_path.c_str());
//    printf("Done.\n");
//    return true;
//
//}
//
//bool ObjectDetection::load_trt_model(const std::string& trt_path, string model_flag){
//    string file_tmp = trt_path;
//    if (1) {
//        initKV();
//        file_tmp = "decrypt_file_2_del" + model_flag;
//        decrypt_file(trt_path, file_tmp);
//    } 
//    TRTLogger tmpLogger;
//    
//    cudaSetDevice(DEVICE);
//
//    // create a model using the API directly and serialize it to a stream
//    char* trtModelStream{ nullptr };
//    size_t size{ 0 };
//
//    std::ifstream file(file_tmp, std::ios::binary);
//    //读取engine文件检测是否符合
//    if (file.good()) {
//        file.seekg(0, file.end);
//        size = file.tellg();
//        file.seekg(0, file.beg);
//        trtModelStream = new char[size];
//        assert(trtModelStream);
//        file.read(trtModelStream, size);
//        file.close();
//    }
//    _CSTD remove(file_tmp.c_str());
//    bool didInitPlugins = initLibNvInferPlugins(nullptr, "");
//    auto runtime = nvinfer1::createInferRuntime(logger);
//    assert(runtime != nullptr);
//    engine = runtime->deserializeCudaEngine(trtModelStream, size);
//    assert(engine != nullptr);
//    context = engine->createExecutionContext();
//    assert(context != nullptr);
//    //delete[] trtModelStream;
//    // 推理前初始化。。。
//    auto out_dims = engine->getBindingDimensions(1);
//    output_size = 1;
//    for (int j = 0; j < out_dims.nbDims; j++) {
//        output_size *= out_dims.d[j];
//    }
//    OBJ_NUM_CLASSES = out_dims.d[2] - 5;
//   // static float* prob_local = new float[output_size];
//    this->prob = new float[output_size];///prob_local;
//    return true;
//}
//
//void ObjectDetection::doInference(nvinfer1::IExecutionContext& context, float* input, float* output, const int output_size, cv::Size input_shape) {
//    const nvinfer1::ICudaEngine& engine = context.getEngine();
//
//    // Pointers to input and output device buffers to pass to engine.
//    // Engine requires exactly IEngine::getNbBindings() number of buffers.
//    assert(engine.getNbBindings() == 2);
//    void* buffers[2];
//
//    // In order to bind the buffers, we need to know the names of the input and output tensors.
//    // Note that indices are guaranteed to be less than IEngine::getNbBindings()
//    const int inputIndex = engine.getBindingIndex(INPUT_BLOB_NAME);
//
//    assert(engine.getBindingDataType(inputIndex) == nvinfer1::DataType::kFLOAT);
//    const int outputIndex = engine.getBindingIndex(OUTPUT_BLOB_NAME);
//    assert(engine.getBindingDataType(outputIndex) == nvinfer1::DataType::kFLOAT);
//    int mBatchSize = engine.getMaxBatchSize();
//
//    // Create GPU buffers on device
//    CHECK(cudaMalloc(&buffers[inputIndex], 3 * input_shape.height * input_shape.width * sizeof(float)));
//    CHECK(cudaMalloc(&buffers[outputIndex], output_size * sizeof(float)));
//
//    // Create stream
//    cudaStream_t stream;
//    CHECK(cudaStreamCreate(&stream));
//
//    // DMA input batch data to device, infer on the batch asynchronously, and DMA output back to host
//    CHECK(cudaMemcpyAsync(buffers[inputIndex], input, 3 * input_shape.height * input_shape.width * sizeof(float), cudaMemcpyHostToDevice, stream));
//    context.enqueue(1, buffers, stream, nullptr);
//    CHECK(cudaMemcpyAsync(output, buffers[outputIndex], output_size * sizeof(float), cudaMemcpyDeviceToHost, stream));
//    cudaStreamSynchronize(stream);
//
//    // Release stream and buffers
//    cudaStreamDestroy(stream);
//    CHECK(cudaFree(buffers[inputIndex]));
//    CHECK(cudaFree(buffers[outputIndex]));
//}
//
//unordered_map<int, vector<cv::Rect>> ObjectDetection::inference(cv::Mat& img)
//{
//
//    TRTLogger gLogger;
//    cudaSetDevice(DEVICE);
//
//    //读图并进行resize处理
//    int img_w = img.cols;
//    int img_h = img.rows;
//    cv::Mat pr_img = static_resize(img);
//    //std::cout << "blob image" << std::endl;
//    // 对图片进行正则化处理
//    float* blob;
//    blob = blobFromImage(pr_img);
//    //std::cout << "blob是" << blob << std::endl;
//
//    float scale = std::min(INPUT_W / (img.cols * 1.0), INPUT_H / (img.rows * 1.0));//读取最小缩放比例
//    // run inference
//    //auto start = std::chrono::system_clock::now();
//    doInference(*context, blob, prob, output_size, pr_img.size());
//    auto end = std::chrono::system_clock::now();
//    //std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
//    //infer_cost = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
//    std::vector<Object> objects;
//    decode_outputs(prob, objects, scale, img_w, img_h);
//    //vector<cv::Rect> result_rect_vec;
//    //for (auto& o : objects) {
//    //    //result_rect_vec.push_back(o.rect);
//    //    if (o.rect.width < img_w && 0 <= o.rect.width && 0 < o.rect.height && o.rect.height <= img_h) {
//    //        result_rect_vec.push_back(o.rect);
//    //    }
//    //}
//    std::unordered_map<int, vector<cv::Rect>> result_obj_map;
//    for (auto& o : objects) {
//        if (o.rect.width < img_w && 0 < o.rect.width && 0 < o.rect.height && o.rect.height < img_h) {
//            result_obj_map[o.label].push_back(o.rect);
//        }
//    }
//    //cv::Mat& result_img = draw_objects(img, objects);
//    delete blob;
//
//    return result_obj_map;
//}
