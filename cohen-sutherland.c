#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

int xwmin,xwmax,ywmin,ywmax,code1[4],code2[4],code3[4],f1=0,f2=0;
float a,b,c,d;
void init();
void display();
void calculations();
void clip();

int main(int argc,char **argv)
{
	printf("\nEnter the original coordinates of the line-:");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	printf("\nEnter the XWmin and XWmax-:");
	scanf("%d%d",&xwmin,&xwmax);
	printf("\nEnter the YWmin and YWmax-:");
	scanf("%d%d",&ywmin,&ywmax);
	calculations();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Cohen Sutherland");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	gluOrtho2D(-700.0,700.0,-700.0,700.0);
}

void display()
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(-700,0);
		glVertex2f(700,0);
	glEnd();
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(0,700);
		glVertex2f(0,-700);
	glEnd();
	glFlush();
	glBegin(GL_LINES);
		glVertex2f(xwmax,ywmax);
		glVertex2f(xwmax,ywmin);
		glVertex2f(xwmin,ywmax);
		glVertex2f(xwmin,ywmin);
		glVertex2f(xwmax,ywmax);
		glVertex2f(xwmin,ywmax);
		glVertex2f(xwmax,ywmin);
		glVertex2f(xwmin,ywmin);

	glEnd();
	glFlush();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(a,b);
		glVertex2f(c,d);
	glEnd();
	glFlush();
}
void calculations()
{
	int i;
	for(i=0;i<4;i++){
		code1[i]=0;
		code2[i]=0;
	}
	if(a < xwmin)
		code1[3]=1;
	else if(a > xwmax)
		code1[2]=1;
	if(b < ywmin)
		code1[1]=1;
	else if(b > ywmax)
		code1[0]=1;
	if(c < xwmin)
		code2[3]=1;
	else if(c > xwmax)
		code2[2]=1;
	if(d < ywmin)
		code2[1]=1;
	else if(d > ywmax)
		code2[0]=1;
	
	for(i=0;i<4;i++)
	{
		code3[i] = code2[i] * code1[i];
		if(code1[i] == 1 || code2[i] == 1)
			f1=1;
	}
	if(f1==1)
	{
	for(i=0;i<4;i++)
	{
		if(code3[i]==1)
			f2=1;
	}
	}
	if(f1==1 && f2==0)
		clip();
}

void clip()
{
float m;
m=(d-b)/(c-a);
if(code1[0]==1){
b=ywmax;
}
else if(code1[1]==1)
b=ywmin;
else{
	if(code1[2]==1){
	a=xwmax;
	b=d-(m*(c-a));
	}
	else if(code1[3]==1){
	a=xwmin;
	b=d-(m*(c-a));
	}
	
}
if(code1[2]==1){
a=c-((d-b)/m);
}
else if(code1[3]==1){
a=c-((d-b)/m);
}
if(code2[0]==1){
d=ywmax;
}
else if(code1[1]==1)
d=ywmin;
else{
if(code2[2]==1){
c=xwmax;
d=b+(m*(c-a));
}
else if(code2[3]==1){
c=xwmin;
d=b+(m*(c-a));
}
}
if(code2[2]==1){
c=((d-b)/m)+a;
}
else if(code2[3]==1){
c=((d-b)/m)+a;
}
}		
