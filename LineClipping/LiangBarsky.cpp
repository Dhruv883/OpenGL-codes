#include <GL/glut.h>
#include <iostream>
using namespace std;

double xi, xf, yi, yf;
double t1 = 0, t2 = 1;
double xmin = -150, ymin = -150, xmax = 150, ymax = 150;

void drawRectangle()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();
}

void drawClippedLine(double x1, double y1, double x2, double y2)
{
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void liang_barsky()
{
    double dx = xf - xi;
    double dy = yf - yi;
    double p[4] = {-dx, dx, -dy, dy};
    double q[4] = {xi - xmin, xmax - xi, yi - ymin, ymax - yi};

    for (int i = 0; i < 4; i++)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
                return;
        }
        else
        {
            double t = q[i] / p[i];
            if (p[i] < 0)
            {
                if (t > t1)
                    t1 = t;
            }
            else
            {
                if (t < t2)
                    t2 = t;
            }
        }
    }

    if (t1 <= t2)
    {
        double x1c, y1c, x2c, y2c;
        x1c = xi + t1 * dx;
        y1c = yi + t1 * dy;
        x2c = xi + t2 * dx;
        y2c = yi + t2 * dy;

        drawRectangle();
        drawClippedLine(x1c, y1c, x2c, y2c);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(xi, yi);
    glVertex2i(xf, yf);
    glEnd();
    drawRectangle();
    liang_barsky();
    glFlush();
}

int main(int argc, char **argv)
{
    cout << "Enter Line Co-ordinates: ";
    cin >> xi >> yi >> xf >> yf;
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Liang-Barsky");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320, 320, -240, 240);
    glutMainLoop();
    return 0;
}
