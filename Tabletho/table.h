	#include<GL/glut.h>
	#include<math.h>
	GLfloat MyVertex[][3] = {
		{ -0.25, -0.25, 0.25 },//v0
			{ -0.25, 0.25, 0.25 },//v1
			{ 0.25, 0.25, 0.25 },//v2
			{ 0.25, -0.25, 0.25 },//v3
		{ -0.25, -0.25, -0.25 },//v4
			{ -0.25, 0.25, -0.25 },//v5
			{ 0.25, 0.25, -0.25 },//v6
			{ 0.25, -0.25, -0.25 },//v7

	 };//Ź�ڱ׸��µ� �ʱ���ǥ]
	GLubyte MyQuadList[] = { 0, 3, 2, 1, 2, 3, 7, 6, 0, 4, 7, 3, 1, 2, 6, 5, 4, 5, 6, 7, 0, 1, 5, 4 };//Ź�ڱ׸��µ� ���̴¸���Ʈ��

	void makeTable(){
		   glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, MyVertex);
		glMatrixMode(GL_MODELVIEW);
	
				glPushMatrix();
		glScalef(3, 0.5, 3);//�����̴�
			for (int i = 0; i<6; i++)
					glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, &MyQuadList[4 * i]);
		glPopMatrix();
	
			glPushMatrix();//��ٸ� 1
	glScalef(0.5, 1, 0.5);
	glTranslatef(-1.0, -0.37, 1.1);
	
			for (int i = 0; i<6; i++)
					glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, &MyQuadList[4 * i]);
	glPopMatrix();
	
				glPushMatrix();//��ٸ� 2
			glScalef(0.5, 1, 0.5);
			glTranslatef(1, -0.37, 1.1);
	for (int i = 0; i<6; i++)
					glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, &MyQuadList[4 * i]);
			glPopMatrix();
	
				glPushMatrix(); //��ٸ�3
			glScalef(0.5, 1, 0.5);
			glTranslatef(1, -0.37, -1.1);
		for (int i = 0; i<6; i++)
					glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, &MyQuadList[4 * i]);
		glPopMatrix();
	
			glPushMatrix();//��ٸ�4
			glScalef(0.5, 1, 0.5);
			glTranslatef(-1.0, -0.37, -1.1);
		for (int i = 0; i<6; i++)
					glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, &MyQuadList[4 * i]);
		glPopMatrix();
	
}
