/*
Given an array of integers, check if array contains a sub-array having 0 sum.

Example:
Given the input array:  { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }

The sub-arrays with 0 sum are:
{ 3, 4, -7 }
{ 4, -7, 3 }
{ -7, 3, 1, 3 }
{ 3, 1, -4 }
{ 3, 1, 3, 1, -4, -2, -2 }
{ 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }

Date: 14/09/2020
Time: From 21h48 to 23h35
*/

#include "const.h"
#include <vector>
#include <algorithm>

void CheckZeroSum(std::vector<int>& vec, std::vector<int>& subset, std::vector<std::vector<int>>& result, int index, bool uniqueNumbers)
{
	if (vec.size() == 0 || vec.size() == 1)
	{
		return;
	}

	int sum = 0;

	for (std::vector<int>::iterator it = subset.begin(); it != subset.end(); ++it)
	{
		sum += *it;
	}

	if (sum == 0 && subset.size() > 0)
	{
		if (uniqueNumbers)
		{
			std::sort(subset.begin(), subset.end());
		}

		if (!(std::find(result.begin(), result.end(), subset) != result.end()))
		{
			result.push_back(subset);
		}
	}

	for (size_t i = index; i < vec.size(); ++i)
	{
		subset.push_back(vec[i]);
		CheckZeroSum(vec, subset, result, i + 1, uniqueNumbers);

		subset.pop_back();
	}

	return;
}

#ifdef ZeroSumSubarrays
int main()
{
	std::vector<int> vec{ 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
	std::vector<int> subset;
	std::vector<std::vector<int>> result;

	int index = 0;
	/*CheckZeroSum(vec, subset, result, index, true);
	std::cout << result.size() << std::endl;

	index = 0;
	subset.clear();
	result.clear();
	CheckZeroSum(vec, subset, result, index, false);
	std::cout << result.size() << std::endl;*/

	vec = {-1, 1, 0};
	index = 0;
	subset.clear();
	result.clear();
	CheckZeroSum(vec, subset, result, index, true);
	std::cout << result.size() << std::endl;

	index = 0;
	subset.clear();
	result.clear();
	CheckZeroSum(vec, subset, result, index, false);
	std::cout << result.size() << std::endl;
}
#endif