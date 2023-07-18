#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recursion(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int target, int index)
    {
        if (index == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        if (arr[index]<=target)
        {
            temp.push_back(arr[index]);
            recursion(arr, ans, temp, target-arr[index], index);
            temp.pop_back();
        }

        recursion(arr, ans, temp, target, index+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recursion(candidates, ans, temp, target, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> candidates ={2,3,6,7};
    s.combinationSum(candidates, 7);
}
