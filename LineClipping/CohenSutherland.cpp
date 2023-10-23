#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

void display();
using namespace std;
double xmin = -100, ymin = -100, xmax = 100, ymax = 100;
double px1, py1, px2, py2;

int getCode(double x, double y)
{
    int c = 0;
    if (y > ymax)
        c = 8;
    if (y < ymin)
        c = 4;
    if (x > xmax)
        c = c | 2;
    if (x < xmin)
        c = c | 1;
    return c;
}

void cohen_sutherland(float x1, float y1, float x2, float y2)
{
    int c1 = getCode(x1, y1);
    int c2 = getCode(x2, y2);
    float m = (y2 - y1) / (x2 - x1);
    while (true)
    {
        if ((c1 | c2) == 0)
        {
            break;
        }

        if ((c1 & c2) != 0)
        {
            exit(0);
        }

        int c = (c1 != 0) ? c1 : c2;
        double xi = (c1 != 0) ? x1 : x2;
        double yi = (c1 != 0) ? y1 : y2;

        double x, y;
        if (c & 8)
        {
            y = ymax;
            x = xi + (ymax - yi) / m;
        }
        else if (c & 4)
        {
            y = ymin;
            x = xi + (ymin - yi) / m;
        }
        else if (c & 2)
        {
            x = xmax;
            y = yi + m * (xmax - xi);
        }
        else if (c & 1)
        {
            x = xmin;
            y = yi + m * (xmin - xi);
        }

        if (c == c1)
        {
            px1 = x;
            py1 = y;
            c1 = getCode(px1, py1);
        }
        else
        {
            px2 = x;
            py2 = y;
            c2 = getCode(px2, py2);
        }
    }

    display();
}

void keyFunc(unsigned char key, int x, int y)
{
    if (key == 'c')
    {
        cout << "Clipping\n";
        cohen_sutherland(px1, py1, px2, py2);
        glFlush();
    }
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin, ymin);
    glVertex2i(xmin, ymax);
    glVertex2i(xmax, ymax);
    glVertex2i(xmax, ymin);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(px1, py1);
    glVertex2i(px2, py2);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter line co-ordinates: ");
    cin >> px1 >> py1 >> px2 >> py2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cohen Sutherland");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyFunc);
    glClearColor(0.0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300, 300, -300, 300);
    glutMainLoop();
    return 0;
}
