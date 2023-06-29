class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;

		for (int i=0; i<nums.size(); i++)
		{
			map<int,int> hm;
			int sum =-nums[i];

			for (int j =i+1; j<nums.size(); j++)
			{
				if (hm.find(sum-nums[j])!=hm.end())
				{
					ans.push_back({nums[i],sum-nums[j],nums[j]});
					cout << i << " " << j << " " << hm[sum-nums[j]] << endl;
				}
				hm.insert({nums[j],j});
			}
			
		}
		return ans;
    }
};

