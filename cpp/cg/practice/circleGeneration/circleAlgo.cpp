#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void display()
{
	 
}

void dda(float r)
{
	int i =0;
	while (pow(2,i)<=r)
		i++;
	
	float e =pow(2, -i);
	float x= r, y =0;
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	while((y)<e || (r-x)>e)
	{
			x += e*y;
			y -=e*x;
			
			glVertex2f(x, y);
			
	}
	glEnd();
	glFlush();
}

void makecircle(int x,int y,int cx,int cy){
    glColor3f(1,0,0);
    glVertex2i(cx+x,cy+y);
    glVertex2i(cx+x,cy-y);
    glVertex2i(cx-x,cy+y);
    glVertex2i(cx-x,cy-y);
    glVertex2i(cx+y,cy+x);
    glVertex2i(cx+y,cy-x);
    glVertex2i(cx-y,cy+x);
    glVertex2i(cx-y,cy-x);
}

void bresenham(float r)
{
	float x =0, y =r;
	float p =3 -2*r;
	glColor3f(1.0 ,0.0, 0.0);
	glBegin(GL_POINTS);
	while (x<=y)
	{
		glVertex2f(x,y);
		if (p<=0)
			p +=4*x +6;
		else 
			p+= (4*(x-y) +10), y--;
		
		x++;
		makecircle(x, y, 0, 0);
	}
	glEnd();
	glFlush();
}

void midPoint(float r)
{
	float p =1 -r;
	float x=r, y=0;
	
	glColor3f(1.0 ,0.0, 0.0);
	glBegin(GL_POINTS);
	while (x>y)
	{
		y++;
		if (p<=0)
			p +=(2*y +1);
		else 
			x--, p+=(2*(y-x) +1);
		
		if (x<y) 
			break;
		
		makecircle(x, y, 0, 0);
		
		glVertex2i(+x,+y);
		glVertex2i(+x,-y);
		glVertex2i(-x,+y);
		glVertex2i(-x,-y);
		
		if (x!=y)
		{		
			glVertex2i(+y,+x);
			glVertex2i(+y,-x);
			glVertex2i(-y,+x);
			glVertex2i(-y,-x);
		}
	}
	glEnd();
	glFlush();
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
	glutCreateWindow("Circle");
	init();
	glutDisplayFunc(display);
	//dda(100);
	//dda1(50);
	//bresenham(100);
	midPoint(100);
	glutMainLoop();
}
