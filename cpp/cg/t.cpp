#include <windows.h>
#include <GL/glut.h>
// #include<iostream>
// using namespace std;

// Clears the current window and draws a triangle.
void display() {

  // Set every pixel in the frame buffer to the current clear color.
  glClear(GL_COLOR_BUFFER_BIT);

  // Drawing is done by specifying a sequence of vertices.  The way these
  // vertices are connected (or not connected) depends on the argument to
  // glBegin.  GL_POLYGON constructs a filled polygon.
  glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
    glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0.75, 0);
  glEnd();


  // Flush drawing command buffer to make drawing happen as soon as possible.
  glFlush();
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.
int main(int argc, char** argv)
{
       glutInit(&argc, argv);                 // Initialize GLUT
       glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
       glutInitWindowSize(320, 320);   // Set the window's initial width & height
       glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
       glutDisplayFunc(display); // Register display callback handler for window re-paint
       glutMainLoop();           // Enter the infinitely event-processing loop
       return 0;
}