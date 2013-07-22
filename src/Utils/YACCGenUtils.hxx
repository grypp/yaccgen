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

#include "YACCGenLog.hxx"
#include "YACCGenException.hxx"

using namespace std;

namespace yaccgen {
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
	void replaceAll(std::string& str, const std::string& from, const std::string& to);
	std::vector<std::string> split(const std::string &s, char delim);
	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
	char copy_file(const char* source, const char* dest);

	static __inline__ bool searchLineInArray(const string arr[], int n, string line) {
		//todo change with startwith function. firstly use trim
		for (int i = 0; i < n; ++i)
			if (line.find(arr[i], 0) != std::string::npos) return true;
		return false;
	}

	static __inline__ std::string getString_vec(std::vector<string> vec, string delimiter) {
		stringstream ss;
		for (int var = 0; var < vec.size(); ++var)
			ss << vec[var] << delimiter;
		return ss.str().substr(0, ss.str().size() - 1);
	}

	static __inline__ std::string getString_vec_ff(std::vector<string> vec, string delimiter) {
		stringstream ss;
		vector<string> tmp;
		for (int var = 0; var < vec.size(); ++var) {
			tmp = split(vec[var], ' ');
			ss << tmp[tmp.size() - 1] << delimiter;
		}
		return ss.str().substr(0, ss.str().size() - 1);
	}

	static __inline__ std::string getString_vec(std::vector<string> vec) {
		return getString_vec(vec, "");
	}

	// trim from start
	static __inline__ std::string &ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		return s;
	}

	// trim from end
	static __inline__ std::string &rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
		return s;
	}

	// trim from both ends
	static __inline__ std::string &trim(std::string &s) {
		return ltrim(rtrim(s));
	}

	static __inline__ std::string intToString(int val) {
		std::ostringstream s;
		s << val;
		return s.str();
	}

	static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	static const int stringLength = sizeof(alphanum) - 1;

	static __inline__ string gen_str(int len) {
		srand(time(NULL));
		char *str = (char*) calloc(len + 1, sizeof(char));
		for (int i = 0; i < len; i++)
			str[i] = alphanum[rand() % stringLength];
		return str;
	}

	static __inline__ const string mergePath(string path, string fname) {
		path += '/';
		path += fname;
		return path;
	}

#ifndef _WIN32_
#define ERROR_EXEC "ERROR"

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
