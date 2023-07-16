#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        std::vector<std::pair<int, int>> train;
        for (int i=0; i<n; i++)
            train.push_back({arr[i], dep[i]});

        sort(train.begin(), train.end());
    
        int ans =1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i=0; i<n; i++)
        {
            while (!pq.empty() && pq.top() < train[i].first) pq.pop();
            pq.push(train[i].second);
            ans =std::max(ans, pq.size());
        }       

        return ans;
    }
};

int main(){

}
