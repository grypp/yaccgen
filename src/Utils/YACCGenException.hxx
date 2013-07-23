/*
 * YACCGenException.hxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#ifndef YACCGenEXCEPTION_HXX_
#define YACCGenEXCEPTION_HXX_

#include <exception>
#include <stdexcept>

namespace yaccgen {

	class YACCGenException: public std::runtime_error {
	public:
		YACCGenException(const std::string &str);
	};

	class YACCGenCompileException: public YACCGenException {
	public:
		YACCGenCompileException(const std::string &str) :
				YACCGenException(str) {
		}
	};

	class YACCGenCodegenException: public YACCGenException {
	public:
		YACCGenCodegenException(const std::string &str):
				YACCGenException(str) {
		}
	};

}

#endif /* YACCGenEXCEPTION_HXX_ */
