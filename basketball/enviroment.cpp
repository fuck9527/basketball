#include<gl\glut.h>
//#include<gl\GL.h>
//#include<gl\GLU.h>
#include "fixture.h"

void background(void)
{
	glClearColor(0.0,0.0,0.0,0.0);//���ñ�����ɫΪ��ɫ
}

void myDisplay(void)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT);//buffer����Ϊ��ɫ��д
	glLoadIdentity();
	gluLookAt(0,100,800, 0,100,0, 0,1,0);

	drawCourt();

	glFlush();//ǿ��OpenGL����������ʱ��������
}

void myReshape(GLsizei w, GLsizei h)
{	
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    gluPerspective(60,(GLfloat)w/(GLfloat)h,0.1,2000);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
 
	
	//gluLookAt(0,0,30, 0,0,0, 0,1,0);
}

int main(int argc,char ** argv)
{
	/*��ʼ��*/
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(720,540);
	glutInitWindowPosition(200,100);

	/*��������*/
	glutCreateWindow("Basketball");

	/*��������ʾ*/
	background();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return(0);
}