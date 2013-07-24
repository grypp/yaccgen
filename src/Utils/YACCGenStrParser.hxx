/*
 * YACCGenStrParser.hxx
 *
 *  Created on: Jul 23, 2013
 *      Author: grypp
 */

#include <algorithm>
#include <string>

using namespace std;

#ifndef YACCGENSTRPARSER_HXX_
#define YACCGENSTRPARSER_HXX_

namespace yaccgen {

	static __inline__ bool search_ArrayInLine(const string arr[], string line) {
		for (int i = 0; i < arr->size(); ++i)
			if (line.find(arr[i], 0) != std::string::npos) return true;
		return false;
	}

	static __inline__ std::string getString_vec(std::vector<string> vec, string delimiter) {
		stringstream ss;
		for (int var = 0; var < vec.size(); ++var)
			ss << vec[var] << delimiter;
		return ss.str().substr(0, ss.str().size() - 1);
	}

	static __inline__ std::string getString_vec(std::vector<string> vec) {
		return getString_vec(vec, " ");
	}

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

	static __inline__ void replaceAll(std::string& str, const std::string& from, const std::string& to) {
		if (from.empty()) return;
		std::size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
	}
	static __inline__ std::string intToString(int val) {
		std::ostringstream s;
		s << val;
		return s.str();
	}
	static __inline__ std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

	static __inline__ std::vector<std::string> split(const std::string &s, char delim) {
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}
}

#endif /* YACCGENSTRPARSER_HXX_ */
