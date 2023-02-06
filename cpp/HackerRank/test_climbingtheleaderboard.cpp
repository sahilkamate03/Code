#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int rank_size ;
    cin >> rank_size;
    
    int ranked[rank_size];
    for (int i=0; i<rank_size; i++) cin>>ranked[i];
    
    int player_size ;
    cin >> player_size;
    
    int result[player_size];
    int player[player_size];
    for (int i=0; i<player_size; i++) cin>>player[player_size - i - 1];

    int n=0;
    int rank = 1;
            
    for (int i=0; i<=rank_size;){

        if (player[n] < ranked[i]) {
            i++; 
            if (ranked[i] != ranked[i-1]) rank++;
            continue;
        }
        
        if (player[n] >= ranked[i]){
            result[n] = rank ;
            n++;
        } 

        // while (player[n]==player[n-1]) result[n]=result[n-1],n++;       

        if (n==player_size) break;
    }

    while (n!=player_size) result[n] = rank-1 ,n++;                

    for(int i=0; i<player_size; i++) cout << result[player_size -i -1] << endl;
}
