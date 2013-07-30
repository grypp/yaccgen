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
			_fname = "kernel_" + yaccgen::gen_str(5);
		}

		YAS_CudaGen::~YAS_CudaGen() {

		}

		string YAS_CudaGen::YAS_get_kernel_signature() {
			string signature;
			signature.reserve(150);
			signature.append(YAS_CudaGen::YAS_get_name() + tok_openBracket);
			for (uint var = 0; var < this->_params.size(); ++var) {
				signature.append(_params[var].type + tok_ws + _params[var].name + tok_ws);
				if (var != _params.size() - 1) signature.append(tok_comma);
			}
			signature.append(tok_closeBracket);
			return signature;
		}

		string YAS_CudaGen::YAS_get_kernel_invoke() {
			string signature;
			signature.reserve(150);
			signature.append(YAS_CudaGen::YAS_get_name() + tok_openBracket);
			for (uint var = 0; var < this->_params.size(); ++var) {
				signature.append(_params[var].name + tok_ws);
				if (var != _params.size() - 1) signature.append(tok_comma);
			}
			signature.append(tok_closeBracket);
			return signature;
		}
		string YAS_CudaGen::YAS_get_kernel_ndrangeFormat() {
			string kernel;

			if (_currentKernel.blockY != "1" || _currentKernel.sizeY != "1") {
				kernel.append("1," + _currentKernel.blockX + "," + _currentKernel.sizeX);

			} else kernel.append("2," + _currentKernel.blockX + "," + _currentKernel.blockY + "," + _currentKernel.sizeX + "," + _currentKernel.sizeY);

			return kernel;
		}

		void YAS_CudaGen::YAS_gen_kernel() {
			YAS_gen_kernel(1, 1, 1, 1, 1, 0);
		}

		void YAS_CudaGen::YAS_gen_kernel(int blkx, int blky, int thrdx, int thrdy, int thrdz, int dynm) {
			yaccgen::YACCGenLog_write_Info(string("kernel is configured with Block[") + intToString(blkx) + string(" , ") + intToString(blky) + string("] [")\
 + intToString(thrdx) + string(" , ") + intToString(thrdy) + string(" , ") + intToString(thrdz) + string("]"));

			CUDAKernel _kernel;
			_kernel.blockX = intToString(blkx);
			_kernel.blockY = intToString(blky);
			_kernel.sizeX = intToString(thrdx);
			_kernel.sizeY = intToString(thrdy);
			_kernel.sizeZ = intToString(thrdz);
			_kernel.dynamicMemSize = dynm == 0 ? "" : intToString(dynm);
			_currentKernel = _kernel;
		}

		void YAS_CudaGen::add_method(string name, ParameterTable params) {
			YAS_CGen::add_method("__global__ void", name, params);
		}

		void YAS_CudaGen::add_method(vector<string> params) {

			this->_codeBlock << "__global__ void" << tok_ws;
			this->_codeBlock << _fname << tok_ws << tok_openBracket;

			for (uint var = 0; var < params.size(); ++var) {

				//todo very bad block
				vector<string> paramstr = split(params[var], tok_ws);
				string name = paramstr.back();
				replaceAll(name, "*", "");
				yaccgen_param param { paramstr.front(), "", name };
				this->_params.push_back(param);
				/////////////////////////////////////

				this->_codeBlock << params[var] << tok_ws;
				if (var != params.size() - 1) this->_codeBlock << tok_comma;
			}

			this->_codeBlock << tok_closeBracket << endl;
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
