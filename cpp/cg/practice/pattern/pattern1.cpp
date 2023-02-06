#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void test()
{
	glPointSize(8.0);
	glColor3f (1.0 ,0.0, 0.0);
	
	glBegin(GL_POINTS);
		glVertex2i(-300,0);
		glVertex2i(0,0);
		glVertex2i(300,0);
	glEnd();
	
	glFlush();
}

void line(float x1, float y1, float x2, float y2)
{
	float dx =x2 -x1;
	float dy =y2 -y1;
	
	int steps =max(abs(dx), abs(dy));
	
	float xinc =dx/steps;
	float yinc =dy/steps;
	
	glPointSize(3.0);
	glColor3f (1.0 ,0.0, 0.0);

	float x =x1, y =y1;
	for (int i=0; i<=steps; i++)
	{
		
		glBegin(GL_POINTS);
		glVertex2f (x, y);
		glEnd();
		
		x +=xinc, y +=yinc;
	}
	
	glFlush();
}


void circle(float r)
{
	int i =0;
	while (pow(2,i)<=r)
		i++;
	
	float e =pow(2, -i);
	float x= r, y =0;
	
	glPointSize(3.0);
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
	glutInitWindowSize (800, 800);
    glutInitWindowPosition (0,0);
	glutCreateWindow("Line");
	init();
	glutDisplayFunc(display);

	float r =400;
	float rc=r/2;
	float rs =(r * sqrt(3)) / 2;
	
	circle(rc);
	circle(r);
	
	line(-rs, -rc, 0, r);
    line(0, r, rs, -rc);
    line(-rs, -rc, rs, -rc);

    
	glutMainLoop();
}