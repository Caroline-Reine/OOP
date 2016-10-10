/* -lGL -lGLU -lX11 -lglut */
#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "tPoint.h"

using namespace std;
const float DT = 0.01;

vector<tPoint> p;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (vector<tPoint>::iterator i = p.begin(); i != p.end(); ++i)
    {
        if (i->getM() <= 2)
        {
            glPointSize(2);
            glBegin(GL_POINTS);
            glVertex2f(i->getX(), i->getY());
            glEnd();
        }
        else
        {
            glBegin(GL_LINES);
            for (int a = 0; a < 360; ++a)
            {
                float x = i->getM() * cos(a * M_PI / 180);
                float y = i->getM() * sin(a * M_PI / 180);
                glVertex2f(i->getX() + x, i->getY() + y);
                x = i->getM() * cos((a + 1) * M_PI / 180);
                y = i->getM() * sin((a + 1) * M_PI / 180);
                glVertex2f(i->getX() + x, i->getY() + y);
            }
            glEnd();
        }
    }
    glutSwapBuffers();
}

void timer(int = 0)
{
    for (vector<tPoint>::iterator i = p.begin(); i != p.end(); ++i)
        for (vector<tPoint>::iterator j = p.begin(); j != p.end(); ++j)
            if (i != j)
            {
                float d = sqrt((i->getX() - j->getX()) * (i->getX() - j->getX()) + (i->getY() - j->getY()) * (i->getY() - j->getY()));
                if (d < i->getM() + j->getM())
                {
                    float f = 99 * (i->getM() + j->getM() - d);
                    i->setVX(i->getVX() + f * (i->getX() - j->getX()) / d / i->getM() * DT);
                    i->setVY(i->getVY() + f * (i->getY() - j->getY()) / d / i->getM() * DT);
                    j->setVX(j->getVX() - f * (i->getX() - j->getX()) / d / j->getM() * DT);
                    j->setVY(j->getVY() - f * (i->getY() - j->getY()) / d / j->getM() * DT);
                }
            }
    for (vector<tPoint>::iterator i = p.begin(); i != p.end(); ++i)
    {
        i->setX(i->getX() + i->getVX() * DT);
        i->setY(i->getY() + i->getVY() * DT);
        if (i->getX() < 0)
            i->setVX(i -> getVX() * (-1));
        if (i->getY() < 0)
            i->setVY(i -> getVY() * (-1));
        if (i->getX() > 480)
            i->setVX(i -> getVX() * (-1));
        if (i->getY() > 480)
            i->setVY(i -> getVY() * (-1));
    }
    display();
    glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv)
{
    //tPoint p0 = tPoint(480 / 2, 480 / 2, 0, 0, 40);
    //p.push_back(p0);
    for (int i = 0; i < 2000; ++i)
    {
        tPoint p0 = tPoint(rand() % 480, (rand() % 480), rand() % 100000 / 500.0 - 100, rand() % 100000 / 500.0 - 100, 1);
        p.push_back(p0);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(20, 1050 - 480 - 20);
    glutCreateWindow("Brownian motion");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, 480, 480, 0, -1, 1);
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}
