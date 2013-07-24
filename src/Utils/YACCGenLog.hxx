/*
 * ACCPLog.hxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#ifndef ACCPLOG_HXX_
#define ACCPLOG_HXX_

#include <string>
#include <iostream>
#include <fstream>
#include "YACCGenException.hxx"

using namespace std;

namespace yaccgen {

	void YACCGenLog_write_Debug(string log);

	void YACCGenLog_write_Info(string log);

	void YACCGenLog_write_Error(string log);

	class YACCGenLog {

	public:
		YACCGenLog();

		YACCGenLog(char*);

		~YACCGenLog();

		void write(string, string);

		void error(string, string);

	private:
		ofstream _fout;
	};
}

#endif /* ACCPLOG_HXX_ */
