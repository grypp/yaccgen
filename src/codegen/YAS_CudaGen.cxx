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

			_fname = pre_yaccgen + pre_kernel + yaccgen::gen_str(5);

			_level = 0;
		}

		YAS_CudaGen::~YAS_CudaGen() {
		}

		string YAS_CudaGen::YAS_get_kernel_signature() {
			string signature;
			signature.reserve(150);
			signature.append("__global__ void ");
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
				string name = _params[var].name;
				//todo very bad block
				replaceAll(name, "*", "");
				signature.append(name + tok_ws);
				if (var != _params.size() - 1) signature.append(tok_comma);
			}
			signature.append(tok_closeBracket);
			return signature;
		}

		string YAS_CudaGen::YAS_get_kernel_ndrangeFormat() {
			string kernel;

			if (_currentKernel.blockY == "1" && _currentKernel.sizeY == "1") {
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
				vector<string> paramstr = split(params[var], tok_ws);
				yaccgen_param param { paramstr.front(), "", paramstr.back() };
				this->_params.push_back(param);
				this->_codeBlock << params[var] << tok_ws;
				if (var != params.size() - 1) this->_codeBlock << tok_comma;
			}

			this->_codeBlock << tok_closeBracket << endl;
		}
	}
}
