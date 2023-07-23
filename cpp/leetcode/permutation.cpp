class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, vector<int> &freq)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i=0; i<nums.size(); i++)
        {
            if (!freq[i])
            {
                temp.push_back(nums[i]);
                freq[i] =1;
                solve(ans, temp, nums, freq);
                freq[i] =0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq (nums.size(), 0);
        solve(ans, temp, nums, freq);
        return ans;
    }
};
