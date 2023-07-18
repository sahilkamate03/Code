class Solution {
public:
    void recursion (vector<int> &nums,set<vector<int>> &st, vector<int> &temp, int N, int current) 
    {
        if (current>=N)
        {
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }

        recursion(nums, st, temp, N, current+1);
        temp.push_back(nums[current]);
        recursion(nums, st, temp, N, current+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        recursion(nums, st, temp, nums.size(), 0);

        vector<vector<int>> ans = {st.begin(), st.end()};
        return ans;
    }
};
