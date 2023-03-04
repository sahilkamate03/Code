#include <bits/stdc++.h>
using namespace std;

bool meow(int s[], int n)
{

    for (int i=0; i<n; i++)
        cout << s[i] << " ";
    cout << endl;
    
    for (int i=0; i<n-1; i++)
    {
        
        if (s[i]==45 || s[i]==77)
        {
            if (s[i+1]!=37 || s[i+1]!=69)
                return false;
            
            if (s[i+1]!=45 || s[i+1]!=77)
                return false;
                
            continue;
        }
        
        if (s[i]==37 || s[i]==69)
        {
            if (s[i+1]!=47 || s[i+1]!=79)
                return false;
            
            if (s[i+1]!=37 || s[i+1]!=69)
                return false;
                
            continue;
        }
        
        if (s[i]==47 || s[i]==79)
        {
            if (s[i+1]!=55 || s[i+1]!=87)
                return false;
            
            if (s[i+1]!=47 || s[i+1]!=79)
                return false;
            
            continue;
        }
        
        if (s[i]==55 || s[i]==87)
        {
            if (s[i+1]!=55 || s[i+1]!=87)
                return false;
                
            continue;
        }
        
        return false;
    }  
    
    return true;
}

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int s[n];

        string st;
        cin >>st;

        for(int i = 0; i < n; i++) 
            s[i]= (int) st[i];
        
        (meow(s,n)) ? cout << "YES\n" : cout << "NO\n";
        
    }
    
}
