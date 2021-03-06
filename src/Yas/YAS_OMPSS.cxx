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
			_fnameInOmpss = fnameIn;
		}

		void YAS_OMPSS::YAS_ACC_PRE_PerformYASSteps() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : Compiling Steps are started."));
			try {
				YAS_ACC::YAS_Prepare();

				string accFname = pre_acc + gen_str(5) + string(_fnameIn);
				string ompssFname = pre_yaccgen + pre_ompss + string(get_filename(_fnameIn.c_str())) + "_" + gen_str(5);
				string ompssHeaderFname = pre_yaccgen + "auxheader_" + string(get_filename(_fnameIn.c_str())) + "_" + gen_str(5);
				YAS_OmpSs_2ACC(mergePath(this->_tmpDir, accFname).c_str());
				this->_fnameIn = mergePath(this->_tmpDir, accFname);
				_ompssGenerator = new YAS_CGen(ompssFname);
				_ompssHeaderGenerator = new YAS_CGen(ompssHeaderFname);

				YAS_ACC::YAS_Pre_Driver();

			} catch (YACCGenException e) {
				throw e;
			} catch (std::exception e) {
				throw e;
			}
			YACCGenLog_write_Debug(getClassName(this) + string(" : Compiling Steps are started."));
		}

		void YAS_OMPSS::YAS_Parallelizer() {
			//todo change approach
			try {

				YAS_ACC::YAS_Parallelizer();
				for (uint var = 0; var < this->parser->_cudaGenerator.size(); ++var)
					_ompssHeaderGenerator->add_line("#include \"" + parser->_cudaGenerator[var]->YAS_get_name() + "." + ext_CUDA + "\"");

				YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Parallelizerare is started."));

				fstream fin(_fnameInOmpss.c_str());
				if (!fin.good()) throw YACCGenCodegenException(getClassName(this) + " File is not opened: " + _fnameInOmpss);
				string line, prevLine;
				int kernelNameCounter = 0;
				while (!fin.eof()) {
					prevLine = line;
					std::getline(fin, line);
					trim(line);

					if (prevLine.find(tok_pp_include, 0) != std::string::npos && line.find(tok_pp_include, 0) == std::string::npos) {
						_ompssGenerator->add_line(string("#include \"") + _ompssHeaderGenerator->YAS_get_name() + "." + ext_H + "\"");
					} else if (line.find(tok_pp_pragma, 0) != std::string::npos) {
						if (line.find(tok_omp_devive_acc, 0) != std::string::npos) {
							replaceAll(line, tok_omp_devive_acc, tok_omp_devive_cuda);
							line.append(" " + tok_omp_ndrange + "(" + parser->_cudaGenerator[kernelNameCounter]->YAS_get_kernel_ndrangeFormat() + ")");
							_ompssHeaderGenerator->add_line(line);

							std::getline(fin, line);
							trim(line);
							if (line.find("#pragma omp task", 0) != std::string::npos) _ompssHeaderGenerator->add_line(line);
							else throw YACCGenCodegenException(getClassName(this) + "there is no #pragma omp task!");

							std::getline(fin, line);
							trim(line);
							if (line.find("#pragma", 0) != std::string::npos) {
								std::getline(fin, line);
								trim(line);
							}

							int bracket = line.find(tok_openCrlyBracket, 0) != std::string::npos ? 1 : 0;
							while (!fin.eof()) {
								std::getline(fin, line);
								trim(line);
								if (line.find(tok_openCrlyBracket, 0) != std::string::npos) bracket++;
								if (line.find(tok_closeCrlyBracket, 0) != std::string::npos) bracket--;
								if (bracket == 0) break;
							}

							_ompssGenerator->add_line(parser->_cudaGenerator[kernelNameCounter]->YAS_get_kernel_invoke() + tok_semicolon);
							_ompssHeaderGenerator->add_line(parser->_cudaGenerator[kernelNameCounter]->YAS_get_kernel_signature() + tok_semicolon);
							kernelNameCounter++;
						} else _ompssGenerator->add_line(line);

					} else _ompssGenerator->add_line(line);
				}

			} catch (exception e) {
				YACCGenLog_write_Error(e.what());
				throw e;
			} catch (YACCGenCodegenException e) {
				throw e;
			}
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Parallelizer finished."));
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

		}

		void YAS_OMPSS::YAS_Post_Driver() {
			YAS_ACC::YAS_Post_Driver();
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Parallelizer is started."));

			_ompssGenerator->print_file(this->_tmpDir, ext_C);
			_ompssHeaderGenerator->print_file(this->_tmpDir, ext_H);

			YACCGenLog_write_Info(getClassName(this) + "  code generated as " + _ompssGenerator->YAS_get_name());

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Parallelizer finished."));
		}

		void YAS_OMPSS::YAS_Compile() {
			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Compile is started."));

			vector<string> flist;
			flist.push_back(mergePath(_tmpDir, _ompssGenerator->YAS_get_name() + "." + ext_C));
			//flist.push_back(mergePath(_tmpDir, _ompssHeaderGenerator->YAS_get_name() + "." + ext_H));

			for (uint var = 0; var < parser->_cudaGenerator.size(); ++var)
				flist.push_back(mergePath(_tmpDir, parser->_cudaGenerator[var]->YAS_get_name() + "." + ext_CUDA));

			compileWithMNVCC(flist, _fnameOut.c_str());

			YACCGenLog_write_Debug(getClassName(this) + string(" : YAS_Compile finished."));
		}
	}
}
