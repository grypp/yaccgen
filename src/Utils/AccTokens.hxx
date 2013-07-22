/*
 * AccTokens.hxx
 *
 *  Created on: Jul 22, 2013
 *      Author: grypp
 */

#ifndef ACCTOKENS_HXX_
#define ACCTOKENS_HXX_

#include <string>
using namespace std;

namespace yaccgen {

		const static string tok_pragma = "#pragma";
		const static string tok_acc = "acc";
		const static string tok_acc_parallel = "parallel";
		const static string tok_acc_kernels = "kernels";
		const static string tok_acc_reduction = "reduction";
		const static string tok_acc_loop = "loop";

		const static string tok_acc_copyin = "copyin";
		const static string tok_acc_copyout = "copyout";
		const static string tok_acc_copyinout = "copy";

		const static char tok_openCrlyBracket = '{';
		const static char tok_closeCrlyBracket = '}';
		const static char tok_openBracket = '(';
		const static char tok_closeBracket = ')';
		const static char tok_semicolon = ';';
		const static char tok_eq = '=';
		const static char tok_ws = ' ';
		const static char tok_lt = '<';
		const static char tok_gt = '>';
		const static string tok_q = "==";
		const static string tok_nq = "!=";
		const static string tok_qlt = "=<";
		const static string tok_qgt = "=>";
}

#endif /* ACCTOKENS_HXX_ */
