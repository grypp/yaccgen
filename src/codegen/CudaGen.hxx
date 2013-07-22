/*
 * cudagen.hxx
 *
 *  Created on: Jul 18, 2013
 *      Author: grypp
 */

#ifndef CUDAGEN_HXX_
#define CUDAGEN_HXX_

#include "../Utils/YACCGenUtils.hxx"
#include "YAS_CudaKernel.hxx"
#include "../Utils/CPPParser.hxx"
#include "KernelFunctions.hxx"

using namespace std;

namespace yaccgen {

	namespace codegen {

		class CudaGen {

		public:
			CudaGen();
			~CudaGen();
			void YAS_gridfy_1d(stringstream &ss, YAS_CudaKernel &currentKernel);
			vector<YAS_CudaKernel> YAS_identifier(stringstream &ss);

		private:
			string YAS_gen_kernelName();
			CUDAKernel YAS_gen_kernel();
			CUDAKernel YAS_gen_kernel(int blkx, int blky, int thrdx, int thrdy, int thrdz, int dynm);

		};
	}
}

#endif /* CUDAGEN_HXX_ */
