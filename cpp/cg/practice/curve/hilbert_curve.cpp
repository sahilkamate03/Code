#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
#include <unistd.h>

using namespace std;

float l_red = 1.0f, l_blue = 0.0f, l_green = 0.0f;

double points[2][2];

class Hilbert_Curve
{
public:
    int n, xx, yy, x, y, h, r, d, l, u;
    void dda_line(int, int, int, int);
    void lineto(int, int);
    void move(int j, int h, int &x, int &y);
    void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y);
} p;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void Hilbert_Curve::dda_line(int xini, int yini, int xend, int yend)
{
    double dx = (xend - xini);
    double dy = (yend - yini);
    double steps;
    float xInc, yInc, x = xini, y = yini;
    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    xInc = dx / (float)steps;
    yInc = dy / (float)steps;
    glLineWidth(10.0);
    glVertex2f(x, y);
    int k;
    for (k = 0; k < steps; k++)
    {
        x += xInc;
        y += yInc;
        glVertex2f(x, y);
    }
}

void Hilbert_Curve::lineto(int x, int y)
{
    points[1][0] = x;
    points[1][1] = y;

    glBegin(GL_POINTS);
    p.dda_line(points[0][0], points[0][1], points[1][0], points[1][1]);
    glEnd();

    glutSwapBuffers();

    points[0][0] = x;
    points[0][1] = y;
    glEnd();
}

void Hilbert_Curve::move(int j, int h, int &x, int &y)
{
    if (j == 1)
        y -= h;
    else if (j == 2)
        x += h;
    else if (j == 3)
        y += h;
    else if (j == 4)
        x -= h;
    lineto(x, y);
    //usleep(75000);
}

void Hilbert_Curve::hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y)
{
    if (i > 0)
    {
        i--;
        hilbert(d, r, u, l, i, h, x, y);
        move(r, h, x, y);
        hilbert(r, d, l, u, i, h, x, y);
        move(d, h, x, y);
        hilbert(r, d, l, u, i, h, x, y);
        move(l, h, x, y);
        hilbert(u, l, d, r, i, h, x, y);
    }
}

int rOff(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

void setPixel(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    glVertex2f(x, y);
    glEnd();
}

void processMenuEvents(int option)
{
    switch (option)
    {
    case 1:
        l_red = 0.0f;
        l_green = 1.0f;
        l_blue = 1.0f;
        break;
    case 2:
        l_red = 1.0f;
        l_green = 0.5f;
        l_blue = 0.0f;
        break;
    case 3:
        l_red = 1.0f;
        l_green = 1.0f;
        l_blue = 0.0f;
        break;
    case 4:
        l_red = 1.0f;
        l_green = 0.0f;
        l_blue = 0.0f;
        break;
    case 5:
        l_red = 0.0f;
        l_green = 1.0f;
        l_blue = 0.0f;
        break;
    case 6:
        l_red = 0.0f;
        l_green = 0.0f;
        l_blue = 1.0f;
        break;
    case 7:
        l_red = 0.647059f;
        l_green = 0.164706f;
        l_blue = 0.164706f;
        break;
    case 8:
        l_red = 0.73f;
        l_green = 0.16f;
        l_blue = 0.96f;
        break;
    }
}

void createGLUTMenus()
{
    int menu;

    menu = glutCreateMenu(processMenuEvents);

    glutAddMenuEntry("Cyan", 1);
    glutAddMenuEntry("Orange", 2);
    glutAddMenuEntry("Yellow", 3);
    glutAddMenuEntry("Red", 4);
    glutAddMenuEntry("Green", 5);
    glutAddMenuEntry("Blue", 6);
    glutAddMenuEntry("Brown", 7);
    glutAddMenuEntry("Purple", 8);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void changeSize(int w, int h)
{
    if (h == 0)
        h = 1;

    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    p.hilbert(p.r, p.d, p.l, p.u, p.n, p.h, p.x, p.y);
}

int main(int argc, char **argv)
{
    p.xx = 50;
    p.yy = 150;
    p.h = 10;
    p.r = 2;
    p.d = 3;
    p.l = 4;
    p.u = 1;

    cout << "\nEnter the number of iterations : ";
    cin >> p.n;
    p.x = p.xx;
    p.y = p.yy;
    points[0][0] = p.x;
    points[0][1] = p.y;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow(" HILBERT CURVE GENERATION");
    init();
    glutDisplayFunc(renderScene);
    createGLUTMenus();
    glutMainLoop();

    return 0;
}
