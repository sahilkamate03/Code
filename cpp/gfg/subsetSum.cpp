class Solution
{
public:
    
    void recursive(vector<int> &arr, vector<int> &ans, int N,int current, int sum)
    {
       if (current>=N) 
       {
           ans.push_back(sum);
           return;
       }
       recursive(arr, ans, N, current+1, sum);
       sum +=arr[current];
       recursive(arr, ans, N, current+1, sum);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int sum =0;
        vector<int> ans;
        recursive(arr ,ans, N, 0, sum);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
