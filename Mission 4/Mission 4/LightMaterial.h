#pragma once
#include <iostream>
#include <time.h>
#include <GL\GLUT.h>
using namespace std;

#define COLOR_WHITE		1.0f,1.0f,1.0f
#define	COLOR_GREY		0.8f,0.8f,0.8f
#define COLOR_BLACK		0.0f,0.0f,0.0f
#define COLOR_CYAN		0.1f,0.6f,0.6f
#define COLOR_BLUE		0.06f,0.3f,0.3f
#define COLOR_GREEN		0.2f,0.6f,0.2f
#define COLOR_RED		0.6f,0.2f,0.2f
#define COLOR_YELLOW	1.0f,0.725f,0.125f

//光源位置参数
GLfloat light_Distance = 50.0f;	//光源和原点的距离
GLfloat light_Angle = 0.0f;		//光源的角度

//光照参数
const GLfloat gloabal_Ambient[]	= { 0.0f,0.0f,0.0f,0.0f,1.0 };		//全局环境光

const GLfloat light0_Ambient[]	= { 0.02f,0.1f,0.1f,1.0f };	//环境光，影响没有正对光源的地方，会覆盖材料的漫射光属性
const GLfloat light0_Diffuse[]	= { COLOR_BLUE,1.0f };			//漫射光，正对光源的地方会显示出漫射光的颜色，会覆盖材料的漫射光属性
const GLfloat light0_Specular[]	= { COLOR_BLUE,1.0f };			//镜面光，材料必须有对应的反射光属性才会显示
const GLfloat light0_Emission[]	= { COLOR_BLUE, 0.0f };			//自发光
const GLfloat light0_Position[]	= { 1.0f,0.0f,0.0f,0.0f };		//位置

const GLfloat light1_Ambient[]	= { 0.2f,0.2f,0.2f,1.0f };		//环境光	
const GLfloat light1_Diffuse[]	= { COLOR_GREY,1.0f };			//漫射光
const GLfloat light1_Specular[]	= { COLOR_GREY,1.0f };			//镜面光
const GLfloat light1_Emission[]	= { COLOR_GREY, 1.0f };			//自发光
const GLfloat light1_Position[]	= { -1.0f,0.0f,0.0f,0.0f };		//位置

const GLfloat torch_Ambient[] = { 0.185f, 0.151f, 0.025f,1.0f };	//环境光	
const GLfloat torch_Diffuse[] = { 0.185f, 0.151f, 0.025f,1.0f };	//漫射光
const GLfloat torch_Specular[] = { 0.625f, 0.625f, 0.425f, 1.0f };	//镜面光
const GLfloat torch_Emission[] = { 0.625f, 0.625f, 0.425f, 1.0f };	//自发光
const GLfloat torch_Position[] = { 0.0f, 0.0f, 0.0f, 1.0f };		//位置

const GLfloat torch_Constant[] = { 0.002f };						//常量衰减系数
const GLfloat torch_Linear[] = { 0.02f };						//一次衰减系数
const GLfloat torch_Quadratic[] = { 0.0f };						//二次衰减系数

bool light0_Status = false;
bool light1_Status = false;

//材质0
GLfloat	mat0_Ambient[]		= { COLOR_RED, 1.0f };
GLfloat mat0_Diffuse[]		= { COLOR_RED, 1.0f };
GLfloat mat0_Specular[]		= { COLOR_BLACK, 1.0f };
GLfloat mat0_Emission[]		= { COLOR_BLACK, 1.0f };
GLfloat mat0_Shininess[]	= { 0.0f };

//材质1
GLfloat	mat1_Ambient[]		= { COLOR_BLACK, 1.0f };
GLfloat mat1_Diffuse[]		= { COLOR_BLACK, 1.0f };
GLfloat mat1_Specular[]		= { COLOR_GREEN, 1.0f };
GLfloat mat1_Emission[]		= { COLOR_BLACK, 1.0f };
GLfloat mat1_Shininess[]	= { 120.0f };

//材质2
GLfloat	mat2_Ambient[]		= { COLOR_BLACK, 1.0f };
GLfloat mat2_Diffuse[]		= { COLOR_BLACK, 1.0f };
GLfloat mat2_Specular[]		= { COLOR_BLACK, 1.0f };
GLfloat mat2_Emission[]		= { COLOR_BLACK, 1.0f };
GLfloat mat2_Shininess[]	= { 0.0f };

clock_t lightSpeed = 1030;
clock_t lastTime;
clock_t nowTime;	//判断过了多少秒


class LightMaterial
{
public:
	LightMaterial();
	void setLight();
	void setTorch(GLfloat x, GLfloat y, GLfloat z);
	void setMaterial(int type);
	void setBackGround();

private:
	GLfloat*** material;
	GLfloat** material0;
	GLfloat** material1;
	GLfloat** material2;
};

LightMaterial::LightMaterial()
{
	material0 = new GLfloat*[5];
	material0[0] = mat0_Ambient;
	material0[1] = mat0_Diffuse;
	material0[2] = mat0_Emission;
	material0[3] = mat0_Specular;
	material0[4] = mat0_Emission;
	material0[5] = mat0_Shininess;

	material1 = new GLfloat*[5];
	material1[0] = mat1_Ambient;
	material1[1] = mat1_Diffuse;
	material1[2] = mat1_Emission;
	material1[3] = mat1_Specular;
	material1[4] = mat1_Emission;
	material1[5] = mat1_Shininess;

	material2 = new GLfloat*[5];
	material2[0] = mat2_Ambient;
	material2[1] = mat2_Diffuse;
	material2[2] = mat2_Emission;
	material2[3] = mat2_Specular;
	material2[4] = mat2_Emission;
	material2[5] = mat2_Shininess;

	material = new GLfloat**[3];
	material[0] = material0;
	material[1] = material1;
	material[2] = material2;
};

void LightMaterial::setBackGround()
{
	GLfloat brightness = 0.5*sin((2 * PI*(float)((int)light_Angle % 360) / 360.0) + PI) + 0.5;
	//cout << brightness << endl;
	glClearColor(brightness* 123 / 255.0, brightness* 184 / 255.0, brightness, 1.0f);
}

void LightMaterial::setLight()
{
	//全局环境光
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gloabal_Ambient);

	glPushMatrix();
	glRotatef(light_Angle, 0.0f, 0.0f, 1.0f);	//旋转

	//0号光源设置(月亮）
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_Diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_Specular);

	//0号光源绘制
	glPushMatrix();
	glTranslated(light_Distance, 0, 0);
	glColor3f(COLOR_BLUE);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_Position);
	glMaterialfv(GL_FRONT, GL_EMISSION, light0_Emission);
	glutSolidSphere(1, 500, 500);
	glPopMatrix();

	//1号光源设置（太阳）
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_Diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_Specular);

	//1号光源绘制
	glPushMatrix();
	glTranslated(-light_Distance, 0, 0);
	glColor3f(COLOR_RED);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_Position);
	glMaterialfv(GL_FRONT, GL_EMISSION, light1_Emission);
	glutSolidSphere(2, 500, 500);
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glPopMatrix();

	if (((int)light_Angle % 360 > 0 && (int)light_Angle % 360 < 180) ||
		((int)light_Angle % 360 < -180 && (int)light_Angle % 360 > -360))
	{
		glEnable(GL_LIGHT0);
		light0_Status = true;
		glDisable(GL_LIGHT1);
		light1_Status = false;
	}
	else
	{
		glEnable(GL_LIGHT1);
		light1_Status = true;
		glDisable(GL_LIGHT0);
		light0_Status = false;
	}

	//光源自动运行
	nowTime = clock();
	if (nowTime - lastTime > lightSpeed)
	{
		lastTime = nowTime;
		light_Angle ++;
	}

	//glLightfv(GL_LIGHT0, GL_CONSTANT_ATTENUATION, light0_Constant);
	//glLightfv(GL_LIGHT0, GL_LINEAR_ATTENUATION, light0_Linear);
	//glLightfv(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, light0_Quadratic);
}

void LightMaterial::setTorch(GLfloat x, GLfloat y, GLfloat z)
{
	glLightfv(GL_LIGHT2, GL_AMBIENT, torch_Ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, torch_Diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, torch_Specular);

	glLightfv(GL_LIGHT2, GL_CONSTANT_ATTENUATION, torch_Constant);
	glLightfv(GL_LIGHT2, GL_LINEAR_ATTENUATION, torch_Linear);
	glLightfv(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, torch_Quadratic);


	glPushMatrix();
	glTranslated(x, y, z);
	glColor3f(0.925f, 0.725f, 0.125f);
	glLightfv(GL_LIGHT2, GL_POSITION, torch_Position);
	glMaterialfv(GL_FRONT, GL_EMISSION, torch_Emission);
	glScalef(1.0f, 5.0f, 1.0f);
	glutSolidCube(0.1);
	glPopMatrix();

	glEnable(GL_LIGHT2);
}

void LightMaterial::setMaterial(int type)
{
	if (type < 3)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, material[type][0]);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, material[type][1]);
		glMaterialfv(GL_FRONT, GL_SPECULAR, material[type][2]);
		glMaterialfv(GL_FRONT, GL_SHININESS, material[type][3]);
		glMaterialfv(GL_FRONT, GL_EMISSION, material[type][4]);
		glMaterialfv(GL_FRONT, GL_SHININESS, material[type][5]);
	}
}