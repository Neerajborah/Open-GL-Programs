#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
void display();
void init();
int x1,a,x2,y2,x3,y3,x4,y4;
int z1=0,z2=0,z3=0,z4=0;
float px,py,t;

int main(int argc, char** argv)
{
 printf("Enter the x&y co-ordinates of control points\n");
 scanf("%d %d %d %d %d %d %d %d",&x1,&a,&x2,&y2,&x3,&y3,&x4,&y4);
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("bezier curve");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

void init()
{
 glClearColor(1,1,1,1);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,1,0);
 gluOrtho2D(-700,700,-700,700);
}

void display()
{
 glBegin(GL_LINES);
		glVertex2f(-700,0);
		glVertex2f(700,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0,-700);
		glVertex2f(0,700);
	glEnd();
	

 glBegin(GL_POINTS); 
 	for(t=0;t<=1;t+=0.001)
	{
 	 px=((1-t)*(1-t)*(1-t)*x1+3*(1-t)*(1-t)*t*x2+3*(1-t)*t*t*x3+t*t*t*x4);
 	 py=((1-t)*(1-t)*(1-t)*a+3*(1-t)*(1-t)*t*y2+3*(1-t)*t*t*y3+t*t*t*y4);
  	 glVertex2f(px,py);
	}
 glEnd();
 glFlush();
}
