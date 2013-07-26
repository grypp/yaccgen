/*
 * yas_ompss.hxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#ifndef YAS_OMPSS_HXX_
#define YAS_OMPSS_HXX_

#include "../Utils/YACCGenUtils.hxx"
#include "YAS_ACC.hxx"

namespace yaccgen {
	namespace yas {

		class YAS_OMPSS: public YAS_ACC {

		public:

			YAS_OMPSS(const char* fnameIn, const char* fnameOut, bool removeFile);

			void YAS_OmpSs_2ACC(const char* fnameOut);

			void YAS_ACC_PRE_PerformYASSteps();

		};
	}
}

#endif /* YAS_OMPSS_HXX_ */

