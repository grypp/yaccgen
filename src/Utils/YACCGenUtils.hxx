#define _OPENACC_

#ifndef YACCGENUTILS_HXX_
#define YACCGENUTILS_HXX_

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <typeinfo>

#include "YACCGenLog.hxx"
#include "YACCGenException.hxx"
#include "YACCGenStrParser.hxx"

using namespace std;

namespace yaccgen {

	typedef pair<string, string> ssPair;

	enum DEVICE {
		CUDA, OPENCL
	};

	enum PTYPE {
		GENKERNEL, COMPILEALL
	};

	typedef struct {
		DEVICE target;
		PTYPE parserType;
	} CurrentConfiguration;

	typedef struct {
		struct timeval start;
		struct timeval end;
		double elapsed_time;
	} timing_t;

	void timing_start(timing_t* t);
	void timing_end(timing_t* t);
	double timing_elapsed(const timing_t* t);

	char copy_file(const char* source, const char* dest);

	static __inline__ string gen_str(int len) {
		static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		static const int stringLength = sizeof(alphanum) - 1;
		srand(time(NULL));
		char *str = (char*) calloc(len + 1, sizeof(char));
		for (int i = 0; i < len; i++)
			str[i] = alphanum[rand() % stringLength];
		return str;
	}

	template<class TYPE>
	static __inline__ string getClassName(TYPE obj) {
		return typeid(TYPE).name();
	}
	static __inline__ string mergePath(string path, string fname) {

		string out(path);
		out += '/';
		out += fname;

		return out;
	}

	static __inline__ const char* get_extension_filename(const char* filename) {
		return strrchr(filename, '.');
	}

	static __inline__ void upd_extension_filename(const char* fname, string newext) {
		string ff(fname);
		replaceAll(ff, string(get_extension_filename(fname)), newext);
		fname = ff.c_str();
	}

#ifndef _WIN32_
#define ERROR_EXEC "ERROR"

	static __inline__ bool is_file_exist(const char* name) {
		if (FILE *file = fopen(name, "r")) {
			fclose(file);
			return true;
		} else {
			return false;
		}
	}

	static __inline__ std::string exec_system(const char* cmd) {
		FILE* pipe = popen(cmd, "r");
		if (!pipe) return ERROR_EXEC;
		char buffer[128];
		std::string result = "";
		while (!feof(pipe)) {
			if (fgets(buffer, 128, pipe) != NULL) result += buffer;
		}
		pclose(pipe);
		return result;
	}

	static __inline__ std::string exec_newdir(string fname) {
		string command = "mkdir ";
		command += fname;
		return exec_system(command.c_str());
	}

#endif
}

#endif
