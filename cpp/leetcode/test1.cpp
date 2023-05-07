#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    int n =A.size();
    int expectedSum = (n*(n-1))/2;
    int currentSum =0;
    int xorN =0;
    int missingNumber =0;
    for (int i=0; i<n; i++)
    {
        currentSum +=A[i];
        xorN ^=(A[i]^ (i+1));
    }
    
    cout << "H: " << expectedSum << " " << currentSum << endl;
    missingNumber =currentSum -expectedSum;
    xorN ^=missingNumber;
    
    vector<int> ans;
    
    ans.push_back(missingNumber);
    ans.push_back(xorN);
    cout << missingNumber << " " << xorN << endl;
    return ans;
}


int main()
{
    vector<int> v1= {3,1,2,4,5,5};
    repeatedNumber(v1);
    
    vector<int> v= {3,1,2,5,3};
    repeatedNumber(v);

    return 0;
}
