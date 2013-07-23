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
			//	delete this;
		}

		string YAS_CudaKernel::toString_kernelConf() {
			stringstream out;
			out << "Block[" << kernelConf.blockX << "," << kernelConf.blockY << "]\t[" << kernelConf.sizeX << "," << kernelConf.sizeY << "," << kernelConf.sizeZ << "]" << endl;
			return out.str();
		}
		string YAS_CudaKernel::get_CSignature() {
			stringstream out;
			out << "extern \"C\" __global__ void " << this->funcName << '( ';

			for (ParameterTable::iterator iter = params.begin(); iter != params.end(); iter++)
				out << (*iter).type << (*iter).name << ',';
			out << " );";
			return out.str();
		}

		string YAS_CudaKernel::get_Cfunction() {
			stringstream out;

			out << this->funcName << "<<<";
			out << "(" << kernelConf.blockX << ',' << kernelConf.blockY << ")";
			out << "(" << kernelConf.sizeX << ',' << kernelConf.sizeY << ',' << kernelConf.sizeZ << ")";
			out << ">>>" << '(';

			for (ParameterTable::iterator iter = params.begin(); iter != params.end(); iter++)
				out << (*iter).val << ',';

			out << " );";
			return out.str();
		}
	}
}

