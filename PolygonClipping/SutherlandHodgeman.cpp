#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;
void display();
void polygonClipping();

vector<vector<double>> polygon = {{-100.0, -150.0}, {225.0, -150.0}, {225.0, 150.0}, {50.0, 250.0}, {-100.0, 150.0}};

double xmin = -200, ymin = -200, xmax = 200, ymax = 200;
int n = polygon.size();

bool isClipped = false;

// vector<vector<double>> cp = {{-200, 200}, {200, 200}, {200, -200}, {-200, -200}};
vector<vector<double>> cp = {{-200, 200}, {-200, -200}, {200, -200}, {200, 200}};

double x_intersect(double x1, double y1, double x2, double y2,
                   double x3, double y3, double x4, double y4)
{
    double num = (x1 * y2 - y1 * x2) * (x3 - x4) -
                 (x1 - x2) * (x3 * y4 - y3 * x4);
    double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    return num / den;
}

double y_intersect(double x1, double y1, double x2, double y2,
                   double x3, double y3, double x4, double y4)
{
    double num = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
    double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    return num / den;
}

void clip(vector<vector<double>> polygon, int n, int x1, int y1, int x2, int y2)
{
    vector<vector<double>> newPoints;
    int n2 = 0;
    for (int i = 0; i < n; i++)
    {
        double k = (i + 1) % n;
        double ix = polygon[i][0], iy = polygon[i][1];
        double kx = polygon[k][0], ky = polygon[k][1];

        double i_pos = (x2 - x1) * (iy - y1) - (y2 - y1) * (ix - x1);
        double k_pos = (x2 - x1) * (ky - y1) - (y2 - y1) * (kx - x1);

        vector<double> temp;

        if (i_pos < 0 && k_pos < 0)
        {
            temp = {kx, ky};
            newPoints.push_back(temp);
            temp.clear();
            n2++;
        }
        else if (i_pos >= 0 && k_pos < 0)
        {

            double a = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
            double b = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);

            temp = {a, b};
            newPoints.push_back(temp);
            temp.clear();
            n2++;

            temp = {kx, ky};
            newPoints.push_back(temp);
            temp.clear();
            n2++;
        }
        else if (i_pos < 0 && k_pos >= 0)
        {
            double a = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
            double b = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);

            temp = {a, b};
            newPoints.push_back(temp);
            temp.clear();
            n2++;
        }
    }

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (auto point : newPoints)
    {
        glVertex2i(point[0], point[1]);
        cout << point[0] << ' ' << point[1] << endl;
    }
    glEnd();
}

void polygonClipping()
{
    isClipped = true;
    for (int i = 0; i < 4; i++)
    {
        int k = (i + 1) % 4;
        double x_1 = cp[i][0], y_1 = cp[i][1], x_2 = cp[k][0], y_2 = cp[k][1];
        clip(polygon, n, x_1, y_1, x_2, y_2);
    }
}

void keyFunc(unsigned char key, int x, int y)
{
    if (key == 'c')
    {
        cout << "Polygon Clipping\n";
        polygonClipping();
        glFlush();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin, ymax);
    glVertex2i(xmax, ymax);
    glVertex2i(xmax, ymin);
    glVertex2i(xmin, ymin);
    glEnd();

    if (!isClipped)
    {
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        for (auto point : polygon)
        {
            glVertex2i(point[0], point[1]);
        }
        glEnd();
    }

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sutherland-Hodgman Clipping");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyFunc);
    glClearColor(0.0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
    glutMainLoop();

    return 0;
}
