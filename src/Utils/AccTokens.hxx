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
	const static string tok_acc_data = "data";
	const static string tok_acc_parallel = "parallel";
	const static string tok_acc_kernels = "kernels";
	const static string tok_acc_reduction = "reduction";
	const static string tok_acc_loop = "loop";

	const static string tok_acc_copyin = "copyin";
	const static string tok_acc_copyout = "copyout";
	const static string tok_acc_copyinout = "copy";

	const static string tok_openCrlyBracket = "{";
	const static string tok_closeCrlyBracket = "}";
	const static string tok_openBracket = "(";
	const static string tok_closeBracket = ")";
	const static char tok_semicolon = ';';
	const static string tok_comma = ",";
	const static char tok_eq = '=';
	const static char tok_ws = ' ';
	const static char tok_lt = '<';
	const static char tok_gt = '>';
	const static string tok_q = "==";
	const static string tok_nq = "!=";
	const static string tok_qlt = "=<";
	const static string tok_qgt = "=>";
	const static string tok_addeq = "+=";

	const static string tok_for = "for";

	const static string tok_com_single = "//";
	const static string tok_com_startMul = "/*";
	const static string tok_com_closeMul = "*/";

	const static string tok_omp = "omp";
	const static string tok_omp_target = "target";
	const static string tok_omp_device = "device";
	const static string tok_omp_env = "acc/cuda";
	const static string tok_omp_copyin = "copy_in";
	const static string tok_omp_copyout = "copy_out";
	const static string tok_omp_copyinout = "copy_inout";

}

#endif /* ACCTOKENS_HXX_ */

