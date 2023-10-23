#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

double xc, yc, r;

void drawCircle(int xc, int yc, int x, int y)
{
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
    glViewport(0, 0, 1000, 1000);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    cout << "Enter xc, yc: ";
    cin >> xc >> yc;
    cout << "Enter radius:";
    cin >> r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800); // Increase the initial window size
    glutCreateWindow("Exp 3");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
