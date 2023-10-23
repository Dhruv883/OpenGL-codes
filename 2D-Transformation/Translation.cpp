#include <GL/glut.h>
#include <iostream>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);

    glVertex2i(-100, 50);
    glVertex2i(100, 50);
    glVertex2i(100, 250);
    glVertex2i(-100, 250);
    glEnd();

    glTranslatef(150.0, -300.0, 0.0);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(-100, 50);
    glVertex2i(100, 50);
    glVertex2i(100, 250);
    glVertex2i(-100, 250);
    glEnd();

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
    glClearColor(0.0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glutMainLoop();

    return 0;
}