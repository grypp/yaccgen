/*
 * YAS_CudaKernel.hxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#ifndef YAS_CUDAKERNEL_HXX_
#define YAS_CUDAKERNEL_HXX_

#include <iostream>
#include <sstream>
#include "CUDAFunctions.hxx"

namespace yaccgen {
	namespace codegen {

		typedef struct {
			string sizeX;
			string sizeY;
			string sizeZ;

			string blockX;
			string blockY;

			string dynamicMemSize;

		} CUDAKernel;

		class YAS_CudaKernel {

		public:
			string _funcName;

			string _codeBody;

			//ParameterTable _params;

			CUDAKernel _kernelConf;

			YAS_CudaKernel();

			~YAS_CudaKernel();

			string toString_kernelConf();
		};
	}
}
#endif /* YAS_CUDAKERNEL_HXX_ */
