#pragma once

#include"Cube.h"

//纹理相关设置
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

class TexCube : public Cube {
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
        : Cube() {
    _x = x;
    _y = y;
    _z = z;
    _size = size;
    switch (tex) {
        case Wood:
            _top = Cube::texWood;
            _bot = Cube::texWood;
            _side = Cube::texWood;
            break;
        case Water:
            _top = Cube::texWater;
            _bot = Cube::texWater;
            _side = Cube::texWater;
            break;
        case Soil:
            _top = Cube::texGrass;
            _bot = Cube::texGrass;
            _side = Cube::texSoil;
            break;
        case Stone:
            _top = Cube::texStone;
            _bot = Cube::texStone;
            _side = Cube::texStone;
            break;
        case RedStone:
            _top = Cube::texRedStone;
            _bot = Cube::texRedStone;
            _side = Cube::texRedStone;
            break;
        case Dirt:
            _top = Cube::texDirt;
            _bot = Cube::texDirt;
            _side = Cube::texDirt;
            break;
        case Brick:
            _top = Cube::texBrick;
            _bot = Cube::texBrick;
            _side = Cube::texBrick;
            break;
        case Table:
            _top = Cube::texTabletop;
            _bot = Cube::texTabletop;
            _side = Cube::texTableside;
            break;
        case Diamond:
            _top = Cube::texDiamond;
            _bot = Cube::texDiamond;
            _side = Cube::texDiamond;
            break;
        case Tnt:
            _top = Cube::texTnttop;
            _bot = Cube::texTnttop;
            _side = Cube::texTntside;
            break;
        case Tree:
            _top = Cube::texTreetop;
            _bot = Cube::texTreetop;
            _side = Cube::texTreeside;
            break;
        case Leaf:
            _top = Cube::texLeaf;
            _bot = Cube::texLeaf;
            _side = Cube::texLeaf;
            break;
        case Bookshelf:
            _top = Cube::texWood;
            _bot = Cube::texWood;
            _side = Cube::texBookshelf;
            break;
        case RedSand:
            _top = Cube::texRedSand;
            _bot = Cube::texRedSand;
            _side = Cube::texRedSand;
            break;
        case Sand:
            _top = Cube::texSand;
            _bot = Cube::texSand;
            _side = Cube::texSand;
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
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + size, y, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + size, y, z + size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y, z + size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y, z);
    glEnd();



    //侧面西
    glBindTexture(GL_TEXTURE_2D, _side);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + size, y, z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + size, z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + size, y + size, z);
    glEnd();


    //侧面东
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y, z + size);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + size, y, z + size);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + size, y + size, z + size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y + size, z + size);
    glEnd();



    //侧面南
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + size, y, z + size);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + size, y, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + size, y + size, z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + size, y + size, z + size);
    glEnd();
    //侧面北
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y, z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y, z + size);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + size, z + size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y + size, z);
    glEnd();

    //顶面
    glBindTexture(GL_TEXTURE_2D, _top);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y + size, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + size, z + size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + size, y + size, z + size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + size, y + size, z);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

TexCube::~TexCube() {
}
