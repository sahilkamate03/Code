#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {

	vector<int> ans;
	int countN = 0;
	int element = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (countN == 0)
		{
			element = nums[i];
			countN = 3;
		}
		else if (nums[i] != element)
			countN--;

		else if (nums[i] == element)
			countN++;

		if (countN - 2 > (int)nums.size() / 3)
		{
			ans.push_back(nums[i]);
			break;
		}

	}

	countN = 0;
	element = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (ans.size() && ans[0] == nums[i])
			continue;

		if (countN == 0)
		{
			element = nums[i];
			countN = 3;
		}
		else if (nums[i] != element)
			countN--;

		else if (nums[i] == element)
			countN++;

		if (countN - 2 > (int)nums.size() / 3)
		{
			ans.push_back(nums[i]);
			break;
		}
	}

	for (int i=0; i<ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	return ans;
}

int main()
{
	vector<int> nums ={3,2,3};

	majorityElement(nums);
	return 0;
}