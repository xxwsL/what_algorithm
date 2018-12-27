#pragma once
#ifndef _NextPermutation_hpp_
#define _NextPermutation_hpp_

#include<vector>	

void nextPermutation(std::vector<int>& nums) {
	
	auto index_left = 0;
	auto index_right = nums.size() - 1;

	for (size_t i = nums.size() - 1; i != 0; --i) {
		size_t siI = i - 1;
		if (nums[i] > nums[siI]) {
			index_left += siI;
			for (size_t j = nums.size() - 1; j != siI; --j) {
				if (nums[j] > nums[siI]) {
					index_right = j;
					break;
				}
			}
			std::swap(nums[index_left], nums[index_right]);
			index_left += 1;
			break;
		}
	}
	std::reverse(nums.begin() + index_left, nums.end());
}

void nextPermutation_t(void) {
	std::cout << "this is NextPermutation test\n";
	std::vector<int> vecTp_0 = { 1, 2, 7, 4, 3, 1 };
	std::vector<int> vecTp_1 = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> vecTp_2 = { 6, 5, 4, 3, 2, 1 };
	std::vector<int> vecTp_3 = { 2, 1, 3, 5, 4, 1 };
	nextPermutation(vecTp_0);
	nextPermutation(vecTp_1);
	nextPermutation(vecTp_2);
	nextPermutation(vecTp_3);

}

#endif