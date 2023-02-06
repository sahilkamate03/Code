#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp(x,y) make_pair(x,y)
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    set<pair<int,int>> bst;
    int n,k,x,y;
    scanf("%d%d",&n,&k);
    scanf("%d%d",&x,&y);
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        bst.insert({a,b});
    }
    int ans=0;
    for(int i=0;i<8;i++){
        int X=x;
        int Y=y;
        while(1){
            X+=dx[i];
            Y+=dy[i];
            if(X<=0 || X>n || Y<=0 || Y>n) break;
            if(bst.find({X,Y})!=bst.end()) break;
            ans++;
        }
        cout << ans << endl;
    }
    printf("%d\n",ans);
}