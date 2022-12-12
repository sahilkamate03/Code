#include <bits/stdc++.h>
using namespace std;

int main(){
	clock_t tStart = clock();
    /* Do your stuff here */
	for (int i=0; i<=1e9; i++) {cout << i << " ";}		
  printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
