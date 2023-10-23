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
    glPointSize(1.5);

    double dx = xf - xi, dy = yf - yi, m = dy / dx;
    double pk = (2 * dy) - dx;
    int i = 0;
    double x = xi, y = yi;
    glBegin(GL_POINTS);
    while ((x != xf || y != yf))
    {
        glVertex2i(x, y);
        if (pk < 0)
        {
            pk = pk + 2 * dy;
            x = x + 1;
            y = y;
        }
        else
        {
            pk = pk + 2 * (dy - dx);
            x = x;
            y = y + 1;
        }
        i++;
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
