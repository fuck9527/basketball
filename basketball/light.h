#include<gl\glut.h>

void setLight()
{
	//高0 弖高
	//GLfloat mat_specular[] = {1, 1, 1, 1};
	//GLfloat mat_shininess[] = {50};
	GLfloat light_position[] = {0, 300, 0, 1};
	//GLfloat white_light[] = {1, 1, 1, 1};
	//GLfloat lmodel_ambient[] = {0.1, 0.1, 0.1, 1.};
	//glShadeModel(GL_SMOOTH);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.5);
	//glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.5);
	//glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.2);

	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 10);
	//GLfloat light_position[] = {0, 100, 0, 0};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	GLfloat spot_direction[] = {0, -1, 0};
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	//高1
	//GLfloat mat_specular[] = {1, 1, 1, 1};
	//GLfloat mat_shininess[] = {50};
	GLfloat light_position1[] = {-390, 300, 0, 1};
	GLfloat white_light[] = {1, 1, 1, 1};
	//GLfloat lmodel_ambient[] = {0.1, 0.1, 0.1, 1.};
	//glShadeModel(GL_SMOOTH);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.5);
	//glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.5);
	//glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.2);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 40);
	//GLfloat light_position[] = {0, 100, 0, 0};
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
	GLfloat spot_direction1[] = {0, -1, 0};
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction1);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	//高2
	//GLfloat mat_specular[] = {1, 1, 1, 1};
	//GLfloat mat_shininess[] = {50};
	GLfloat light_position2[] = {390, 300, 0, 1};
	//GLfloat white_light[] = {1, 1, 1, 1};
	//GLfloat lmodel_ambient[] = {0.1, 0.1, 0.1, 1.};
	//glShadeModel(GL_SMOOTH);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.5);
	//glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.5);
	//glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.2);

	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 40);
	//GLfloat light_position[] = {0, 100, 0, 0};
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT2, GL_SPECULAR, white_light);
	GLfloat spot_direction2[] = {0, -1, 0};
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction2);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
}