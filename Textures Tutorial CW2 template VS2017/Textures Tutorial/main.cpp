//Windows includes - DO NOT EDIT AS LOTS OF INTERDEPENDENCE


#include <math.h>						
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>	//Needed for console output (debugging)
#include <gl/freeglut.h>
#include <iostream>
#include <vector>

#ifdef WIN32
#include "gltools.h"
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include "glm.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#endif

#include "3DExample1/ObjLoader.h"
//can define any number of textures here - we just have 2 images
//these are just integers so you can use them as such
#define TEXTURE_HUD 0
#define TEXTURE_STARFIELD 1
#define TEXTURE_RING 2

#define TEXTURE_COUNT 3
GLuint  textures[TEXTURE_COUNT];
ObjLoader ObjLoad;
const char *textureFiles[TEXTURE_COUNT] = {"hud.tga", "starField.tga","stone.tga"};

GLfloat mKa[4] = {0.11f,0.06f,0.11f,1.0f}; //ambient
GLfloat mKd[4] = {0.43f,0.47f,0.54f,1.0f}; //diffuse
GLfloat mKs[4] = {1.0f,1.0f,1.0f,1.0f}; //specular
GLfloat mKe[4] = {0.5f,0.5f,0.0f,1.0f}; //emission

bool upKeyPressed = false;
bool keys[256];
float TestRotate = 45.0;

GLfloat  whiteLightBright[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  redLight[] = { 1.0f, 0.0f, 0.0f, 1.0f };
GLfloat  whiteLightLessBright[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat	 lightPos[] = { 100.0f, 100.0f, 50.0f, 1.0f };

GLint iWidth, iHeight, iComponents;
GLenum eFormat;

GLbyte *pBytes0;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);


void drawTexturedQuad(int image)
{
    //add some lighting normals for each vertex
    //draw the texture on the front
    glEnable(GL_TEXTURE_2D);
   // glFrontFace(GL_CW); //use glFrontFace(GL_CW) to texture the other side - not needed here as we set this elsewhere
    glColor3f(0.8, 0.8, 0.8);
    glEnable( GL_TEXTURE_2D );
    //bind the texture 
    glBindTexture(GL_TEXTURE_2D, textures[image]);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0,0.0);
    glVertex3f(-50.0, 0.0,100.0);
    glTexCoord3f(1.0,0.0,0.0);
    glVertex3f(50.0, 0.0,100.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(50.0, 100.0,100.0);
    glTexCoord2f(0.0,1.0);
    glVertex3f(-50.0, 100.0,100.0);
    glEnd();
    glDisable( GL_TEXTURE_2D );
    
}
void cameraUpDown()
{
	//code here

}
// Called to draw scene
void processCamera() {

	cameraUpDown(); 
	//need all the calls here to hand the camera (up down left right and rotate (roll))
}

void KeyPressed(unsigned char key, int x, int y) {
	keys[key] = true; // Set the state of the current key to pressed  
}

void KeyReleased(unsigned char key, int x, int y) {
	keys[key] = false; // Set the state of the current key to not pressed  
}

void CameraUpdateView()
{
	
	glPushMatrix();
	glTranslatef(cameraPos.x, cameraPos.y, cameraPos.z);
}

void processKeys(void)
{
	float cameraSpeed = 1.0f;
	double CamSpeed = 1.0f;
	if (keys['s'])
	{
		cameraPos += cameraSpeed * cameraFront;
	}
	if (keys['w'])
	{
		cameraPos -= cameraSpeed * cameraFront;
	}
	if (keys['d'])
	{
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}
	if (keys['a'])
	{
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}
	if (keys['q'])
	{
		
	}
	if (keys['e'])
	{
		
	}
	CameraUpdateView();
}

void RenderScene(void)
{
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(0.0, 0.0, 0.0, 0.0);
	glOrtho(0.0, 800, 600, 0.0, 0.0, 0.0);
	glTranslatef(0.0, -205.0, 0.0);
	glScalef(5.5, 4.1, 0.0);
    drawTexturedQuad(TEXTURE_HUD);
    glPopMatrix();
	
	processKeys();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glOrtho(0.0, 800, 600, 0.0, 0.0, 0.0);
	glutSolidTorus(1.0, 3.0, 32.0, 32.0);
	//glRotatef(TestRotate, 0.0, 1.0, 0.0);
	glPopMatrix();


}


// This function does any needed initialization on the rendering
// context.
void SetupRC()
{
    //textures

    GLuint texture;
    glGenTextures( 1, &texture );
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);

    glGenTextures(TEXTURE_COUNT, textures);
    //this puts the texture into OpenGL texture memory
 //   glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); - not defined so probably need to update GLEW - not needed here so ignore
    for(int iLoop = 0; iLoop < TEXTURE_COUNT; iLoop++)
    {
        // Bind to next texture object
        glBindTexture(GL_TEXTURE_2D, textures[iLoop]);
        
        // Load texture data, set filter and wrap modes
        //note that gltLoadTGA is in the glm.cpp file and not a built-in openGL function
        pBytes0 = gltLoadTGA(textureFiles[iLoop],&iWidth, &iHeight,
                             &iComponents, &eFormat);
        
        glTexImage2D(GL_TEXTURE_2D, 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBytes0);
        
            //set up texture parameters
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
         glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        //try these too
       // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);
        // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        free(pBytes0);
    }
    
	//enable textures
    glEnable(GL_TEXTURE_2D);

    
	glEnable(GL_DEPTH_TEST);	// Hidden surface removal    
    glFrontFace(GL_CCW);// Counter clock-wise polygons face out
	glEnable(GL_CULL_FACE);		// Do not calculate inside

//    glCullFace(GL_FRONT_AND_BACK);
    
	// Enable lighting
//	glEnable(GL_LIGHTING);
	glEnable(GL_POINT_SMOOTH);
	// Setup and enable light 0
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLightLessBright);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,redLight);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glEnable(GL_LIGHT0);

	// Enable colour tracking
	glEnable(GL_COLOR_MATERIAL);
	
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    
	// Black blue background
	glClearColor(0.0f, 0.0f, 0.03f, 1.0f );
}


void TimerFunc(int value)
{
    glutSwapBuffers();
    glutPostRedisplay();
    glutTimerFunc(25, TimerFunc, 1);
}

void ChangeSize(int w, int h)
{
    GLfloat fAspect;
    
    // Prevent a divide by zero
    if(h == 0)
        h = 1;
    
    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);
    
    // Calculate aspect ratio of the window
    fAspect = (GLfloat)w/(GLfloat)h;
    
    // Set the perspective coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // field of view of 45 degrees, near and far planes 1.0 and 1000
    //that znear and zfar should typically have a ratio of 1000:1 to make sorting out z depth easier for the GPU
    gluPerspective(55.0f, fAspect, 1.0, 1000.0); //may need to make larger depending on project
    // Modelview matrix reset
    glMatrixMode(GL_MODELVIEW);
    //pull the eye position back to view the scene
    gluLookAt(0.00,0.00,400.0,//eye
              0.00,0.00,0.00,//centre
              0.00,1.00,0.00);//up
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);// a 4:3 ratio
	glutCreateWindow("Textures Tutorial");
	glutKeyboardFunc(KeyPressed);
	glutKeyboardUpFunc(KeyReleased);
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
    glutTimerFunc(25, TimerFunc, 1);
	SetupRC();
	glutMainLoop();
	return 0;
}






