#pragma once
#ifndef _SearchInRotatedSortedArray_h_
#define _SearchInRotatedSortedArray_h_

#include <iostream>
#include <vector>

int SearchInRotatedSortedArray(std::vector<int>& nums, int target) {
	if (nums.empty()) {
		return -1;
	}
	int siIndex_left = 0, siIndex_right = nums.size() - 1, siIndex_media = siIndex_right >> 1;

	while (1) {
		int iValue_left = nums[siIndex_left], iValue_right = nums[siIndex_right], iValue_media = nums[siIndex_media];
		if (target == iValue_left) {
			return siIndex_left;
		}
		else if (target == iValue_right) {
			return siIndex_right;
		}
		else if (target == iValue_media) {
			return siIndex_media;
		}
		else if ((iValue_left < iValue_media && target > iValue_left && target < iValue_media) || \
				(iValue_left > iValue_media && (target > iValue_left || target < iValue_media))) {
			siIndex_left++;
			siIndex_right = siIndex_media - 1;
			siIndex_media = (siIndex_left + siIndex_right) >> 1;
			
		}
		else if ((iValue_media < iValue_right && target > iValue_media && target < iValue_right) || \
				(iValue_media > iValue_right && (target > iValue_media || target < iValue_right))) {
			siIndex_left = siIndex_media + 1;
			siIndex_right--;
			siIndex_media = (siIndex_left + siIndex_right) >> 1;
		}
		else {
			return -1;
		}
		if (siIndex_left > siIndex_right) {
			return -1;
		}
	}
}

void SearchInRotatedSortedArray_t() {
	std::cout << ">> this is SearchInRotatedSortedArray test\n";

	std::vector<int> vecTest;
	int iTarget;

	vecTest = {4, 5, 6, 7, 0, 1, 2};
	iTarget = 0;
	std::cout << "test 0 out : " << SearchInRotatedSortedArray(vecTest, iTarget) << "\n\n";

	vecTest = { 4, 5, 6, 7, 0, 1, 2 };
	iTarget = 3;
	std::cout << "test 1 out : " << SearchInRotatedSortedArray(vecTest, iTarget) << "\n\n";

	vecTest = { 4, 5, 6, 7, 8, 1, 2, 3 };
	iTarget = 8;
	std::cout << "test 2 out : " << SearchInRotatedSortedArray(vecTest, iTarget) << "\n\n";

	vecTest = { 1,2,3,4,5,6 };
	iTarget = 4;
	std::cout << "test 3 out : " << SearchInRotatedSortedArray(vecTest, iTarget) << "\n\n";

	vecTest = { 5, 1, 2, 3, 4 };
	iTarget = 1;
	std::cout << "test 4 out : " << SearchInRotatedSortedArray(vecTest, iTarget) << "\n\n";


}

#endif