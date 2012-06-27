#include<gl\glut.h>
//#include<gl\GL.h>
//#include<gl\GLU.h>
#include "fixture.h"
#include "light.h"

float xRot = 0;
float yRot = 100;
float zRot = 600;

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);//���ñ�����ɫΪ��ɫ
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	GLfloat l1[] = {1,1,1,1};
	GLfloat l2[] = {0,0,0,1};
	glMaterialfv(GL_FRONT, GL_SPECULAR, l2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, l1);
    glMaterialf(GL_FRONT, GL_SHININESS, 20);
}

void Display(void)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT);//buffer����Ϊ��ɫ��д
	glClear(GL_DEPTH_BUFFER_BIT);
	
	//glEnable(GL_DEPTH_TEST);
	
	glLoadIdentity();
	//gluLookAt(0,100,600, 0,100,0, 0,1,0);
	gluLookAt(xRot,yRot,zRot, xRot,yRot,-1, 0,1,0);
	//gluLookAt(0,1000,0, 0,100,0, 0,0,-1);
	
	setLight();
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

	//glLoadIdentity();	
	//gluLookAt(0,100,600, 0,100,0, 0,1,0);
}

void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        zRot -= 20;

    if(key == GLUT_KEY_DOWN)
        zRot += 20;

    if(key == GLUT_KEY_LEFT)
        xRot -= 20;

    if(key == GLUT_KEY_RIGHT)
		xRot += 20;

	glutPostRedisplay();
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
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
	return(0);
}