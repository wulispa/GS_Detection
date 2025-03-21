#include "pch.h"
#include"../utils/kernel_function.h"
#include<math.h>
/************************************************************************************************
* cuda check
*************************************************************************************************/
bool __check_cuda_runtime(cudaError_t code, const char* op, const char* file, int line) {
	if (code != cudaSuccess) {
		const char* err_name = cudaGetErrorName(code);
		const char* err_message = cudaGetErrorString(code);
		printf("runtime error %s:%d  %s failed. \n  code = %s, message = %s\n", file, line, op, err_name, err_message);
		return false;
	}
	return true;
}
/************************************************************************************************
* math kernel function
*************************************************************************************************/
__device__ 
float atomicMaxf(float* address, float val)
{
	int* address_as_int = (int*)address;
	int old = *address_as_int, assumed;
	while (val > __int_as_float(old)) {
		assumed = old;
		old = atomicCAS(address_as_int, assumed,
			__float_as_int(val));
	}
	return __int_as_float(old);
}

__device__ 
float atomicMinf(float* address, float val)
{
	int* address_as_int = (int*)address;
	int old = *address_as_int, assumed;
	while (val < __int_as_float(old)) {
		assumed = old;
		old = atomicCAS(address_as_int, assumed,
			__float_as_int(val));
	}
	return __int_as_float(old);
}

__global__ 
void max_float_array_device_kernel(float* src, int size, float* max_val)
{
	// get data
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	__shared__ float shared_per_block[BLOCK_SIZE];
	if (idx < size)
	{
		shared_per_block[threadIdx.x] = src[idx];
	}
	else
	{
		shared_per_block[threadIdx.x] = -FLT_MAX; // alpha
	}
	__syncthreads();

	// get max val in per block
	float temp_val;
	for (int length = BLOCK_SIZE / 2; length >= 1; length /= 2)
	{
		if (threadIdx.x < length)
		{
			temp_val = max(shared_per_block[threadIdx.x], shared_per_block[threadIdx.x + length]);
		}
		__syncthreads();
		if (threadIdx.x < length)
		{
			shared_per_block[threadIdx.x] = temp_val;
		}
		__syncthreads();
	}
	// automic
	if (blockDim.x * blockIdx.x < size)
	{
		if (threadIdx.x == 0)
		{
			max_val[0] = -FLT_MAX; // alpha
			atomicMaxf(max_val, shared_per_block[0]);
		}
	}
}

__global__ 
void min_float_array_device_kernel(float* src, int size, float* min_val)
{
	// get data
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	__shared__ float shared_per_block[BLOCK_SIZE];
	if (idx < size)
	{
		shared_per_block[threadIdx.x] = src[idx];
	}
	else
	{
		shared_per_block[threadIdx.x] = FLT_MAX; // alpha
	}
	__syncthreads();

	// get max val in per block
	float temp_val;
	for (int length = BLOCK_SIZE / 2; length >= 1; length /= 2)
	{
		if (threadIdx.x < length)
		{
			temp_val = min(shared_per_block[threadIdx.x], shared_per_block[threadIdx.x + length]);
		}
		__syncthreads();
		if (threadIdx.x < length)
		{
			shared_per_block[threadIdx.x] = temp_val;
		}
		__syncthreads();
	}
	
	// automic
	if (blockDim.x * blockIdx.x < size)
	{
		if (threadIdx.x == 0)
		{
			min_val[0] = FLT_MAX; // alpha
			atomicMinf(min_val, shared_per_block[0]);
		}
	}
}

__global__ 
void min_max_float_array_device_kernel(float* src, int size, float* min_val, float* max_val)
{
	// get data
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	__shared__ float shared_per_block_min[BLOCK_SIZE];
	__shared__ float shared_per_block_max[BLOCK_SIZE];
	if (idx < size)
	{
		shared_per_block_min[threadIdx.x] = src[idx];
		shared_per_block_max[threadIdx.x] = src[idx];
	}
	else
	{
		shared_per_block_min[threadIdx.x] = FLT_MAX; 
		shared_per_block_max[threadIdx.x] = -FLT_MAX;
	}
	__syncthreads();

	// get max val in per block
	float t1, t2;
	for (int length = BLOCK_SIZE / 2; length >= 1; length /= 2)
	{
		if (threadIdx.x < length)
		{
			t1 = min(shared_per_block_min[threadIdx.x], shared_per_block_min[threadIdx.x + length]);
			t2 = max(shared_per_block_max[threadIdx.x], shared_per_block_max[threadIdx.x + length]);
		}
		__syncthreads();
		if (threadIdx.x < length)
		{
			shared_per_block_min[threadIdx.x] = t1;
			shared_per_block_max[threadIdx.x] = t2;
		}
		__syncthreads();
	}
	// automic
	if (blockDim.x * blockIdx.x < size)
	{
		if (threadIdx.x == 0)
		{
			min_val[0] = FLT_MAX;  
			max_val[0] = -FLT_MAX; 
			atomicMinf(min_val, shared_per_block_min[0]);
			atomicMaxf(max_val, shared_per_block_max[0]);
		}
	}
}

__global__ 
void max_int_array_device_kernel(int* src, int size, int* max_val)
{
	// get data
	__shared__ int shared_per_block[BLOCK_SIZE];
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < size)
	{
		shared_per_block[threadIdx.x] = src[idx];
	}
	else
	{
		shared_per_block[threadIdx.x] = -INT_MAX;
	}
	__syncthreads();

	// get max val in per block
	int temp_val;
	for (int length = BLOCK_SIZE / 2; length >= 1; length /= 2)
	{
		if (threadIdx.x < length)
		{
			temp_val = max(shared_per_block[threadIdx.x], shared_per_block[threadIdx.x + length]);
		}
		__syncthreads();
		if (threadIdx.x < length)
		{
			shared_per_block[threadIdx.x] = temp_val;
		}
		__syncthreads();
	}

	// automic
	if (blockDim.x * blockIdx.x < size)
	{
		if (threadIdx.x == 0)
		{
			max_val[0] = -INT_MAX;
			atomicMax(max_val, shared_per_block[0]);
		}
	}
}

__global__ 
void min_int_array_device_kernel(int* src, int size, int* min_val)
{
	// get data
	__shared__ float shared_per_block[BLOCK_SIZE];
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < size)
	{
		shared_per_block[threadIdx.x] = src[idx];
	}
	else
	{
		shared_per_block[threadIdx.x] = INT_MAX; 
	}
	__syncthreads();

	// get max val in per block
	int temp_val;
	for (int length = BLOCK_SIZE / 2; length >= 1; length /= 2)
	{
		if (threadIdx.x < length)
		{
			temp_val = min(shared_per_block[threadIdx.x], shared_per_block[threadIdx.x + length]);
		}
		__syncthreads();
		if (threadIdx.x < length)
		{
			shared_per_block[threadIdx.x] = temp_val;
		}
		__syncthreads();
	}
	// automic
	if (blockDim.x * blockIdx.x < size)
	{
		if (threadIdx.x == 0)
		{
			min_val[0] = INT_MAX;
			atomicMin(min_val, shared_per_block[0]);
		}
			
	}
}

//extern __managed__ float max_val_flt[1];
//extern __managed__ float min_val_flt[1];
//extern __managed__ int   max_val_int[1];
//extern __managed__ int   min_val_int[1];

// change to dynamic batch!
// legacy
__managed__ float max_val_flt[1];
__managed__ float min_val_flt[1];
__managed__ int   max_val_int[1];
__managed__ int   min_val_int[1];

float maxFloatDevice(float* src, int size)
{
	unsigned int grid_size = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
	max_float_array_device_kernel << < grid_size, BLOCK_SIZE, 0, nullptr >> > (src, size, max_val_flt);
	cudaDeviceSynchronize();
	return max_val_flt[0];
}

/*
* @note: overload: compute max vals of matrix
* @in: src : batchSize * srcVolume
* @in: srcVolume = srcChannel * srcHeight * srcWidth
* @in: dst : batchSize * 1
*/
//void maxFloatDevice(const int& batchSize, float* src, int srcVolume, float* dst);


float minFloatDevice(float* src, int size)
{
	unsigned int grid_size = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
	min_float_array_device_kernel << < grid_size, BLOCK_SIZE, 0, nullptr >> > (src, size, min_val_flt);
	cudaDeviceSynchronize();
	return min_val_flt[0];
}

int maxIntDevice(int* src, int size)
{
	unsigned int grid_size = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
	max_int_array_device_kernel << < grid_size, BLOCK_SIZE, 0, nullptr >> > (src, size, max_val_int);
	cudaDeviceSynchronize();
	return max_val_int[0];
}

int minIntDevice(int* src, int size)
{
	unsigned int grid_size = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
	min_int_array_device_kernel << < grid_size, BLOCK_SIZE, 0, nullptr >> > (src, size, min_val_int);
	cudaDeviceSynchronize();
	return min_val_int[0];
}

// ------------------------------------------------
void maxFloatDevice(float* src, int size, float* dst)
{
	unsigned int grid_size = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
	max_float_array_device_kernel << < grid_size, BLOCK_SIZE, 0, nullptr >> > (src, size, dst);
	cudaDeviceSynchronize();
	return;
}

void minFloatDevice(float* src, int size, float* dst)
{
	unsigned int grid_size = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
	min_float_array_device_kernel << < grid_size, BLOCK_SIZE, 0, nullptr >> > (src, size, dst);
	cudaDeviceSynchronize();
	return;
}

void maxIntDevice(int* src, int size, int* dst)
{
	unsigned int grid_size = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
	max_int_array_device_kernel << < grid_size, BLOCK_SIZE, 0, nullptr >> > (src, size, dst);
	cudaDeviceSynchronize();
	return;
}

void minIntDevice(int* src, int size, int* dst)
{
	unsigned int grid_size = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
	max_int_array_device_kernel << < grid_size, BLOCK_SIZE, 0, nullptr >> > (src, size, dst);
	cudaDeviceSynchronize();
	return;
}

std::pair<float, float> minmaxFloatDevice(float* src, int size)
{
	unsigned int grid_size = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
	min_max_float_array_device_kernel << < grid_size, BLOCK_SIZE, 0, nullptr >> > (src, size, min_val_flt, max_val_flt);
	cudaDeviceSynchronize();
	return std::pair<float, float>(min_val_flt[0], max_val_flt[0]);
}


/************************************************************************************************
* preprocess kernel function
*************************************************************************************************/
// (x, y) -> (proj_x, proj_y)
__device__ 
void affine_project_device_kernel(dl_utils::AffineMat* matrix, int x, int y, float* proj_x, float* proj_y)
{
	*proj_x = matrix->v0 * x + matrix->v1 * y + matrix->v2;
	*proj_y = matrix->v3 * x + matrix->v4 * y + matrix->v5;
}

__global__ 
void resize_rgb_padding_device_kernel(float* src, int src_width, int src_height, int src_area, int src_volume,
	float* dst, int dst_width, int dst_height, int dst_area, int dst_volume,
	int batch_size, float padding_value, dl_utils::AffineMat matrix)
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;
	if (dx < dst_area && dy < batch_size)
	{
		int dst_y = dx / dst_width; // dst row
		int dst_x = dx % dst_width; // dst col
		float src_x = 0;
		float src_y = 0;
		affine_project_device_kernel(&matrix, dst_x, dst_y, &src_x, &src_y);
		float c0 = padding_value, c1 = padding_value, c2 = padding_value;
		if (src_x < -1 || src_x >= src_width || src_y < -1 || src_y >= src_height)
		{
			// todo
		}
		else
		{
			// get neibor four points
			int y_low = floorf(src_y); // 0.8 -> 0 
			int x_low = floorf(src_x); // 0.6 -> 0
			int y_high = y_low + 1;    // 0 -> 1
			int x_high = x_low + 1;    // 1 -> 2
			float const_values[] = { padding_value, padding_value, padding_value };
			// cal four areas
			float ly = src_y - y_low;
			float lx = src_x - x_low;
			float hy = 1 - ly;
			float hx = 1 - lx;
			float w1 = hy * hx, w2 = hy * lx, w3 = ly * hx, w4 = ly * lx; // areas
			// default vals
			float* v1 = const_values;
			float* v2 = const_values;
			float* v3 = const_values;
			float* v4 = const_values;

			if (y_low >= 0)
			{
				if (x_low >= 0)
					v1 = src + dy * src_volume + y_low * src_width * 3 + x_low * 3;

				if (x_high < src_width)
					v2 = src + dy * src_volume + y_low * src_width * 3 + x_high * 3;
			}

			if (y_high < src_height)
			{
				if (x_low >= 0)
					v3 = src + dy * src_volume + y_high * src_width * 3 + x_low * 3;

				if (x_high < src_width)
					v4 = src + dy * src_volume + y_high * src_width * 3 + x_high * 3;
			}
			// 3 channels' val
			c0 = floorf(w1 * v1[0] + w2 * v2[0] + w3 * v3[0] + w4 * v4[0] + 0.5f);
			c1 = floorf(w1 * v1[1] + w2 * v2[1] + w3 * v3[1] + w4 * v4[1] + 0.5f);
			c2 = floorf(w1 * v1[2] + w2 * v2[2] + w3 * v3[2] + w4 * v4[2] + 0.5f);
		}
		//uint8_t* pdst = dst + dy * dst_line_size + dx * 3;
		float* pdst = dst + dy * dst_volume + dst_y * dst_width * 3 + dst_x * 3;
		pdst[0] = c0;
		pdst[1] = c1;
		pdst[2] = c2;
	}
}

// overload: paddingValue and src's type is uin8
__global__
void resize_rgb_padding_device_kernel(unsigned char* src, int src_width, int src_height, int src_area, int src_volume,
	float* dst, int dst_width, int dst_height, int dst_area, int dst_volume,
	int batch_size, float padding_value, dl_utils::AffineMat matrix)
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;
	if (dx < dst_area && dy < batch_size)
	{
		int dst_y = dx / dst_width; // dst row
		int dst_x = dx % dst_width; // dst col
		float src_x = 0;
		float src_y = 0;
		affine_project_device_kernel(&matrix, dst_x, dst_y, &src_x, &src_y);
		float c0 = padding_value, c1 = padding_value, c2 = padding_value;
		if (src_x < -1 || src_x >= src_width || src_y < -1 || src_y >= src_height)
		{
			// todo
		}
		else
		{
			// get neibor four points
			int y_low = floorf(src_y); // 0.8 -> 0 
			int x_low = floorf(src_x); // 0.6 -> 0
			int y_high = y_low + 1;    // 0 -> 1
			int x_high = x_low + 1;    // 1 -> 2
			unsigned char const_values[] = { 
				(unsigned char)padding_value, 
				(unsigned char)padding_value, 
				(unsigned char)padding_value }; 
			// cal four areas
			float ly = src_y - y_low;
			float lx = src_x - x_low;
			float hy = 1 - ly;
			float hx = 1 - lx;
			float w1 = hy * hx, w2 = hy * lx, w3 = ly * hx, w4 = ly * lx; // areas
			// default vals
			unsigned char* v1 = const_values;
			unsigned char* v2 = const_values;
			unsigned char* v3 = const_values;
			unsigned char* v4 = const_values;

			if (y_low >= 0)
			{
				if (x_low >= 0)
					v1 = src + dy * src_volume + y_low * src_width * 3 + x_low * 3;

				if (x_high < src_width)
					v2 = src + dy * src_volume + y_low * src_width * 3 + x_high * 3;
			}

			if (y_high < src_height)
			{
				if (x_low >= 0)
					v3 = src + dy * src_volume + y_high * src_width * 3 + x_low * 3;

				if (x_high < src_width)
					v4 = src + dy * src_volume + y_high * src_width * 3 + x_high * 3;
			}
			// 3 channels' val
			c0 = floorf(w1 * v1[0] + w2 * v2[0] + w3 * v3[0] + w4 * v4[0] + 0.5f);
			c1 = floorf(w1 * v1[1] + w2 * v2[1] + w3 * v3[1] + w4 * v4[1] + 0.5f);
			c2 = floorf(w1 * v1[2] + w2 * v2[2] + w3 * v3[2] + w4 * v4[2] + 0.5f);
		}
		//uint8_t* pdst = dst + dy * dst_line_size + dx * 3;
		float* pdst = dst + dy * dst_volume + dst_y * dst_width * 3 + dst_x * 3;
		pdst[0] = c0;
		pdst[1] = c1;
		pdst[2] = c2;
	}
}
__global__
void resize_rgb_without_padding_device_kernel(float* src, int src_width, int src_height, int src_area, int src_volume,
	float* dst, int dst_width, int dst_height, int dst_area, int dst_volume,
	int batch_size, /*float padding_value, */dl_utils::AffineMat matrix)
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;
	if (dx < dst_area && dy < batch_size)
	{
		int dst_y = dx / dst_width; // dst row
		int dst_x = dx % dst_width; // dst col
		float src_x = 0;
		float src_y = 0;
		affine_project_device_kernel(&matrix, dst_x, dst_y, &src_x, &src_y);
		//float c0 = padding_value, c1 = padding_value, c2 = padding_value;
		float default_val = 114.f;
		float c0 = default_val, c1 = default_val, c2 = default_val;
		//printf("dst_x = %d, dst_y = %d, src_x = %f, src_y = %f \n", dst_x, dst_y, src_x, src_y);
		if (src_x < -1 || src_x >= src_width || src_y < -1 || src_y >= src_height)
		{
			// todo
		}
		else
		{
			int y_low = floorf(fmaxf(src_y, 0.f)); // 0.8 -> 0 
			int x_low = floorf(fmaxf(src_x, 0.f)); // 0.6 -> 0
			int y_high = min(y_low + 1, src_height - 1); // 0 -> 1
			int x_high = min(x_low + 1, src_width - 1); // 1 -> 2

			//int y_low = floorf(src_y); // 0.8 -> 0 
			//int x_low = floorf(src_x); // 0.6 -> 0
			//int y_high = y_low + 1; // 0 -> 1
			//int x_high = x_low + 1; // 1 -> 2
			float const_values[] = { default_val, default_val, default_val };
			// 
			float ly = src_y - y_low;
			float lx = src_x - x_low;
			float hy = 1 - ly;
			float hx = 1 - lx;
			float w1 = hy * hx, w2 = hy * lx, w3 = ly * hx, w4 = ly * lx; // 
			//
			float* v1 = const_values;
			float* v2 = const_values;
			float* v3 = const_values;
			float* v4 = const_values;

			if (y_low >= 0)
			{
				if (x_low >= 0)
					v1 = src + dy * src_volume + y_low * src_width * 3 + x_low * 3;

				if (x_high < src_width) // 
					v2 = src + dy * src_volume + y_low * src_width * 3 + x_high * 3;
			}

			if (y_high < src_height)
			{
				if (x_low >= 0)
					v3 = src + dy * src_volume + y_high * src_width * 3 + x_low * 3;

				if (x_high < src_width)
					v4 = src + dy * src_volume + y_high * src_width * 3 + x_high * 3;
			}
			// 
			c0 = floorf(w1 * v1[0] + w2 * v2[0] + w3 * v3[0] + w4 * v4[0] + 0.5f);
			c1 = floorf(w1 * v1[1] + w2 * v2[1] + w3 * v3[1] + w4 * v4[1] + 0.5f);
			c2 = floorf(w1 * v1[2] + w2 * v2[2] + w3 * v3[2] + w4 * v4[2] + 0.5f);
		}
		//uint8_t* pdst = dst + dy * dst_line_size + dx * 3;
		float* pdst = dst + dy * dst_volume + dst_y * dst_width * 3 + dst_x * 3;
		pdst[0] = c0;
		pdst[1] = c1;
		pdst[2] = c2;
	}
}

__global__
void resize_gray_without_padding_device_kernel(float* src, int src_width, int src_height, int src_area, /*int src_volume,*/
	float* dst, int dst_width, int dst_height, int dst_area, /*int dst_volume,*/
	int batch_size, /*float padding_value, */dl_utils::AffineMat matrix)
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;
	if (dx < dst_area && dy < batch_size)
	{
		int dst_y = dx / dst_width; // dst row
		int dst_x = dx % dst_width; // dst col
		float src_x = 0;
		float src_y = 0;
		affine_project_device_kernel(&matrix, dst_x, dst_y, &src_x, &src_y);
		//float c0 = padding_value, c1 = padding_value, c2 = padding_value;
		float default_val = 114.f;
		float c0 = default_val/*, c1 = default_val, c2 = default_val*/;
		//printf("dst_x = %d, dst_y = %d, src_x = %f, src_y = %f \n", dst_x, dst_y, src_x, src_y);
		if (src_x < -1 || src_x >= src_width || src_y < -1 || src_y >= src_height)
		{
			// todo
		}
		else
		{
			int y_low = floorf(fmaxf(src_y, 0.f)); // 0.8 -> 0 
			int x_low = floorf(fmaxf(src_x, 0.f)); // 0.6 -> 0
			int y_high = min(y_low + 1, src_height - 1); // 0 -> 1
			int x_high = min(x_low + 1, src_width - 1); // 1 -> 2

			//int y_low = floorf(src_y); // 0.8 -> 0 
			//int x_low = floorf(src_x); // 0.6 -> 0
			//int y_high = y_low + 1; // 0 -> 1
			//int x_high = x_low + 1; // 1 -> 2
			float const_values[] = { default_val/*, default_val, default_val*/ };
			// 
			float ly = src_y - y_low;
			float lx = src_x - x_low;
			float hy = 1 - ly;
			float hx = 1 - lx;
			float w1 = hy * hx, w2 = hy * lx, w3 = ly * hx, w4 = ly * lx; // 
			//
			float* v1 = const_values;
			float* v2 = const_values;
			float* v3 = const_values;
			float* v4 = const_values;

			if (y_low >= 0)
			{
				if (x_low >= 0)
					//v1 = src + dy * src_volume + y_low * src_width * 3 + x_low * 3;
					v1 = src + dy * src_area + y_low * src_width * 1 + x_low * 1;

				if (x_high < src_width) //
					//v2 = src + dy * src_volume + y_low * src_width * 3 + x_high * 3;
					v2 = src + dy * src_area + y_low * src_width * 1 + x_high * 1;
			}

			if (y_high < src_height)
			{
				if (x_low >= 0)
					//v3 = src + dy * src_volume + y_high * src_width * 3 + x_low * 3;
					v3 = src + dy * src_area + y_high * src_width * 1 + x_low * 1;

				if (x_high < src_width)
					//v4 = src + dy * src_volume + y_high * src_width * 3 + x_high * 3;
					v4 = src + dy * src_area + y_high * src_width * 1 + x_high * 1;
			}
			// 
			c0 = floorf(w1 * v1[0] + w2 * v2[0] + w3 * v3[0] + w4 * v4[0] + 0.5f);
			/*c1 = floorf(w1 * v1[1] + w2 * v2[1] + w3 * v3[1] + w4 * v4[1] + 0.5f);
			c2 = floorf(w1 * v1[2] + w2 * v2[2] + w3 * v3[2] + w4 * v4[2] + 0.5f);*/
		}
		//uint8_t* pdst = dst + dy * dst_line_size + dx * 3;
		//float* pdst = dst + dy * dst_volume + dst_y * dst_width * 3 + dst_x * 3;
		float* pdst = dst + dy * dst_area + dst_y * dst_width * 1 + dst_x * 1;
		pdst[0] = c0;
	/*	pdst[1] = c1;
		pdst[2] = c2;*/
	}
}

__global__ 
void bgr2rgb_device_kernel(float* src, float* dst,
	int batch_size, int img_height, int img_width, int img_area, int img_volume)
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;
	if (dx < img_volume && dy < batch_size)
	{
		//dst[dy * img_volume + dx] = src[dy * img_volume + dx];
		int ch = dx % 3;
		assert(ch < 3);

		switch (ch)
		{
		case 0:
			dst[dy * img_volume + dx] = src[dy * img_volume + dx + 2];
			return;
		case 1:
			dst[dy * img_volume + dx] = src[dy * img_volume + dx];
			return;
		case 2:
			dst[dy * img_volume + dx] = src[dy * img_volume + dx - 2];
			return;
		}
	}
}

static __device__  
float norm_device(float val, float s, float mean, float std)
{
	return ((val / s) - mean) / std;
}

__global__ 
void norm_device_kernel(float* src, float* dst,
	int batch_size, int img_height, int img_width, int img_area, int img_volume,
	float scale,
	float mean0, float mean1, float mean2,
	float std0, float std1, float std2)
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;
	if (dx < img_volume && dy < batch_size)
	{
		int ch = dx % 3;
		assert(ch < 3);

		switch (ch)
		{
		case 0:
			dst[dy * img_volume + dx] = norm_device(src[dy * img_volume + dx], scale, mean0, std0);
			break;
		case 1:
			dst[dy * img_volume + dx] = norm_device(src[dy * img_volume + dx], scale, mean1, std1);
			break;
		case 2:
			dst[dy * img_volume + dx] = norm_device(src[dy * img_volume + dx], scale, mean2, std2);
			break;
		}
		//dst[dy * img_volume + dx] = norm_device(src[dy * img_volume + dx], norm_param.scale, norm_param.means[ch], norm_param.stds[ch]);
	}
}

__global__ void hwc2chw_device_kernel(float* src, float* dst,
	int batch_size, int img_height, int img_width, int img_area, int img_volume)
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;
	if (dx < img_volume && dy < batch_size)
	{

		int ch = dx / img_area; // 0 1 2
		assert(ch < 3);
		int sub_idx = dx % img_area;
		int row = sub_idx / img_width;
		int col = sub_idx % img_width;

		int dx_ = row * (img_width * 3) + col * 3 + ch;
		dst[dy * img_volume + dx] = src[dy * img_volume + dx_];

		//printf("[x = %d; y = %d] \n", dx, dy);

	}
}
//note: resize rgb with padding
void resizeDevice(const int& batchSize, float* src, int srcWidth, int srcHeight,
	float* dst, int dstWidth, int dstHeight,
	float paddingValue, dl_utils::AffineMat matrix)
{
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 grid_size((dstWidth * dstHeight /** 3*/ + BLOCK_SIZE - 1) / BLOCK_SIZE,
		(batchSize + BLOCK_SIZE - 1) / BLOCK_SIZE);

	int src_volume = 3 * srcHeight * srcWidth;
	int src_area = srcHeight * srcWidth;

	int dst_volume = 3 * dstHeight * dstWidth;
	int dst_area = dstHeight * dstWidth;

	resize_rgb_padding_device_kernel << < grid_size, block_size, 0, nullptr >> > (src, srcWidth, srcHeight, src_area, src_volume,
		dst, dstWidth, dstHeight, dst_area, dst_volume,
		batchSize, paddingValue, matrix);
}

//overload:resize rgb with padding, but src's type is uin8
void resizeDevice(const int& batchSize, unsigned char* src, int srcWidth, int srcHeight,
	float* dst, int dstWidth, int dstHeight,
	float paddingValue, dl_utils::AffineMat matrix)
{
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 grid_size((dstWidth * dstHeight /** 3*/ + BLOCK_SIZE - 1) / BLOCK_SIZE,
		(batchSize + BLOCK_SIZE - 1) / BLOCK_SIZE);

	int src_volume = 3 * srcHeight * srcWidth;
	int src_area = srcHeight * srcWidth;

	int dst_volume = 3 * dstHeight * dstWidth;
	int dst_area = dstHeight * dstWidth;

	resize_rgb_padding_device_kernel << < grid_size, block_size, 0, nullptr >> > (src, srcWidth, srcHeight, src_area, src_volume,
		dst, dstWidth, dstHeight, dst_area, dst_volume,
		batchSize, paddingValue, matrix);
}

// overload: resize rgb/gray without padding
void resizeDevice(const int& batchSize, float* src, int srcWidth, int srcHeight,
	float* dst, int dstWidth, int dstHeight, 
	dl_utils::ColorMode mode, dl_utils::AffineMat matrix)
{
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 grid_size((dstWidth * dstHeight /** 3*/ + BLOCK_SIZE - 1) / BLOCK_SIZE,
		(batchSize + BLOCK_SIZE - 1) / BLOCK_SIZE);
	int src_area = srcHeight * srcWidth;
	int dst_area = dstHeight * dstWidth;

	int src_volume = 3 * srcHeight * srcWidth;
	int dst_volume = 3 * dstHeight * dstWidth;
	
	switch (mode)
	{
	case dl_utils::ColorMode::RGB:
		resize_rgb_without_padding_device_kernel << < grid_size, block_size, 0, nullptr >> > (src, srcWidth, srcHeight, src_area, src_volume,
			dst, dstWidth, dstHeight, dst_area, dst_volume,
			batchSize, matrix);
		return;
	case dl_utils::ColorMode::GRAY:
		resize_gray_without_padding_device_kernel << < grid_size, block_size, 0, nullptr >> > (src, srcWidth, srcHeight, src_area, /*src_volume,*/
			dst, dstWidth, dstHeight, dst_area, /*dst_volume,*/
			batchSize, matrix);
		return;
	}
}

void bgr2rgbDevice(const int& batchSize, float* src, int srcWidth, int srcHeight,
	float* dst, int dstWidth, int dstHeight)
{
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 grid_size((dstWidth * dstHeight * 3 + BLOCK_SIZE - 1) / BLOCK_SIZE,
		(batchSize + BLOCK_SIZE - 1) / BLOCK_SIZE);

	int img_volume = 3 * srcHeight * srcWidth;
	int img_area = srcHeight * srcWidth;
	int img_height = srcHeight;
	int img_width = srcWidth;
	bgr2rgb_device_kernel << < grid_size, block_size, 0, nullptr >> > (src, dst, batchSize, img_height, img_width, img_area, img_volume);
}

void normDevice(const int& batchSize, float* src, int srcWidth, int srcHeight,
	float* dst, int dstWidth, int dstHeight,
	dl_utils::InitParameter param)
{
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 grid_size((dstWidth * dstHeight * 3 + BLOCK_SIZE - 1) / BLOCK_SIZE,
		(batchSize + BLOCK_SIZE - 1) / BLOCK_SIZE);

	int img_volume = 3 * srcHeight * srcWidth;
	int img_area = srcHeight * srcWidth;
	int img_height = srcHeight;
	int img_width = srcWidth;
	norm_device_kernel << < grid_size, block_size, 0, nullptr >> > (src, dst, batchSize, img_height, img_width, img_area, img_volume,
		param.scale, param.means[0], param.means[1], param.means[2], param.stds[0], param.stds[1], param.stds[2]);
}

void hwc2chwDevice(const int& batchSize, float* src, int srcWidth, int srcHeight,
	float* dst, int dstWidth, int dstHeight)
{
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 grid_size((dstWidth * dstHeight * 3 + BLOCK_SIZE - 1) / BLOCK_SIZE,
		(batchSize + BLOCK_SIZE - 1) / BLOCK_SIZE);


	int img_volume = 3 * srcHeight * srcWidth;
	int img_area = srcHeight * srcWidth;
	int img_height = srcHeight;
	int img_width = srcWidth;
	hwc2chw_device_kernel << < grid_size, block_size, 0, nullptr >> > (src, dst, batchSize, img_height, img_width, img_area, img_volume);
}

/************************************************************************************************
* postprocess kernel function  
*************************************************************************************************/
// for yolo3 yolo5 yolo6 yolo7
__global__ 
void decode_yolo_device_kernel(int batch_size, int  num_class, int topK, float conf_thresh,
	float* src, int srcWidth, int srcHeight, int srcArea,
	float* dst, int dstWidth, int dstHeight, int dstArea)
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x; // "srcArea" dim
	int dy = blockDim.y * blockIdx.y + threadIdx.y; // "batch size" dim
	if (dx >= srcHeight || dy >= batch_size)
	{
		return;
	}
	float* pitem = src + dy * srcArea + dx * srcWidth;
	float objectness = pitem[4]; //  Pr(Object)
	if (objectness < conf_thresh)
	{
		return;
	}
	// find max Pr(Classi/Object)
	// 5: xywhp
	float* class_confidence = pitem + 5;    // Pr(Class0/Object)
	float confidence = *class_confidence++; // Pr(Class1/Object)
	int label = 0;
	for (int i = 1; i < num_class; ++i, ++class_confidence)
	{
		if (*class_confidence > confidence)
		{
			confidence = *class_confidence;
			label = i;
		}
	}
	confidence *= objectness; // Pr(Class0/Object) * Pr(Object)
	if (confidence < conf_thresh)
	{
		return;
	}

	/*
	 parray:count, box1, box2, box3(count:num of good box)
	 parray[0]:count
	 atomicAdd -> count += 1
	 atomicAdd: return the old_count
	 int index = atomicAdd(dst + dy * dstArea, 1);
	 assert(dy == 1);
	*/
	int index = atomicAdd(dst + dy * dstArea, 1);

	//int index = atomicAdd(&(dst + dy * dstWidth)[0], 1);
	if (index >= topK)
	{
		return;
	}
	//printf("count = %f \n", (dst + dy * dstArea)[0]);
	// xywh -> xyxy
	float cx = *pitem++;
	float cy = *pitem++;
	float width = *pitem++;
	float height = *pitem++;
	float left = cx - width * 0.5f;
	float top = cy - height * 0.5f;
	float right = cx + width * 0.5f;
	float bottom = cy + height * 0.5f;
	// 1st element of parray is: count
	//float* pout_item = dst + dy * dstArea + 1 + index * dstWidth;
	float* pout_item = dst + dy * dstArea + 1 + index * dstWidth;
	*pout_item++ = left;
	*pout_item++ = top;
	*pout_item++ = right;
	*pout_item++ = bottom;
	*pout_item++ = confidence;
	*pout_item++ = label;
	*pout_item++ = 1;// 1 = keep, 0 = ignore
}

static __device__ 
float box_iou(
	float aleft, float atop, float aright, float abottom,
	float bleft, float btop, float bright, float bbottom
) {
	float cleft = max(aleft, bleft);
	float ctop = max(atop, btop);
	float cright = min(aright, bright);
	float cbottom = min(abottom, bbottom);

	float c_area = max(cright - cleft, 0.0f) * max(cbottom - ctop, 0.0f);
	if (c_area == 0.0f)
		return 0.0f;

	float a_area = max(0.0f, aright - aleft) * max(0.0f, abottom - atop);
	float b_area = max(0.0f, bright - bleft) * max(0.0f, bbottom - btop);
	return c_area / (a_area + b_area - c_area);
}

__global__ 
void nms_fast_kernel(int topK, int batch_size, float iou_thresh,
	float* src, int srcWidth, int srcHeight, int srcArea) // topK = srcHeigh
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;

	//int count = min((int)*(src + dy * srcArea), topK);
	if (dy >= batch_size) // prevent from p_temp out of range, eg: dy >= batch_size
	{
		return;
	}
	float* p_count = src + dy * srcArea;
	int count = min(int(p_count[0]), topK);
	
	if (dx >= count)
	{
		return;
	}

	// left, top, right, bottom, confidence, class, keepflag
	float* pcurrent = src + dy * srcArea + 1 + dx * srcWidth; // one row data
	for (int i = 0; i < count; ++i) 
	{
		float* pitem = src + dy * srcArea + 1 + i * srcWidth; 
		if (i == dx || pcurrent[5] != pitem[5]) 
			continue;

		if (pitem[4] >= pcurrent[4])
		{
			if (pitem[4] == pcurrent[4] && i < dx) 
				continue;

			float iou = box_iou(pcurrent[0], pcurrent[1], pcurrent[2], pcurrent[3],
				pitem[0], pitem[1], pitem[2], pitem[3]);

			if (iou > iou_thresh)
			{
				pcurrent[6] = 0;  // 1=keep, 0=ignore
				return;
			}
		}
	}
}

__global__
void get_key_val_kernel(int batchSize, float* src, int srcWidth, int srcHeight, int srcArea,
	int* idx, float* conf)
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;
	if (dy >= batchSize || dx >= srcHeight) // srcHeight = topK
	{
		return;
	}
	int* p_idx_row    = idx  + dy * srcHeight + dx;
	float* p_conf_row = conf + dy * srcHeight + dx;

	p_idx_row[0] = dx;
	// left, top, right, bottom, confidence, class, keepflag
	float* p_src_row = src + dy * srcArea + 1 + dx * srcWidth; 
	p_conf_row[0] = p_src_row[4];
}

__global__
void nms_sort_kernel(int topK, int batch_size, float iou_thresh,
	float* src, int srcWidth, int srcHeight, int srcArea,
	int* idx) // topK = srcHeigh,
{
	int dx = blockDim.x * blockIdx.x + threadIdx.x;
	int dy = blockDim.y * blockIdx.y + threadIdx.y;

	//int count = min((int)*(src + dy * srcArea), topK);
	if (dy >= batch_size) // prevent from p_temp out of range, eg: dy >= batch_size
	{
		return;
	}
	float* p_count = src + dy * srcArea;
	int count = min(int(p_count[0]), topK);

	if (dx >= count)
	{
		return;
	}

	//
	int* p_idx1 = idx + dy * srcHeight + dx;
	float* pcurrent = src + dy * srcArea + 1 + p_idx1[0] * srcWidth;  // left, top, right, bottom, confidence, class, keepflag
	
	for (int i = (dx + 1); i < count; ++i) // 
	{
		int* p_idx2 = idx + dy * srcHeight + i;
		float* pitem = src + dy * srcArea + 1 + p_idx2[0] * srcWidth; //
		
		if (abs(pcurrent[5] - pitem[5]) > 1e-3) //
			continue;
		float iou = box_iou(pcurrent[0], pcurrent[1], pcurrent[2], pcurrent[3],
			pitem[0], pitem[1], pitem[2], pitem[3]);

		if (iou > iou_thresh)
		{
			pitem[6] = 0;  // 1=keep, 0=ignore 
		}
	}
}

void decodeDevice(dl_utils::InitParameter param, float* src, int srcWidth, int srcHeight, int srcArea, float* dst, int dstWidth, int dstHeight)
{
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 grid_size((srcHeight + BLOCK_SIZE - 1) / BLOCK_SIZE,
		(param.batch_size + BLOCK_SIZE - 1) / BLOCK_SIZE);
	int dstArea = 1 + dstWidth * dstHeight;

	decode_yolo_device_kernel << < grid_size, block_size, 0, nullptr >> > (param.batch_size, param.num_class, param.topK, param.conf_thresh,
		src, srcWidth, srcHeight, srcArea,
		dst, dstWidth, dstHeight, dstArea);
}

void nmsDeviceV1(dl_utils::InitParameter param, float* src, int srcWidth, int srcHeight, int srcArea)
{
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 grid_size((param.topK + BLOCK_SIZE - 1) / BLOCK_SIZE, // todo
		(param.batch_size + BLOCK_SIZE - 1) / BLOCK_SIZE);

	nms_fast_kernel << < grid_size, block_size, 0, nullptr >> > (param.topK, param.batch_size, param.iou_thresh,
		src, srcWidth, srcHeight, srcArea);
}
// nms with sort
void nmsDeviceV2(dl_utils::InitParameter param, float* src, int srcWidth, int srcHeight, int srcArea,
	int* idx, float* conf)
{
	dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
	dim3 grid_size((param.topK + BLOCK_SIZE - 1) / BLOCK_SIZE, // todo
		(param.batch_size + BLOCK_SIZE - 1) / BLOCK_SIZE);

	// get keys and vals(confs)
	get_key_val_kernel << < grid_size, block_size, 0, nullptr >> > (param.batch_size, src, srcWidth, srcHeight, srcArea, idx, conf);
	//checkRuntime(cudaDeviceSynchronize()); 

	// sort by conf
	for (size_t i = 0; i < param.batch_size; i++)
	{
		int* p_idx     = idx + i * srcHeight;
		float* p_conf = conf + i * srcHeight;
		thrust::sort_by_key(thrust::device, p_conf, p_conf + srcHeight, p_idx, thrust::greater<float>());
	}
	
	nms_sort_kernel << < grid_size, block_size, 0, nullptr >> > (param.topK, param.batch_size, param.iou_thresh,
		src, srcWidth, srcHeight, srcArea, idx);
}
