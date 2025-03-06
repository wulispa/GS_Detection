#include "pch.h"
#include"yolo.h"

yolo::YOLO::YOLO()
{
    ////dl_utils::InitParameter param;
    //// input
    //m_input_src_device = nullptr;
    //m_input_resize_device = nullptr;
    //m_input_rgb_device = nullptr;
    //m_input_norm_device = nullptr;
    //m_input_hwc_device = nullptr;
    ////checkRuntime(cudaMalloc(&m_input_src_device,    param.batch_size * 3 * param.src_h * param.src_w * sizeof(float)));
    //int batch_size = 1, topK = 1000;
    //int src_h = 1456;
    //int src_w = 1088;
    //int dst_h = 480;
    //int dst_w = 480;

    //checkRuntime(cudaMalloc(&m_input_src_device, batch_size * 3 * src_h * src_w * sizeof(unsigned char)));
    //checkRuntime(cudaMalloc(&m_input_resize_device, batch_size * 3 * dst_h * dst_w * sizeof(float)));
    //checkRuntime(cudaMalloc(&m_input_rgb_device, batch_size * 3 * dst_h * dst_w * sizeof(float)));
    //checkRuntime(cudaMalloc(&m_input_norm_device, batch_size * 3 * dst_h * dst_w * sizeof(float)));
    //checkRuntime(cudaMalloc(&m_input_hwc_device, batch_size * 3 * dst_h * dst_w * sizeof(float)));

    //// output
    //m_output_src_device = nullptr;
    //m_output_objects_device = nullptr;
    //m_output_objects_host = nullptr;
    //m_output_objects_width = 7;
    //m_output_idx_device = nullptr;
    //m_output_conf_device = nullptr;

    //int output_objects_size = batch_size * (1 + topK * m_output_objects_width); // 1: count
    ////int output_objects_size = param.batch_size * (0 + 6720 * m_output_objects_width); // 1: count
    //checkRuntime(cudaMalloc(&m_output_objects_device, output_objects_size * sizeof(float)));
    //checkRuntime(cudaMalloc(&m_output_idx_device, batch_size * topK * sizeof(int)));
    //checkRuntime(cudaMalloc(&m_output_conf_device, batch_size * topK * sizeof(float)));
    //m_output_objects_host = new float[output_objects_size];

    //m_objectss.resize(batch_size);

}

yolo::YOLO::YOLO(const dl_utils::InitParameter& param) : m_param(param)
{
    // input
    m_input_src_device = nullptr;
    m_input_resize_device = nullptr;
    m_input_rgb_device = nullptr;
    m_input_norm_device = nullptr;
    m_input_hwc_device = nullptr;
    //checkRuntime(cudaMalloc(&m_input_src_device,    param.batch_size * 3 * param.src_h * param.src_w * sizeof(float)));
    checkRuntime(cudaMalloc(&m_input_src_device,    param.batch_size * 3 * param.src_h * param.src_w * sizeof(unsigned char)));
    checkRuntime(cudaMalloc(&m_input_resize_device, param.batch_size * 3 * param.dst_h * param.dst_w * sizeof(float)));
    checkRuntime(cudaMalloc(&m_input_rgb_device,    param.batch_size * 3 * param.dst_h * param.dst_w * sizeof(float)));
    checkRuntime(cudaMalloc(&m_input_norm_device,   param.batch_size * 3 * param.dst_h * param.dst_w * sizeof(float)));
    checkRuntime(cudaMalloc(&m_input_hwc_device,    param.batch_size * 3 * param.dst_h * param.dst_w * sizeof(float)));

    // output
    m_output_src_device = nullptr;
    m_output_objects_device = nullptr;
    m_output_objects_host = nullptr;
    m_output_objects_width = 7;
    m_output_idx_device = nullptr;
    m_output_conf_device = nullptr;

    int output_objects_size = param.batch_size * (1 + param.topK * m_output_objects_width); // 1: count
    //int output_objects_size = param.batch_size * (0 + 6720 * m_output_objects_width); // 1: count
    checkRuntime(cudaMalloc(&m_output_objects_device, output_objects_size * sizeof(float)));
    checkRuntime(cudaMalloc(&m_output_idx_device, m_param.batch_size * m_param.topK * sizeof(int)));
    checkRuntime(cudaMalloc(&m_output_conf_device, m_param.batch_size * m_param.topK * sizeof(float)));
    m_output_objects_host = new float[output_objects_size];

    m_objectss.resize(param.batch_size);
}

yolo::YOLO::~YOLO()
{
    // input
    checkRuntime(cudaFree(m_input_src_device));
    checkRuntime(cudaFree(m_input_resize_device));
    checkRuntime(cudaFree(m_input_rgb_device));
    checkRuntime(cudaFree(m_input_norm_device));
    checkRuntime(cudaFree(m_input_hwc_device));
    // output
    checkRuntime(cudaFree(m_output_src_device));
    checkRuntime(cudaFree(m_output_objects_device));
    checkRuntime(cudaFree(m_output_idx_device));
    checkRuntime(cudaFree(m_output_conf_device));
    delete[] m_output_objects_host;
}

bool yolo::YOLO::init(const std::vector<unsigned char>& trtFile)
{
    //// 1. init engine & context
    //if (trtFile.empty())
    //{
    //    return false;
    //}
    //// runtime
    //std::unique_ptr<nvinfer1::IRuntime> runtime =
    //    std::unique_ptr<nvinfer1::IRuntime>(nvinfer1::createInferRuntime(sample::gmyLogger.getTRTmyLogger()));
    //if (runtime == nullptr)
    //{
    //    return false;
    //}
    //// deserializeCudaEngine
    //this->m_engine = std::unique_ptr<nvinfer1::ICudaEngine>(runtime->deserializeCudaEngine(trtFile.data(), trtFile.size()));

    //if (this->m_engine == nullptr)
    //{
    //    return false;
    //}
    //// context
    //this->m_context = std::unique_ptr<nvinfer1::IExecutionContext>(this->m_engine->createExecutionContext());
    //if (this->m_context == nullptr)
    //{
    //    return false;
    //}
    //// binding dim
    //if (m_param.dynamic_batch) // for some models only support static mutil-batch. eg: yolox
    //{
    //    this->m_context->setBindingDimensions(0, nvinfer1::Dims4(m_param.batch_size, 3, m_param.dst_h, m_param.dst_w));
    //}
    //
    //// 2. get output's dim
    //m_output_dims = this->m_context->getBindingDimensions(1);
    //m_total_objects = m_output_dims.d[1];
    //assert(m_param.batch_size <= m_output_dims.d[0]);
    //m_output_area = 1; // 22500 * 85
    //for (int i = 1; i < m_output_dims.nbDims; i++)
    //{
    //    if (m_output_dims.d[i] != 0)
    //    {
    //        m_output_area *= m_output_dims.d[i];
    //    }
    //}
    //// 3. malloc
    //checkRuntime(cudaMalloc(&m_output_src_device, m_param.batch_size * m_output_area * sizeof(float)));

    //// 4. cal affine matrix
    //float a = float(m_param.dst_h) / m_param.src_h;
    //float b = float(m_param.dst_w) / m_param.src_w;
    //float scale = a < b ? a : b;
    //cv::Mat src2dst = (cv::Mat_<float>(2, 3) << scale, 0.f, (-scale * m_param.src_w + m_param.dst_w + scale - 1) * 0.5,
    //    0.f, scale, (-scale * m_param.src_h + m_param.dst_h + scale - 1) * 0.5);
    //cv::Mat dst2src = cv::Mat::zeros(2, 3, CV_32FC1);
    //cv::invertAffineTransform(src2dst, dst2src);

    //m_dst2src.v0 = dst2src.ptr<float>(0)[0];
    //m_dst2src.v1 = dst2src.ptr<float>(0)[1];
    //m_dst2src.v2 = dst2src.ptr<float>(0)[2];
    //m_dst2src.v3 = dst2src.ptr<float>(1)[0];
    //m_dst2src.v4 = dst2src.ptr<float>(1)[1];
    //m_dst2src.v5 = dst2src.ptr<float>(1)[2];

    return true;
}


bool yolo::YOLO::init(const std::vector<unsigned char>& trtFile, const dl_utils::InitParameter& param)
{
    //m_input_src_device = nullptr;
    //m_input_resize_device = nullptr;
    //m_input_rgb_device = nullptr;
    //m_input_norm_device = nullptr;
    //m_input_hwc_device = nullptr;
    ////checkRuntime(cudaMalloc(&m_input_src_device,    param.batch_size * 3 * param.src_h * param.src_w * sizeof(float)));
    //checkRuntime(cudaMalloc(&m_input_src_device, param.batch_size * 3 * param.src_h * param.src_w * sizeof(unsigned char)));
    //checkRuntime(cudaMalloc(&m_input_resize_device, param.batch_size * 3 * param.dst_h * param.dst_w * sizeof(float)));
    //checkRuntime(cudaMalloc(&m_input_rgb_device, param.batch_size * 3 * param.dst_h * param.dst_w * sizeof(float)));
    //checkRuntime(cudaMalloc(&m_input_norm_device, param.batch_size * 3 * param.dst_h * param.dst_w * sizeof(float)));
    //checkRuntime(cudaMalloc(&m_input_hwc_device, param.batch_size * 3 * param.dst_h * param.dst_w * sizeof(float)));

    //// output
    //m_output_src_device = nullptr;
    //m_output_objects_device = nullptr;
    //m_output_objects_host = nullptr;
    //m_output_objects_width = 7;
    //m_output_idx_device = nullptr;
    //m_output_conf_device = nullptr;

    //int output_objects_size = param.batch_size * (1 + param.topK * m_output_objects_width); // 1: count
    ////int output_objects_size = param.batch_size * (0 + 6720 * m_output_objects_width); // 1: count
    //checkRuntime(cudaMalloc(&m_output_objects_device, output_objects_size * sizeof(float)));
    //checkRuntime(cudaMalloc(&m_output_idx_device, param.batch_size * param.topK * sizeof(int)));
    //checkRuntime(cudaMalloc(&m_output_conf_device, param.batch_size * param.topK * sizeof(float)));
    //m_output_objects_host = new float[output_objects_size];

    //m_objectss.resize(param.batch_size);

    //// 1. init engine & context
    //if (trtFile.empty())
    //{
    //    return false;
    //}
    //// runtime
    //std::unique_ptr<nvinfer1::IRuntime> runtime =
    //    std::unique_ptr<nvinfer1::IRuntime>(nvinfer1::createInferRuntime(sample::gmyLogger.getTRTmyLogger()));
    //if (runtime == nullptr)
    //{
    //    return false;
    //}
    //// deserializeCudaEngine
    //this->m_engine = std::unique_ptr<nvinfer1::ICudaEngine>(runtime->deserializeCudaEngine(trtFile.data(), trtFile.size()));

    //if (this->m_engine == nullptr)
    //{
    //    return false;
    //}
    //// context
    //this->m_context = std::unique_ptr<nvinfer1::IExecutionContext>(this->m_engine->createExecutionContext());
    //if (this->m_context == nullptr)
    //{
    //    return false;
    //}
    //// binding dim
    //if (param.dynamic_batch) // for some models only support static mutil-batch. eg: yolox
    //{
    //    this->m_context->setBindingDimensions(0, nvinfer1::Dims4(param.batch_size, 3, param.dst_h, param.dst_w));
    //}

    //// 2. get output's dim
    //m_output_dims = this->m_context->getBindingDimensions(1);
    //m_total_objects = m_output_dims.d[1];
    //assert(param.batch_size <= m_output_dims.d[0]);
    //m_output_area = 1; // 22500 * 85
    //for (int i = 1; i < m_output_dims.nbDims; i++)
    //{
    //    if (m_output_dims.d[i] != 0)
    //    {
    //        m_output_area *= m_output_dims.d[i];
    //    }
    //}
    //// 3. malloc
    //checkRuntime(cudaMalloc(&m_output_src_device, param.batch_size * m_output_area * sizeof(float)));

    //// 4. cal affine matrix
    //float a = float(param.dst_h) / param.src_h;
    //float b = float(param.dst_w) / param.src_w;
    //float scale = a < b ? a : b;
    //cv::Mat src2dst = (cv::Mat_<float>(2, 3) << scale, 0.f, (-scale * param.src_w + param.dst_w + scale - 1) * 0.5,
    //    0.f, scale, (-scale * param.src_h + param.dst_h + scale - 1) * 0.5);
    //cv::Mat dst2src = cv::Mat::zeros(2, 3, CV_32FC1);
    //cv::invertAffineTransform(src2dst, dst2src);

    //m_dst2src.v0 = dst2src.ptr<float>(0)[0];
    //m_dst2src.v1 = dst2src.ptr<float>(0)[1];
    //m_dst2src.v2 = dst2src.ptr<float>(0)[2];
    //m_dst2src.v3 = dst2src.ptr<float>(1)[0];
    //m_dst2src.v4 = dst2src.ptr<float>(1)[1];
    //m_dst2src.v5 = dst2src.ptr<float>(1)[2];

    return true;

}

void yolo::YOLO::check()
{
    //// print inputs and outputs' dims
    //int idx;
    //nvinfer1::Dims dims;

    //sample::gLogInfo << "the engine's info:" << std::endl;
    //for (auto layer_name : m_param.input_output_names)
    //{
    //    idx = this->m_engine->getBindingIndex(layer_name.c_str());
    //    dims = this->m_engine->getBindingDimensions(idx);
    //    sample::gLogInfo << "idx = " << idx << ", " << layer_name << ": ";
    //    for (int i = 0; i < dims.nbDims; i++)
    //    {
    //        sample::gLogInfo << dims.d[i] << ", ";
    //    }
    //    sample::gLogInfo << std::endl;
    //}

    //sample::gLogInfo << "the context's info:" << std::endl;
    //for (auto layer_name : m_param.input_output_names)
    //{
    //    idx = this->m_engine->getBindingIndex(layer_name.c_str());
    //    //dims = this->m_context->getBindingDimensions(idx);
    //    dims = this->m_engine->getBindingDimensions(idx);

    //    sample::gLogInfo << "idx = " << idx << ", " << layer_name << ": ";
    //    for (int i = 0; i < dims.nbDims; i++)
    //    {
    //        sample::gLogInfo << dims.d[i] << ", ";
    //    }
    //    sample::gLogInfo << std::endl;
    //}
}
// copy to device
void yolo::YOLO::copy(const std::vector<cv::Mat>& imgsBatch)
{
#if 0 
    cv::Mat img_fp32 = cv::Mat::zeros(imgsBatch[0].size(), CV_32FC3); // todo 
    cudaHostRegister(img_fp32.data, img_fp32.elemSize() * img_fp32.total(), cudaHostRegisterPortable);
    float* pi = m_input_src_device;
    for (size_t i = 0; i < imgsBatch.size(); i++)
    {
        imgsBatch[i].convertTo(img_fp32, CV_32FC3);
        checkRuntime(cudaMemcpy(pi, img_fp32.data, sizeof(float) * 3 * m_param.src_h * m_param.src_w, cudaMemcpyHostToDevice));
        pi += 3 * m_param.src_h * m_param.src_w;
    }
    cudaHostUnregister(img_fp32.data);
#endif

#if 0 // for Nvidia TX2
    cv::Mat img_fp32 = cv::Mat::zeros(imgsBatch[0].size(), CV_32FC3); // todo 
    float* pi = m_input_src_device;
    for (size_t i = 0; i < imgsBatch.size(); i++)
    {
        std::vector<float> img_vec = std::vector<float>(imgsBatch[i].reshape(1, 1));
        imgsBatch[i].convertTo(img_fp32, CV_32FC3);
        checkRuntime(cudaMemcpy(pi, img_fp32.data, sizeof(float) * 3 * m_param.src_h * m_param.src_w, cudaMemcpyHostToDevice));
        pi += 3 * m_param.src_h * m_param.src_w;
    }
#endif

    // update 20230302, faster. 
    // 1. move uint8_to_float in cuda kernel function. For 8*3*1920*1080, cost time 15ms -> 3.9ms
    // 2. Todo
    unsigned char* pi = m_input_src_device;
    for (size_t i = 0; i < imgsBatch.size(); i++)
    {
        checkRuntime(cudaMemcpy(pi, imgsBatch[i].data, sizeof(unsigned char) * 3 * m_param.src_h * m_param.src_w, cudaMemcpyHostToDevice));
        pi += 3 * m_param.src_h * m_param.src_w;
    }

#if 0 // cuda stream
    cudaStream_t streams[32];
    for (int i = 0; i < imgsBatch.size(); i++) 
    {
        checkRuntime(cudaStreamCreate(&streams[i]));
    }
    unsigned char* pi = m_input_src_device;
    for (size_t i = 0; i < imgsBatch.size(); i++)
    {
        checkRuntime(cudaMemcpyAsync(pi, imgsBatch[i].data, sizeof(unsigned char) * 3 * m_param.src_h * m_param.src_w, cudaMemcpyHostToDevice, streams[i]));
        pi += 3 * m_param.src_h * m_param.src_w;
    }
    checkRuntime(cudaDeviceSynchronize());
#endif
}

void yolo::YOLO::preprocess(const std::vector<cv::Mat>& imgsBatch)
{
    // 1.resize
    resizeDevice(m_param.batch_size, m_input_src_device, m_param.src_w, m_param.src_h,
        m_input_resize_device, m_param.dst_w, m_param.dst_h, 114, m_dst2src);

#if 0 // valid
    {
        float* phost = new float[3 * m_param.dst_h * m_param.dst_w];
        float* pdevice = m_input_resize_device;
        for (size_t j = 0; j < imgsBatch.size(); j++)
        {
            checkRuntime(cudaMemcpy(phost, pdevice + j * 3 * m_param.dst_h * m_param.dst_w,
                sizeof(float) * 3 * m_param.dst_h * m_param.dst_w, cudaMemcpyDeviceToHost));
            cv::Mat ret(m_param.dst_h, m_param.dst_w, CV_32FC3, phost);
            ret.convertTo(ret, CV_8UC3, 1.0, 0.0);
            cv::namedWindow("ret", cv::WINDOW_NORMAL);
            //cv::imshow("ret", ret);
            //cv::waitKey(1);
        }
        delete[] phost;
    }
#endif // 0

    // 2. bgr2rgb
    bgr2rgbDevice(m_param.batch_size, m_input_resize_device, m_param.dst_w, m_param.dst_h,
        m_input_rgb_device, m_param.dst_w, m_param.dst_h);

#if 0 // valid
    {
        float* phost = new float[3 * m_param.dst_h * m_param.dst_w];
        float* pdevice = m_input_rgb_device;
        for (size_t j = 0; j < imgsBatch.size(); j++)
        {
            checkRuntime(cudaMemcpy(phost, pdevice + j * 3 * m_param.dst_h * m_param.dst_w,
                sizeof(float) * 3 * m_param.dst_h * m_param.dst_w, cudaMemcpyDeviceToHost));
            cv::Mat ret(m_param.dst_h, m_param.dst_w, CV_32FC3, phost);
            ret.convertTo(ret, CV_8UC3, 1.0, 0.0);
            cv::namedWindow("ret", cv::WINDOW_NORMAL);
            //cv::imshow("ret", ret);
            //cv::waitKey(1);
        }
        delete[] phost;
    }
#endif // 0

    // 3. norm:scale mean std
    normDevice(m_param.batch_size, m_input_rgb_device, m_param.dst_w, m_param.dst_h,
        m_input_norm_device, m_param.dst_w, m_param.dst_h, m_param);

#if 0 // valid
    {
        float* phost = new float[3 * m_param.dst_h * m_param.dst_w];
        float* pdevice = m_input_norm_device;
        for (size_t j = 0; j < imgsBatch.size(); j++)
        {
            checkRuntime(cudaMemcpy(phost, pdevice + j * 3 * m_param.dst_h * m_param.dst_w,
                sizeof(float) * 3 * m_param.dst_h * m_param.dst_w, cudaMemcpyDeviceToHost));
            cv::Mat ret(m_param.dst_h, m_param.dst_w, CV_32FC3, phost);
            for (size_t y = 0; y < ret.rows; y++)
            {
                for (size_t x = 0; x < ret.cols; x++)
                {
                    for (size_t c = 0; c < 3; c++)
                    {
                        //
                        ret.at<cv::Vec3f>(y, x)[c]
                            = m_param.scale * (ret.at<cv::Vec3f>(y, x)[c] * m_param.stds[c] + m_param.means[c]);
                    }

                }
            }
            ret.convertTo(ret, CV_8UC3, 1.0, 0.0);
            //cv::imshow("ret", ret);
            //cv::waitKey(1);
        }
        delete[] phost;
    }
#endif // 0

    // 4. hwc2chw
    hwc2chwDevice(m_param.batch_size, m_input_norm_device, m_param.dst_w, m_param.dst_h,
        m_input_hwc_device, m_param.dst_w, m_param.dst_h);
#if 0
    {

        float* phost = new float[3 * m_param.dst_h * m_param.dst_w];
        float* pdevice = m_input_hwc_device;
        for (size_t j = 0; j < imgsBatch.size(); j++)
        {
            checkRuntime(cudaMemcpy(phost, pdevice + j * 3 * m_param.dst_h * m_param.dst_w,
                sizeof(float) * 3 * m_param.dst_h * m_param.dst_w, cudaMemcpyDeviceToHost));

            cv::Mat tmp = imgsBatch[j].clone();

            cv::Mat b(m_param.dst_h, m_param.dst_w, CV_32FC1, phost);
            cv::Mat g(m_param.dst_h, m_param.dst_w, CV_32FC1, phost + 1 * m_param.dst_h * m_param.dst_w);
            cv::Mat r(m_param.dst_h, m_param.dst_w, CV_32FC1, phost + 2 * m_param.dst_h * m_param.dst_w);
            std::vector<cv::Mat> bgr{ b, g, r };
            cv::Mat ret;
            cv::merge(bgr, ret);
            ret.convertTo(ret, CV_8UC3, 255, 0.0);
            //cv::imshow("ret", ret);

            /* SYSTEMTIME st = { 0 };
             GetLocalTime(&st);
             std::string t = std::to_string(st.wHour) + std::to_string(st.wMinute) + std::to_string(st.wMilliseconds);
             std::string save_path = "F:/Data/temp/";;
             cv::imwrite(save_path + t + ".jpg", ret);*/
            //cv::waitKey(1);

            cv::Mat img_ = imgsBatch[j].clone();
        }
        delete[] phost;

    }
#endif

}

bool yolo::YOLO::infer()
{
    float* bindings[] = { m_input_hwc_device, m_output_src_device };
    bool context = m_context->executeV2((void**)bindings);
    return context;
}
//
//struct GridAndStride
//{
//    int grid0;
//    int grid1;
//    int stride;
//};
struct Object
{
    cv::Rect_<float> rect;
    int label;
    float prob;
};
static void generate_grids_and_stride(const int INPUT_W, const int INPUT_H, std::vector<int>& strides, std::vector<dl_utils::GridAndStride>& grid_strides)
{
    dl_utils::GridAndStride temp;
    for (auto stride : strides)
    {
        int num_grid_y = INPUT_H / stride;
        int num_grid_x = INPUT_W / stride;
        for (int g1 = 0; g1 < num_grid_y; g1++)
        {
            for (int g0 = 0; g0 < num_grid_x; g0++)
            {
                temp.grid0 = g0;
                temp.grid1 = g1;
                temp.stride = stride;
                grid_strides.push_back(temp);
            }
        }
    }
}

static inline float intersection_area(const Object& a, const Object& b)
{
    cv::Rect_<float> inter = a.rect & b.rect;
    return inter.area();
}

static void qsort_descent_inplace(std::vector<Object>& faceobjects, int left, int right)
{
    int i = left;
    int j = right;
    float p = faceobjects[(left + right) / 2].prob;

    while (i <= j)
    {
        while (faceobjects[i].prob > p)
            i++;

        while (faceobjects[j].prob < p)
            j--;

        if (i <= j)
        {
            // swap
            std::swap(faceobjects[i], faceobjects[j]);

            i++;
            j--;
        }
    }

#pragma omp parallel sections
    {
#pragma omp section
        {            if (left < j) qsort_descent_inplace(faceobjects, left, j);
        }
#pragma omp section
        {
            if (i < right) qsort_descent_inplace(faceobjects, i, right);
        }
    }
}

static void qsort_descent_inplace(std::vector<Object>& objects)
{
    if (objects.empty())
        return;

    qsort_descent_inplace(objects, 0, objects.size() - 1);
}

static void nms_sorted_bboxes(const std::vector<Object>& faceobjects, std::vector<int>& picked, float nms_threshold)
{
    picked.clear();

    const int n = faceobjects.size();

    std::vector<float> areas(n);
    for (int i = 0; i < n; i++)
    {
        areas[i] = faceobjects[i].rect.area();
    }

    for (int i = 0; i < n; i++)
    {
        const Object& a = faceobjects[i];

        int keep = 1;
        for (int j = 0; j < (int)picked.size(); j++)
        {
            const Object& b = faceobjects[picked[j]];

            // intersection over union
            float inter_area = intersection_area(a, b);
            float union_area = areas[i] + areas[picked[j]] - inter_area;
            // float IoU = inter_area / union_area
            if (inter_area / union_area > nms_threshold)
                keep = 0;
        }

        if (keep)
            picked.push_back(i);
    }
}
const int OBJ_NUM_CLASSES = 1;
static void generate_yolox_proposals(std::vector<dl_utils::GridAndStride> grid_strides, float* feat_blob, float prob_threshold, std::vector<Object>& objects)
{
    //const int num_class = 1;

    const int num_anchors = grid_strides.size();

    for (int anchor_idx = 0; anchor_idx < num_anchors; anchor_idx++)
    {
        const int grid0 = grid_strides[anchor_idx].grid0;
        const int grid1 = grid_strides[anchor_idx].grid1;
        const int stride = grid_strides[anchor_idx].stride;

        const int basic_pos = anchor_idx * (OBJ_NUM_CLASSES + 5);

        // yolox/models/yolo_head.py decode logic
        float x_center = (feat_blob[basic_pos + 0] + grid0) * stride;
        float y_center = (feat_blob[basic_pos + 1] + grid1) * stride;
        float w = exp(feat_blob[basic_pos + 2]) * stride;
        float h = exp(feat_blob[basic_pos + 3]) * stride;
        float x0 = x_center - w * 0.5f;
        float y0 = y_center - h * 0.5f;

        float box_objectness = feat_blob[basic_pos + 4];
        for (int class_idx = 0; class_idx < OBJ_NUM_CLASSES; class_idx++)
        {
            float box_cls_score = feat_blob[basic_pos + 5 + class_idx];
            float box_prob = box_objectness * box_cls_score;
            if (box_prob > prob_threshold)
            {
                Object obj;
                obj.rect.x = x0;
                obj.rect.y = y0;
                obj.rect.width = w;
                obj.rect.height = h;
                obj.label = class_idx;
                obj.prob = box_prob;

                objects.push_back(obj);
            }

        } // class loop

    } // point anchor loop
}
const int INPUT_W = 640;
const int INPUT_H = 512;
float BBOX_CONF_THRESH = 0.2f;
float NMS_THRESH = 0.45f;
void decode_outputs(float* prob, std::vector<Object>& objects, float scale, const int img_w, const int img_h) {
    std::vector<Object> proposals;
    std::vector<int> strides = { 8, 16, 32 };
    std::vector<dl_utils::GridAndStride> grid_strides;
    generate_grids_and_stride(INPUT_W, INPUT_H, strides, grid_strides);
    generate_yolox_proposals(grid_strides, prob, BBOX_CONF_THRESH, proposals);
    std::cout << "num of boxes before nms: " << proposals.size() << std::endl;

    qsort_descent_inplace(proposals);

    std::vector<int> picked;
    nms_sorted_bboxes(proposals, picked, NMS_THRESH);


    int count = picked.size();
    std::cout << "num of boxes: " << count << std::endl;

    objects.resize(count);
    for (int i = 0; i < count; i++)
    {
        objects[i] = proposals[picked[i]];

        // adjust offset to original unpadded
        float x0 = (objects[i].rect.x) / scale;
        float y0 = (objects[i].rect.y) / scale;
        float x1 = (objects[i].rect.x + objects[i].rect.width) / scale;
        float y1 = (objects[i].rect.y + objects[i].rect.height) / scale;

        // clip
        x0 = std::max(std::min(x0, (float)(img_w - 1)), 0.f);
        y0 = std::max(std::min(y0, (float)(img_h - 1)), 0.f);
        x1 = std::max(std::min(x1, (float)(img_w - 1)), 0.f);
        y1 = std::max(std::min(y1, (float)(img_h - 1)), 0.f);

        objects[i].rect.x = x0;
        objects[i].rect.y = y0;
        objects[i].rect.width = x1 - x0;
        objects[i].rect.height = y1 - y0;
    }
}

void yolo::YOLO::postprocess(const std::vector<cv::Mat>& imgsBatch)
{
    std::vector<std::vector<Object>> batch_objects;
#if 1 // valid
    {
        //float* phost = new float[m_param.batch_size * m_output_area];
        float* phost = new float[m_output_area];
        float* pdevice = m_output_src_device;
        
        for (size_t j = 0; j < imgsBatch.size(); j++)
        {
            checkRuntime(cudaMemcpy(phost, pdevice + j * m_output_area, sizeof(float) * m_output_area, cudaMemcpyDeviceToHost));
            std::vector<Object> objects;
            decode_outputs(phost, objects, 0.5, 1280, 1024);
            batch_objects.push_back(objects);
            //cv::Mat prediction(m_total_objects, m_param.num_class + 5, CV_32FC1, phost);
        }
        delete[] phost;
    }
#endif // 0

    // decode
    decodeDevice(m_param, m_output_src_device, 5 + m_param.num_class, m_total_objects, m_output_area,
        m_output_objects_device, m_output_objects_width, m_param.topK);
#if 0 // valid
    {
        //* phost = new float[m_param.batch_size * (1 + m_output_objects_width * m_param.topK)];
        float* phost = new float[1 + m_output_objects_width * m_param.topK];
        float* pdevice = m_output_objects_device;
        for (size_t j = 0; j < imgsBatch.size(); j++)
        {
            /* cv::imshow("srcimg", imgsBatch[j]);
             cv::waitKey(0);*/
            checkRuntime(cudaMemcpy(phost, pdevice + j * (1 + m_output_objects_width * m_param.topK), 
                sizeof(float) * (1 + m_output_objects_width * m_param.topK), cudaMemcpyDeviceToHost));
            int num_candidates = phost[0];
            cv::Mat prediction(m_param.topK, m_output_objects_width, CV_32FC1, phost + 1);

            //save to binary
            //utils::saveBinaryFile(phost, (1 + m_output_objects_width * m_param.topK), "yolov7.bin");
        }
        delete[] phost;
    }
#endif // 0

    // nmsv1(nms faster)
    nmsDeviceV1(m_param, m_output_objects_device, m_output_objects_width, m_param.topK, m_param.topK * m_output_objects_width + 1);
#if 0 // valid
    {
        float* phost = new float[1 + m_output_objects_width * m_param.topK];
        float* pdevice = m_output_objects_device;
        for (size_t j = 0; j < imgsBatch.size(); j++)
        {
            /*cv::imshow("srcimg", imgsBatch[j]);
            cv::waitKey(0);*/
            checkRuntime(cudaMemcpy(phost, pdevice + j * (1 + m_output_objects_width * m_param.topK), 
                sizeof(float) * (1 + m_output_objects_width * m_param.topK), cudaMemcpyDeviceToHost));
            int num_candidates_objects = phost[0];
            cv::Mat prediction(m_param.topK, m_output_objects_width, CV_32FC1, phost + 1);
        }
        delete[] phost;
    }
#endif // 0
    // nmsv2(nms sort)
    //nmsDeviceV2(m_param, m_output_objects_device, m_output_objects_width, m_param.topK, m_param.topK * m_output_objects_width + 1, m_output_idx_device, m_output_conf_device);
#if 0 // valid
    {
        // prediction
        float* phost = new float[1 + m_output_objects_width * m_param.topK];
        float* pdevice = m_output_objects_device;
        for (size_t j = 0; j < 1; j++)
        {
            checkRuntime(cudaMemcpy(phost, pdevice + j * (1 + m_output_objects_width * m_param.topK),
                sizeof(float) * (1 + m_output_objects_width * m_param.topK), cudaMemcpyDeviceToHost));
            int num_candidates_objects = phost[0];
            cv::Mat prediction(m_param.topK, m_output_objects_width, CV_32FC1, phost + 1);
        }
        delete[] phost;

        // conf & idx
        float* phost_conf = new float[m_param.topK];
        int* phost_idx = new int[m_param.topK];
        float* pdevice_conf = m_output_conf_device;
        int* pdevice_idx = m_output_idx_device;
        for (size_t j = 0; j < m_param.batch_size; j++)
        {
            checkRuntime(cudaMemcpy(phost_conf, pdevice_conf + j * m_param.topK, sizeof(float) * m_param.topK, cudaMemcpyDeviceToHost));
            checkRuntime(cudaMemcpy(phost_idx,  pdevice_idx  + j * m_param.topK, sizeof(float) * m_param.topK, cudaMemcpyDeviceToHost));
            cv::Mat img_conf(m_param.topK, 1, CV_32FC1, phost_conf);
            cv::Mat img_idx(m_param.topK, 1, CV_32S, phost_idx);
        }
        delete[] phost_idx;
        delete[] phost_conf;
    }
#endif // 0

    // copy result
    checkRuntime(cudaMemcpy(m_output_objects_host, m_output_objects_device, m_param.batch_size * sizeof(float) * (1 + 7 * m_param.topK), cudaMemcpyDeviceToHost));
    //checkRuntime(cudaMemcpy(m_output_objects_host, m_output_objects_device, m_param.batch_size * sizeof(float) * (6 * 6720), cudaMemcpyDeviceToHost));

# if 0 // src code
    // transform to source image coordinate,
    for (size_t bi = 0; bi < imgsBatch.size(); bi++)
    {
        int num_boxes = std::min((int)(m_output_objects_host + bi * (m_param.topK * m_output_objects_width + 1))[0], m_param.topK);
        for (size_t i = 0; i < num_boxes; i++)
        {
            float* ptr = m_output_objects_host + bi * (m_param.topK * m_output_objects_width + 1) + m_output_objects_width * i + 1;
            int keep_flag = ptr[6];
            if (keep_flag)
            {
                float x_lt = m_dst2src.v0 * ptr[0] + m_dst2src.v1 * ptr[1] + m_dst2src.v2; // left & top
                float y_lt = m_dst2src.v3 * ptr[0] + m_dst2src.v4 * ptr[1] + m_dst2src.v5;
                float x_rb = m_dst2src.v0 * ptr[2] + m_dst2src.v1 * ptr[3] + m_dst2src.v2; // right & bottom
                float y_rb = m_dst2src.v3 * ptr[2] + m_dst2src.v4 * ptr[3] + m_dst2src.v5;
                //float x_lt = 100; // left & top
                //float y_lt = 100;
                //float x_rb = 200; // right & bottom
                //float y_rb = 200;
                /*x_lt = x_lt * 16;
                y_lt = y_lt * 16;
                x_rb = x_rb * 16;
                y_rb = y_rb * 16;*/
                m_objectss[bi].emplace_back(x_lt, y_lt, x_rb, y_rb, ptr[4], (int)ptr[5]); //
            }
        }
   
    }
#endif

#if 1  // my yolox code
    {
        for (size_t j = 0; j < imgsBatch.size(); j++)
        {
            std::vector<Object> objects = batch_objects[j];
            //cv::Mat prediction(m_total_objects, m_param.num_class + 5, CV_32FC1, phost);
            for (size_t i = 0; i < objects.size(); i++) {
                float x_lt = objects[i].rect.x; // left & top
                float y_lt = objects[i].rect.y;
                float x_rb = objects[i].rect.x + objects[i].rect.width / 2; // right & bottom
                float y_rb = objects[i].rect.y + objects[i].rect.height / 2;
                m_objectss[j].emplace_back(x_lt, y_lt, x_rb, y_rb, objects[i].prob, (int)objects[i].label);
            }
        }
    }
#endif
}

//void yolo::YOLO::yolox_postprocess(const std::vector<cv::Mat>& imgsBatch)
//{
//    float* phost = new float[m_param.batch_size * m_output_area];
//    //float* phost = new float[m_output_area];
//    float* pdevice = m_output_src_device;
//    for (size_t j = 0; j < imgsBatch.size(); j++)
//    {
//        checkRuntime(cudaMemcpy(phost, pdevice + j * m_output_area, sizeof(float) * m_output_area, cudaMemcpyDeviceToHost));
//        std::vector<Object> objects;
//        decode_outputs(phost, objects, 0.5, 1280, 1024);
//        cv::Mat prediction(m_total_objects, m_param.num_class + 5, CV_32FC1, phost);
//        for (size_t i = 0; i < objects.size(); i++) {
//            float x_lt = objects[i].rect.x; // left & top
//            float y_lt = objects[i].rect.y;
//            float x_rb = objects[i].rect.x + objects[i].rect.width / 2; // right & bottom
//            float y_rb = objects[i].rect.y + objects[i].rect.height / 2;
//            m_objectss[j].emplace_back(x_lt, y_lt, x_rb, y_rb, objects[i].prob, (int)objects[i].label);
//        }
//    }
//    delete[] phost;
//}

std::vector<std::vector<dl_utils::Box>> yolo::YOLO::getObjectss() const
{
    return this->m_objectss;
}

void yolo::YOLO::reset()
{
    checkRuntime(cudaMemset(m_output_objects_device, 0, sizeof(float) * m_param.batch_size * (1 + 7 * m_param.topK)));
    for (size_t bi = 0; bi < m_param.batch_size; bi++)
    {
        m_objectss[bi].clear();
    }
}



