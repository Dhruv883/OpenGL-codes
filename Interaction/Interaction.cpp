#include <GL/glut.h>
#include <iostream>
using namespace std;
int xg = 0, yg = 0;

void initFunc()
{
    glClearColor(1.0, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-800.0, 800.0, -800.0, 800.0);
}

void erase()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void pointDraw(int x, int y)
{
    printf("X: %d Y: %d\n", x, y);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5);
    glVertex2i(x, y);
    glEnd();
    return;
}

void keyFunc(unsigned char key, int x, int y)
{

    if (key == 'c')
    {
        cout << "Clearing Window\n";
        erase();
        glutPostRedisplay();
    }
    else if (key == 'e')
    {
        cout << "Exiting\n";
        exit(0);
    }
}

void specKeyFunc(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        pointDraw(xg, yg + 10);
        yg += 10;
    }
    else if (key == GLUT_KEY_DOWN)
    {
        pointDraw(xg, yg - 10);
        yg -= 10;
    }
    else if (key == GLUT_KEY_LEFT)
    {
        pointDraw(xg - 10, yg);
        xg -= 10;
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        pointDraw(xg + 10, yg);
        xg += 10;
    }
    glutPostRedisplay();
}

void mouseFunc(int button, int state, int x, int y)
{
    x = x * (800 - (-800)) / 800 + (-800);
    y = (800 - y) * (800 - -800) / 800 + (-800);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        pointDraw(x, y);
        glutPostRedisplay();
    }
}

void display()
{
    glBegin(GL_LINE_LOOP);
    glVertex2i(xg, yg);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Mouse Keyboard Interaction");
    glutKeyboardFunc(keyFunc);
    glutSpecialFunc(specKeyFunc);
    glutMouseFunc(mouseFunc);
    glutDisplayFunc(display);
    initFunc();
    glutMainLoop();

    return 0;
}