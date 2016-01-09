#include "Param.h"



//光源太阳
GLfloat s_angle = 0.0f;
GLfloat LightPosition[] = { 0.0f,0.0f,0.0f,1.0f };		//光源位置

GLfloat ambient = 0.2f;
GLfloat LightAmbient[] = { ambient,ambient,ambient,1.0f };		//环境光
GLfloat diffuse = 0.2f;
GLfloat LightDiffuse[] = { diffuse,0,0,1.0f };		//漫反射
GLfloat specular = 0.2f;
GLfloat LightSpecular[] = { specular,0.6f,0.6f,1.0f };	//镜面反射

														//材料参数
GLfloat matEmissionR, matEmissionG, matEmissionB;
GLfloat	MatEmission[] = { matEmissionR, matEmissionG, matEmissionB, 1.0f };
GLfloat matAmbientR, matAmbientG, matAmbientB;
GLfloat	MatAmbient[] = { matAmbientR, matAmbientG, matAmbientB, 1.0f };
GLfloat matDiffuseR, matDiffuseG, matDiffuseB;
GLfloat MatDiffuse[] = { matDiffuseR, matDiffuseG, matDiffuseB, 1.0f };
GLfloat matSpecularR, matSpecularG, matSpecularB;
GLfloat MatSpecular[] = { matSpecularR, matSpecularG, matSpecularB, 1.0f };
GLfloat MatShininess;

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
	glScalef(man.head_scale.x, man.head_scale.y, man.head_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	// left eye
	glColor3f(0.9f, 0.9f, 0.9f);
	glPushMatrix();
	glTranslatef(man.eyeL.x, man.eyeL.y, man.eyeL.z);
	glScalef(man.eye_scale.x, man.eye_scale.y, man.eye_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	// right eye
	glColor3f(0.9f, 0.9f, 0.9f);
	glPushMatrix();
	glTranslatef(man.eyeR.x, man.eyeR.y, man.eyeR.z);
	glScalef(man.eye_scale.x, man.eye_scale.y, man.eye_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	// mouth
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(man.mouth.x, man.mouth.y, man.mouth.z);
	glScalef(man.mouth_scale.x, man.mouth_scale.y, man.mouth_scale.z);
	glutSolidCube(1);
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
	glTranslatef(man.thighR.x, 2 * man.thighR.y, man.thighR.z);
	glRotatef(man.rtangle, 0, 0, 1);
	glTranslatef(0, -man.thighR.y, 0);
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
	glColor3f(0.3f, 0.2f, 0.3f);
	glPushMatrix();

	glScalef(1, 4, 1);
	glutSolidCube(1.2);
	glPopMatrix();
}



void floor()
{
	glColor3f(0.3f, 1.0f, 0.3f);
	int num_cube = 5;
	int i = 1;
	int j = 1;
	for (int i = num_cube;i >= (-num_cube);i--)
	{
		for (int j = num_cube;j >= (-num_cube);j--)
		{
			Cube* a = new Cube(i,0,j,1.0f,texGrass,texGrass,texSoil);
			a->createCube();
		}
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	
}

// 光源太阳
void sun()
{
	//cout << "ambient:" << ambient << endl;
	glPushMatrix();
	glRotated(s_angle, 1, 0, 0);
	glTranslatef(0.0f, 5.0f, 0.0f);

	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);		//设置环境光
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);		//设置漫射光
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);	//镜面光
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);	//设置光源位置

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	//绘制白色的太阳
	MatShininess = 0.01f;
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);

	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(0.2, 40, 40);
	glPopMatrix();
	glEnable(GL_COLOR_MATERIAL);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_BLEND);
	sun();

	glDisable(GL_BLEND);
	floor();
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	matDiffuseR = 1.0f, matDiffuseG = 1.0f, matDiffuseB = 0.0f;
	matSpecularR = 0.5f, matSpecularG = 0.5f, matSpecularB = 0.5f;
	MatShininess = 20.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);
	//reference();

	matDiffuseR = 0.2f, matDiffuseG = 0.2f, matDiffuseB = 0.0f;
	matSpecularR = 1.0f, matSpecularG = 1.0f, matSpecularB = 1.0f;
	MatShininess = 130.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	//human();

	glutSwapBuffers();


	if (view_person == FIRST_PERSON)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		cameraAt.x = man.x;
		cameraAt.y = man.head.y;
		cameraAt.z = man.z;

		lookAt.x = man.x + 5 * cos(man.vangle / 180.0 * PI);
		lookAt.y = man.hair.y;
		lookAt.z = man.z - 5 * sin(man.vangle / 180.0 * PI);

		gluLookAt(cameraAt.x, cameraAt.y, cameraAt.z,
			lookAt.x, lookAt.y, lookAt.z,
			0.0f, 1.0f, 0.0f);
	}
	else if (view_person == GOD)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		if (!reset_god)
		{
			cameraAt = godAt;
			lookAt.x = 0;
			lookAt.y = 0;
			lookAt.z = 0;
			reset_god = true;
		}

		gluLookAt(cameraAt.x, cameraAt.y, cameraAt.z,
			lookAt.x, lookAt.y, lookAt.z,
			0.0f, 1.0f, 0.0f);
	}
	else if (view_person == THIRD_PERSON)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		cameraAt.x = man.x - 10 * cos(man.vangle / 180.0 * PI);
		cameraAt.y = man.head.y + 10;
		cameraAt.z = man.z + 10 * sin(man.vangle / 180.0 * PI);

		lookAt.x = man.x;
		lookAt.y = man.hair.y;
		lookAt.z = man.z;

		gluLookAt(cameraAt.x, cameraAt.y, cameraAt.z,
			lookAt.x, lookAt.y, lookAt.z,
			0.0f, 1.0f, 0.0f);
	}
	else if (view_person == BALL)
	{
		cout << "123" << endl;
		if (trackballMove)
		{
			glRotatef(angle, axis[0], axis[1], axis[2]);
		}
	}
}

void init()
{
	glClearColor(0.0f, 0.25f, 0.4f, 0.0f);

	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);        // Do not calculate inside of jet
	glFrontFace(GL_CCW);        // Counter clock-wise polygons face out

	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glEnable(GL_COLOR_MATERIAL);
}

// 计算平面点对应跟踪球上的位置，返回值在v中
void trackball_ptov(int x, int y, int width, int height, float v[3])
{
	// 将x,y投影到在width和height范围内的半球面上
	float d, a;


	/// 坐标系变换，实现归一化x，y的范围为（-1,1）
	v[0] = (2.0F*x - width) / width;
	v[1] = (height - 2.0*y) / height;
	d = (float)sqrt(v[0] * v[0] + v[1] * v[1]);
	v[2] = (float)cos((PI / 2.0F) * ((d < 1.0F) ? d : 1.0F));	  // 一种对应方案，解决了如果点不在半球覆盖范围内的情况				
	a = 1 / (float)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]); // 归一化
	v[0] *= a;
	v[1] *= a;
	v[2] *= a;
}

void startMotion(int x, int y)
{
	cout << x << " " << y << endl;
	trackingMouse = true;
	redrawContinue = false;
	startX = x; startY = y;
	curx = x; cury = y;
	trackball_ptov(x, y, scr_w, scr_h, lastPos);
	trackballMove = true;
}

void stopMotion(int x, int y)
{
	trackingMouse = false;

	if (startX != x || startY != y)	 // 如果鼠标发生移动，则后面自动转动
	{
		cout << "startX:" << startX << "realX:" << x << endl;
		cout << "startY:" << startY << "realY:" << y << endl;
		redrawContinue = true;
	}
	else	// 如果按下鼠标后没有移动，则停止自动转动
	{
		angle = 0.0F;
		redrawContinue = false;
		trackballMove = false;

		//视角放大
		if (near_sight * VIEW_SCALE > 0.1)
		{
			/*near_sight /= VIEW_SCALE;
			far_sight /= VIEW_SCALE;*/
			cameraAt.x /= VIEW_SCALE;
			cameraAt.y /= VIEW_SCALE;
			cameraAt.z /= VIEW_SCALE;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(35.0, (float)scr_w / scr_h, near_sight, far_sight);
			//glMatrixMode(GL_MODELVIEW);
			//glLoadIdentity();
			//gluLookAt(lookatX * view_stretch, lookatY * view_stretch, lookatZ * view_stretch, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		}
	}
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
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		//视角放大
		if (state == GLUT_DOWN && near_sight * VIEW_SCALE > 5)
		{
			/*near_sight /= VIEW_SCALE;
			far_sight /= VIEW_SCALE;*/
			cameraAt.x /= VIEW_SCALE;
			cameraAt.y /= VIEW_SCALE;
			cameraAt.z /= VIEW_SCALE;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(35.0, (float)scr_w / scr_h, near_sight, far_sight);
			//glMatrixMode(GL_MODELVIEW);
			//glLoadIdentity();
			//gluLookAt(lookatX * view_stretch, lookatY * view_stretch, lookatZ * view_stretch, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		// 视角收缩
		if (state == GLUT_DOWN && far_sight / VIEW_SCALE <1000)
		{
			cameraAt.x *= VIEW_SCALE;
			cameraAt.y *= VIEW_SCALE;
			cameraAt.z *= VIEW_SCALE;
		}
		break;
	}
}

// 鼠标点击函数
void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		switch (state)
		{
		case GLUT_DOWN:
			//y = scr_h - y;
			startMotion(x, y);
			break;
		case GLUT_UP:
			stopMotion(x, y);
			break;

		}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		// 视角收缩
		if (state == GLUT_DOWN && far_sight / VIEW_SCALE <1000)
		{
			/*near_sight *= VIEW_SCALE;
			far_sight *= VIEW_SCALE;*/
			cameraAt.x *= VIEW_SCALE;
			cameraAt.y *= VIEW_SCALE;
			cameraAt.z *= VIEW_SCALE;
		}
	}
}
// 鼠标移动回调函数
void mouseMotion(int x, int y)
{
	float curPos[3], dx, dy, dz;

	trackball_ptov(x, y, scr_w, scr_h, curPos);

	if (trackingMouse)
	{
		// 计算差向量
		dx = curPos[0] - lastPos[0];
		dy = curPos[1] - lastPos[1];
		dz = curPos[2] - lastPos[2];

		// 三者不能同时为0，否则相当于没动
		if (dx || dy || dz)
		{
			// 计算旋转角度，旋转角度与sin角度近似
			angle = 90.0F * sqrt(dx*dx + dy*dy + dz*dz);

			// 计算叉积，得到旋转轴
			axis[0] = lastPos[1] * curPos[2] - lastPos[2] * curPos[1];
			axis[1] = lastPos[2] * curPos[0] - lastPos[0] * curPos[2];
			axis[2] = lastPos[0] * curPos[1] - lastPos[1] * curPos[0];

			// 保存新位置坐标
			lastPos[0] = curPos[0];
			lastPos[1] = curPos[1];
			lastPos[2] = curPos[2];
		}
	}
	glutPostRedisplay();
}
// 空闲回调函数
void idle()
{
	// 如果鼠标发生移动，则后面自动转动
	if (redrawContinue) glutPostRedisplay();
}
// 键盘输入
void control(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		man.move = true;
		man.x -= man.speed * sin(man.vangle / 180 * PI);
		man.z -= man.speed * cos(man.vangle / 180 * PI);
		break;
	case 'd':
		man.move = true;
		man.x += man.speed * sin(man.vangle / 180 * PI);
		man.z += man.speed * cos(man.vangle / 180 * PI);
		break;
	case 'w':
		man.move = true;
		man.x += man.speed * cos(man.vangle / 180 * PI);
		man.z -= man.speed * sin(man.vangle / 180 * PI);
		break;
	case 's':
		man.move = true;
		man.x -= man.speed * cos(man.vangle / 180 * PI);
		man.z += man.speed * sin(man.vangle / 180 * PI);
		break;
	case 'h':
		reset_god = false;
		if (view_person >= 3)
		{
			view_person = 0;
		}
		else
		{
			view_person++;
		}
		cout << view_person << endl;
		break;
	case 'r':
		if (view_person != 3)
		{
			last_view = view_person;
			view_person = 3;
		}
		else
		{
			view_person = last_view;
		}
		break;
	case 'o':
		s_angle++;
		glutPostRedisplay();
		break;
	case 'p':
		s_angle--;
		glutPostRedisplay();
		break;
	case '[':
		cout << "[\n";
		ambient += 0.1;
		glutPostRedisplay();
		break;
	case ']':
		ambient -= 0.1;
		glutPostRedisplay();
		break;
	case ';':
		diffuse += 0.1;
		glutPostRedisplay();
		break;
	case '\'':
		cout << "\'\n";
		diffuse -= 0.1;
		glutPostRedisplay();
		break;
	case ',':
		specular += 0.1;
		glutPostRedisplay();
		break;
	case '.':
		specular -= 0.1;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
	default:
		break;
	}

}
// 按键松开
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

	
	//启用2D纹理和材质初始化
	glEnable(GL_TEXTURE_2D);
	// 在这里做一些初始化
	glEnable(GL_DEPTH_TEST);
	glTexParameterf(GL_NEAREST, GL_TEXTURE_WRAP_S, GL_REPEAT);
	refresh(0);
	//纹理相关设置
	texGround = load_texture("ground.bmp");
	texWall = load_texture("wall.bmp");
	texLeaf = load_texture("leaf.bmp");
	texRedStone = load_texture("red.bmp");
	texGrass = load_texture("grass.bmp");
	texSoil = load_texture("soil.bmp");
	texStone = load_texture("stone.bmp");
	texWater = load_texture("water.bmp");
	texWood = load_texture("wood.bmp"); 

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(passiveMotion);

	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
	glutKeyboardUpFunc(controlup);
	glutKeyboardFunc(control);
	glutMainLoop();
	return 0;
}

