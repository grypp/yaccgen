/*
 * yas_ompss.hxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#ifndef YAS_OMPSS_HXX_
#define YAS_OMPSS_HXX_

#include "../Utils/YACCGenUtils.hxx"
#include "../codegen/YAS_CGen.hxx"
#include "../codegen/YAS_CudaGen.hxx"
#include "../codegen/YAS_CudaKernel.hxx"
#include "YAS_ACC.hxx"

using namespace yaccgen;
using namespace codegen;

namespace yaccgen {
	namespace yas {

		class YAS_OMPSS: public YAS_ACC {

		private:
			YAS_CGen *_ompssGenerator;
			string _fnameInOmpss;

		public:

			YAS_OMPSS(const char* fnameIn, const char* fnameOut, bool removeFile);

			void YAS_OmpSs_2ACC(const char* fnameOut);

			void YAS_ACC_PRE_PerformYASSteps();

			void YAS_Parallelizer();

			void YAS_Post_Driver();

			void YAS_Compile();

		};
	}
}

#endif /* YAS_OMPSS_HXX_ */

