#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

void display()
{

}

void keyboard(unsigned char key, int x, int y)
{
	if ((int) key == 27)
		exit(0);
}

void menu(int choice)
{
	switch (choice)
	{
		case 1:
			cout << "hello" << endl;
			break;
		case 2:
			cout << "world" << endl;
			break;
		case 3:
			exit(0);
	}
}

void createMenu()
{
	int print =glutCreateMenu(menu);
	glutAddMenuEntry("hello", 1);
	glutAddMenuEntry("world", 2);
	
	glutCreateMenu(menu);
	glutAddSubMenu("Print", print);
	glutAddMenuEntry("Exit", 3);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		cout << x << " " << y << endl;
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Scan Line");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	createMenu();
	glutMainLoop();
}