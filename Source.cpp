#include <glut.h>

double rotate_x = 0;

double rotate_y = 0;

void display()

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glRotatef(rotate_x, 1, 0, 0);

	glRotatef(rotate_y, 0, 1, 0);

	glBegin(GL_LINE_STRIP);

	//glColor3f(1, 0, 0);

	glVertex3f(-0.5, -0.5, -0.5);

	glVertex3f(0.5, -0.5, -0.5);

	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(-0.5, 0.5, -0.5);

	glVertex3f(-0.5, -0.5, -0.5);

	glEnd();

	glBegin(GL_LINE_STRIP);

	glVertex3f(-0.5, -0.5, 0.5);

	glVertex3f(0.5, -0.5, 0.5);

	glVertex3f(0.5, 0.5, 0.5);

	glVertex3f(-0.5, 0.5, 0.5);

	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();

	glBegin(GL_LINES);

	glVertex3f(-0.5, -0.5, 0.5);

	glVertex3f(-0.5, -0.5, -0.5);

	glVertex3f(0.5, -0.5, 0.5);

	glVertex3f(0.5, -0.5, -0.5);

	glVertex3f(0.5, 0.5, 0.5);

	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(-0.5, 0.5, 0.5);

	glVertex3f(-0.5, 0.5, -0.5);

	glEnd();

	glFlush();

	glutSwapBuffers();

}

void special_keys(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT)

		rotate_y += 5;

	else if (key == GLUT_KEY_LEFT)

		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)

		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)

		rotate_x -= 5;

	glutPostRedisplay();

}

int main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("Cube");

	glutDisplayFunc(display);

	glutSpecialFunc(special_keys);

	glutMainLoop();

	return 0;

}