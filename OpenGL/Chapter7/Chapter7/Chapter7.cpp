//#define SAMPLECODE_7_1
#ifdef SAMPLECODE_7_1

#include <glut.h>
#include <stdio.h>

int Width, Height;

void Init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); //행렬 모드를 투상 행렬로 설정
	glLoadIdentity(); // 투상 행렬 값을 항등 행렬로 초기화
	//물체가 x,y,z축으로 (-1,1) 범위에 분포하는 상태에서 
	//투상면의 좌우하상을 (-2.0, 2.0, -2.0, 2.0) 으로 설정함으로써 
	//대략 물체 크기의 2배 정도의 가시 부피가 설정된다.
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0); 

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DrawScene()
{
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(2.0, 0.0, 2.0);
		glVertex3f(2.0, 0.0, -2.0);
		glVertex3f(-2.0, 0.0, -2.0);
		glVertex3f(-2.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();

	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireTeapot(1.0);
	glPopMatrix();
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, Width / 2, Height / 2);
	glPushMatrix();
		gluLookAt(0.0, 0.0, 1.0,	0.0, 0.0, 0.0,	0.0, 1.0, 0.0);
		DrawScene();
	glPopMatrix();

	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
		gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		DrawScene();
	glPopMatrix();

	glViewport(0, Height/2, Width / 2, Height / 2);
	glPushMatrix();
		gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
		DrawScene();
	glPopMatrix();

	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluPerspective(30, 1.0, 3.0, 50.0);
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		DrawScene();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}

void MyReshape(int w, int h)
{
	Width = w;
	Height = h;
}

int main(int argc, char**argv)
{
	Width = 500, Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	Init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}

#endif //SAMPLECODE_7_1

#define SAMPLECODE_7_2
#ifdef SAMPLECODE_7_2

#include <glut.h>

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.3, 0.7);
	glutWireTeapot(1.0);
	glFlush();
}

void MyReshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, (GLdouble)w / (GLdouble)h, 1.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutPostRedisplay();
}

int main(int argc, char**argv)
{
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}





#endif//SAMPLECODE_7_2