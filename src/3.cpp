/* -lGL -lGLU -lX11 -lglut */
#include <time.h>
#include <GL/glut.h>

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(200);
    glLineWidth(30);

    glBegin(GL_POINTS);
    glVertex3d(1, 1, 1);
    glEnd();

    glBegin(GL_LINES);
    glColor3d(1, 0, 0);
    glVertex2d(200, 300);
    glColor3d(0, 0, 1);
    glVertex2d(400, 300);
    glEnd();

    glutSwapBuffers();
}

int main (int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL lesson 1");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
