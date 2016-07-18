
#include "kadane.h"

namespace puzzles
{

	std::tuple<int,int,int> puzzles::ExplainedKadane(const std::vector<int>& data)
	{
		int current_streak = 0; /**< sum over the currents streak */
		int current_start = 0; /**< location of the current streak's starpoint */
		int current_end = 0; /**< location of the current streak's endpoint */

		int best_streak = 0; /**< sum over the best streak */
		int best_start = 0;/**< location of the best streak's starpoint */
		int best_end = 0; /**< location of the best streak's endpoint */

		int index = 0; /**< keeps track of current position in the vector */


		for (std::vector<int>::const_iterator it = data.begin(); it != data.end(); ++it)
		{
			if (*it > current_streak + *it)
			{
				current_start = index; // Abandon current streak and start new streak
			}
			else
			{
				current_end = index;  // continue current streak (*it could be negative, but still continue)
			}

			// update new value of current_streak
			current_streak = std::max(*it, current_streak + *it);

			if (current_streak > best_streak)
			{
				// The current streak is better than the best recorded streak so far.
				// Update the indicies of the streak.
				best_start = current_start;
				best_end = current_end;
			}

			// update the new best streak found so far if current streak is better
			best_streak = std::max(best_streak, current_streak);
			++index;
		}

		std::tuple<int, int, int> result(best_start, best_end, best_streak);
		return result;
	}
}