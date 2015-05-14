#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int xCenter,yCenter,radius,i;
void init(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	gluOrtho2D(-500.0,500.0,-500.0,500.0);
}
void display()
{
	int x=0,y=radius;
	int p=1-radius;
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2f(xCenter,yCenter);
	while(x<y)
{
		glVertex2f(x+xCenter,y+yCenter);
			x++;
		 if(p<0)
			{
				p+=2*x+1;
			}
		else
			{
				y--;
				p+=(2*x)+1-(2*y);
			}
			glVertex2f(xCenter+x,yCenter+y);
			glVertex2f(xCenter+y,yCenter+x);
			glVertex2f(xCenter-x,yCenter+y);
			glVertex2f(xCenter+y,yCenter-x);
			glVertex2f(xCenter-x,yCenter-y);
			glVertex2f(xCenter-y,yCenter-x);
			glVertex2f(xCenter+x,yCenter-y);
			glVertex2f(xCenter-y,yCenter+x);

	}
{
glColor3f(0.0,1.0,0.0);
for(i=-500;i<=500;i++)
{
glVertex2s(i,0);
glVertex2s(0,i);
}

}
	glEnd();
	glFlush();
}
int main(int argc,char **argv)
{
	printf(" Enter the center points:-");
	scanf("%d %d",&xCenter,&yCenter);
	printf("Enter the radius:- ");
	scanf("%d",&radius);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Mid-point Circle Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
