/*
 * ACCPLog.cxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#ifndef ACCPLOG_CXX_
#define ACCPLOG_CXX_

#include "YACCGenLog.hxx"

namespace yaccgen {

	static YACCGenLog logger;

	void YACCGenLog_write_Debug(string log) {
		logger.write("[YACCGEN][DEBUG]", log);
	}

	void YACCGenLog_write_Info(string log) {
		logger.write("[YACCGEN][INFO]", log);
	}

	void YACCGenLog_write_Error(string log) {
		logger.error("[YACCGEN][ERROR]", log);
	}

	YACCGenLog::YACCGenLog() {
	}

	YACCGenLog::YACCGenLog(char *fname) {
		_fout.open(fname);
	}

	YACCGenLog::~YACCGenLog() {
		if (_fout.is_open()) _fout.close();
	}

	void YACCGenLog::write(string prefix, string log) {
		cout << prefix << ": \t" << log << endl;
	}

	void YACCGenLog::error(string prefix, string log) {

		cout << "\033[1;31m" << prefix << ": \t" << log << "\033[0m" << endl;
	}

} // namespace accp

#endif /* ACCPLOG_CXX_ */
