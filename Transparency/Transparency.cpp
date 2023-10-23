#include <GL/glut.h>
#include <iostream>

void initFunc()
{
    glClearColor(0.0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(0.0, 0.0, 1.0, 0.75);
    glBegin(GL_POLYGON);
    glVertex2i(-100, 50);
    glVertex2i(100, 50);
    glVertex2i(100, 250);
    glVertex2i(-100, 250);
    glEnd();

    glColor4f(1.0, 0.0, 0.0, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(-50, 0);
    glVertex2i(150, 0);
    glVertex2i(150, 200);
    glVertex2i(-50, 200);
    glEnd();

    glDisable(GL_BLEND);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Translation");
    glutDisplayFunc(display);
    initFunc();
    glutMainLoop();

    return 0;
}