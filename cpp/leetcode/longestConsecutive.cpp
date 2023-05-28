#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int ans = 0;
	int count = 1;
	int lastMin = INT_MIN;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] - 1 == lastMin)
			count++,
			ans = max(count, ans),
			lastMin = nums[i];
		else if (nums[i] == lastMin)
			continue;
		else
			lastMin = nums[i],
			count = 1;
	}

	return ans;
}

int main()
{
	std::vector<int> v = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
	cout << longestConsecutive(v) << "\n";
	return 0;
}