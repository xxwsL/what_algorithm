#pragma once
#ifndef _LongestVaildParentheses_h_
#define _LongestVaildParentheses_h_

#include <iostream>
#include <string>
#include <stack>
#include <vector>

int LongestVaildParentheses(std::string s) {
	if (s.empty()) {
		return 0;
	}
	int iCount_start = 0, iCurrLen_start = 0, iVaildLen_start = 0, \
		iCount_end = 0, iCurrLen_end = 0, iVaildLen_end = 0;
	size_t siStrLen = s.size() - 1;
	for (size_t i = 0; i <= siStrLen; ++i) {
		iCurrLen_start++;
		iCurrLen_end++;
		iCount_start += s[i] == '(' ? 1 : -1;
		iCount_end += s[siStrLen - i] == ')' ? 1 : -1;
		if (iCount_start == 0) {
			if (iCurrLen_start > iVaildLen_start) {
				iVaildLen_start = iCurrLen_start;
			}
		}
		else if (iCount_start < 0) {
			iCurrLen_start = 0;
			iCount_start = 0;
		}

		if (iCount_end == 0) {
			if (iCurrLen_end > iVaildLen_end) {
				iVaildLen_end = iCurrLen_end;
			}
		}
		else if (iCount_end < 0) {
			iCurrLen_end = 0;
			iCount_end = 0;
		}
	}
	return iVaildLen_start > iVaildLen_end ? iVaildLen_start : iVaildLen_end;
}

int LongestVaildParentheses_1(std::string s) {
	if (s.empty()) {
		return 0;
	}
	std::stack<std::pair<char, int>> stackTp;
	stackTp.push(std::make_pair(s[0], 0));

	int iVaildLen = 0, iTpLen = 0, iIndex_tp = 0;
	bool bPushFlag = 0;
	for (size_t i = 1; i < s.size(); ++i) {
		if (!stackTp.empty() && stackTp.top().first == '(' && s[i] == ')') {
			iTpLen = i - stackTp.top().second + 1;
			if (iTpLen > iVaildLen) {
				iVaildLen = iTpLen;
			}
			iIndex_tp = stackTp.top().second;
			bPushFlag = 1;
			stackTp.pop();
		}
		else {
			if (bPushFlag) {
				stackTp.push(std::make_pair(s[i], iIndex_tp));
				bPushFlag = 0;
			}
			else {
				stackTp.push(std::make_pair(s[i], i));
			}
		}
	}
	return iVaildLen;
}

void LongestVaildParentheses_t (void){

	std::cout << "this is LongestVaildParentheses test\n";
	std::string strTest = "(()";
	std::cout << "test 0 " << strTest << " = " << LongestVaildParentheses(strTest) << std::endl;

	strTest = ")()())";
	std::cout << "test 1 " << strTest << " = " << LongestVaildParentheses(strTest) << std::endl;

	strTest = "()(()";
	std::cout << "test 2 " << strTest << " = " << LongestVaildParentheses(strTest) << std::endl;

	strTest = "(())";
	std::cout << "test 3 " << strTest << " = " << LongestVaildParentheses(strTest) << std::endl;


	std::cout << "this is LongestVaildParentheses test_1\n";
	strTest = "(()";
	std::cout << "test_1 0 " << strTest << " = " << LongestVaildParentheses_1(strTest) << std::endl;

	strTest = ")()())";
	std::cout << "test_1 1 " << strTest << " = " << LongestVaildParentheses_1(strTest) << std::endl;

	strTest = "()(()";
	std::cout << "test_1 2 " << strTest << " = " << LongestVaildParentheses_1(strTest) << std::endl;	

	strTest = "(())";
	std::cout << "test_1 3 " << strTest << " = " << LongestVaildParentheses(strTest) << std::endl;
}


#endif