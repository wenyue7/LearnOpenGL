#include <GL/glut.h>
#include <iostream>

using namespace std;

void renderPreFrame();

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("First Window");

    glutDisplayFunc(renderPreFrame);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutMainLoop();

    return 0;
}

void renderPreFrame()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}