#pragma once
#ifndef _SubstringWithConcatenation_h_
#define _SubstringWithConcatenation_h_

#include <iostream>
#include <vector>

std::vector<int> SubstringWithConcatenation(std::string s, std::vector<std::string> words) {
	std::vector<int> vecRe;
	if (s.empty() || words.empty()) {
		return vecRe;
	}

	std::vector<std::vector<std::pair<int, int>>> vecPos;
	vecPos.resize(words.size());

	for (size_t i = 0; i < words.size(); ++i) {
		int iLen = 0;
		for (size_t j = 0; j < s.size(); ++j) {
			if (words[i][iLen] == s[j]) {
				iLen++;
			}
			else {
				iLen = 0;
			}
			if (iLen == words[i].size()) {
				vecPos[i].push_back(std::make_pair(j - words[i].size(), j));
				iLen = 0;
			}
		}
	}

	if (vecPos.size() != words.size()) {
		return vecRe;
	}

	int iLeft, iRight;
	size_t siMatchIndex;

	std::vector<int> vecIndex;
	vecIndex.resize(words.size());

	for (size_t i = 0; i < vecPos[0].size(); ++i) {
		iLeft = vecPos[0][i].first; iRight = vecPos[0][i].second;
		for (size_t i = 0; i < vecIndex.size(); ++i) {
			vecIndex[i] = 0;
		}
		
		bool bMatchFlag = 1;
		size_t siCount = 1;
		while (bMatchFlag) {
			size_t j = 1;
			while(j < vecIndex.size() && bMatchFlag) {
				if (vecIndex[j]) {
					continue;
				}
				size_t k = 0;
				while (k < vecPos[j].size() && bMatchFlag) {
					if (vecPos[j][k].first == iRight) {
						iRight = vecPos[j][k].second;
						vecIndex[j] = 1;
						siCount++;
						break;
					}
					else if (vecPos[j][k].second == iLeft) {
						iLeft = vecPos[j][k].first;
						vecIndex[j] = 1;
						siCount++;
						break;
					}
					else if (j == vecIndex.size() - 1 && k == vecPos[j].size() - 1) {
						bMatchFlag = 0;
					}
					k++;
				}
				if (siCount == vecPos.size()) {
					vecRe.push_back(iLeft + 1);
					bMatchFlag = 0;
				}
				j++;
			}
		}
	}
	
	return vecRe;
}

void SubstringWithConcatenation_t(void) {
	
	std::cout << "this is SubstringWithConcatenation test\n\n";

	std::string strTest;
	std::vector<std::string> vecWords;
	std::vector<int> vecOut;

	strTest = "barfoothefoobarman";
	vecWords = {"foo", "bar"};
	vecOut = SubstringWithConcatenation(strTest, vecWords);
	if (vecOut.empty()) {
		std::cout << "test 1 out is empty\n\n";
	}
	else {
		std::cout << "test 0 = [" << vecOut[0] << ", " << vecOut[1] << "]" << "\n\n";
	}

	strTest = "wordgoodstudentgoodword";
	vecWords = { "word","student" };
	vecOut = SubstringWithConcatenation(strTest, vecWords);
	if (vecOut.empty()) {
		std::cout << "test 1 out is empty\n\n";
	}
	else {
		std::cout << "test 1 = [" << vecOut[0] << ", " << vecOut[1] << "]" << "\n\n";
	}

	strTest = "wordgoodgoodgoodbestword";
	vecWords = {"word","good","best","word"};
	vecOut = SubstringWithConcatenation(strTest, vecWords);
	if (vecOut.empty()) {
		std::cout << "test 1 out is empty\n\n";
	}
	else {
		std::cout << "test 1 = [" << vecOut[0] << ", " << vecOut[1] << "]" << "\n\n";
	}

	
}

#endif