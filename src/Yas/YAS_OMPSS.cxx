/*
 * yas_ompss.cxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#include "YAS_OMPSS.hxx"

using namespace yaccgen;
using namespace codegen;

namespace yaccgen {
	namespace yas {

		void YAS_OmpSs_Init(const char* fnameIn, const char* fnameOut, bool removeFile) {
			string newDir = string("yaccgen_") + yaccgen::gen_str(10);
			exec_newdir(newDir);

			string accFile = mergePath(newDir, string("acc_") + fnameIn);
			string workingOrgFile = mergePath(newDir, fnameIn);
			string yaccgenFile = mergePath(newDir, string("yaccgen_") + fnameIn);

			YAS_OmpSs_2ACC(fnameIn, accFile.c_str(), removeFile);
			copy_file(fnameIn, workingOrgFile.c_str());
			YAS_GENKERNEL(accFile.c_str(), newDir.c_str(), removeFile);
		}

		void YAS_OmpSs_2ACC(const char* fnameIn, const char* fnameOut, bool removeFile) {
			fstream fin(fnameIn);
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
			if (removeFile) remove(fnameOut);
		}

		void YAS_GENKERNEL(const char* fnameIn, const char* dir, bool removeFile) {
		/*	YAS_CudaKernel currentKernel;
			CudaGen cudaGenerator;
			std::string line;
			stringstream ss;
			fstream fin(fnameIn);

			if (!fin.good()) throw YACCGenCodegenException(string("File error :") + string(fnameIn));

			while (!fin.eof()) {
				std::getline(fin, line);
				if (line.find(yaccgen::tok_pragma, 0) != std::string::npos) {
					ss << line << endl;
					getInsideBrackets(fin, ss);
					vector<YAS_CudaKernel> kernels = cudaGenerator.YAS_identifier(ss);

				}
			}

			fin.close();*/
		}
	}
}
