/*

 * cudagen.cxx
 *
 *  Created on: Jul 18, 2013
 *      Author: grypp
 */

#include "YAS_CudaGen.hxx"

namespace yaccgen {
	namespace codegen {

		YAS_CudaGen::YAS_CudaGen() {
		}

		YAS_CudaGen::~YAS_CudaGen() {

		}

		CUDAKernel YAS_CudaGen::YAS_gen_kernel() {
			return YAS_gen_kernel(1, 1, 1, 1, 1, 0);
		}

		CUDAKernel YAS_CudaGen::YAS_gen_kernel(int blkx, int blky, int thrdx, int thrdy, int thrdz, int dynm) {
			yaccgen::YACCGenLog_write_Info(string("kernel is configured with Block[") + intToString(blkx) + string(" , ") + intToString(blky) + string("] [")\
 + intToString(thrdx) + string(" , ") + intToString(thrdy) + string(" , ") + intToString(thrdz) + string("]"));

			CUDAKernel _kernel;
			_kernel.blockX = intToString(blkx);
			_kernel.blockY = intToString(blky);
			_kernel.sizeX = intToString(thrdx);
			_kernel.sizeY = intToString(thrdy);
			_kernel.sizeZ = intToString(thrdz);
			_kernel.dynamicMemSize = dynm == 0 ? "" : intToString(dynm);
			return _kernel;
		}

		void YAS_CudaGen::add_method(string name, ParameterTable params) {
			YAS_CGen::add_method("__global__ void", name, params);
		}

		void YAS_CudaGen::add_method(vector<string> params) {

			this->_codeBlock << "__global__ void" << tok_ws;
			this->_codeBlock << _name << tok_ws << tok_openBracket;

			for (uint var = 0; var < params.size(); ++var) {
				this->_codeBlock << params[var] << tok_ws;
				if (var != params.size() - 1) this->_codeBlock << tok_comma;
			}

			this->_codeBlock << tok_closeBracket << endl;
		}

		void YAS_CudaGen::YAS_gen_kernelName() {
			_name = "kernel_" + yaccgen::gen_str(5);
		}

#if old
	void YAS_CudaGen::YAS_gridfy_1d(stringstream &ss, YAS_CudaKernel &currentKernel) {
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
		currentKernel.codeBody = output.str();
	}

	vector<YAS_CudaKernel> YAS_CudaGen::YAS_identifier(stringstream &ss) {
		vector<YAS_CudaKernel> outkernels;

		YAS_CudaKernel currentKernel;
		currentKernel.funcName = YAS_gen_kernelName();
		YACCGenLog_write_Info(currentKernel.funcName);
		string line;
		while (!ss.eof()) {
			std::getline(ss, line);
			if (line.find(yaccgen::tok_pragma, 0) != std::string::npos) if (line.find(yaccgen::tok_acc, 0) != std::string::npos) if (line.find(yaccgen::tok_acc_parallel, 0) != std::string::npos) if (line.find(yaccgen::tok_acc_loop, 0) != std::string::npos) {
				currentKernel.kernelConf = YAS_gen_kernel(16, 1, 1, 8, 1, 0);
				YAS_gridfy_1d(ss, currentKernel);
			}
		}
		outkernels.push_back(currentKernel);
		return outkernels;
	}

#endif

	}
}
