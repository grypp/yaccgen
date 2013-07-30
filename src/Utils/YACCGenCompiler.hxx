/*
 * YACCGenCompiler.hxx
 *
 *  Created on: Jul 29, 2013
 *      Author: grypp
 */

#ifndef YACCGENCOMPILER_HXX_
#define YACCGENCOMPILER_HXX_

#include "YACCGenUtils.hxx"
namespace yaccgen {

#ifdef GCC
	static const string CC = "gcc";
#elif ICC
	static const string CC = "icc";
#else
	static const string CC = "gcc";
#endif

	static const string MNVCC = "mnvcc";
	static const string NVCC = "nvcc";

	static const string MNVCCFLAGS = "--ompss";

	static __inline__ void compileWithMNVCC(vector<string> flist, const char* fout) {
		string command;
		command.reserve(100);
		command.append(MNVCC);
		command.append(tok_ws + MNVCCFLAGS + tok_ws);
		for (uint var = 0; var < flist.size(); ++var)
			command.append(tok_ws + flist[var]);

		command.append(string(" -o ") + fout);

		exec_system(command.c_str());
	}

}  // namespace  yaccgen

#endif /* YACCGENCOMPILER_HXX_ */
