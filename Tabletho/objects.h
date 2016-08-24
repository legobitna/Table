#include<GL/glut.h>
#include<math.h>

float points[][2] = { { 0.3, 0.0 }, { 0.25, 0.4 }, { 0.5, 0.1 }, { 0.4, 0.65 } };//�ű׸��µ� �ʱ���ǥ
float cupData[760][3];//�ű׸���
float circleData[200][3];//����� ��
float lineData[200][3];//����� ���
float quadData[400][3];//�� �׸���

int k = 0;
int l = 0;
int c = 0;
float radius = 0.5;//����� �׸��µ� ������

const double ToRadian = 3.141592 / 180.0;//���Ȱ�

void computeCoord(){  //�� �׸���

	double phi, theta;
	for (phi = -80; phi <= 80.0; phi += 20.0){//�����ڸ��� ������ �ڸ����� �浵�� �ѹ��� �߸��� ������ 180���� ������ �ȴ� 
		double phiR = phi* ToRadian;
		double phiR20 = (phi + 20.0)*ToRadian;//20�� ���� ��
		for (theta = -180; theta <= 180.0; theta += 20){//�浵�ڸ���
			double thetaR = theta*ToRadian;
			double x1 = sin(thetaR)*cos(phiR);
			double y1 = cos(thetaR)*cos(phiR);
			double z1 = sin(phiR);
			quadData[k][0] = x1;
			quadData[k][1] = y1;
			quadData[k][2] = z1;
			k++;
			x1 = sin(thetaR)*cos(phiR20);
			y1 = cos(thetaR)*cos(phiR20);
			z1 = sin(phiR20);
			quadData[k][0] = x1;
			quadData[k][1] = y1;
			quadData[k][2] = z1;
			k++;
		}
	}k = 0;//���� ��ü�׸��µ� �������� k�� �ʱ�ȭ
}
void cylinder()//����� �׸���
{
	double phi;
	double y;

	for (y = 0.5; y >= -0.5; y -= 1.0)//���׸���
	{
		circleData[k][0] = 0.0;
		circleData[k][1] = y;
		circleData[k][2] = 0.0;

		k++;

		for (phi = 0.0; phi <= 360.0; phi += 20.0)
		{
			double phiR = phi * ToRadian;

			double x = radius * cos(phiR);
			double z = radius * sin(phiR);

			circleData[k][0] = x;
			circleData[k][1] = y;
			circleData[k][2] = z;

			k++;
		}
	}

	for (phi = 0.0; phi <= 360.0; phi += 20.0)//����� �׸���
	{
		double phiR = phi * ToRadian;

		double x = radius * cos(phiR);
		double z = radius * sin(phiR);

		lineData[l][0] = x;
		lineData[l][1] = 0.5;
		lineData[l][2] = z;

		l++;

		lineData[l][0] = x;
		lineData[l][1] = -0.5;
		lineData[l][2] = z;

		l++;
	}


}
void cup(){//�ű׸���
	double  theta;
	for (float alpha = 0.0f; alpha <= 1.0f; alpha += 0.05){
		float px = (1 - alpha)*(1 - alpha)*(1 - alpha)*points[0][0] + 3 * (1 - alpha)*(1 - alpha)*alpha*points[1][0] + 3 * (1 - alpha)*alpha*alpha*points[2][0] + alpha*alpha*alpha*points[3][0];//������ �����
		float py = (1 - alpha)*(1 - alpha)*(1 - alpha)*points[0][1] + 3 * (1 - alpha)*(1 - alpha)*alpha*points[1][1] + 3 * (1 - alpha)*alpha*alpha*points[2][1] + alpha*alpha*alpha*points[3][1];
		float px1 = (1 - (alpha + 0.05))*(1 - (alpha + 0.05))*(1 - (alpha + 0.05))*points[0][0] + 3 * (1 - (alpha + 0.05))*(1 - (alpha + 0.05))*(alpha + 0.05)*points[1][0] + 3 * (1 - (alpha + 0.05))*(alpha + 0.05)*(alpha + 0.05)*points[2][0] + (alpha + 0.05)*(alpha + 0.05)*(alpha + 0.05)*points[3][0];//0.05���� ��(���� ��������)
		float py1 = (1 - (alpha + 0.05))*(1 - (alpha + 0.05))*(1 - (alpha + 0.05))*points[0][1] + 3 * (1 - (alpha + 0.05))*(1 - (alpha + 0.05))*(alpha + 0.05)*points[1][1] + 3 * (1 - (alpha + 0.05))*(alpha + 0.05)*(alpha + 0.05)*points[2][1] + (alpha + 0.05)*(alpha + 0.05)*(alpha + 0.05)*points[3][1];

		for (theta = -180; theta <= 180.0; theta += 20){
			float radian = ToRadian*theta;
			cupData[c][0] = px*sin(radian);
			cupData[c][1] = py;
			cupData[c][2] = px*cos(radian);
			c++;


			cupData[c][0] = px1*sin(radian);
			cupData[c][1] = py1;
			cupData[c][2] = px1*cos(radian);
			c++;

		}
	}
}
void drawObjects(){




	glScalef(0.2, 0.2, 0.2);//���� ũ������
	glTranslatef(-1, 1.55, -1);//���� ��ġ����
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i<304; i++){  //���׸���
		glVertex3fv(quadData[i]);
	}


	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i<36; i += 2){
		glVertex3f(0, 0, -1);
		glVertex3fv(quadData[i]);
	}
	for (int i = 267; i<304; i += 2){
		glVertex3f(0, 0, 1);
		glVertex3fv(quadData[i]);
	}
	glEnd();


	glScalef(1.5, 1.5, 1.5);//������� ũ������
	glTranslatef(0, -0.1, 1.8);//������� ��ġ���� 
	glBegin(GL_TRIANGLE_FAN);

	for (int idx = 0; idx < k / 2; idx++)
		glVertex3fv(circleData[idx]);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	for (int idx = k / 2; idx < k; idx++)
		glVertex3fv(circleData[idx]);

	glEnd();

	glBegin(GL_LINES);
	for (int idx = 0; idx < l; idx++)
		glVertex3fv(lineData[idx]);
	glEnd();

	glScalef(0.7, 0.7, 0.7);//�������� ũ������ 
	glTranslatef(2.5, 0, -2);//�������� ũ������ 
	glutWireTeapot(1);//������ �׸��� 

	glScalef(1.5, 1.5, 1.5);
	glTranslatef(0, -0.5, 1.5);
	glBegin(GL_QUAD_STRIP);//�ű׸���
	for (int i = 0; i<760; i++){
		glVertex3fv(cupData[i]);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);//�� �ؿ� �ݱ�
	glVertex3f(0, 0, 0);
	for (int i = 0; i<40; i += 2) {
		glVertex3fv(cupData[i]);
	}
	glEnd();

}
