/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static int mD =0;

    static bool comparator (Job j1, Job j2)
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
        if (n == 0) return {0, 0};
        else if (n == 1) return {1, arr[0].profit};
        sort (arr, arr+n, comparator);
        int jobDone =0;
        int profit =0;
        int task[mD] ={0};

        for (int i=0; i<n && mD; i++)
        {
            int t =arr[i].dead -1;
            while (task[t]!=0 && t>0)
                t--;

            if (task[t]==0)
            {
                task[t] =arr[i].id;
                profit +=arr[i].profit;
                mD--; jobDone++;
            }
        }

        return {jobDone, profit};
    } 
};
