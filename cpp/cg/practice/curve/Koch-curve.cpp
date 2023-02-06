
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat oldx=-0.7,oldy=0.5; //are static float coordinates for the vertex of triangle.

void drawkoch(GLfloat dir,GLfloat len,GLint iter)  //dir-stores the angle of line segment.
 {            
 GLdouble dirRad = 0.0174533 * dir;              //calculates radians of angle using dir.
 GLfloat newX = oldx + len * cos(dirRad);  //newX, newY : calculates new vertex coordinates for cuvre using oldx and oldy by performing cosine and sine operations on dirRad.
 GLfloat newY = oldy + len * sin(dirRad);
 if (iter==0) {
  glVertex2f(oldx, oldy);
  glVertex2f(newX, newY);
  oldx = newX;
  oldy = newY;
 }
 else {
  iter--;
 
  drawkoch(dir, len, iter);     //draw the four parts of the side _/\_
  dir += 60.0;
  drawkoch(dir, len, iter);
  dir -= 120.0;
  drawkoch(dir, len, iter);
  dir += 60.0;
  drawkoch(dir, len, iter);
      }
 }

void display(){
  glClear( GL_COLOR_BUFFER_BIT );
  glBegin(GL_LINES);
  glColor3f(0.0, 1.0, 0.0);
  drawkoch(0.0,0.04,3);
  drawkoch(-120.0, 0.04, 3);
  drawkoch(120.0,0.04,3);
  glEnd();
  glFlush();
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(0,0);
 glutCreateWindow("Koch Curve");
 glutDisplayFunc(display);
 glutMainLoop();
} 
