#include<GL/glut.h>
#include<math.h>
#include"Table.h"
#include"Objects.h"

GLfloat gXAngle, gYAngle, gZAngle;//로테이트 값을 받을 변수
void myDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);



	glLoadIdentity();
	glRotatef(gXAngle, 1.0, 0.0, 0.0);//키보드 누를떄마다 로테이트 각이 바뀜 
	glRotatef(gYAngle, 0.0, 1.0, 0.0);
	glRotatef(gZAngle, 0.0, 0.0, 1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	makeTable();

	drawObjects();



	glutSwapBuffers();

}

void gSetPos(int dir)//키보드 값마다 로테이트값 바뀜 
{
	switch (dir)
	{
	case 1:
		gYAngle += 10.0f;
		break;
	case 2:
		gYAngle -= 10.0f;
		break;
	case 3:
		gXAngle += 10.0f;
		break;
	case 4:
		gXAngle -= 10.0f;
		break;
	case 5:
		gZAngle += 10.0f;
		break;
	case 6:
		gZAngle -= 10.0f;
		break;
	}
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
	//q,w,e,a,s,d 을 누르면 테이블 전체가 회전이 된다 
	//z로 종료하기
	switch (KeyPressed)
	{
	case 'Z':
	case 'z':
		exit(0);
		break;

	case 'W':
	case 'w':
		gSetPos(1);//y++
		break;
	case 'S':
	case 's':
		gSetPos(2);//y--
		break;
	case 'Q':
	case 'q':
		gSetPos(3);//x++
		break;
	case 'A':
	case 'a':
		gSetPos(4);//x--
		break;
	case 'E':
	case 'e':
		gSetPos(5);//z++
		break;
	case 'd':
	case 'D':
		gSetPos(6);//z--
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();//다시 그려주기
}

void myInit(){//초기화라를 여기서해줌 
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv){
	computeCoord();
	cup();
	cylinder();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);

	myInit();
	glutCreateWindow("Table");

	glutDisplayFunc(myDisplay);//display callback function
	glLoadIdentity();
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}
