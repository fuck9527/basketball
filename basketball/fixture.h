#include<gl\glut.h>
//#include<gl\GL.h>
//#include<gl\GLU.h>

void drawCuboid(float x, float y, float z)
{
	glPushMatrix();
	glBegin(GL_QUADS);
		//up
		glVertex3f(x/2, y, z/2);
        glVertex3f(-x/2, y, z/2);
        glVertex3f(-x/2, y, -z/2);
        glVertex3f(x/2, y, -z/2);
		//down
		glVertex3f(x/2, 0, z/2);
        glVertex3f(-x/2, 0, z/2);
        glVertex3f(-x/2, 0, -z/2);
        glVertex3f(x/2, 0, -z/2);
		//left
		glVertex3f(-x/2, y, z/2);
        glVertex3f(-x/2, y, -z/2);
        glVertex3f(-x/2, 0, -z/2);
        glVertex3f(-x/2, 0, z/2);
		//right
		glVertex3f(x/2, y, z/2);
        glVertex3f(x/2, y, -z/2);
        glVertex3f(x/2, 0, -z/2);
        glVertex3f(x/2, 0, z/2);
		//front
		glVertex3f(x/2, y, z/2);
        glVertex3f(-x/2, y, z/2);
        glVertex3f(-x/2, 0, z/2);
        glVertex3f(x/2, 0, z/2);
		//back
		glVertex3f(x/2, y, -z/2);
        glVertex3f(-x/2, y, -z/2);
        glVertex3f(-x/2, 0, -z/2);
        glVertex3f(x/2, 0, -z/2);		
    glEnd();
	glPopMatrix();
}

void drawStands()
{
	glPushMatrix();
	glColor3f(0, 1, 0);
	drawCuboid(10, 100, 10);

	glTranslatef(20, 100, 0);
	drawCuboid(50, 10, 10);

	glTranslatef(27, -15, 0);
	glColor3f(1, 1, 1);
	drawCuboid(4, 40, 60);

	glTranslatef(13, 10, 0);
	glRotatef(90, 1, 0, 0);
	glColor3f(0.5, 0.4, 0.2);
	glutSolidTorus(1, 10, 20, 20);
	glPopMatrix();
}

void drawCourt()
{
	glPushMatrix();
	glTranslatef(0, -4, 0);
	glColor3f(0.94, 0.78, 0.08);
	drawCuboid(1080, 4, 600);

	glTranslatef(-390, 4, 0);
	drawStands();
	glTranslatef(780, 0, 0);
	glRotatef(180, 0, 1, 0);
	drawStands();
	glPopMatrix();
}