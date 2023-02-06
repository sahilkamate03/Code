#include <bits/stdc++.h>
using namespace std;

void bresenhamAlgo(int x1, int y1, int x2, int y2)
{

	int dx =abs(x2 -x1), dy =abs(y2 -y1);
	// int steps =max(dx, dy);
	int p = (2*dy) -dx;

	int x =x1, y =y1;
	for (int i=0; i<=dx; i++)
	{
		cout << x << " " <<  y << endl;
		if (p <0)
		{
			x++;
			p +=2*dy;
		}else {
			x++, y++;
			p += (2*dy -2*dx);
		}
	}	
}

void midPointAlgo(int x1, int y1, int x2, int y2)
{

	int dx =x2 -x1, dy =y2 -y1;

	int p = 2*dy -dx;
	int d =2*(dy -dx);

	int x=x1, y=y1;
	for (int i=0; i<dx; i++)
	{
		if (p<0)
		{
			x++; p +=2*dy;
		} else {
			x++, y++;
			p +=d;
		}

		cout << x << " " << y << endl;
	}
}

void midpoint_line(int x1, int y1, int x2, int y2) {
  int dx = x2 - x1;
  int dy = y2 - y1;
  int d = dy - (dx / 2);
  int x = x1;
  int y = y1;

  while (x <= x2) {
    		cout << x << " " <<  y << endl;


    if (d > 0) {
      y = y + 1;
      d = d - dx;
    }

    x = x + 1;
    d = d + dy;
  }
}


int main(){
	
	cout << "bresenhamAlgo: " << endl;
	bresenhamAlgo(0, 0, -10, 15);
	cout << "midPointAlgo: " << endl;
	midPointAlgo(0, 0,-10, 15);
	cout << "midpoint_line: " << endl;
	midpoint_line(0, 0, -10, 15);

	return 0;
}
