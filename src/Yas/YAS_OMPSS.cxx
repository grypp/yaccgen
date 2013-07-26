/*
 * yas_ompss.cxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#include "YAS_OMPSS.hxx"

using namespace yaccgen;

namespace yaccgen {

	namespace yas {

		YAS_OMPSS::YAS_OMPSS(const char* fnameIn, const char* fnameOut, bool removeFile) :
				YAS_ACC(fnameIn, fnameOut, removeFile) {

		}

		void YAS_OMPSS::YAS_ACC_PRE_PerformYASSteps() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : Compiling Steps are started."));
			try {
				YAS_ACC::YAS_Prepare();

				string accFname = string("acc_") + gen_str(10) + string(_fnameIn);
				YAS_OmpSs_2ACC(mergePath(this->_tmpDir, accFname).c_str());
				this->_fnameIn = mergePath(this->_tmpDir, accFname);

				YAS_ACC::YAS_Pre_Driver();

			} catch (YACCGenException e) {
				throw e;
			} catch (std::exception e) {
				throw e;
			}
			YACCGenLog_write_Debug(getClassName(this) + string(" : Compiling Steps are started."));
		}

		void YAS_OMPSS::YAS_OmpSs_2ACC(const char* fnameOut) {
			fstream fin(_fnameIn.c_str());
			ofstream fout(fnameOut);
			string line;

			//-----------------------------parsing from OmpSs to openACC--------------------
			string accStructPragma;
			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find("#pragma", 0) != std::string::npos) {
					if (line.find("#pragma omp for", 0) != std::string::npos) {
						replaceAll(line, "omp for", "acc loop");
						fout << line << endl;
					}
					if (line.find("device(acc/cuda)", 0) != std::string::npos) {
						yaccgen::replaceAll(line, "copy_inout(", "copy(");
						yaccgen::replaceAll(line, "copy_in(", "copyin(");
						yaccgen::replaceAll(line, "copy_out(", "copyout(");
						yaccgen::replaceAll(line, "omp target device(acc/cuda)", "acc kernels");
						accStructPragma = line;

						std::getline(fin, line);
						if (line.find("#pragma omp task", 0) == std::string::npos) {
							cout << "#pragma omp task" << endl;
							exit(-1);
						}
						std::getline(fin, line);
						if (line.find("#pragma", 0) == std::string::npos) {
							fout << accStructPragma << endl;
							fout << line << endl;
							continue;
						}

						if (line.find("#pragma omp for", 0) != std::string::npos) {
							fout << accStructPragma << endl;
							replaceAll(line, "omp for", "acc loop");
							fout << line << endl;
						} else if (line.find("#pragma omp parallel", 0) != std::string::npos) {
							yaccgen::replaceAll(accStructPragma, "kernels", line.substr(line.find("parallel", 0), line.size()));
							yaccgen::replaceAll(accStructPragma, "for", "loop");
							fout << accStructPragma << endl;
						}
					}
				} else fout << line << endl;
			}
			fout.close();
			fin.close();

			//if (this->_removeFiles) remove(fnameOut);
		}

	}
}
