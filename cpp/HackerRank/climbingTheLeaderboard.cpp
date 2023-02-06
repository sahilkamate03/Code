#include <bits/stdc++.h>
using namespace std;

int main()
{
    int rank_size;
    cin >> rank_size;
    
    int ranked[rank_size];
    for (int i=0; i<rank_size; i++) cin>>ranked[i];
    
    int player_size = 4;
    cin >> player_size;
    
    int result[player_size];
    int player[player_size];
    for (int i=0; i<player_size; i++) cin>>player[player_size - i - 1];
    
    // for (int i=0; i<player_size; i++) cin>>player[player_size - i - 1];

    // for (int i=0; i<player_size; i++) cout<<player[i];


    int n=0;
    int rank = 1;
            
    for (int i=0; i<rank_size; i++){

        // if (n == player_size) break;
        if ( i!=0 && ranked[i] == ranked[i-1]) continue;
        
        if (player[n] >= ranked[i]){
            result[n] = rank ;
            // cout << player[n] << " : " << rank  << endl;
            count++; n++;
        }        

        rank++;

        if (i==rank_size -1) result[n] = rank;
    }               

    for(int i=0; i<player_size; i++) cout << result[player_size -i -1] << endl;
}
