#include<gl\glut.h>
//#include<gl\GL.h>
//#include<gl\GLU.h>
#include "fixture.h"
#include "light.h"

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);//设置背景颜色为黑色
	setLight();
}

void Display(void)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT);//buffer设置为颜色可写
	glLoadIdentity();
	gluLookAt(0,100,600, 0,100,0, 0,1,0);

	drawCourt();

	glFlush();//强制OpenGL函数在有限时间内运行
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
	/*初始化*/
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(720,540);
	glutInitWindowPosition(200,100);

	/*创建窗口*/
	glutCreateWindow("Basketball");

	/*绘制与显示*/
	init();
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);

	glutMainLoop();
	return(0);
}