#include <glut.h>
#include <math.h>
#define Pi 3.1415

//#define SAMPLECODE_9_10
#ifdef SAMPLECODE_9_10
void MyDisplay()
{
	GLfloat Size[2];
	GLfloat Angle;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
	glPointSize(Size[0]*5);
	glBegin(GL_POINTS);
	for (Angle = 0.0; Angle <= 2.0*Pi; Angle += Pi / 20.0)
		glVertex3f(0.5*cos(Angle), 0.5*sin(Angle), 0.0);
	glEnd();
	glFlush();
}
#endif //SAMPLECODE_9_10


//#define SAMPLECODE_9_11
#ifdef SAMPLECODE_9_11
void MyDisplay()
{
	GLint ScaleFactor = 1;
	GLushort Pattern = 0x00FF;
	GLfloat Height;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glEnable(GL_LINE_STIPPLE);
	for (Height = -0.9; Height < 0.9; Height += 0.4)
	{
		glLineStipple(ScaleFactor, Pattern);
		glBegin(GL_LINES);
		glVertex3f(-1.0, Height, 0.0);
		glVertex3f(1.0, Height, 0.0);
		glEnd();
		ScaleFactor *= 2;
	}
	glDisable(GL_LINE_STIPPLE);
	glFlush();

}
#endif //SAMPLECODE_9_11


//#define SAMPLECODE_9_12
#ifdef SAMPLECODE_9_12
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(10.0);
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glEnd();
	glFlush();
}
#endif //SAMPLECODE_9_12

//#define SAMPLECODE_9_13
#ifdef SAMPLECODE_9_13
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	glFlush();
}

#endif //SAMPLECODE_9_13

#define SAMPLECODE_9_14
#ifdef SAMPLECODE_9_14

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glPointSize(12);
	glBegin(GL_POINTS);
	glVertex3f(-0.9, -0.65, 0);
	glEnd();
	glDisable(GL_POINT_SMOOTH);

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glBegin(GL_LINES);
	glVertex3f(-1.0, -0.6, 0.0);
	glVertex3f(1.0, -0.2, 0.0);
	glVertex3f(-1.0, -0.6, 0.0);
	glVertex3f(0.75, 1.0, 0.0);
	glVertex3f(-1.0, -0.6, 0.0);
	glVertex3f(-0.75, 1.0, 0.0);

	glEnd();
	glDisable(GL_LINE_SMOOTH);

	glDisable(GL_BLEND);
	glFlush();
	
}


#endif // SAMPLECODE_9_14

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
	
}