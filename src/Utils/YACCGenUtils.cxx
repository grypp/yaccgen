/*
 * YACCGenUtils.cxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#include "YACCGenUtils.hxx"

namespace yaccgen {

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

