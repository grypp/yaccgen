/*
 * YAS_ACC.cxx
 *
 *  Created on: Jul 23, 2013
 *      Author: grypp
 */

#include "YAS_ACC.hxx"

namespace yaccgen {

	namespace yas {

		YAS_ACC::YAS_ACC(const char *fnameIn, const char *fnameOut, bool removeFiles) {
			if (!is_file_exist(fnameIn)) throw new yaccgen::YACCGenException(string("File not exist") + fnameIn);
			_fnameIn = fnameIn;
			_fnameOut = fnameOut;
			_removeFiles = removeFiles;
		}

		YAS_ACC::~YAS_ACC() {
			if (_fin.is_open()) _fin.close();
			if (_fout.is_open()) _fout.close();
			_finSS.str("");
		}

		void YAS_ACC::YAS_ACC_PRE_PerformYASSteps() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : PRE Compiling Steps are started."));

			try {

				YAS_Prepare();

				YAS_Pre_Driver();

			} catch (YACCGenException e) {
				throw e;
			} catch (std::exception e) {
				throw e;
			}

			YACCGenLog_write_Debug(getClassName(this) + string(" : PRE Compiling Steps finished."));
		}

		void YAS_ACC::YAS_ACC_POST_PerformYASSteps() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : POST Compiling Steps are started."));

			try {
				YAS_CheckPragmas();

				YAS_DepedencyIdentifier();

				YAS_Parallelizer();

				YAS_Post_Driver();

			} catch (YACCGenException e) {
				throw e;
			} catch (std::exception e) {
				throw e;
			}

			YACCGenLog_write_Debug(getClassName(this) + string(" : POST Compiling Steps finished."));
		}

		void YAS_ACC::YAS_ACC_PerformYASSteps() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : Compiling Steps are started."));
			try {

				YAS_ACC_PRE_PerformYASSteps();

				YAS_ACC_POST_PerformYASSteps();

			} catch (YACCGenException e) {
				throw e;
			} catch (std::exception e) {
				throw e;
			}
			YACCGenLog_write_Debug(getClassName(this) + string(" : Compiling Steps finished."));
		}

		void YAS_ACC::YAS_Prepare() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Prepare are started."));

			this->_tmpDir = string("yaccgen_") + yaccgen::gen_str(10);
			exec_newdir(_tmpDir);

			string workingFile = mergePath(_tmpDir, string("yaccgen_") + _fnameIn);
			this->_fnameInWorking = workingFile.c_str();
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Prepare finished."));
		}

		void YAS_ACC::YAS_Pre_Driver() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Pre_Driver are started."));

			copy_file(_fnameIn.c_str(), _fnameInWorking.c_str());
			_fin.open(_fnameInWorking.c_str());

			if (!_fin.is_open()) throw YACCGenCodegenException(getClassName(this) + string(" File can't be opened"));

			string line;
			while (!_fin.eof()) {
				std::getline(_fin, line);
				_finSS << line << endl;
			}
			_fin.seekg(0, std::ios::beg);

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Pre_Driver finished."));
		}

		void YAS_ACC::YAS_CheckPragmas() {

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_CheckPragmas are started."));
			try {

				parser = new YAS_ParserWrapper(_fnameInWorking.c_str(), false, false);
				parser->parse_accpragma();

			} catch (YACCGenException e) {
				throw e;
			} catch (std::exception e) {
				throw e;
			}
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_CheckPragmas finished."));
		}

		void YAS_ACC::YAS_DepedencyIdentifier() {
		}

		void YAS_ACC::YAS_Parallelizer() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Parallelizer are started."));

			try {

				parser->generate_cuda();

			} catch (YACCGenException e) {
				throw e;
			} catch (std::exception e) {
				throw e;
			}

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Parallelizer finished."));
		}

		void YAS_ACC::YAS_Post_Driver() {

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Post_Driver are started."));
			try {

				string kernelName = mergePath(this->_tmpDir, "kernel0.cu");
				ofstream fout(kernelName.c_str());
				parser->print_cuda(fout);
				fout.close();

			} catch (YACCGenException e) {
				throw e;
			} catch (std::exception e) {
				throw e;
			}

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Post_Driver finished."));
		}
	}
}
