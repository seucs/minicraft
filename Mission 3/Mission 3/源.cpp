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
	// head
	glColor3f(139.0 / 255, 115.0 / 255, 85.0 / 255);
	glPushMatrix();
	glTranslatef(man.head.x, man.head.y, man.head.z);
	glPushMatrix();
	glScalef(man.head_scale.x, man.head_scale.y, man.head_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	//// left eye
	//glColor3f(0.9f, 0.9f, 0.9f);
	//glPushMatrix();
	//glTranslatef(-0.05, 0.03, -0.05);
	//glScalef(0.2, 0.1, 0.2);
	//glutSolidCube(1);
	//glPopMatrix();

	//// right eye
	//glColor3f(0.9f, 0.9f, 0.9f);
	//glPushMatrix();
	//glTranslatef(-0.05, 0.03, 0.05);
	//glScalef(0.2, 0.1, 0.2);
	//glutSolidCube(1);
	//glPopMatrix();

	//// mouth
	//glColor3f(1, 1, 1);
	//glPushMatrix();
	//glTranslatef(-0.03, -0.02, 0);
	//glScalef(0.3, 0.1, 0.3);
	//glutSolidCube(1);
	//glPopMatrix();

	glPopMatrix();

	///////////////////////////Body////////////////////////////
	glColor3f(0.0f, 206.0 / 255, 209.0 / 255);
	glPushMatrix();
	glTranslatef(man.body.x, man.body.y, man.body.z);
	glScalef(man.body_scale.x, man.body_scale.y, man.body_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	/////////////////////////Leg/////////////////////////
	//Left leg
	glColor3f(67.0 / 255, 110.0 / 255, 238.0 / 255);
	glPushMatrix();
	glTranslatef(man.thighL.x, 2 * man.thighL.y, man.thighL.z);
	glRotatef(man.ltangle, 0, 0, 1);
	glTranslatef(0, -man.thighR.y, 0);
	glScalef(man.thigh_scale.x, man.thigh_scale.y, man.thigh_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	//Right leg
	glColor3f(67.0 / 255, 110.0 / 255, 238.0 / 255);
	glPushMatrix();
	glTranslatef(man.thighR.x,2 * man.thighR.y, man.thighR.z);
	glRotatef(man.rtangle, 0, 0, 1);
	glTranslatef(0, - man.thighR.y,0);
	glScalef(man.thigh_scale.x, man.thigh_scale.y, man.thigh_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	///////////////////////Arm////////////////////////

	//Left Arm
	glColor3f(139.0 / 255, 115.0 / 255, 85.0 / 255);
	glPushMatrix();
	glTranslatef(man.armL.x, man.arm_scale.y / 2 + man.armL.y, man.armL.z);
	glRotatef(man.laangle, 0, 0, 1);
	glTranslatef(0, -man.arm_scale.y / 2, 0);
	glScalef(man.arm_scale.x, man.arm_scale.y, man.arm_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	//Right Arm
	glColor3f(139.0 / 255, 115.0 / 255, 85.0 / 255);
	glPushMatrix();
	glTranslatef(man.armR.x, man.arm_scale.y / 2 + man.armR.y, man.armR.z);
	glRotatef(man.raangle, 0, 0, 1);
	glTranslatef(0, -man.arm_scale.y / 2, 0);
	glScalef(man.arm_scale.x, man.arm_scale.y, man.arm_scale.z);
	glutSolidCube(1);
	glPopMatrix();



	glPopMatrix();
}

void reference()
{
	glPolygonMode(GL_FRONT_AND_BACK, GLU_FILL);
	glutSolidCube(3);
}

void floor()
{
	glColor3f(0.3f, 1.0f, 0.3f);
	for (int i = 0; i < NUM_OF_LINE * 2; i++)
	{
		glBegin(GL_LINES);
		glVertex3f((NUM_OF_LINE - i) * BLOCK_SIZE, -1, NUM_OF_LINE * BLOCK_SIZE);
		glVertex3f((NUM_OF_LINE - i) * BLOCK_SIZE, -1, -NUM_OF_LINE * BLOCK_SIZE);
		glVertex3f(NUM_OF_LINE * BLOCK_SIZE, -1, (NUM_OF_LINE - i) * BLOCK_SIZE);
		glVertex3f(-NUM_OF_LINE * BLOCK_SIZE, -1, (NUM_OF_LINE - i) * BLOCK_SIZE);
		glEnd();
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	floor();
	human();
	reference();
	//crawler();

	glutSwapBuffers();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0, (GLfloat)scr_w / scr_h, near_sight, far_sight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (first_person)
	{
		cameraAt.x = man.x;
		cameraAt.y = man.head.y;
		cameraAt.z = man.z;

		lookAt.x = man.x - 5 * cos(man.vangle / 180.0 * PI);
		lookAt.y = man.hair.y;
		lookAt.z = man.z + 5 * sin(man.vangle / 180.0 * PI);
	}
	else
	{
		cameraAt.x = 5;
		cameraAt.y = 5;
		cameraAt.z = 5;

		lookAt.x = 0;
		lookAt.y = 0;
		lookAt.z = 0;
	}
	gluLookAt(cameraAt.x, cameraAt.y, cameraAt.z,
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
		if (man.ltangle < -60)
		{
			left_forward = false;
		}
		else if (man.ltangle > 60)
		{
			left_forward = true;
		}
		if (man.rtangle < -60)
		{
			right_forward = false;
		}
		else if (man.rtangle > 60)
		{
			right_forward = true;
		}
		if (left_forward)
		{
			man.ltangle--;
			man.laangle++;
		}
		else
		{
			man.ltangle++;
			man.laangle--;
		}
		if (right_forward)
		{
			man.rtangle--;
			man.raangle++;
		}
		else
		{
			man.rtangle++;
			man.raangle--;
		}

	}
	else 
	{
		man.raangle = 0;
		man.laangle = 0;
		man.rtangle = 0;
		man.ltangle = 0;
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
	gluPerspective(75.0, (GLfloat)scr_w / scr_h, near_sight, far_sight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//切换视角
	//gluLookAt(lookatX,lookatY,lookatZ,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	//gluLookAt(lookatX, lookatY, lookatZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		//视角放大
		if (state == GLUT_DOWN && near_sight * VIEW_SCALE > 5)
		{
			near_sight /= VIEW_SCALE;
			far_sight /= VIEW_SCALE;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(75.0, (float)scr_w / scr_h, near_sight, far_sight);
			//glMatrixMode(GL_MODELVIEW);
			//glLoadIdentity();
			//gluLookAt(lookatX * view_stretch, lookatY * view_stretch, lookatZ * view_stretch, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		// 视角收缩
		if (state == GLUT_DOWN && far_sight / VIEW_SCALE <1000)
		{
			near_sight *= VIEW_SCALE;
			far_sight *= VIEW_SCALE;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(75.0, (float)scr_w / scr_h, near_sight, far_sight);
			//glMatrixMode(GL_MODELVIEW);
			//glLoadIdentity();
			//gluLookAt(lookatX * view_stretch, lookatY * view_stretch, lookatZ * view_stretch, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		}
		break;
	}
}

void control(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		man.move = true;
		break;
	case 'd':
		man.move = true;
		break;
	case 'w':
		man.move = true;
		man.x -= man.speed * cos(man.vangle / 180 * PI);
		man.z += man.speed * sin(man.vangle / 180 * PI);
		break;
	case 's':
		man.move = true;
		man.x += man.speed * cos(man.vangle / 180 * PI);
		man.z -= man.speed * sin(man.vangle / 180 * PI);
		break;
	case 'h':
		first_person = !first_person;
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
		man.move = false;
		break;
	case 's':
		man.move = false;
		break;
	case 'a':
		man.move = false;
		break;
	case 'd':
		man.move = false;
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
	//glutSpecialFunc(SpecialKeys);
	glutMouseFunc(mouse);
	glutKeyboardUpFunc(controlup);
	glutKeyboardFunc(control);
	//glutIdleFunc(idle);
	//glutSetCursor

	glutMainLoop();
	return 0;
}