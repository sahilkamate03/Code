class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting 
    {
        int start;
        int end;
    };

    bool comparator (meeting &meet1, meeting &meet2)
    {
        if (meet1.end < meet2.end) return true;
        else if (meet1.end > meet2.end) return false;
        return false;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for (int i=0; i<n; i++)
        {
            meet[i].start =start[i], meet[i].end =end[i];
        }

        sort (meet, meet+n, comparator);

        int ans =1;
        int limit =meet[0].end;
        for (int i=1; i<n; i++)
        {
            if (meet[i].start > limit)
            {
                ans++;
                limit =meet[i].end;
            }
        }

        return ans;
    }
};
