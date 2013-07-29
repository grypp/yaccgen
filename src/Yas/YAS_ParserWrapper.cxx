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

		void YAS_ParserWrapper::generate_ompss() {

		}


		void YAS_ParserWrapper::parse_accpragma() {
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
		void YAS_ParserWrapper::generate_cuda() {

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
				//loopVar_Val = ((Variable*) (((RelExpr*) _forList[var]->init)->_leftExpr))->name->entry->Show();
				params.push_back(((Variable*) ((RelExpr*) _forList[var]->init)->_leftExpr)->name->entry->Show());
				YACCGenLog_write_Info(string("Loop ") + loopVar + string(" will be gridified"));

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

				string firstVal = "0";
				_cudaGenerator->add_line(string("if(") + firstVal + tok_lt + nblock + string("  )"));
				_cudaGenerator->add_openBlock();

				yaccgen_param _nblock { string(kernelfunction.int32()), string(cudafunction.gr_atidminx()), "_nblock" };
				_cudaGenerator->add_param(_nblock);

				yaccgen_param _startIter { kernelfunction.int32(), string(cudafunction.gr_atidx()), "_startIter" };
				_cudaGenerator->add_param(_startIter);

				yaccgen_param _endIter { kernelfunction.int32(), nblock, "_endIter" };
				_cudaGenerator->add_param(_endIter);

				yaccgen_param _loopVar { kernelfunction.int32(), "", "_i" };
				_cudaGenerator->add_param(_loopVar);

				_cudaGenerator->add_for(_loopVar.name + tok_eq + _startIter.name, _loopVar.name + tok_lt + _endIter.name, _loopVar.name + tok_addeq + _nblock.name);
				_cudaGenerator->add_openBlock();
				stringstream ss;
				((ExpressionStemnt*) _forList[var]->block)->expression->print(ss);
				string tmpComp = ss.str();
				replaceAll(tmpComp, loopVar, "_i");
				_cudaGenerator->add_line(tmpComp + tok_semicolon);

				_cudaGenerator->add_closeBlock();
				_cudaGenerator->add_closeBlock();
				_cudaGenerator->add_closeBlock();
			}
		}

		void YAS_ParserWrapper::print_cuda(std::ostream& out) {
			out << _cudaGenerator->_codeBlock;
		}
	}
}

