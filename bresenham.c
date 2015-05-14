#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
float xO,yO,x2,y2;
void linealg(void)
{
	int dx=(x2-xO), dy=(y2-yO),twody=2*dy,twodydx=2*(dy-dx);
	int p=2*dy-dx;
	int r,q=-700;
	/*glBegin(GL_POINTS);
	for(r=-700;r<700;r++)
	{q+=1;
	glVertex2f(q,0);
	glVertex2f(0,q);}
    glEnd();*/

	int slope=(dy/dx);
if(0<slope<1){
		glBegin(GL_POINTS);
		int x,y;
		if(xO>x2)
		{
			x=x2; y=y2; x2=x;}
		else{
			x=xO; y=yO;}
		glVertex2f(x,y);
		while(x<x2)
		{x++;
		if(p<0)
		{
 		p+=twody;}
		else{
		y++;
		p+=twodydx;}
		glVertex2f(x,y);}
		glEnd();}

else{   
	glBegin(GL_POINTS);
	int x,y;
	if(yO>y2)
	{
	y=y2; x=x2; y2=y;}
	else{
	y=yO; x=xO;}
	glVertex2f(x,y);
	while(y<y2)
	{y++;
		if(p<0)
		{
 		p+=2*dx;}
	else{
		x++;
		p+=2*(dx-dy);}
	glVertex2f(x,y);}
	glEnd();}
glFlush();
}

void init(void)
{
glClearColor(0.0,1.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,0.0);
gluOrtho2D(-700,700,-700,700);
}

int main(int argc,char** argv)
{
	printf("enter the initial co-ordinates:\n");
	printf("xO and yO\n");
	scanf("%f %f",&xO,&yO);
	printf("enter the final co-ordinates:\n");
	printf("x2 and y2\n");
	scanf("%f %f",&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("Line Bresenham Algorithm");
	init();
	glutDisplayFunc(linealg);
	glutMainLoop();
	return 0;
}

