void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Set up projection and modelview matrices
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    // Draw ground
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, -10.0);
    glVertex3f(-10.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, -10.0);
    glEnd();
    // Set up light position and view matrices
    glPushMatrix();
    glLoadIdentity();
    GLfloat lightPos[] = {5.0, 10.0, 5.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glPopMatrix();
    // Enable shadow mapping
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_FLAT);
    // Render sphere
    glPushMatrix();
    glTranslatef(2.0, 0.5, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    // Render pyramid
    glPushMatrix();
    glTranslatef(0.0, 1.5, -2.0);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, 0.0, 1.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(1.0, 0.0, -1.0);
    K.J.Somaiya College of Engineering, Mumbai - 77(A Constituent College of Somaiya Vidyavihar University)Department of Computer Engineering CG Sem V / July - Dec 2023 glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 0.0, -1.0);
    glVertex3f(-1.0, 0.0, -1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, 0.0, -1.0);
    glVertex3f(-1.0, 0.0, 1.0);
    glEnd();
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);
    // Render shadows
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    // Sphere shadow
    glPushMatrix();
    GLfloat shadowMatSphere[16] = {
        lightPos[1], 0.0, 0.0, 0.0,
        -lightPos[0], 0.0, -lightPos[2], 0.0,
        0.0, 0.0, lightPos[1], 0.0,
        0.0, 0.0, 0.0, lightPos[1]};
    glMultMatrixf(shadowMatSphere);
    glTranslatef(2.0, 0.0, 0.0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    // Pyramid shadow
    glPushMatrix();
    GLfloat shadowMatPyramid[16] = {
        lightPos[1], 0.0, 0.0, 0.0,
        -lightPos[0], 0.0, -lightPos[2], 0.0,
        0.0, 0.0, lightPos[1], 0.0,
        0.0, 0.0, 0.0, lightPos[1]};
    glMultMatrixf(shadowMatPyramid);
    glTranslatef(0.0, 0.0, -2.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, 0.0, 1.0);
    glVertex3f(1.0, 0.0, 1.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}
K.J.Somaiya College of Engineering, Mumbai - 77(A Constituent College of Somaiya Vidyavihar University)Department of Computer Engineering CG Sem V / July - Dec 2023 int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Shadow Mapping");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutMainLoop();
    return 0;
}