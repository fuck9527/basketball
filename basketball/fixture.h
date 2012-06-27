#include<gl\glut.h>
#include<gl\GLAUX.H>
#include<stdio.h>
#include<cstring>
#pragma comment( lib, "glaux.lib")	
//#include<gl\GL.h>
//#include<gl\GLU.h>


GLuint *textures = new GLuint();

AUX_RGBImageRec *LoadBMP(char *Filename)     // Loads A Bitmap Image
{
	FILE *File=NULL;          // File Handle
	if (!Filename)           // Make Sure A Filename Was Given
	{
		return NULL;          // If Not Return NULL
	}
	File=fopen(Filename,"r");        // Check To See If The File Exists
	if (File)            // Does The File Exist?
	{
		fclose(File);          // Close The Handle;
		return auxDIBImageLoadA(Filename);     // Load The Bitmap And Return A Pointer
		printf("ok");
	}
	return NULL;           // If Load Failed Return NULL
}

void LoadGLTextures(char *filename)          // Load Bitmaps And Convert To Textures
{
	int Status=FALSE;          // Status Indicator
	AUX_RGBImageRec *TextureImage[1];      // Create Storage Space For The Texture
	memset(TextureImage,0,sizeof(void *)*1);           // Set The Pointer To NULL
	// 装入bmp格式图像，并检查错误，工程下创建的文件夹data
	//printf("filename: %s\n", filename);
	if (TextureImage[0]=LoadBMP(filename))
	{
		//printf("haha");
		//Status=TRUE;          // Set The Status To TRUE
		glGenTextures(1, &textures[0]);      // 创建纹理
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	if (TextureImage[0])          // If Texture Exists
	{
		//printf ("haha1");
		if (TextureImage[0]->data)        // If Texture Image Exists
		{
			free(TextureImage[0]->data);      // Free The Texture Image Memory
		}
		free(TextureImage[0]);         // Free The Image Structure
	}
	//glEnable(GL_TEXTURE_2D);
}

void drawCuboid(float x, float y, float z)
{
	glPushMatrix();
	glEnable(GL_NORMALIZE);	
	glBegin(GL_QUADS);
		//up
		glVertex3f(x/2, y, z/2);
		glNormal3f(x/2, y, z/2);
        glVertex3f(-x/2, y, z/2);
		glNormal3f(-x/2, y, z/2);
        glVertex3f(-x/2, y, -z/2);
		glNormal3f(-x/2, y, -z/2);
        glVertex3f(x/2, y, -z/2);
		glNormal3f(x/2, y, -z/2);
		//down
		glVertex3f(x/2, 0, z/2);
		glNormal3f(x/2, 0, z/2);
        glVertex3f(-x/2, 0, z/2);
		glNormal3f(-x/2, 0, z/2);
        glVertex3f(-x/2, 0, -z/2);
		glNormal3f(-x/2, 0, -z/2);
        glVertex3f(x/2, 0, -z/2);
		glNormal3f(x/2, 0, -z/2);
		//left
		glVertex3f(-x/2, y, z/2);
        glNormal3f(-x/2, y, z/2);
		glVertex3f(-x/2, y, -z/2);
        glNormal3f(-x/2, y, -z/2);
		glVertex3f(-x/2, 0, -z/2);
        glNormal3f(-x/2, 0, -z/2);
		glVertex3f(-x/2, 0, z/2);
		glNormal3f(-x/2, 0, z/2);
		//right
		glVertex3f(x/2, y, z/2);
        glNormal3f(x/2, y, z/2);
		glVertex3f(x/2, y, -z/2);
        glNormal3f(x/2, y, -z/2);
		glVertex3f(x/2, 0, -z/2);
        glNormal3f(x/2, 0, -z/2);
		glVertex3f(x/2, 0, z/2);
		glNormal3f(x/2, 0, z/2);
		//front
		glVertex3f(x/2, y, z/2);
		glNormal3f(x/2, y, z/2);
        glVertex3f(-x/2, y, z/2);
		glNormal3f(-x/2, y, z/2);
        glVertex3f(-x/2, 0, z/2);
		glNormal3f(-x/2, 0, z/2);
        glVertex3f(x/2, 0, z/2);
		glNormal3f(x/2, 0, z/2);
		//back
		glVertex3f(x/2, y, -z/2);
		glNormal3f(x/2, y, -z/2);
        glVertex3f(-x/2, y, -z/2);
		glNormal3f(-x/2, y, -z/2);
        glVertex3f(-x/2, 0, -z/2);
		glNormal3f(-x/2, 0, -z/2);
        glVertex3f(x/2, 0, -z/2);
		glNormal3f(x/2, 0, -z/2);
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

	glPushMatrix();
		glTranslatef(2,20,0);
		LoadGLTextures("b.bmp");
		glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
				glNormal3f(0,-20,30);
				glTexCoord2f(0,1);
				glVertex3f(0, 20, 30);
				glNormal3f(0,20,30);
				glTexCoord2f(1,1);
				glVertex3f(0, 20, -30);
				glNormal3f(0,20,-30);
				glTexCoord2f(1,0);
				glVertex3f(0, -20, -30);
				glNormal3f(0,-20,-30);
				glTexCoord2f(0,0);
				glVertex3f(0, -20, 30);
			glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glTranslatef(13, 10, 0);
	glRotatef(90, 1, 0, 0);
	glColor3f(0.5, 0.4, 0.2);
	glutSolidTorus(1, 10, 20, 20);
	glPopMatrix();
}

void drawCourt()
{
	glEnable(GL_COLOR_MATERIAL);

	glPushMatrix();
		glTranslatef(0, -4, 0);
		glColor3f(0.94, 0.78, 0.08);
		drawCuboid(1080, 4, 600);
	glPopMatrix();

	glPushMatrix();
		LoadGLTextures("g.bmp");
		glEnable(GL_TEXTURE_2D);
		//glTranslatef(-525, 0, 290);
		glTranslatef(-536, 0, 296);
		for (int j = 0; j<135; j++)
		{
			for (int k = 0; k<75; k++)
			{
				glBegin(GL_QUADS);
				
				glNormal3f(-4, 0, 4);
				glTexCoord2f(1-1.0/135*j, 0+1.0/75*k);
				glVertex3f(-4, 0, 4);
				
				glNormal3f(-4, 0, -4);
				glTexCoord2f(1-1.0/135*j, 0+1.0/75*(k+1));
				glVertex3f(-4, 0, -4);

				glNormal3f(4, 0, -4);
				glTexCoord2f(1-1.0/135*(j+1), 0+1.0/75*(k+1));
				glVertex3f(4, 0, -4);

				glNormal3f(4, 0, 4);
				glTexCoord2f(1-1.0/135*(j+1), 0+1.0/75*k);
				glVertex3f(4, 0, 4);
				glEnd();

				glTranslatef(0, 0, -8.0);
			}
			glTranslatef(8.0, 0, 600);
		}
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-390, 4, 0);
		drawStands();
		glTranslatef(780, 0, 0);
		glRotatef(180, 0, 1, 0);
		drawStands();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,250,-300);
		LoadGLTextures("a1.bmp");
		glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
				glNormal3f(-540,-250,0);
				glTexCoord2f(0,1);
				glVertex3f(-540,250,0);

				glNormal3f(-540,250,0);
				glTexCoord2f(1,1);
				glVertex3f(540,250,0);

				glNormal3f(540,250,0);
				glTexCoord2f(1,0);
				glVertex3f(540,-250,0);

				glNormal3f(540,-250,0);
				glTexCoord2f(0,0);
				glVertex3f(-540,-250,0);
			glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-540,250,0);
		LoadGLTextures("a2.bmp");
		glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
				glNormal3f(0,-250,300);
				glTexCoord2f(0,1);
				glVertex3f(0, 250, 300);
				glNormal3f(0,250,300);
				glTexCoord2f(1,1);
				glVertex3f(0, 250, -300);
				glNormal3f(0,250,-300);
				glTexCoord2f(1,0);
				glVertex3f(0, -250, -300);
				glNormal3f(0,-250,-300);
				glTexCoord2f(0,0);
				glVertex3f(0, -250, 300);
			glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(540,250,0);
		glRotatef(180, 0, 1, 0);
		LoadGLTextures("a2.bmp");
		glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
				glNormal3f(0,-250,300);
				glTexCoord2f(0,1);
				glVertex3f(0, 250, 300);
				glNormal3f(0,250,300);
				glTexCoord2f(1,1);
				glVertex3f(0, 250, -300);
				glNormal3f(0,250,-300);
				glTexCoord2f(1,0);
				glVertex3f(0, -250, -300);
				glNormal3f(0,-250,-300);
				glTexCoord2f(0,0);
				glVertex3f(0, -250, 300);
			glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	/*glPushMatrix();
	LoadGLTextures("E:\\f.bmp");
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glVertex3f(-540, 1, 300);
		glTexCoord2f(0,1);
		glVertex3f(-540, 1, -300);
		glTexCoord2f(1,1);
		glVertex3f(540, 1, -300);
		glTexCoord2f(1,0);
		glVertex3f(540, 1, 300);
		glTexCoord2f(0,0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();*/
}
