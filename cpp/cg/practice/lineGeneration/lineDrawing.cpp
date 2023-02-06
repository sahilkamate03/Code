#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;


void ddaLineAlgo()
{
	int x1(0), y1(0);
	int x2(90), y2(90);
	cout << "Enter x1 and y1 dda: "; cin >>x1 >>y1;
	cout << "Enter x2 and y2 dda: "; cin >>x2 >>y2;

	int dx (x2 -x1);
	int dy (y2 -y1);

	int steps (max(abs(dx), abs(dy)));

	int xinc =dx /steps;
	int yinc =dy /steps;

	glPointSize(3.0);

    int x(x1), y(y1);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

	for (int i=0; i<steps; i++)
	{
		x += xinc, y +=yinc;
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POINTS);
			glVertex2i(x, y);
		glEnd();

	}

	glFlush();

}

void bresenhamAlgo()
{
	int x1(0), y1(0);
	int x2(0), y2(90);
	cout << "Enter x1 and y1: "; cin >>x1 >>y1;
	cout << "Enter x2 and y2: "; cin >>x2 >>y2;

	int dx (abs(x2 -x1)), dy (abs(y2 -y1));
	int pk ((2*dx) -dy);
	int steps(max(dx, dy));
	int x (x1), y (y1);

	glPointSize(8.0);

	for (int i=0; i<steps; i++)
	{

		cout << x << " " << y << endl;
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POINTS);
			glVertex2i(x, y);
		glEnd();

		if (pk<0) {
			pk +=(2*dy);
			x++;
		}else {
			pk +=((2*dy) - (2*dx));
			x++, y++;
		}

		
	}

	glFlush();
}

void display()
{
	// ddaLineAlgo();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0 ,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutCreateWindow("Line Drawing");
	init();
	glutDisplayFunc(display);
	bresenhamAlgo();
	glutMainLoop();
	return 0;
}

