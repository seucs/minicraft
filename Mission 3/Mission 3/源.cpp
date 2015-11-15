#include "Param.h"

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	GLfloat ambientLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // 明亮的白光
	glEnable(GL_DEPTH_TEST);    // Hidden surface removal
	glEnable(GL_CULL_FACE);        // Do not calculate inside of jet
	glFrontFace(GL_CCW);        // Counter clock-wise polygons face out

	glEnable(GL_COLOR_MATERIAL);  // 开启颜色追踪
	glEnable(GL_LIGHTING);

	//设置混色函数取得半透明效果
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	//glShadeModel(GL_SMOOTH);
	//glEnable(GL_BLEND);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight); // 设置光照模型

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);  // 设置颜色追踪的材料属性以及多边形的面
}

void human()
{
	// 人
	glPushMatrix();
	glTranslatef(man.x, man.y, man.z);
	glRotatef(man.vangle, 0, 1, 0);

	////////////////////////////Hair//////////////////////////
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(man.hair.x, man.hair.y, man.hair.z);
	glScalef(man.hair_scale.x, man.hair_scale.y, man.hair_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	///////////////////////////Head////////////////////////////
	glColor3f(139.0 / 255, 115.0 / 255, 85.0 / 255);
	glPushMatrix();
	glTranslatef(man.head.x, man.head.y, man.head.z);
	glPushMatrix();
	glScalef(man.head_scale.x, man.head_scale.y, man.head_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	// left eye
	glColor3f(0.9f, 0.9f, 0.9f);
	glPushMatrix();
	glTranslatef(-0.05, 0.03, -0.05);
	glScalef(0.2, 0.1, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	// right eye
	glColor3f(0.9f, 0.9f, 0.9f);
	glPushMatrix();
	glTranslatef(-0.05, 0.03, 0.05);
	glScalef(0.2, 0.1, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	// mouth
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(-0.03, -0.02, 0);
	glScalef(0.3, 0.1, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

	///////////////////////////Body////////////////////////////
	glColor3f(0.0f, 206.0 / 255, 209.0 / 255);
	glPushMatrix();
	glTranslatef(man.body.x, man.body.y, man.body.z);
	glScalef(man.body_scale.x, man.body_scale.y, man.body_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	/////////////////////////Leg/////////////////////////
	glColor3f(67.0 / 255, 110.0 / 255, 238.0 / 255);
	glPushMatrix();
	glRotatef(left_thigh_angle, 0, 0, 1);
	glTranslatef(thighL[0], thighL[1], thighL[2]);
	glScalef(THIGH_SCALE_X, THIGH_SCALE_Y, THIGH_SCALE_Z);
	glutSolidCube(basic_size);
	glPopMatrix();

	//Right leg
	glColor3f(67.0 / 255, 110.0 / 255, 238.0 / 255);
	glPushMatrix();
	glRotatef((GLfloat)right_thigh_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(thighR[0], thighR[1], thighR[2]);
	glScalef(THIGH_SCALE_X, THIGH_SCALE_Y, THIGH_SCALE_Z);
	glutSolidCube(basic_size);
	glPopMatrix();

	///////////////////////Arm////////////////////////

	//Left Arm
	glColor3f(139.0 / 255, 115.0 / 255, 85.0 / 255);
	glPushMatrix();
	glTranslatef(0.0f, basic_size * BODY_SCALE_Y, 0.0f);
	glRotatef((GLfloat)left_arm_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(armL[0], armL[1], armL[2]);
	glScalef(ARM_SCALE_X, ARM_SCALE_Y, ARM_SCALE_Z);
	glutSolidCube(basic_size);
	glPopMatrix();

	//Right Arm
	glColor3f(139.0 / 255, 115.0 / 255, 85.0 / 255);
	glPushMatrix();
	glTranslatef(0.0f, basic_size * BODY_SCALE_Y, 0.0f);
	//Arm
	glRotatef((GLfloat)right_arm_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(armR[0], armR[1], armR[2]);
	glScalef(ARM_SCALE_X, ARM_SCALE_Y, ARM_SCALE_Z);
	glutSolidCube(basic_size);
	glPopMatrix();



	glPopMatrix();
}

void crawler()
{
	glPushMatrix();
	glRotatef(c_vangle, 0, 1, 0);
	glTranslatef(crawler_x, crawler_y, crawler_z);

	//head
	glColor3f(0.0f, 130.0 / 255, 0.0f);
	glPushMatrix();
	glTranslatef(hair[0], hair[1], hair[2]);
	glScalef(1, 1, 1);
	glutSolidCube(basic_size);

	// left eye
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.1, 0.03, -0.05);
	glScalef(0.3, 0.3, 0.3);
	glutSolidCube(basic_size);
	glPopMatrix();

	// right eye
	glPushMatrix();
	glTranslatef(-0.1, 0.03, 0.05);
	glScalef(0.3, 0.3, 0.3);
	glutSolidCube(basic_size);
	glPopMatrix();

	// mouth
	glColor3f(0, 0, 0);
	glTranslatef(-0.1, -0.1, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidCube(basic_size);

	glPopMatrix();

	//body
	glColor3f(0.0f, 130.0 / 255, 0.0f);
	glPushMatrix();
	glTranslatef(hair[0], hair[1] - 0.3, hair[2]);
	glScalef(0.7, 3, 0.7);
	glutSolidCube(basic_size);
	glPopMatrix();

	//leg
	glPushMatrix();
	glTranslatef(hair[0], hair[1] - 0.7, hair[2]);
	glScalef(1, 1, 1);
	glutSolidCube(basic_size);
	glPopMatrix();

	glPopMatrix();
}

void floor()
{
	glColor3f(0.3f, 1.0f, 0.3f);
	for (int i = 0; i < NUM_OF_LINE * 2; i++)
	{
		glBegin(GL_LINES);
		glVertex3f((NUM_OF_LINE - i) * BLOCK_SIZE + floor_move_x, -basic_size * (BODY_SCALE_Y + THIGH_SCALE_X) / 2, NUM_OF_LINE * BLOCK_SIZE);
		glVertex3f((NUM_OF_LINE - i) * BLOCK_SIZE + floor_move_x, -basic_size * (BODY_SCALE_Y + THIGH_SCALE_X) / 2, -NUM_OF_LINE * BLOCK_SIZE);
		glVertex3f(NUM_OF_LINE * BLOCK_SIZE, -basic_size * (BODY_SCALE_Y + THIGH_SCALE_X) / 2, (NUM_OF_LINE - i) * BLOCK_SIZE - floor_move_y);
		glVertex3f(-NUM_OF_LINE * BLOCK_SIZE, -basic_size * (BODY_SCALE_Y + THIGH_SCALE_X) / 2, (NUM_OF_LINE - i) * BLOCK_SIZE - floor_move_y);
		glEnd();
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	floor();
	human();
	crawler();

	glutSwapBuffers();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	lookAt.x = man.x - 5 * cos(vangle / 180.0 * PI);
	lookAt.y = basic_size * (BODY_SCALE_Y + THIGH_SCALE_X) / 2;
	lookAt.z = man.z + 5 * sin(vangle / 180.0 * PI);
	gluLookAt(man.x, man.y, man.z,
		lookAt.x, lookAt.y, lookAt.z,
		0.0f, 1.0f, 0.0f);
	//cout <<"x:"<< human_x <<"y:"<< human_y<<"z:"<< human_z<< endl;

}

void passiveMotion(int x, int y)
{
	man.vangle = (man.vangle - (x - scr_w / 2) / 150);
}

void refresh(int c)
{
	//center.y = -(1 - sin(-left_thigh_angle / 180.0 * PI)) * basic_size * THIGH_SCALE_X + basic_size * FOOT_SCALE_Y / 2;
	if (man.isMoving())
	{
		if (left_thigh_angle < -120)
		{
			left_forward = false;
		}
		else if (left_thigh_angle > -60)
		{
			left_forward = true;
		}
		if (right_thigh_angle < -120)
		{
			right_forward = false;
		}
		else if (right_thigh_angle > -60)
		{
			right_forward = true;
		}
		if (left_forward)
		{
			left_thigh_angle--;
			left_arm_angle += 1.0;
			left_forearm_angle += 0.5;
		}
		else
		{
			left_thigh_angle++;
			left_arm_angle -= 1.0;
			left_forearm_angle -= 0.5;
		}
		if (right_forward)
		{
			right_thigh_angle--;
			right_arm_angle += 1.0;
			right_forearm_angle += 0.5;
		}
		else
		{
			right_thigh_angle++;
			right_arm_angle -= 1.0;
			right_forearm_angle -= 0.5;
		}

	}
	else {
		right_arm_angle = -90;
		left_arm_angle = -90;
		right_thigh_angle = -90;
		left_thigh_angle = -90;
	}
	glutTimerFunc(DELAY, refresh, 0);
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	scr_w = w;
	scr_h = h;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0, (GLfloat)scr_w / (GLfloat)scr_h, near_sight * view_stretch, far_sight * view_stretch);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//切换视角
	//gluLookAt(lookatX,lookatY,lookatZ,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	gluLookAt(lookatX, lookatY, lookatZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			//视角放大收缩
			if (near_sight * view_stretch > 0.5)
				view_stretch *= STRETCH_SCALE;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(75.0, (GLfloat)scr_w / (GLfloat)scr_h, near_sight * view_stretch, far_sight * view_stretch);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(lookatX * view_stretch, lookatY * view_stretch, lookatZ * view_stretch, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{
			//减小收缩
			if (far_sight * view_stretch < 1000.0)
				view_stretch /= STRETCH_SCALE;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(75.0, (GLfloat)scr_w / (GLfloat)scr_h, near_sight * view_stretch, far_sight * view_stretch);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(lookatX * view_stretch, lookatY * view_stretch, lookatZ * view_stretch, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		}
		break;
	}
}

void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		xRot -= 5.0f;

	if (key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if (key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if (key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if (key > 356.0f)
		xRot = 0.0f;

	if (key < -1.0f)
		xRot = 355.0f;

	if (key > 356.0f)
		yRot = 0.0f;

	if (key < -1.0f)
		yRot = 355.0f;

	// 刷新窗口
	glutPostRedisplay();
}

void control(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		man_move = true;
		vangle = (vangle + 4) % 360;
		break;
	case 'd':
		man_move = true;
		vangle = (vangle - 4) % 360;
		break;
	case 'w':
		/*vangle = -(180 - vangle) % 360;*/
		man_move = true;
		human_x -= INCREMENT * cos((double)vangle / 180.0 * PI);
		human_z += INCREMENT * sin((double)vangle / 180.0 * PI);
		//dx = INCREMENT ;
		break;
	case 's':
		/*vangle = -(180 - vangle) % 360;*/
		human_x += INCREMENT * cos((double)vangle / 180.0 * PI);
		human_z -= INCREMENT * sin((double)vangle / 180.0 * PI);
		man_move = true;
		break;
	case 'z':
		c_vangle = (c_vangle + 4) % 360;
		break;
	case 'x':
		c_vangle = (c_vangle - 4) % 360;
		break;
	case 'c':
		crawler_x += INCREMENT;
		break;
	case 'v':
		crawler_x -= INCREMENT;
		break;
	case 'j':
		//向左
		p_air.x -= 0.05;
		break;
	case 'l':
		//向右
		p_air.x += 0.05;
		break;
	case 'i':
		//向前
		p_air.z -= 0.05;
		break;
	case 'k':
		//向后
		p_air.z += 0.05;
		break;
	case 'o':
		//上升
		p_air.y += 0.05;
		break;
	case 'p':
		//下降
		p_air.y -= 0.05;
		break;
	case 'r':
		//各位置复位
		p_air.x = 1.0;
		p_air.y = 1.0;
		p_air.z = 1.0;
		break;
	case 27:
		exit(0);
	default:
		break;
	}

}

void controlup(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		man_move = false;
		break;
	case 's':
		man_move = false;
		break;
	case 'a':
		man_move = false;
		break;
	case 'd':
		man_move = false;
		break;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Passenger and plane");
	init();
	refresh(0);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(passiveMotion);
	glutSpecialFunc(SpecialKeys);
	glutMouseFunc(mouse);
	glutKeyboardUpFunc(controlup);
	glutKeyboardFunc(control);
	//glutIdleFunc(idle);
	//glutSetCursor

	glutMainLoop();
	return 0;
}