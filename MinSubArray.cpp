#include <bits/stdc++.h> // header files
using namespace std;

int minSubSliding(int target, vector<int> &nums)
{
	// define a variable for minimum size
	// and set it to maximum integer possible
	int min = std::numeric_limits<int>::max();

	// a variable to hold running sum
	int total = 0;
	// variable to hold start and end index of our subarray / window
	int start = 0, end = 0;

	// use a for loop to add new elements into the window
	for (end = 0; end < nums.size(); end++)
	{
		// add the current element into the total sum of the subarray
		total += nums[end];

		// if the total of the subarray is greater or equal to target
		// and since we need the minimum subarray start decreasing the
		// size from left
		while (total >= target)
		{
			// update the minimum length of our window if length of our current
			// window is smaller
			if (end - start + 1 < min)
			{
				min = end - start + 1;
			}

			// decrease the size from left or shrink the window
			total -= nums[start];
			start++;
		}
	}

	// when there is no such window with sum greater or equal to target
	// then our min will remain unchange, if it is unchanged then return 0
	if (min == std::numeric_limits<int>::max())
		return 0;

	return min;
}

// driver program
int main()
{

	int target = 8;
	vector<int> input{4, 3, 1, 2, 6};
	cout << "The length of the smallest subarray with target " << target << " is ";
	cout << minSubSliding(8, input) << endl;
	return 0;
