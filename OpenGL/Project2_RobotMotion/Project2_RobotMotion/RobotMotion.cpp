#include <windows.h>
#include <mmsystem.h>
#include <glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static double time = 0;
static double time2 = 0;
static double time3 = 0;
static double time4 = 0;
static double time6 = 0;

GLfloat R_Arm_x = 0;
GLfloat R_Arm_y = 0;
GLfloat L_Arm_x = 0;
GLfloat L_Arm_y = 0;
GLfloat R_Leg_x = 0;
GLfloat R_Leg_y = 0;
GLfloat L_Leg_x = 0;
GLfloat L_Leg_y = 0;
GLfloat R = 0;
GLfloat R2 = 0;

GLUquadricObj* cyl;

int a = 0;
int b = 0;
int c = 0;

static int flag = 0;
static int key = 0;

#define RUN 1
#define JAP 2
#define ROCKET 3
#define YUNA 4
#define EXIT 6

void glInit()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.3f, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat position[] = { 400.0, 300.0, -700.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void Draw_Color(int i)
{
	if (i == RUN)
		glColor3f(0.0, 1.0, 0.0);
	else if (i == JAP)
		glColor3f(1.0, 1.0, 1.0);
	else if (i == ROCKET)
		glColor3f(0.0, 1.0, 1.0);
	else if (i == YUNA)
		glColor3f(1.0, 0.0, 1.0);
	else if (i == EXIT)
		glColor3f(0.2, 0.2, 0.2);
}

void Change_Wire_Or_Solid(int i)
{
	if (flag == 1)
		gluQuadricDrawStyle(cyl, GLU_LINE);
}
