/*
 * YAS_CudaKernel.cxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */
#include "YAS_CudaKernel.hxx"

namespace yaccgen {
	namespace codegen {

		YAS_CudaKernel::YAS_CudaKernel() {
		}

		YAS_CudaKernel::~YAS_CudaKernel() {
			delete this;
		}

		string YAS_CudaKernel::toString_kernelConf() {
			stringstream out;
			out << "Block[" << _kernelConf.blockX << "," << _kernelConf.blockY << "]\t[" << _kernelConf.sizeX << "," << _kernelConf.sizeY << "," << _kernelConf.sizeZ << "]" << endl;
			return out.str();
		}
	}
}
