#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void dda(int x1, int y1, int x2, int y2)
{
	int dx =x2 -x1;
	int dy =y2 -y1;
	
	int steps =max(dx, dy);
	
	int xinc =dx/steps;
	int yinc =dy/steps;
	
	glPointSize(8.0);
	glColor3f (1.0 ,0.0, 0.0);
	
	int x =x1, y =y1;
	for (int i=0; i<steps; i++)
	{
		glBegin(GL_POINTS);
		glVertex2i (x, y);
		glEnd();
		
		x +=xinc, y +=yinc;
	}
	
	glFlush();
}

void bresenhamAlgo(int x1, int y1, int x2, int y2)
{
	int dx =abs(x2-x1), dy =abs(y2 -y1);
	int p =2*dy -dx;
	
	int x=x1, y=y1;
	glPointSize(3.0);
	glColor3f(0.0, 1.0, 0.0);
	
	for (int i=0; i<dx; i++)
	{
		
		cout << x << " " << y << endl;
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		
		if (p<0){
			p +=2*dy;
		}else {
			y++;
			p +=(2*dy - 2*dx);
		}
		x++;
	}
	
	glFlush();
}

void midPoint(int x1, int y1, int x2, int y2)
{
	int dx =x2-x1, dy =y2 -y1;
	int p = dy - dx/2;
	
	int x =x1, y =y1;
	
	glPointSize(3.0);
	glColor3f(1.0, 0.0, 0.0);
	
	while (x<=x2)
	{
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		
		if (p>0)
		{
			y++;
			p -=dx;
		}
		
		x++;
		p +=dy;
	}
	
	glFlush();
}

void display()
{
	 
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Line");
	init();
	glutDisplayFunc(display);
	
	//dda(0 ,0, 300, 0);
	dda(0 ,0, -300, 0);
	/*
	cout << "BRES";
	cout<<endl;
	bresenhamAlgo(-90, -90, 0, 0);
	*/
	
	//midPoint(0,0,100,50);
	glutMainLoop();
}