//============================================================================
// Name        : YACCGen.cxx
// Author      : guray ozen
// Version     : 0.1
// Copyright   : yet another ACC generator
// Description : Main in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Yas/YAS_OMPSS.hxx"
#include "Utils/YACCGenUtils.hxx"
using namespace std;
using namespace yaccgen;

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

char *input, *output;

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

	int n = 1024;
	int blockIdx = 1;
	__int32_t nbiter_1;
	__int32_t firstiter_1;
	__int32_t lastiter_1;
	nbiter_1 = 1 + (n - 1) / 16;                          //64
	firstiter_1 = (blockIdx) * nbiter_1;            //block by block computing 2.step = 64
	lastiter_1 = ((firstiter_1 + nbiter_1 - 1) < (n - 1) ? (firstiter_1 + nbiter_1 - 1) : (n - 1));
	cout << nbiter_1 << endl;
	cout << firstiter_1 << endl;
	cout << lastiter_1 << endl;
	return 1;

	yaccgen::timing_t timing_global;
	yaccgen::timing_start(&timing_global);

	cl_parse(argc, argv);
	yas::YAS_OMPSS ompssBooter(input, output, false);
	ompssBooter.YAS_ACC_PerformYASSteps();

	yaccgen::timing_end(&timing_global);
	cout << endl << "Elapsed Time \t" << yaccgen::timing_elapsed(&timing_global) << endl;
	return 0;
}

