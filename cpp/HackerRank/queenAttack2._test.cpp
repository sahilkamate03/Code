#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int size) {
	cout << arr[0] << " " << arr[1] << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int board_size, obst_no, q_y, q_x, e_y, e_x, add, sum =0;
	int max_size = 100000;
	
	int s;
	cin >>board_size >>obst_no >>q_y >>q_x;

	int la[3] = {0,0,max_size},
	lb[3] = {0,0,max_size}, 
	lc[3] = {0,0,max_size}, 
	ld[3] = {0,0,max_size}, 
	le[3] = {0,0,max_size}, 
	lf[3] = {0,0,max_size},
	lg[3] = {0,0,max_size}, 
	lh[3] = {0,0,max_size};


	int a,b,c,d,e,f,g,h;
	
	int vector_x, vector_y;

	// loop to find limit
	while (obst_no--){
		cin >> e_y >> e_x;

		if ((e_x==q_x || e_y==q_y) || (abs(q_x-e_x)==abs(q_y- e_y))) {
		
		vector_x = q_x - e_x; vector_y = q_y - e_y;

		if (vector_x>0 && vector_y<0){ 
			s = vector_x-vector_y;
			if (la[2]!=min(la[2],s)) la[0]=e_x, la[1]=e_y, la[2]=s;
			 //a
		}
 		else if (vector_x==0 && vector_y<0) {
 			s = - vector_y;
 			if (lb[2]!=min(lb[2],s)) lb[0]=e_x, lb[1]=e_y, lb[2]=s;
 			 //b
 		} 
		else if (vector_x<0 && vector_y<0) {
			s = - vector_x - vector_y;
			if (lc[2]!=min(lc[2],s)) lc[0]=e_x, lc[1]=e_y, lc[2]=s;
			 //c
		}
		else if (vector_x<0 && vector_y==0){
			s = - vector_x;
			if (ld[2]!=min(ld[2],s)) ld[0]=e_x, ld[1]=e_y, ld[2]=s;
			//d
		} 
		else if (vector_x<0 && vector_y>0) {
			s = - vector_x + vector_y;
			if (le[2]!=min(le[2],s)) le[0]=e_x, le[1]=e_y, le[2]=s;
			 //e
		}  
		else if (vector_x==0 && vector_y>0) {
			s =  vector_y;
			if (lf[2]!=min(lf[2],s)) lf[0]=e_x, lf[1]=e_y, lf[2]=s;
			 //f
		} 
		else if (vector_x>0 && vector_y>0) {
			s =  vector_x + vector_y;
			if (lg[2]!=min(lg[2],s)) lg[0]=e_x, lg[1]=e_y, lg[2]=s;
			 //g
		} 
		else if (vector_x>0 && vector_y==0) {
			s = vector_x;
			if (lh[2]!=min(lh[2],s)) lh[0]=e_x, lh[1]=e_y, lh[2]=s;
			 //h
		} 

		}
	}

	// print(la, 2);
	// print(lb, 2);
	// print(lc, 2);
	// print(ld, 2);
	// print(le, 2);
	// print(lf, 2);
	// print(lg, 2);
	// print(lh, 2);

	a =q_x -1; b =q_y -1;
	c =q_x -1; d =board_size -q_y;
	e =board_size -q_x; f =q_y -1;
	g =board_size -q_x; h =board_size -q_y;
	add =2*(board_size -1);
	// cout << min(c,d) << endl; //a
	// cout << min(g,h) << endl; //c
	// cout << min(e,f) << endl;  //e
	// cout << min(a,b) << endl; //g
	sum= add+min(a,b)+min(c,d)+min(e,f)+min(g,h);

	int l[16];
	int skip=0;
	l[skip] =la[0], l[skip+1] =la[1], skip+=2;
	l[skip] =lb[0], l[skip+1] =lb[1], skip+=2;
	l[skip] =lc[0], l[skip+1] =lc[1], skip+=2;
	l[skip] =ld[0], l[skip+1] =ld[1], skip+=2;
	l[skip] =le[0], l[skip+1] =le[1], skip+=2;
	l[skip] =lf[0], l[skip+1] =lf[1], skip+=2;
	l[skip] =lg[0], l[skip+1] =lg[1], skip+=2;
	l[skip] =lh[0], l[skip+1] =lh[1], skip+=2;

	for (int i=0; i<16; i+=2){
		e_x = l[i], e_y=l[i+1];

		if (e_x==0 && e_y==0) continue;
		// cout << l[i] << " " << l[i+1] << endl;

		if ((e_x==q_x || e_y==q_y) || (abs(q_x-e_x)==abs(q_y- e_y))) {

		a =e_x -1; b =e_y -1;
		c =e_x -1; d =board_size -e_y;
		e =board_size -e_x; f =e_y -1;
		g =board_size -e_x; h =board_size -e_y;

		vector_x = q_x - e_x; vector_y = q_y - e_y;
		if (vector_x>0 && vector_y<0) sum-=min(c,d) +1; //a
		else if (vector_x==0 && vector_y<0) sum-=board_size -e_y +1; //b
		else if (vector_x<0 && vector_y<0) sum-=min(g,h) +1; //c
		else if (vector_x<0 && vector_y==0) sum-=board_size -e_x +1; //d
		else if (vector_x<0 && vector_y>0) sum-=min(e,f) +1; //e
		else if (vector_x==0 && vector_y>0) sum-=e_y; //f
		else if (vector_x>0 && vector_y>0) sum-=min(a,b) +1; //g
		else if (vector_x>0 && vector_y==0) sum-=e_x; //h

		}
	}


	cout << sum << endl;
}
