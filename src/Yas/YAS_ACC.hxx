/*
 * YAS_ACC.hxx
 *
 *  Created on: Jul 23, 2013
 *      Author: grypp
 */

#ifndef YAS_ACC_HXX_
#define YAS_ACC_HXX_

using namespace std;


#include <fstream>
#include <ostream>
#include "../Utils/YACCGenUtils.hxx"
#include "../Utils/CPPParser.hxx"


namespace yaccgen {
	namespace yas {

		class YAS_ACC {

		private:
			fstream _fin;
			stringstream _finSS;
			fstream _fout;

			const char* _fnameIn;
			const char* _fnameOut;
			const char* _fnameInWorking;
			string _tmpDir;

			vector<string> _pragmaCodeBlocks;

		public:
			YAS_ACC(const char *fnameIn,const char *fnameOut);

			~YAS_ACC();

			void YAS_ACC_PerformAllSteps();

			void YAS_Pre_Driver();

			void YAS_CheckPragmas();

			void YAS_DepedencyIdentifier();

			void YAS_Parallelizer();

			void YAS_Post_Driver();
		};
	}
}

#endif /* YAS_ACC_HXX_ */

