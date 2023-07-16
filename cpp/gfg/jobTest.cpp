#include <bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

int mD =0;

bool comparator (Job j1, Job j2)
{
    mD =max (mD, max(j1.dead, j2.dead));
    if (j1.profit > j2.profit) return true;
    else if (j1.profit < j2.profit) return false;
    else if (j1.dead > j2.dead) return true;
    return false;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort (arr, arr+n, comparator);
    vector <int> ans;
    cout << mD << endl;
    return ans;
} 

int main()
{
    Job arr[2];
    struct Job job1;
    job1.id =1;
    job1.profit =2;
    job1.dead =3;

    arr[0] =job1;

    struct Job job2;
    job2.id =2;
    job2.profit =3;
    job2.dead =1;
    arr[1] =job2;

    JobScheduling(arr, 2);
}
