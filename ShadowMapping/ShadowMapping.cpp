#include <GL/glut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-5.0, 0.0, -5.0);
    glVertex3f(-5.0, 0.0, 5.0);
    glVertex3f(5.0, 0.0, 5.0);
    glVertex3f(5.0, 0.0, -5.0);
    glEnd();

    glPushMatrix();
    glLoadIdentity();
    GLfloat lightPos[] = {-3, 5, 5.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glPopMatrix();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_FLAT);

    glColor3f(0.0, 0.0, 1.0);
    glutSolidSphere(1.0, 10, 10);
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    GLfloat shadowMat[16] = {
        lightPos[1], 0.0, 0.0, 0.0,
        -lightPos[0], 0.0, -lightPos[2], -1.0,
        0.0, 0.0, lightPos[1], 0.0,
        0.0, 0.0, 0.0, lightPos[1]};
    glMultMatrixf(shadowMat);
    glutSolidSphere(1.0, 10, 10);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Shadow Mapping");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutMainLoop();
    return 0;
}
