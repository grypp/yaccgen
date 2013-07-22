//============================================================================
// Name        : YACCGen.cxx
// Author      : guray ozen
// Version     : 0.1
// Copyright   : yet another openacc generator
// Description : Main in C++, Ansi-style
//============================================================================

#include <iostream>
#include "codegen/CudaGen.hxx"
using namespace std;
using namespace yaccgen;
using namespace codegen;

//============================================================================
#define VERSION 0.1
//============================================================================
#define HELP_STRING \
"Default usage: accp inputfile.cpp -o output.x \n" \
"Options: \n" \
"  -h		                Shows this help and quits\n" \
"  -v		                Shows version and quits\n" \
"  -k		                Keep translated and extracted files\n" \
"  -o		                Output file\n" \
"  -a			        Generate Kernel as Cuda Code \n" \
"  -p			        compiler parameters \n" \
"\n"
//============================================================================

char *input, *output, *output_temp = "accp_tmp.c", *input_2;

bool removeFile = true;
string CPPFLAGS;
void cl_parse(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'k') {
				removeFile = false;
			} else if (argv[i][1] == 'p') {
				CPPFLAGS = argv[i + 1];
				i++;
			} else if (argv[i][1] == 'v') {
				cout << VERSION <<endl;
				exit(1);
			} else if (argv[i][1] == 'h') {
				cout << HELP_STRING << endl;
				exit(1);
			} else if (argv[i][1] == 'o') {
				output = argv[i + 1];
				i++;
			} else if (argv[i][1] == 'a') {
				output = argv[i + 1];
				i++;
			}
		} else input = argv[i];
	}
	if (argc < 4) {
		fprintf(stderr, HELP_STRING);
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	std::string line;
	stringstream ss;
	fstream finx("pragma.txt");
	while (!finx.eof()) {
		std::getline(finx, line);
		ss << line << endl;
	}
	CudaGen sulo;
	YAS_CudaKernel kernel = sulo.YAS_identifier(ss);

	return 1;
}
