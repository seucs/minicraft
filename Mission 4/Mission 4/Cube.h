#pragma once
#include "Param.h"
#define BMP_Header_Length 54

class Cube
{
public:
	Cube(float, float, float, float, GLuint, GLuint, GLuint);
	void createCube();
	static int power_of_two(int n);
	static GLuint load_texture(const char* file_name);
	static void initCubeTexture();
	~Cube();	
public:
	float _x, _y, _z, _size;
public:
	static GLuint texRedStone;
	static GLuint texGrass;
	static GLuint texSoil;
	static GLuint texStone;
	static GLuint texWater;
	static GLuint texWood;
	static GLuint texDirt;
	static GLuint texBrick;
	static GLuint texTabletop;
	static GLuint texTableside;
	static GLuint texDiamond;
	static GLuint texTnttop;
	static GLuint texTntside;
	static GLuint texTreetop;
	static GLuint texTreeside;
	static GLuint texLeaf;
	static GLuint texBookshelf;
	static GLuint texRedSand;
	static GLuint texSand;
protected:
	Cube() {};
	GLuint _top, _bot, _side;
};

Cube::Cube(float x, float y, float z, float size, GLuint top, GLuint bot, GLuint side)
	:_x(x), _y(y), _z(z), _size(size), _top(top), _bot(bot), _side(side)
{
}

Cube::~Cube()
{
}

// 检查一个整数是否为2的整数次方，如果是，返回1，否则返回0
int Cube::power_of_two(int n)
{
	if (n <= 0)
		return 0;
	return (n & (n - 1)) == 0;
}

//读取一个BMP文件作为纹理
GLuint Cube::load_texture(const char* file_name)
{
	GLint width, height, total_bytes;
	GLubyte* pixels = 0;
	GLuint last_texture_ID = 0, texture_ID = 0;

	// 打开文件，如果失败，返回
	FILE* pFile = fopen(file_name, "rb");
	if (pFile == 0)
		return 0;

	// 读取文件中图象的宽度和高度
	fseek(pFile, 0x0012, SEEK_SET);
	fread(&width, 4, 1, pFile);
	fread(&height, 4, 1, pFile);
	fseek(pFile, BMP_Header_Length, SEEK_SET);

	// 计算每行像素所占字节数，并根据此数据计算总像素字节数
	{
		GLint line_bytes = width * 3;
		while (line_bytes % 4 != 0)
			++line_bytes;
		total_bytes = line_bytes * height;
	}

	// 根据总像素字节数分配内存
	pixels = (GLubyte*)malloc(total_bytes);
	if (pixels == 0)
	{
		fclose(pFile);
		return 0;
	}

	// 读取像素数据
	if (fread(pixels, total_bytes, 1, pFile) <= 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	// 在旧版本的OpenGL中
	// 如果图象的宽度和高度不是的整数次方，则需要进行缩放
	// 这里并没有检查OpenGL版本，出于对版本兼容性的考虑，按旧版本处理
	// 另外，无论是旧版本还是新版本，
	// 当图象的宽度和高度超过当前OpenGL实现所支持的最大值时，也要进行缩放
	{
		GLint max;
		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);
		if (!power_of_two(width)
			|| !power_of_two(height)
			|| width > max
			|| height > max)
		{
			const GLint new_width = 256;
			const GLint new_height = 256; // 规定缩放后新的大小为边长的正方形
			GLint new_line_bytes, new_total_bytes;
			GLubyte* new_pixels = 0;

			// 计算每行需要的字节数和总字节数
			new_line_bytes = new_width * 3;
			while (new_line_bytes % 4 != 0)
				++new_line_bytes;
			new_total_bytes = new_line_bytes * new_height;

			// 分配内存
			new_pixels = (GLubyte*)malloc(new_total_bytes);
			if (new_pixels == 0)
			{
				free(pixels);
				fclose(pFile);
				return 0;
			}

			// 进行像素缩放
			gluScaleImage(GL_RGB,
				width, height, GL_UNSIGNED_BYTE, pixels,
				new_width, new_height, GL_UNSIGNED_BYTE, new_pixels);

			// 释放原来的像素数据，把pixels指向新的像素数据，并重新设置width和height
			free(pixels);
			pixels = new_pixels;
			width = new_width;
			height = new_height;

		}
	}

	// 分配一个新的纹理编号
	glGenTextures(1, &texture_ID);
	if (texture_ID == 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	// 绑定新的纹理，载入纹理并设置纹理参数
	// 在绑定前，先获得原来绑定的纹理编号，以便在最后进行恢复
	GLint lid = last_texture_ID;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &lid);
	glBindTexture(GL_TEXTURE_2D, texture_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, last_texture_ID);

	// 之前为pixels分配的内存可在使用glTexImage2D以后释放
	// 因为此时像素数据已经被OpenGL另行保存了一份（可能被保存到专门的图形硬件中）
	free(pixels);

	return texture_ID;
}

void Cube::createCube() {
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
//初始化材质
void Cube::initCubeTexture()
{
	texRedStone = Cube::load_texture("img/redStone.bmp");
	texGrass = Cube::load_texture("img/grass.bmp");
	texSoil = Cube::load_texture("img/soil.bmp");
	texStone = Cube::load_texture("img/stone.bmp");
	texWater = Cube::load_texture("img/water.bmp");
	texWood = Cube::load_texture("img/wood.bmp");
	texDirt = Cube::load_texture("img/dirt.bmp");;
	texBrick = Cube::load_texture("img/brick.bmp");
	texTabletop = Cube::load_texture("img/tabletop.bmp");
	texTableside = Cube::load_texture("img/tableside1.bmp");
	texDiamond = Cube::load_texture("img/diamond.bmp");
	texTnttop = Cube::load_texture("img/tnttop.bmp");
	texTntside = Cube::load_texture("img/tntside.bmp");
	texTreetop = Cube::load_texture("img/treetop.bmp");
	texTreeside = Cube::load_texture("img/treeside.bmp");
	texLeaf = Cube::load_texture("img/leaf.bmp");
	texBookshelf = Cube::load_texture("img/bookshelf.bmp");
	texRedSand = Cube::load_texture("img/redsand.bmp");
	texSand = Cube::load_texture("img/sand.bmp");
}

GLuint Cube::texRedStone = 0;
GLuint Cube::texGrass = 0;
GLuint Cube::texSoil = 0;
GLuint Cube::texStone = 0;
GLuint Cube::texWater = 0;
GLuint Cube::texWood = 0;
GLuint Cube::texDirt = 0;
GLuint Cube::texBrick = 0;
GLuint Cube::texTabletop = 0;
GLuint Cube::texTableside = 0;
GLuint Cube::texDiamond = 0;
GLuint Cube::texTnttop = 0;
GLuint Cube::texTntside = 0;
GLuint Cube::texTreetop = 0;
GLuint Cube::texTreeside = 0;
GLuint Cube::texLeaf = 0;
GLuint Cube::texBookshelf = 0;
GLuint Cube::texRedSand = 0;
GLuint Cube::texSand = 0;