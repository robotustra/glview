/*******************************************************
* Zeus CMD - OpenGL Tutorial 06 : Primitive Attributes *
* By Grant James (ZEUS)                                *
* http://www.zeuscmd.com                               *
*******************************************************/
#include <stdlib.h>
#include <GL/glut.h>

int lineStipples[] = 
{
	//1010 1010 1010 1010 = 10 10 10 10
	0xAAAA,
	//0000 1111 0000 1111 =  0 15  0 15
	0x0F0F,
	//1111 1111 1111 0000 = 15 15 15  0
	0xFFF0,
	//0000 0000 0000 1111 =  0  0  0 15
	0x000F,
	//0001 0001 0001 0001 =  1  1  1  1
	0x1111
};

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

	// Point Size
	float pointSize = 0;
	glGetFloatv(GL_POINT_SIZE, &pointSize);

	for (int i = 0; i < 5; i++)
	{
		glPointSize((float)(i + 1));

		glBegin(GL_POINTS);
			glVertex3f(-0.4f + i / 5.0f, 0.8f, 0.0f);
		glEnd();
	}

	glPointSize(pointSize);

	// Line Width
	float lineWidth = 0;
	glGetFloatv(GL_LINE_WIDTH, &lineWidth);

	for (int i = 0; i < 5; i++)
	{
		glLineWidth((float)(i + 1));

		glBegin(GL_LINES);
			glVertex3f(-0.6f, 0.7f - i * 0.1f, 0.0f);
			glVertex3f( 0.6f, 0.7f - i * 0.1f, 0.0f);
		glEnd();
	}

	glLineWidth(lineWidth);

	// Polygon Mode
	int polygonMode[2];
	glGetIntegerv(GL_POLYGON_MODE, polygonMode);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.8f, 0.0f, 0.0f);
		glVertex3f(-0.6f, 0.0f, 0.0f);
		glVertex3f(-0.7f, 0.2f, 0.0f);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
		glVertex3f( 0.1f, 0.0f, 0.0f);
		glVertex3f(-0.1f, 0.0f, 0.0f);
		glVertex3f( 0.0f, 0.2f, 0.0f);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glBegin(GL_TRIANGLES);
		glVertex3f( 0.6f, 0.0f, 0.0f);
		glVertex3f( 0.8f, 0.0f, 0.0f);
		glVertex3f( 0.7f, 0.2f, 0.0f);
	glEnd();

	glPolygonMode(GL_FRONT, polygonMode[0]);
	glPolygonMode(GL_BACK, polygonMode[1]);

	// Line Stipple
	glEnable(GL_LINE_STIPPLE);
	for (int i = 0; i < 5; i++)
	{
		glLineStipple(1, lineStipples[i]);
		glBegin(GL_LINES);
			glVertex3f(-0.6f, -0.1f - i * 0.1f, 0.0f);
			glVertex3f(-0.1f, -0.1f - i * 0.1f, 0.0f);
		glEnd();

		glLineStipple(3, lineStipples[i]);
		glBegin(GL_LINES);
			glVertex3f( 0.6f, -0.1f - i * 0.1f, 0.0f);
			glVertex3f( 0.1f, -0.1f - i * 0.1f, 0.0f);
		glEnd();
	}
	glDisable(GL_LINE_STIPPLE);

	// Edge Flags
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
		glEdgeFlag(GL_TRUE);
		glVertex3f(-0.2f, -0.6f, 0.0f);
		glEdgeFlag(GL_FALSE);
		glVertex3f(-0.4f, -0.8f, 0.0f);
		glEdgeFlag(GL_TRUE);
		glVertex3f( 0.0f, -0.7f, 0.0f);

		glEdgeFlag(GL_FALSE);
		glVertex3f(-0.4f, -0.8f, 0.0f);
		glVertex3f( 0.0f, -0.7f, 0.0f);
		glEdgeFlag(GL_TRUE);
		glVertex3f( 0.4f, -0.8f, 0.0f);

		glEdgeFlag(GL_FALSE);
		glVertex3f( 0.0f, -0.7f, 0.0f);
		glEdgeFlag(GL_TRUE);
		glVertex3f( 0.4f, -0.8f, 0.0f);
		glVertex3f( 0.2f, -0.6f, 0.0f);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

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
	
	glutCreateWindow("06 - Primitive Attributes");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);

	if (!init())
		return 1;

	glutMainLoop();

	return 0;
}

