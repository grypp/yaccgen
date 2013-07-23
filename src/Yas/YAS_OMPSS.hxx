/*
 * yas_ompss.hxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#ifndef YAS_OMPSS_HXX_
#define YAS_OMPSS_HXX_

#include "../Utils/YACCGenUtils.hxx"
#include "../codegen/YAS_CudaKernel.hxx"

namespace yaccgen {
	namespace yas {

		void YAS_OmpSs_Init(const char* fnameIn, const char* fnameOut, bool removeFile);

		void YAS_GENKERNEL(const char* fnameIn, const char* dir, bool removeFile);

		void YAS_OmpSs_2ACC(const char* fnameIn, const char* fnameOut, bool removeFile);
	}
}

#endif /* YAS_OMPSS_HXX_ */
