#include "CUDAFunctions.hxx"

using namespace std;

namespace yaccgen {

#if 0
template <typename T>
__device__ __inline__ void gr_copyin(T * dst, T * src, size_t num_element)
{
	for (size_t i = 0; i < num_element; i += (blockDim.x * blockDim.y))
	{
		size_t pos = i + (threadIdx.y * blockDim.x + threadIdx.x);
		if (pos < num_element)
		{
			dst[pos] = src[pos];
		}
	}
#endif
}
