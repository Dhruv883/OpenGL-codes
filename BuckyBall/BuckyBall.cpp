#include <GL/glut.h>
#include <math.h>
void drawRosette(int sides)
{
    GLfloat angle = 2.0 * M_PI / sides;
    GLfloat radius = 0.4;
    GLfloat centerRadius = 0.2;
    GLfloat centerX, centerY;
    glColor3f(0.15, 0.15, 0.15);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; i++)
    {
        GLfloat x = radius * cos(i * angle);
        GLfloat y = radius * sin(i * angle);
        glVertex2f(x, y);
    }
    glEnd();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; i++)
    {
        GLfloat x = centerRadius * cos(i * angle + angle / 2.0);
        GLfloat y = centerRadius * sin(i * angle + angle / 2.0);
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_LINES);
    for (int i = 0; i < sides; i++)
    {
        GLfloat x1 = radius * cos(i * angle);
        GLfloat y1 = radius * sin(i * angle);
        GLfloat x2 = centerRadius * cos(i * angle + angle / 2.0);
        GLfloat y2 = centerRadius * sin(i * angle + angle / 2.0);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}
void display(void)
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-0.7, 0.5, 0);
    drawRosette(5);
    glTranslatef(1.2, 0, 0);
    drawRosette(11);
    glTranslatef(-0.8, -1.2, 0);

    drawRosette(17);
    glFlush();
}
void myinit()
{
    glOrtho(-2.0, 3.0, -1.5, 2.0, -1.0, 1.0);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rosettes");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}