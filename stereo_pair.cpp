#include <glut.h>
#include <cmath>

GLfloat light_position[] = { -1.0, 1.0, 1.0, 0.0 };

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// 재질 속성 설정
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

	양쪽 viewport에 이미지가
		  ㅁ       ㅇ
	이런식으로 있을 때 눈을 가운대로 모으면 초점이 흐려져서
		ㅁ  ㅁ     ㅇ   ㅇ
	이미지가 이렇게 보이게 된다

	왼쪽 뷰포트에서 오른쪽 ㅁ은 오른쪽 눈이 본 이미지고
	오른쪽 뷰포트에서 왼쪽 ㅇ은 왼쪽 눈이 본 이미지다.

	이제 모인 눈을 조금씩 풀어 가운데 둘을 합치자
		ㅁ  ㅁ     ㅇ   ㅇ
			   ...
		 ㅁ  ㅁ   ㅇ   ㅇ
			   ...
		   ㅁ  ㅁㅇ   ㅇ
			   ...
			 ㅁ ■  ㅇ
	이 때 보이는 ■는 양안시차가 적용된 이미지로,
	원근감이 느껴지게 된다.

	*/

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, 600, 800); // viewport L (오른쪽 눈으로 볼 이미지)
	glLoadIdentity();
	gluLookAt(-3.0, 4.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	glPushMatrix();
	glTranslatef(-1.0, 2.5, 3.0);
	glutSolidSphere(1.0, 50, 50); // 구 그리기
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 0.0, -7.0);
	glutSolidCube(5.0); // 큐브 그리기
	glPopMatrix();

	//-------------------------------------------------------------------//

	glViewport(600, 0, 600, 800); // viewport R (왼쪽 눈으로 볼 이미지)
	glLoadIdentity();
	gluLookAt(-3.5, 4.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	glPushMatrix();
	glTranslatef(-1.0, 2.5, 3.0);
	glutSolidSphere(1.0, 50, 50); // 구 그리기
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 0.0, -7.0);
	glutSolidCube(5.0); // 큐브 그리기
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
	glutCreateWindow("HW5_195511_이진우");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}