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
        
        for (int i=indec; i<arr.size(); i++)
        {
            if (i>index && arr[index] == arr[index+1]) index++;
            if (arr[index] > target) continue;

            temp.push_back(arr[index]);
            recursion(arr, ans, temp, target, index+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        recursion(candidates, ans, temp, target, 0);
        return ans;
    }
};
