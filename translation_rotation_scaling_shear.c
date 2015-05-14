#include<stdio.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
int a,b,c,d,e,f,flag=0,flag2=0,flag3=0,sx=1,sy=1,tx=0,ty=0,shx=1,shy=0,theta;
void init()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-700,700,-700,700);
}
void translate()
{
	printf("\nEnter the amt. of translation in x : ");
	scanf("%d",&tx);
	printf("\nEnter the amt. of translation in y : ");
	scanf("%d",&ty);
	flag=1;
}
void rotate()
{
	printf("\nEnter the angle theta : ");
	scanf("%d",&theta);
	flag2=1;
}
void shear()
{
	int booli;
	printf("\nEnter 1 for shear in x and 0 for shear in y : ");
	scanf("%d",&booli);
	if(booli)
	{
		printf("\nEnter the value of shearing in x : ");
		scanf("%d",&shx);
	}
	else
	{
		printf("\nEnter the value of shearing in y : ");
		scanf("%d",&shy);
	}
	flag3=1;
}
void scale()
{
	printf("\nEnter the scaling x and y : ");
	scanf("%d%d",&sx,&sy);
	flag=1;
}
void display()
{
	glBegin(GL_LINES);
		glVertex2f(700,0);glColor3f(1,0,0);
		glVertex2f(-700,0);glColor3f(1,0,0);
	glEnd();
	glBegin(GL_LINES);	
		glVertex2f(0,-700);glColor3f(1,0,0);
		glVertex2f(0,700);glColor3f(1,0,0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(a,b);glColor3f(1,0,0);
		glVertex2f(c,d);glColor3f(1,0,0);
		glVertex2f(e,f);glColor3f(1,0,0);
	glEnd();
	glBegin(GL_POLYGON);
		if(flag==1)
		{
			glVertex2f(sx*a+tx,sy*b+ty);glColor3f(0,1,0);
			glVertex2f(sx*c+tx,sy*d+ty);glColor3f(0,1,0);
			glVertex2f(sx*e+tx,sy*f+ty);glColor3f(0,1,0);
		}
		if(flag2==1)
		{
			glVertex2f(a*cos(theta)-b*sin(theta),a*sin(theta)+b*cos(theta));glColor3f(0,1,0);
			glVertex2f(c*cos(theta)-d*sin(theta),c*sin(theta)+d*cos(theta));glColor3f(0,1,0);
			glVertex2f(e*cos(theta)-f*sin(theta),e*sin(theta)+f*cos(theta));glColor3f(0,1,0);
		}
		if(flag3==1)
		{
			glVertex2f(a+b*shx,b+a*shy);glColor3f(0,1,0);
			glVertex2f(c+d*shx,d+c*shy);glColor3f(0,1,0);
			glVertex2f(e+f*shx,f+e*shy);glColor3f(0,1,0);
		}
	glEnd();
	glFlush();
}
void main(int argc, char**argv)
{
	int choice;
	printf("Enter the coordinates of all vertices in order : ");
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	printf("\nPress 1 for translation\nPress 2 for rotation\nPress 3 for scaling\nPress 4 for shear : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			translate();
			break;
		case 2:
			rotate();
			break;
		case 3:
			scale();
			break;
		case 4:
			shear();
			break;
		default:
			printf("\nWrong input!!!");
			exit(1);
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Geometric Transformations");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return;
}


				
