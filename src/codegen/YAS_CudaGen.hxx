/*
 * cudagen.hxx
 *
 *  Created on: Jul 18, 2013
 *      Author: grypp
 */

#ifndef YASCUDAGEN_HXX_
#define YASCUDAGEN_HXX_

#include "../Utils/YACCGenUtils.hxx"
#include "../Utils/CPPParser.hxx"
#include "YAS_CudaKernel.hxx"
#include "YAS_CGen.hxx"
#include "KernelFunctions.hxx"

using namespace std;

namespace yaccgen {

	namespace codegen {

		class YAS_CudaGen: public YAS_CGen {

		public:
			YAS_CudaGen();

			~YAS_CudaGen();

			void add_method(string name, ParameterTable params);

			void add_method(vector<string> params);

			CUDAKernel YAS_gen_kernel();

			CUDAKernel YAS_gen_kernel(int blkx, int blky, int thrdx, int thrdy, int thrdz, int dynm);

			void YAS_gen_kernelName();

			string YAS_get_kernelName() const {
				return _name;
			}

		private:
			string _name;
		};
	}
}

#endif /* CUDAGEN_HXX_ */
