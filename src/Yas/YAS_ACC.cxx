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

		void YAS_ACC::YAS_Pre_Driver() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Pre_Driver are started."));

			this->_tmpDir = string("yaccgen_") + yaccgen::gen_str(10);
			exec_newdir(_tmpDir);

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

		void YAS_ACC::YAS_CheckPragmas() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_CheckPragmas are started."));

			//3 main concepts
			vector<string> items = yaccgen::findBlock_inCode(this->_finSS, tok_acc_parallel);
			for (uint var = 0; var < items.size(); ++var) {
				pair<string, string> np(tok_acc_parallel, items[var]);
				this->_pragmaCodeBlocks.push_back(np);
			}
			items = yaccgen::findBlock_inCode(this->_finSS, tok_acc_kernels);
			for (uint var = 0; var < items.size(); ++var) {
				pair<string, string> np(tok_acc_kernels, items[var]);
				this->_pragmaCodeBlocks.push_back(np);
			}
			items = yaccgen::findBlock_inCode(this->_finSS, tok_acc_data);
			for (uint var = 0; var < items.size(); ++var) {
				pair<string, string> np(tok_acc_data, items[var]);
				this->_pragmaCodeBlocks.push_back(np);
			}

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_CheckPragmas finished."));
		}

		void YAS_ACC::YAS_DepedencyIdentifier() {
		}

		void YAS_ACC::YAS_Parallelizer() {
		}

		void YAS_ACC::YAS_Post_Driver() {
		}
	}
}
