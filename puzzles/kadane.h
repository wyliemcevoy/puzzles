#pragma once
#include <algorithm>
#include <vector>
#include <tuple>

namespace puzzles {
	/** \brief Finds the maximum subarray in a vector of ints
	* The problem to be solved: Given an array of integers, find a subarray that is of maximum sum.
	* This does an O(n) pass over a vector of integers and determines a continuous subsection of them which has maximal sum.
	* In the case that the solution is non-unique, it returns the first streak found.
	* It is possible to do this with fewer variables and templated, this implementation is for understanding the algorithm.
	* @param data A vector of integers.
	* @return An tuple of the start index of the streak, the end index of the streak, and the sum over the streak (in that order).
	*/
	std::tuple<int,int,int> ExplainedKadane(const std::vector<int> & data);
}
