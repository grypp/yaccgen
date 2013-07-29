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

		void YAS_CGen::print_file() {
			ofstream fout(_fname.c_str());
			fout << this->_codeBlock.str();
			fout.close();
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
			stringstream ss;
			if (!param.val.empty()) ss << param.type << yaccgen::tok_ws << param.name << yaccgen::tok_eq << param.val << yaccgen::tok_semicolon;
			else ss << param.type << yaccgen::tok_ws << param.name << yaccgen::tok_semicolon;
			add_line(ss.str());
		}

		void YAS_CGen::add_openBlock() {
			add_line(tok_openCrlyBracket);
			_level++;
		}

		void YAS_CGen::add_closeBlock() {
			_level--;
			add_line(tok_closeCrlyBracket);
		}

		void YAS_CGen::add_for(string assignment, string binary, string unary) {
			string forstr;
			forstr.reserve(100);
			forstr.append(tok_for + tok_openBracket);
			forstr.append(assignment + tok_semicolon);
			forstr.append(binary + tok_semicolon);
			forstr.append(unary);
			forstr.append(tok_closeBracket);
			add_line(forstr);
		}

		void YAS_CGen::add_line(string line) {
			for (int var = 0; var < _level; ++var)
				this->_codeBlock << "\t";
			this->_codeBlock << line << endl;
		}
	}
}
