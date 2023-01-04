#include <bits/stdc++.h> // all in one header file :)

using namespace std;

int maximum_sum_subarray_k(vector<int> &input, int k)
{
	// declare a variable to hold the result
	int max_sum = 0;

	// find the sum of first k elements
	int current_subarray_sum = 0;
	for (int i = 0; i < k; i++)
	{
		current_subarray_sum += input[i];
	}

	max_sum = current_subarray_sum;
	// loop to find the maximum sum subarray
	for (int i = k; i < input.size(); i++)
	{
		// add the ith element and subtract the (i - k)th element
		current_subarray_sum = current_subarray_sum - input[i - k] + input[i];
		// update the result if current subarray sum is greater than result
		max_sum = max(max_sum, current_subarray_sum);
	}

	return max_sum;
}

// Driver probram
int main()
{
	// input
	vector<int> input{4, 3, 9, 5, 1, 2};
	int k = 3;
	cout << maximum_sum_subarray_k(input, k) << endl;
}
