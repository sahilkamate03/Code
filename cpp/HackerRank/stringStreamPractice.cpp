#include <bits/stdc++.h>
using namespace std;

int countWords(string str)
{
    // Breaking input into word
    // using string stream
   
    // Used for breaking words
    stringstream s(str);
   
    // To store individual words
    string word;
 
    int count = 0;
    while (s >> word)
        count++;
    return count;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s = "geeks for geeks geeks "
               "contribution placements";
    cout << " Number of words are: " << countWords(s) << endl;

    stringstream sr(s);
    sr << " sahil";
    cout << s;
    return 0;

}
