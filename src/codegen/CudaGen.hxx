/*
 * cudagen.hxx
 *
 *  Created on: Jul 18, 2013
 *      Author: grypp
 */

#ifndef CUDAGEN_HXX_
#define CUDAGEN_HXX_

#include "../Utils/YACCGenLog.hxx"
#include "../Utils/YACCGenUtils.hxx"
#include "../Utils/CPPParser.hxx"
#include "../Utils/AccTokens.hxx"
#include "CUDAFunctions.hxx"
#include "KernelFunctions.hxx"
#include "YAS_CudaKernel.hxx"

namespace yaccgen {
	namespace codegen {

		const static string ERR_GEN = "GEN_001";

		class CudaGen {

		public:
			CudaGen();

			~CudaGen();

			void YAS_gridfy_1d(stringstream&, YAS_CudaKernel&);

			YAS_CudaKernel YAS_identifier(stringstream &ss);

			CUDAKernel YAS_gen_kernel();

			CUDAKernel YAS_gen_kernel(int blkx, int blky, int thrdx, int thrdy, int thrdz, int dynm);

		private:
			string YAS_gen_kernelName();
		};
	}
}

#endif /* CUDAGEN_HXX_ */
