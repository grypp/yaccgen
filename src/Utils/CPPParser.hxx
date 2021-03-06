/*
 * CPPParser.cxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */
#ifndef YAS_CPPPARSER_HXX_
#define YAS_CPPPARSER_HXX_

#include <list>
#include "YACCGenUtils.hxx"
#include "AccTokens.hxx"

using namespace std;

namespace yaccgen {

	typedef struct {
		string type;
		string val;
		string name;
	} yaccgen_param;

	typedef std::vector<yaccgen_param> ParameterTable;

	static const string C_LeX[5] = { "for", "if", "else", "while", "do" };

	static const string ext_C = "c";
	static const string ext_H = "h";
	static const string ext_CXX = "cxx";
	static const string ext_CUDA = "cu";
	static const string ext_OPENCL = "cl";

	static const string pre_kernel = "kernel_";
	static const string pre_ompss = "ompss_";
	static const string pre_acc = "acc_";
	static const string pre_yaccgen = "yaccgen_";
	static const string pre_org = "orginal_";

	static __inline__ void load_file2ss(fstream &fin, stringstream &ss) {
		string line;
		while (!fin.eof()) {
			std::getline(fin, line);
			ss << line << endl;
		}
	}

	static __inline__ string getLine(stringstream &ss, int linenum) {
		string line;
		int i = 1;
		while (!ss.eof()) {
			std::getline(ss, line);
			if (i == linenum) return line;
			i++;
		}
		ss.seekg(0, std::ios::beg);
		return line;
	}

	static __inline__ string remove_for_token(fstream &fin, string token) {
		stringstream ss;
		string line, prevline;
		try {
			while (!fin.eof()) {
				prevline = line;
				std::getline(fin, line);
				trim(line);
				if (line.find(tok_for, 0) != std::string::npos) {
					if (prevline.find(token, 0) == std::string::npos) {
						prevline = line;
						std::getline(fin, line);
						trim(line);
						if (prevline.find(tok_openCrlyBracket, 0) != string::npos || line.find(tok_openCrlyBracket, 0) == 0 || search_ArrayInLine(C_LeX, line)) {
							int bracket = prevline.find(tok_openCrlyBracket, 0) != string::npos || line.find(tok_openCrlyBracket, 0) != std::string::npos ? 1 : 0;
							while (!fin.eof()) {
								std::getline(fin, line);
								trim(line);
								if (line.find(tok_openCrlyBracket, 0) != std::string::npos) bracket++;
								if (line.find(tok_closeCrlyBracket, 0) != std::string::npos) bracket--;
								if (bracket == 0) break;
							}
						}
					} else ss << line << endl;
				} else ss << line << endl;
			}
		} catch (std::exception e) {
			YACCGenLog_write_Error(string("remove_for_token") + e.what());
			throw e;
		}

		return ss.str();
	}

	static __inline__ vector<string> findBlock_inCode(stringstream &fin, vector<string> tokenList) {
		vector<string> outList;
		string line = "";
		stringstream tmp;
		outList.clear();
		try {
			while (!fin.eof()) {
				std::getline(fin, line);
				for (int i = 0; i != tokenList.size(); ++i)
					if (line.find(tokenList[i], 0) != std::string::npos) {

						std::getline(fin, line);
						trim(line);

						if (line.find(tok_openCrlyBracket, 0) == 0 || search_ArrayInLine(C_LeX, line)) {

							bool getLast = false;
							if (line.find(tok_openCrlyBracket, 0) != 0) {
								tmp << line << endl;
								getLast = true;
							}

							int bracket = line.find(tok_openCrlyBracket, 0) != std::string::npos ? 1 : 0;

							while (!fin.eof()) {
								std::getline(fin, line);
								trim(line);
								if (line.find(tok_com_single, 0) == 0 || line.empty()) continue;
								if (line.find(tok_openCrlyBracket, 0) != std::string::npos) bracket++;
								if (line.find(tok_closeCrlyBracket, 0) != std::string::npos) bracket--;

								if (bracket == 0) {
									if (getLast) tmp << line << endl;
									break;
								} else tmp << line << endl;
							}
							outList.push_back(tmp.str());
							tmp.str("");
						} else outList.push_back(line);

					}
			}
		} catch (std::exception e) {
			YACCGenLog_write_Error(string("Block Parser") + e.what());
			throw e;
		}
		return outList;
	}

	static __inline__ vector<string> findBlock_inCode(stringstream &fin, string token) {
		vector<string> tokenList;
		tokenList.push_back(token);
		return findBlock_inCode(fin, tokenList);
	}

	/*static __inline__ ForItems analyze_for(string line) {
	 ForItems items;
	 stringstream output, tmp1, tmp2, tmp3;

	 int i = line.find(yaccgen::tok_openBracket, 0);
	 i++;
	 for (; line[i] != yaccgen::tok_ws; i++)
	 tmp1 << line[i];
	 for (; line[i] != yaccgen::tok_semicolon; i++) {
	 if (line[i] == yaccgen::tok_ws) continue;
	 else if (line[i] == yaccgen::tok_eq) {
	 if (tmp2.str().size() != 0) {
	 i++;
	 break;
	 } else continue;
	 }
	 tmp2 << line[i];
	 }
	 for (; line[i] != yaccgen::tok_semicolon; i++) {
	 if (line[i] == yaccgen::tok_ws) continue;
	 tmp3 << line[i];
	 }

	 //if (tmp3.str().size() != 0) items.init_params[tmp2.str()][tmp1.str()] = tmp3.str();
	 //else items.init_params[tmp1.str()]["int"] = tmp2.str();

	 tmp1.str("");
	 tmp2.str("");
	 tmp3.str("");

	 for (i++; line[i] != '!'; i++) {
	 tmp3 << line[i];
	 if (line[i] == yaccgen::tok_ws) continue;
	 tmp1 << line[i];
	 }
	 tmp3 << line[i];
	 i++;
	 tmp3 << line[i];
	 for (i++; line[i] != yaccgen::tok_semicolon; i++) {
	 tmp3 << line[i];
	 if (line[i] == yaccgen::tok_ws) continue;
	 tmp2 << line[i];
	 }
	 items.end_rule = tmp3.str();
	 //items.end_params[tmp1.str()]["int"] = "0";
	 //items.end_params[tmp2.str()]["int"] = "0";

	 tmp1.str("");
	 tmp2.str("");
	 tmp3.str("");

	 for (i++; line[i] != yaccgen::tok_closeBracket.c_str(); i++)
	 if (line[i] == yaccgen::tok_ws) continue;
	 else tmp1 << line[i];

	 items.acc_param = tmp1.str();
	 replaceAll(items.acc_param, "++", "");
	 replaceAll(items.acc_param, "--", "");
	 items.iteration_acc = tmp1.str();
	 return items;
	 }*/

	static __inline__ void getInsideBrackets(fstream &fin, stringstream &ss) {

		string line;
		std::getline(fin, line);
		ss << line << endl;
		std::getline(fin, line);
		ss << line << endl;
		if (line.find("{", 0) != std::string::npos) {
			int bracketCnt = 1;
			while (bracketCnt != 0) {
				std::getline(fin, line);
				ss << line << endl;
				if (line.find("{", 0) != std::string::npos) bracketCnt++;
				else if (line.find("}", 0) != std::string::npos) bracketCnt--;
			}
		}
	}
}

#endif
