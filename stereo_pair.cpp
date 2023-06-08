#include <glut.h>
#include <cmath>

GLfloat light_position[] = { -1.0, 1.0, 1.0, 0.0 };

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// ���� �Ӽ� ����
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void display() {
	/*

	���� viewport�� �̹�����
		  ��       ��
	�̷������� ���� �� ���� ������ ������ ������ �������
		��  ��     ��   ��
	�̹����� �̷��� ���̰� �ȴ�

	���� ����Ʈ���� ������ ���� ������ ���� �� �̹�����
	������ ����Ʈ���� ���� ���� ���� ���� �� �̹�����.

	���� ���� ���� ���ݾ� Ǯ�� ��� ���� ��ġ��
		��  ��     ��   ��
			   ...
		 ��  ��   ��   ��
			   ...
		   ��  ����   ��
			   ...
			 �� ��  ��
	�� �� ���̴� ��� ��Ƚ����� ����� �̹�����,
	���ٰ��� �������� �ȴ�.

	*/

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, 600, 800); // viewport L (������ ������ �� �̹���)
	glLoadIdentity();
	gluLookAt(-3.0, 4.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	glPushMatrix();
	glTranslatef(-1.0, 2.5, 3.0);
	glutSolidSphere(1.0, 50, 50); // �� �׸���
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 0.0, -7.0);
	glutSolidCube(5.0); // ť�� �׸���
	glPopMatrix();

	//-------------------------------------------------------------------//

	glViewport(600, 0, 600, 800); // viewport R (���� ������ �� �̹���)
	glLoadIdentity();
	gluLookAt(-3.5, 4.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	glPushMatrix();
	glTranslatef(-1.0, 2.5, 3.0);
	glutSolidSphere(1.0, 50, 50); // �� �׸���
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 0.0, -7.0);
	glutSolidCube(5.0); // ť�� �׸���
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h / 2, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("HW5_195511_������");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}