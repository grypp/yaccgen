/*
 * ACCPException.cxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#include "YACCGenException.hxx"

namespace yaccgen {
	YACCGenException::YACCGenException(const std::string &str) :
			std::runtime_error(str) {
#ifdef ACCP_VERBOSE_EXCEPTIONS
		std::cout << "Throwing Exception:" << str << std::endl;
#endif
	}
}

