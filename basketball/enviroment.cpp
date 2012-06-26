#include<gl\glut.h>
//#include<gl\GL.h>
//#include<gl\GLU.h>
#include "fixture.h"
#include "light.h"

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);//���ñ�����ɫΪ��ɫ
	setLight();
}

void Display(void)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT);//buffer����Ϊ��ɫ��д
	glLoadIdentity();
	gluLookAt(0,100,600, 0,100,0, 0,1,0);

	drawCourt();

	glFlush();//ǿ��OpenGL����������ʱ��������
}

void Reshape(GLsizei w, GLsizei h)
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
	init();
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);

	glutMainLoop();
	return(0);
}