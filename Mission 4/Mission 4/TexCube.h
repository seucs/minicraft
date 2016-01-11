#pragma once
#include"Cube.h"
//纹理相关设置
GLuint texRedStone;
GLuint texGrass;
GLuint texSoil;
GLuint texStone;
GLuint texWater;
GLuint texWood;
GLuint texDirt;
GLuint texBrick;
GLuint texTabletop;
GLuint texTableside;
GLuint texDiamond;
GLuint texTnttop;
GLuint texTntside;
GLuint texTreetop;
GLuint texTreeside;
GLuint texLeaf;
GLuint texBookshelf;
GLuint texRedSand;
GLuint texSand;
enum CubeTex {
	Wood,
	Water,
	Soil,
	Stone,
	RedStone,
	Dirt,
	Brick,
	Table,
	Diamond,
	Tnt,
	Tree,
	Leaf,
	Bookshelf,
	RedSand,
	Sand
};

class TexCube :public Cube
{
public:
	TexCube(float, float, float, float, CubeTex);
	TexCube() {};
	void createCube();
	~TexCube();
private:
	GLuint _top;
	GLuint _bot;
	GLuint _side;
};

TexCube::TexCube(float x, float y, float z, float size, CubeTex tex)
	:Cube()
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
		break;
	case RedStone:
		_top = texRedStone;
		_bot = texRedStone;
		_side = texRedStone;
		break;
	case Dirt:
		_top = texDirt;
		_bot = texDirt;
		_side = texDirt;
		break;
	case Brick:
		_top = texBrick;
		_bot = texBrick;
		_side = texBrick;
		break;
	case Table:
		_top = texTabletop;
		_bot = texTabletop;
		_side = texTableside;
		break;
	case Diamond:
		_top = texDiamond;
		_bot = texDiamond;
		_side = texDiamond;
		break;
	case Tnt:
		_top = texTnttop;
		_bot = texTnttop;
		_side = texTntside;
		break;
	case Tree:
		_top = texTreetop;
		_bot = texTreetop;
		_side = texTreeside;
		break;
	case Leaf:
		_top = texLeaf;
		_bot = texLeaf;
		_side = texLeaf;
		break;
	case Bookshelf:
		_top = texWood;
		_bot = texWood;
		_side = texBookshelf;
		break;
	case RedSand:
		_top = texRedSand;
		_bot = texRedSand;
		_side = texRedSand;
		break;
	case Sand:
		_top = texSand;
		_bot = texSand;
		_side = texSand;
		break;
	default:
		break;
	}
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
