#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void display()
{
	// glBegin(GL_POINTS);
    // glVertex2i(5,5);

    glClear (GL_COLOR_BUFFER_BIT); /* Clear the window */
    glLoadIdentity ();
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutWireCube(2.0);
    glFlush();
}

void keyboard (unsigned char key, int x, int y)
{
	if (key=27) exit(0);
}

void reshape(int w, int h)
{
	// * Called if the window is moved or resized */
	glViewport (0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode (GL_MODELVIEW);
}





int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	int mode = GLUT_RGB|GLUT_SINGLE;
	glutInitDisplayMode(mode);
	glutInitWindowSize(500,500);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}