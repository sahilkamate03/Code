#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

GLfloat angle =0.0;

void spin()
{
	angle+= 1.0;
	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //clear the window
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0,
			  0.0, 0.0, 0.0,
			  0.0, 1.0, 0.0);
	glRotatef(angle, 1, 0, 0);
	glRotatef(angle, 0, 1, 0);
	glRotatef(angle, 0, 0, 1);
	glutWireCube(2.0);
	glutSwapBuffers();
	//glFlush(); //force update the screen
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sahil");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(spin);
	glutMainLoop();
	return 0;
}