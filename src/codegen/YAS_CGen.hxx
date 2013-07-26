/*
 * YASCGen.hxx
 *
 *  Created on: Jul 26, 2013
 *      Author: grypp
 */

#ifndef YASCGEN_HXX_
#define YASCGEN_HXX_

#include "../Utils/YACCGenUtils.hxx"
#include "../Utils/CPPParser.hxx"

namespace yaccgen {

	namespace codegen {

		class YAS_CGen {

		protected:
			stringstream _codeBlock;

		public:
			YAS_CGen();

			virtual ~YAS_CGen();

			void print_file(const char* fname);

			virtual void add_method(string returnType, string name, ParameterTable params);

			void add_openBlock();

			void add_param(yaccgen_param param);

			void add_closeBlock();

			virtual void add_line(string line);

		};

	}
}
#endif /* YASCGEN_HXX_ */
