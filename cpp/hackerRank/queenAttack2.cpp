#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int board_size, obst_no, q_y, q_x, e_y, e_x, add, sum =0;
	cin >>board_size >>obst_no >>q_y >>q_x;

	int a,b,c,d,e,f,g,h;
	a =q_x -1; b =q_y -1;
	c =q_x -1; d =board_size -q_y;
	e =board_size -q_x; f =q_y -1;
	g =board_size -q_x; h =board_size -q_y;
	add =2*(board_size -1);
	sum= add+min(a,b)+min(c,d)+min(e,f)+min(g,h);

	int vector_x, vector_y;
	while (obst_no--){
		cout << sum << endl;
		cin >> e_y >> e_x;

		if ((e_x==q_x || e_y==q_y) || (abs(q_x-e_x)==abs(q_y- e_y))) {
		// int conditon1 = min(min(board_size -e_x +1, board_size -e_y +1), min(x,y));

		vector_x = q_x - e_x; vector_y = q_y - e_y;
		if (vector_x>0 && vector_y<0) sum-=min(e_x,e_y); //a
		else if (vector_x==0 && vector_y<0) sum-=board_size -e_y +1; //b
		else if (vector_x<0 && vector_y<0) sum-=min(board_size -e_x +1, board_size -e_y +1); //c
		else if (vector_x<0 && vector_y==0) sum-=board_size -e_x +1; //d
		else if (vector_x<0 && vector_y>0) sum-=min(e_x, e_y); //e
		else if (vector_x==0 && vector_y>0) sum-=e_y; //f
		else if (vector_x>0 && vector_y>0) sum-=min(e_x,e_y); //g
		else if (vector_x>0 && vector_y==0) sum-=e_x; //h

		}
	}


	cout << sum << endl;
}
