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

			int _level;
			string _fname;

		public:
			stringstream _codeBlock;

			YAS_CGen();

			YAS_CGen(string fname) {
				_fname = fname;
				_level=0;
			}

			virtual ~YAS_CGen();

			void print_file() {
				print_file("", "");
			}

			void print_file(string dir, string ext);

			virtual void add_method(string returnType, string name, ParameterTable params);

			void add_openBlock();

			void add_param(yaccgen_param param);

			void add_closeBlock();

			virtual void add_line(string line);

			virtual void add_for(string assignment, string binary, string unary);

			string YAS_get_name() const {
				return _fname;
			}

		};

	}
}
#endif /* YASCGEN_HXX_ */
