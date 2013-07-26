/*
 * YASCGen.cxx
 *
 *  Created on: Jul 26, 2013
 *      Author: grypp
 */

#include "YAS_CGen.hxx"

namespace yaccgen {
	namespace codegen {

		YAS_CGen::YAS_CGen() {
		}

		YAS_CGen::~YAS_CGen() {
			_codeBlock.str("");
		}

		void YAS_CGen::print_file(const char* fname) {
			ofstream fout(fname);
			fout << this->_codeBlock;
		}

		void YAS_CGen::add_method(string returnType, string name, ParameterTable params) {
			this->_codeBlock << returnType << tok_ws;
			this->_codeBlock << name << tok_ws << tok_openBracket;

			for (uint var = 0; var < params.size(); ++var) {
				this->_codeBlock << ((yaccgen_param) params[var]).type << tok_ws;
				this->_codeBlock << ((yaccgen_param) params[var]).name << tok_ws;
				if (var != params.size() - 1) this->_codeBlock << tok_comma;
			}

			this->_codeBlock << tok_closeBracket << endl;
		}

		void YAS_CGen::add_param(yaccgen_param param) {
			if (param.val.empty()) this->_codeBlock << param.type << yaccgen::tok_ws << param.name << yaccgen::tok_eq << param.val << yaccgen::tok_semicolon << '\n';
			else this->_codeBlock << param.type << yaccgen::tok_ws << param.name << yaccgen::tok_semicolon << '\n';
		}

		void YAS_CGen::add_openBlock() {
			this->_codeBlock << tok_openCrlyBracket << endl;
		}

		void YAS_CGen::add_closeBlock() {
			this->_codeBlock << tok_openCrlyBracket << endl;
		}

		void YAS_CGen::add_line(string line) {
			this->_codeBlock << line << endl;
		}
	}
}
