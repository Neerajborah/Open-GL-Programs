#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex3f(0.25,0.25,0.0);
glVertex3f(0.75,0.25,0.0);
glVertex3f(0.75,0.75,0.0);
glVertex3f(0.25,0.75,0.0);
glEnd();
glFlush();
}
void init(void)
{
glClearColor(0.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
}
void main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(200,0);
glutCreateWindow("graphic 1");
init();
glutDisplayFunc(display);
glutMainLoop();

}