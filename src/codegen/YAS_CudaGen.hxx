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

		private:
			vector<yaccgen_param> _params;
			CUDAKernel _currentKernel;

		public:
			YAS_CudaGen();

			YAS_CudaGen(string fname) : YAS_CGen(fname) { }

			~YAS_CudaGen();

			void add_method(string name, ParameterTable params);

			void add_method(vector<string> params);

			void YAS_gen_kernel();

			void YAS_gen_kernel(int blkx, int blky, int thrdx, int thrdy, int thrdz, int dynm);

			string YAS_get_kernel_ndrangeFormat();

			string YAS_get_kernel_signature();

			string YAS_get_kernel_invoke();

		};
	}
}

#endif /* CUDAGEN_HXX_ */
