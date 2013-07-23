/*
 * YAS_ACC.cxx
 *
 *  Created on: Jul 23, 2013
 *      Author: grypp
 */

#include "YAS_ACC.hxx"
#include <typeinfo>
namespace yaccgen {
	namespace codegen {

		yaccgen::codegen::YAS_ACC::YAS_ACC(const char *fnameIn, const char *fnameOut) {
			_fnameIn = fnameIn;
			_fnameOut = fnameOut;
		}

		yaccgen::codegen::YAS_ACC::~YAS_ACC() {
			if (_fin.is_open()) _fin.close();
			if (_fout.is_open()) _fout.close();
			_finSS.str("");
		}

		void yaccgen::codegen::YAS_ACC::YAS_ACC_PerformAllSteps() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : Compiling Steps are started."));
			try {

				YAS_Pre_Driver();

				YAS_CheckPragmas();

				YAS_DepedencyIdentifier();

				YAS_Parallelizer();

				YAS_Post_Driver();

			} catch (YACCGenException e) {
			} //catch (YACCGenException e) {
			  //}
			YACCGenLog_write_Debug(getClassName(this) + string(" : Compiling Steps finished."));
		}

		void yaccgen::codegen::YAS_ACC::YAS_Pre_Driver() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Pre_Driver are started."));

			this->_tmpDir = string("yaccgen_") + yaccgen::gen_str(10);
			this->_fnameInWorking = mergePath(_tmpDir, string("yaccgen_") + _fnameIn).c_str();
			copy_file(_fnameIn, _fnameInWorking);
			_fin.open(_fnameInWorking);

			string line;
			while (!_fin.eof()) {
				std::getline(_fin, line);
				_finSS << line << endl;
			}

			_fin.seekg(0, std::ios::beg);

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Pre_Driver finished."));
		}

		void yaccgen::codegen::YAS_ACC::YAS_CheckPragmas() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_CheckPragmas are started."));
			//3 main concepts
			vector<string> ACCTokenList;
			ACCTokenList.push_back(tok_acc_kernels);
			ACCTokenList.push_back(tok_acc_parallel);
			ACCTokenList.push_back(tok_acc_data);

			this->_pragmaCodeBlocks = yaccgen::findBlock_inCode(this->_finSS, ACCTokenList);

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_CheckPragmas finished."));
		}

		void yaccgen::codegen::YAS_ACC::YAS_DepedencyIdentifier() {
		}

		void yaccgen::codegen::YAS_ACC::YAS_Parallelizer() {
		}

		void yaccgen::codegen::YAS_ACC::YAS_Post_Driver() {
		}
	}
}
