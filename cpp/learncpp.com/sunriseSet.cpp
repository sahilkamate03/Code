#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

#define DEG2RAD 3.14159/180

void drawSun() {
  glColor3f(1.0, 1.0, 0.0); // Set sun color to yellow
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++) {
    float degInRad = i*DEG2RAD;
    glVertex2f(cos(degInRad),sin(degInRad));
  }
  glEnd();
}

void drawSky() {
  glBegin(GL_QUADS);
  glColor3f(0.0, 0.0, 1.0); // Set sky color to blue
  glVertex2f(-1.0, 1.0);
  glVertex2f(-1.0, -1.0);
  glVertex2f(1.0, -1.0);
  glVertex2f(1.0, 1.0);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawSky();
  drawSun();
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Sun Rise and Set");
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
