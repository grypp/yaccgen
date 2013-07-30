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
#include "YAS_ParserWrapper.hxx"
#include "../Utils/YACCGenCompiler.hxx"

namespace yaccgen {
	namespace yas {

		class YAS_ACC {

		private:
			vector<ssPair> _pragmaCodeBlocks;

		protected:
			fstream _fin;
			stringstream _finSS;
			fstream _fout;

			string _fnameIn;
			string _fnameOut;
			string _fnameInWorking;
			string _tmpDir;

			bool _removeFiles;

			YAS_ParserWrapper* parser;

		public:

			YAS_ACC(const char *fnameIn, const char *fnameOut, bool removeFiles);

			virtual ~YAS_ACC();

			virtual void YAS_ACC_PRE_PerformYASSteps();

			virtual void YAS_ACC_POST_PerformYASSteps();

			virtual void YAS_ACC_PerformYASSteps();

			virtual void YAS_Prepare();

			virtual void YAS_Pre_Driver();

			virtual void YAS_CheckPragmas();

			virtual void YAS_DepedencyIdentifier();

			virtual void YAS_Parallelizer();

			virtual void YAS_Post_Driver();

			virtual void YAS_Compile(){}

		};
	}
}

#endif /* YAS_ACC_HXX_ */

