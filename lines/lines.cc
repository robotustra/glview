#include <math.h>
#include <GL/glut.h>
//#include <GL.h>

//Initialize OpenGL 
void init(void) {
    glClearColor(0.0,0.0,0.0,0.0); 
    

    //glMatrixMode(GL_PROJECTION); 
    
    glOrtho(-5.0,5.0,-5.0,5.0, -10.0, 10);
    
    glClearColor(0, 0, 0, 0);

    glViewport(0, 0, 500, 500);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(0, 500, 0, 500, 1, -1);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

} 

void drawLines(void) {
    glClear(GL_COLOR_BUFFER_BIT);  
    glColor3f(0.0,0.4,0.2); 
    glPointSize(3.0);  

    /*
    glBegin(GL_LINES);
    //glVertex2d(180, 15);
    //glVertex2d(10, 145);

    glVertex3f(0.5, 0.15, 0.5);
    glVertex3f(0.2, 0.66, 0.5);


    glEnd();
*/

    //glBegin(GL_TRIANGLE_FAN);
    glBegin(GL_LINES);

glVertex3f(-1.0f, -0.5f, -4.0f);    // A
glVertex3f( 1.0f, -0.5f, -2.0f);    // B

glVertex3f( 1.0f, -0.5f, -2.0f);    // B
glVertex3f( 0.0f,  0.5f, -4.0f);    // C

glVertex3f( 0.0f,  0.5f, -4.0f);    // C
glVertex3f(-1.5f,  0.0f, -5.0f);    // D

glVertex3f(-1.5f,  0.0f, -5.0f);    // D
glVertex3f(-1.8f, -1.0f, -4.0f);    // E

glVertex3f(-1.8f, -1.0f, -4.0f);    // E
glVertex3f( 0.2f, -1.5f, -6.0f);    // F

glVertex3f( 0.2f, -1.5f, -6.0f);    // F
glVertex3f( 1.0f, -0.5f, -4.0f);    // G

glEnd();
    glFlush();
} 

int main(int argc, char**argv) {
    glutInit(&argc, argv);  
    glutInitWindowPosition(10,10); 
    glutInitWindowSize(500,500); 
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

    glutCreateWindow("Example"); 
    init(); 
    glutDisplayFunc(drawLines); 
    glutMainLoop();
}