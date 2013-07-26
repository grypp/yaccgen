/*
 * YASParserWrapper.cxx
 *
 *  Created on: Jul 25, 2013
 *      Author: grypp
 */

#include "YAS_ParserWrapper.hxx"

namespace yaccgen {
	namespace yas {

		YAS_ParserWrapper::YAS_ParserWrapper(const char* fname, bool use_cpp, bool isDebug) {
			_prj = new Project();
			_prj->SetPrintOption(isDebug);
			_unit = _prj->parse(fname, false, NULL, true, NULL, NULL, NULL);
			this->_cudaGenerator = new YAS_CudaGen();
		}

		YAS_ParserWrapper::~YAS_ParserWrapper() {
			this->_prj->~Project();
			this->_unit->~TransUnit();
		}

		void YAS_ParserWrapper::findout_acc_pragma() {
			//todo only one main code!!
			//todo only for
			//todo only without block pragma!!
			//todo no look pragma
			Statement * s = _unit->head;
			Block* b = (Block*) s;
			for (Statement *statement = b->head; statement; statement = statement->next) {
				if (statement->type == ST_ForStemnt) {
					ForStemnt *f = (ForStemnt *) statement;
					_forList.push_back(f);
				}
			}
		}
		void YAS_ParserWrapper::parallel() {

			KernelFunctions kernelfunction;
			CUDAFunctions cudafunction;

			//FOR EACH blocks in the list will be generated new kernel!
			for (uint var = 0; var < _forList.size(); ++var) {
				string nblock, loopVar;
				//fixme change parameter table!
				//ParameterTable params;
				vector<string> params;

				//todo kernel configuration must depend on items
				this->_cudaGenerator->YAS_gen_kernel(16, 1, 8, 1, 1, 0);
				_cudaGenerator->YAS_gen_kernelName();

				loopVar = ((Variable*) (((RelExpr*) _forList[var]->init)->_leftExpr))->name->name;
				params.push_back(((Variable*) ((RelExpr*) _forList[var]->init)->_leftExpr)->name->entry->Show());
				YACCGenLog_write_Info(string("Loop ") + loopVar + string(" will be shared"));

				//todo check all condition variable
				if (((Variable*) ((RelExpr*) _forList[var]->cond)->_leftExpr)->name->name != ((Variable*) ((RelExpr*) _forList[var]->init)->_leftExpr)->name->name) {
					nblock = ((Variable*) ((RelExpr*) _forList[var]->cond)->_leftExpr)->name->name;
					params.push_back(((Variable*) ((RelExpr*) _forList[var]->cond)->_leftExpr)->name->entry->Show());
				} else {
					nblock = ((Variable*) ((RelExpr*) _forList[var]->cond)->_rightExpr)->name->name;
					params.push_back(((Variable*) ((RelExpr*) _forList[var]->cond)->_rightExpr)->name->entry->Show());
				}

				//one line
				if (_forList[var]->block->type == ST_ExpressionStemnt) {
					if (((ExpressionStemnt*) _forList[var]->block)->expression->etype == ET_BinaryExpr) {
						if (((AssignExpr*) ((ExpressionStemnt*) _forList[var]->block)->expression)->leftExpr()->etype == ET_IndexExpr) {
							params.push_back(((Variable*) ((IndexExpr*) ((AssignExpr*) ((ExpressionStemnt*) _forList[var]->block)->expression)->leftExpr())->array)->name->entry->Show());
						}
						params.push_back(((Variable*) ((IndexExpr*) ((BinaryExpr*) ((AssignExpr*) ((ExpressionStemnt*) _forList[var]->block)->expression)->_rightExpr)->_leftExpr)->array)->name->entry->Show());
						params.push_back(((Variable*) ((IndexExpr*) ((BinaryExpr*) ((AssignExpr*) ((ExpressionStemnt*) _forList[var]->block)->expression)->_rightExpr)->_rightExpr)->array)->name->entry->Show());
					}
				}
				_cudaGenerator->add_method(params);
				_cudaGenerator->add_openBlock();

				yaccgen_param _nblock { string(kernelfunction.int32()), "1+(n-1)/16", "_nblock" };
				_cudaGenerator->add_param(_nblock);

				yaccgen_param _startIter { kernelfunction.int32(), string(cudafunction.gr_gbidx()) + "* _nblock", "_startIter" };
				_cudaGenerator->add_param(_startIter);

				yaccgen_param _endIter { kernelfunction.int32(), "((_startIter+_nblock-1) < (n-1) ?	(_startIter+_nblock-1) : (n-1))", "_endIter" };
				_cudaGenerator->add_param(_endIter);

				_cudaGenerator->add_line("for (int _i = _startIter+(threadIdx.y) ; _i <= _endIter ; _i = _i+(blockDim.y))");
				stringstream ss;
				((ExpressionStemnt*) _forList[var]->block)->expression->print(ss);
				string tmpComp = ss.str();
				replaceAll(tmpComp, loopVar, "_i");
				_cudaGenerator->add_line(tmpComp + tok_semicolon);

				_cudaGenerator->add_closeBlock();

				YACCGenLog_write_Error("\n" + _cudaGenerator->_codeBlock.str());
			}
		}
	}
}

