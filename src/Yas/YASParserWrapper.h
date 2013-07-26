/*
 * YASParserWrapper.h
 *
 *  Created on: Jul 25, 2013
 *      Author: grypp
 */

#ifndef YASPARSERWRAPPER_H_
#define YASPARSERWRAPPER_H_

#include <iostream>
#include <vector>
#include "../Utils/YACCGenUtils.hxx"
#include "../parser/ctool.h"
#include "../parser/PrintTraversal.h"

namespace yaccgen {
	namespace yas {

		class YAS_Parser_Wrapper {
		private:
			Project *prj;
			TransUnit *unit;
		public:

			YAS_Parser_Wrapper(const char* fList, bool use_cpp, bool isDebug);

			virtual ~YAS_Parser_Wrapper();

			vector<string> get_Statement_For();

			vector<string> get_Statement_ACCPragma();
		}
		;
	}
#endif /* YASPARSERWRAPPER_H_ */
