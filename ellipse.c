#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

int rx,ry,x,y,a,b,p1,p2;
void init();
void display();
void shade();

int main(int argc,char **argv)
{
	printf("\nEnter the radii");
	scanf("%d%d",&rx,&ry);
	printf("\nEnter the centre-:");
	scanf("%d%d",&a,&b);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Mid point Ellipse Algorithm");
	init();
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
		glVertex2f(0+a,ry+b);
		glVertex2f(0+a,-ry+b);
		x=0;y=ry;
		p1=ry*ry - rx*rx*ry + rx*rx/4;
		while(2*ry*ry*x < 2*rx*rx*y)
		{
			shade();
			if(p1<0)
			{
				x=x+1;
				p1 = p1 + 2*ry*ry*x + ry*ry;
			}
			else
			{
				x=x+1;
				y=y-1;
				p1=p1 + 2*ry*ry*x + ry*ry - 2*rx*rx*y;
			}
			glVertex2f(x+a,y+b);
			glVertex2f(-x+a,y+b);
			glVertex2f(x+a,-y+b);
			glVertex2f(-x+a,-y+b);
		}
		
		p2 = ry*ry*(x+(1/2))*(x+(1/2)) + rx*rx*(y-1)*(y-1) - rx*rx*ry*ry;
		while(y>=0)
		{
			shade();
			if(p2 > 0)
			{
				y=y-1;
				p2 = p2 - 2 *rx*rx*y + rx*rx;
			}
			else
			{
				y=y-1;
				x=x+1;
				p2 = p2 - 2 *rx*rx*y + rx*rx + 2*ry*ry*x;
			}
			glVertex2f(x+a,y+b);
			glVertex2f(-x+a,y+b);
			glVertex2f(x+a,-y+b);
			glVertex2f(-x+a,-y+b);
		}
	glEnd();
	glFlush();
}

void shade()
{
	glBegin(GL_LINES);
		glVertex2f(a,b);
		glVertex2f(x+a,y+b);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(a,b);
		glVertex2f(-x+a,y+b);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(a,b);
		glVertex2f(x+a,-y+b);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(a,b);
		glVertex2f(-x+a,-y+b);
	glEnd();
}
