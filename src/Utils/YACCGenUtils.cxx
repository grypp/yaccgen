/*
 * YACCGenUtils.cxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */


#include "YACCGenUtils.hxx"

namespace yaccgen {

	void replaceAll(std::string& str, const std::string& from, const std::string& to) {
		if (from.empty()) return;
		std::size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
	}

	void eraseStringinString(string& str, const string& erased) {
		int tmpBracketCounter = 1, end = 0;
		if (str.find(erased, 0) != std::string::npos) {
			for (int k = str.find(erased, 0) + erased.size() + 1; k != str.size(); k++) {
				if (tmpBracketCounter == 0) break;
				if (str[k] == '(') tmpBracketCounter++;
				else if (str[k] == ')') tmpBracketCounter--;
				else end++;
			}
			end += erased.size() + 3;
			str.erase(str.find(erased, 0), end);
		}
	}

	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

	std::vector<std::string> split(const std::string &s, char delim) {
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}

	void timing_start(timing_t* t) {
		memset(t, 0, sizeof(*t));
		gettimeofday(&(t->start), NULL);
	}

	void timing_end(timing_t* t) {
		gettimeofday(&(t->end), NULL);

		double start_value = t->start.tv_sec * 1e6 + t->start.tv_usec;
		double end_value = t->end.tv_sec * 1e6 + t->end.tv_usec;

		double diff_value = end_value - start_value;

		t->elapsed_time = diff_value / 1e6;
	}

	double timing_elapsed(const timing_t* t) {
		return (t->elapsed_time);
	}

	char copy_file(const char* source, const char* dest) {
		// Plain old copy
		FILE* orig_file = fopen(source, "r");
		if (orig_file == NULL) return -1;

		FILE* dest_file = fopen(dest, "w");

		if (dest_file == NULL) {
			fclose(orig_file);
			return -1;
		}

#define BLOCK_SIZE 1024
		char c[BLOCK_SIZE];
		int actually_read = fread(c, sizeof(char), BLOCK_SIZE, orig_file);

		while (actually_read != 0) {
			int actually_written = fwrite(c, sizeof(char), actually_read, dest_file);
			if (actually_written < actually_read) {
				fclose(dest_file);
				fclose(orig_file);
				return -1;
			}
			actually_read = fread(c, sizeof(char), BLOCK_SIZE, orig_file);
		}
#undef BLOCK_SIZE
		if (feof(orig_file)) {
			// Everything is OK
			clearerr(orig_file);
		} else if (ferror(orig_file)) {
			// Something went wrong
			fclose(dest_file);
			fclose(orig_file);
			return -1;
		}

		fclose(orig_file);
		fclose(dest_file);
		return 0;
	}
}


