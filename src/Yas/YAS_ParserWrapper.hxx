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
#include "../codegen/YAS_CudaGen.hxx"

using namespace yaccgen;
using namespace codegen;

namespace yaccgen {
	namespace yas {

		class YAS_ParserWrapper {
		private:
			Project *_prj;
			TransUnit *_unit;
			vector<ForStemnt*> _forList;
			string _workingDir;
		public:

			vector<YAS_CudaGen*> _cudaGenerator;

			YAS_ParserWrapper(const char* fname, string workingDir, bool use_cpp, bool isDebug);

			virtual ~YAS_ParserWrapper();

			void parse_accpragma();

			void generate_cuda();

			void print_cuda();
		}
		;
	}
}
#endif /* YASPARSERWRAPPER_H_ */
