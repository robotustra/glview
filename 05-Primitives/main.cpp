/*********************************************
* Zeus CMD - OpenGL Tutorial 05 : Primitives *
* By Grant James (ZEUS)                      *
* http://www.zeuscmd.com                     *
*********************************************/
#include <stdlib.h>
#include <GL/glut.h>

bool fullscreen = false;

bool init()
{
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);

	return true;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	glVertex3f( 0.7f, -0.5f, 0.0f);
	glVertex3f( 0.6f, -0.7f, 0.0f);
	glVertex3f( 0.6f, -0.8f, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0f,  1.0f, 0.0f);
	glVertex3f(-0.5f,  0.5f, 0.0f);
	glVertex3f(-0.7f,  0.5f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f( 0.5f, -0.5f, 0.0f);
	glVertex3f( 0.0f,  0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-0.5f, -1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(-1.0f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f( 0.8f,  0.6f, 0.0f);
	glVertex3f( 0.9f,  0.8f, 0.0f);
	glVertex3f( 0.5f,  0.9f, 0.0f);
	glVertex3f( 0.6f,  0.5f, 0.0f);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(1);
}

void specialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		fullscreen = !fullscreen;

		if (fullscreen)
			glutFullScreen();
		else
		{
			glutReshapeWindow(500, 500);
			glutPositionWindow(50, 50);
		}
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutCreateWindow("05 - Primitives");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);

	if (!init())
		return 1;

	glutMainLoop();

	return 0;
}
