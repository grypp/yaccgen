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
		logger.write("[ACCP][DEBUG]", log);
	}

	void YACCGenLog_write_Info(string log) {
		logger.write("[ACCP][INFO]", log);
	}

	void YACCGenLog_write_Error(string log) {
		logger.write("[ACCP][ERROR]", log);
	}

	YACCGenLog::YACCGenLog() {
	}

	YACCGenLog::YACCGenLog(char *fname) {
		_fout.open(fname);
	}

	YACCGenLog::~YACCGenLog() {
		if (_fout.is_open()) _fout.close();
		delete this;
	}

	void YACCGenLog::write(string prefix, string log) {
		cout << prefix << ": \t" << log << endl;
	}

}  // namespace accp

#endif /* ACCPLOG_CXX_ */
