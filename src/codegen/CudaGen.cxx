/*
 * cudagen.cxx
 *
 *  Created on: Jul 18, 2013
 *      Author: grypp
 */

#include "CudaGen.hxx"

namespace yaccgen {
	namespace codegen {

		CudaGen::CudaGen() {
		}

		CudaGen::~CudaGen() {

		}

		CUDAKernel CudaGen::YAS_gen_kernel() {
			return YAS_gen_kernel(1, 1, 1, 1, 1, 0);
		}

		CUDAKernel CudaGen::YAS_gen_kernel(int blkx, int blky, int thrdx, int thrdy, int thrdz, int dynm) {
			string log = "kernel is configured with Block[";
			log += blkx;
			log += " , ";
			log += blky;
			log += "]";
			log += thrdx;
			log += " , ";
			log += thrdy;
			log += " , ";
			log += thrdz + "]";
			//yaccgen::ACCPLog_write_Info(log);

			CUDAKernel _kernel;
			_kernel.blockX = intToString(blkx);
			_kernel.blockY = intToString(blky);
			_kernel.sizeX = intToString(thrdx);
			_kernel.sizeY = intToString(thrdy);
			_kernel.sizeZ = intToString(thrdz);
			_kernel.dynamicMemSize = dynm == 0 ? "" : intToString(dynm);
			return _kernel;
		}

		void CudaGen::YAS_gridfy_1d(stringstream &ss, YAS_CudaKernel &currentKernel) {
			stringstream output, tmp1, tmp2, tmp3;
			string line;
			std::getline(ss, line);

			ForItems items = yaccgen::analyze_for(line);
			YACCGenLog_write_Info("gridfied 1D with " + items.acc_param);
			string acc_val = items.acc_param + "_1";
			output << yaccgen::add_param(acc_val, yaccgen::KernelFunctions::int32(), CUDAFunctions::gr_gbidf());
			std::getline(ss, line);
			if (line.find(yaccgen::tok_openCrlyBracket, 0) != std::string::npos) std::getline(ss, line);
			//cout << line << endl;
			replaceAll(line, items.acc_param, acc_val);
			output << line << endl;
			currentKernel._codeBody = output.str();
		}

		vector<YAS_CudaKernel> CudaGen::YAS_identifier(stringstream &ss) {
			vector<YAS_CudaKernel> outkernels;

			YAS_CudaKernel currentKernel;
			currentKernel._funcName = YAS_gen_kernelName();
			YACCGenLog_write_Info(currentKernel._funcName);
			string line;
			while (!ss.eof()) {
				std::getline(ss, line);
				if (line.find(yaccgen::tok_pragma, 0) != std::string::npos) if (line.find(yaccgen::tok_acc, 0) != std::string::npos) if (line.find(yaccgen::tok_acc_parallel, 0) != std::string::npos) if (line.find(yaccgen::tok_acc_loop, 0) != std::string::npos) {
					currentKernel._kernelConf = YAS_gen_kernel(16, 1, 1, 8, 1, 0);
					YAS_gridfy_1d(ss, currentKernel);
				}
			}
			outkernels.push_back(currentKernel);
			return outkernels;
		}

		string CudaGen::YAS_gen_kernelName() {
			return yaccgen::gen_str(5);
		}

	}
}

