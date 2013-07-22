/*
 * CPPParser.cxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#include <vector>
#include <map>
#include "YACCGenUtils.hxx"
#include "AccTokens.hxx"

using namespace std;
using namespace yaccgen;

namespace yaccgen {

	typedef std::vector<string> SVector;
	typedef std::map<string, string> inMap;
	typedef std::map<string, inMap> ParameterTable;

	typedef struct {
		ParameterTable init_params;
		string end_rule;
		ParameterTable end_params;
		string iteration_acc;
		string acc_param;
	} ForItems;

	static __inline__ string add_param(string name, string type, string val) {
		stringstream ss;
		if (val.empty()) ss << type << yaccgen::tok_ws << name << yaccgen::tok_eq << val << yaccgen::tok_semicolon << '\n';
		else ss << type << yaccgen::tok_ws << name << yaccgen::tok_semicolon << '\n';
		return ss.str();
	}
	static __inline__ string add_param(string name, string type) {
		return add_param(name, type, "");
	}
	static __inline__ ForItems analyze_for(string line) {
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
				}else continue;
			}
			tmp2 << line[i];
		}
		for (; line[i] != yaccgen::tok_semicolon; i++) {
			if (line[i] == yaccgen::tok_ws) continue;
			tmp3 << line[i];
		}

		if (tmp3.str().size() != 0) items.init_params[tmp2.str()][tmp1.str()] = tmp3.str();
		else items.init_params[tmp1.str()]["int"] = tmp2.str();

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
		items.end_params[tmp1.str()]["int"] = "0";
		items.end_params[tmp2.str()]["int"] = "0";

		tmp1.str("");
		tmp2.str("");
		tmp3.str("");
		i++;
		for (i++; line[i] != yaccgen::tok_closeBracket; i++)
			if (line[i] == yaccgen::tok_ws) continue;
			else tmp1 << line[i];

		items.acc_param = tmp1.str();
		replaceAll(items.acc_param, "++", "");
		replaceAll(items.acc_param, "--", "");
		items.iteration_acc = tmp1.str();
		return items;
	}
}

