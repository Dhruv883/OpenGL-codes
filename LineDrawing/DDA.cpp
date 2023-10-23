#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

double xi, yi, xf, yf;

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
    glViewport(0, 0, 1000, 1000);

    glColor3f(1.0, 1.0, 1.0);

    double dx = xf - xi, dy = yf - yi, m = dy / dx;
    double n, x, y;
    if (abs(dx) > abs(dy))
        n = abs(dx);
    else
        n = abs(dy);

    double x_in = dx / n, y_in = dy / n;

    x = xi;
    y = yi;

    glPointSize(1.5);

    glBegin(GL_POINTS);
    for (int i = 1; i <= n; i++)
    {
        x += x_in;
        y += y_in;
        glVertex2i(x, y);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    cout << "Enter xi, yi: ";
    cin >> xi >> yi;
    cout << "Enter xf, yf: ";
    cin >> xf >> yf;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800); // Increase the initial window size
    glutCreateWindow("Exp 3");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
