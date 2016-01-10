#include"Cube.h"
//纹理相关设置
GLuint texRedStone;
GLuint texGrass;
GLuint texSoil;
GLuint texStone;
GLuint texWater;
GLuint texWood;
enum CubeTex {
	Wood,
	Water,
	Soil,
	Stone,
	RedStone,
};

class TexCube :public Cube
{
public:
	TexCube(float, float, float, float,CubeTex);
	void createCube();
	~TexCube();
private:
	GLuint _top;
	GLuint _bot;
	GLuint _side;
};

TexCube::TexCube(float x, float y, float z, float size,CubeTex tex)
{
	_x = x;
	_y = y;
	_z = z;
	_size = size;
	switch (tex)
	{
	case Wood:
		_top = texWood;
		_bot = texWood;
		_side = texWood;
		break;
	case Water:
		_top = texWater;
		_bot = texWater;
		_side = texWater;
		break;
	case Soil:
		_top = texGrass;
		_bot = texGrass;
		_side = texSoil;
		break;
	case Stone:
		_top = texStone;
		_bot = texStone;
		_side = texStone;
	case RedStone:
		_top = texRedStone;
		_bot = texRedStone;
		_side = texRedStone;
	default:
		break;
	}
	Cube::Cube(x, y, z, size, _top, _bot, _side);
}

void TexCube::createCube() {
	float x = _x;
	float y = _y;
	float z = _z;
	float size = _size;
	glBindTexture(GL_TEXTURE_2D, _bot);
	glBegin(GL_QUADS);
	//底面
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + size, y, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y, z + size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z + size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();



	//侧面西
	glBindTexture(GL_TEXTURE_2D, _side);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + size, y, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + size, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z);
	glEnd();


	//侧面东
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + size, y, z + size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y + size, z + size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + size, z + size);
	glEnd();



	//侧面南
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + size, y, z + size);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + size, y, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + size, y + size, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z + size);
	glEnd();
	//侧面北
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + size);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + size, z + size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + size, z);
	glEnd();

	//顶面
	glBindTexture(GL_TEXTURE_2D, _top);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + size, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + size, z + size);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + size, y + size, z + size);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + size, y + size, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

TexCube::~TexCube()
{
}


