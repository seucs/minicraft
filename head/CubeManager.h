//
// Created by 朴智新 on 2017/4/13.
//

#pragma once

#include"TexCube.h"
#include<map>
#include<string>

class CubeManager {
public:
    void insertCube(const TexCube &texcube);

    CubeManager() {};

    ~CubeManager() {};

    void createAllCube();

    void buildPyramid(int x, int y, int z);

    void buildannexBuilding(int x, int y, int z);

    void buildPool(int x, int y, int z);

    void buildTree(int x, int y, int z);

    void buildDiamondBuilding(int x, int y, int z);

    bool isExist(string);

    map<string, TexCube> cubeMap;
};

void CubeManager::insertCube(const TexCube &texcube) {
    int x, y, z;
    x = texcube._x;
    y = texcube._y;
    z = texcube._z;
    string s = to_string(x) + "_" + to_string(y) + "_" + to_string(z);
    cubeMap[s] = texcube;
}

void CubeManager::createAllCube() {
    for (auto it : cubeMap) {
        it.second.createCube();
    }
}

bool CubeManager::isExist(string id) {
    return cubeMap.find(id) != cubeMap.end();
}

// …≥ƒÆ…ÒµÓ
void CubeManager::buildPyramid(int x, int y, int z) {
    for (int n = y; n <= 10; n++) {
        for (int i = x + n; i < 2 * 10 - n; i++) {
            for (int j = z + n; j < 2 * 10 - n; j++) {
                this->insertCube(TexCube(i, n, j, 1.0f, Sand));
            }
        }
    }
    for (int i = y; i < 4 + y; i++) {
        this->insertCube(TexCube(x + 7, i, z, 1.0f, Sand));
    }
    for (int i = y; i < 4 + y; i++) {
        this->insertCube(TexCube(x + 11, i, z, 1.0f, Sand));
    }
    for (int i = x + 8; i <= x + 10; i++) {
        for (int j = y + 3; j <= y + 5; j++) {
            this->insertCube(TexCube(i, j, z, 1.0f, Sand));
        }
    }
    this->insertCube(TexCube(x + 8, y + 4, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 10, y + 4, z, 1.0f, RedSand));
    this->buildannexBuilding(x, y, z);
    this->buildannexBuilding(x + 14, y, z);
}

// …≥ƒÆ…ÒµÓ∏Ω Ù–°¬•
void CubeManager::buildannexBuilding(int x, int y, int z) {
    for (int k = y; k < y + 9; k++) {
        for (int i = x; i < x + 5; i++) {
            for (int j = z; j < z + 5; j++) {
                this->insertCube(TexCube(i, k, j, 1.0f, Sand));
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->insertCube(TexCube(x + i + 1, y + 9, z + j + 1, 1.0f, Sand));
        }
    }
    this->insertCube(TexCube(x, y + 9, z + 2, 1.0f, Sand));
    this->insertCube(TexCube(x + 2, y + 9, z, 1.0f, Sand));
    this->insertCube(TexCube(x + 2, y + 9, z + 4, 1.0f, Sand));
    this->insertCube(TexCube(x + 4, y + 9, z + 2, 1.0f, Sand));
    this->insertCube(TexCube(x + 2, y + 1, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 2, y + 2, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 1, y + 3, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 3, y + 3, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 2, y + 4, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 1, y + 5, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 3, y + 5, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 1, y + 6, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 2, y + 6, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 3, y + 6, z, 1.0f, RedSand));
}

// ÀÆ≥ÿ
void CubeManager::buildPool(int x, int y, int z) {
    int num_cube = 4;
    for (int i = x + 1; i <= x + num_cube; i++) {
        for (int j = z + 1; j <= z + num_cube; j++) {
            this->insertCube(TexCube(i, y, j, 1.0f, Water));
        }
    }

    for (int i = x; i <= x + 1 + num_cube; i++) {
        this->insertCube(TexCube(i, y, z, 1.0f, Soil));
        this->insertCube(TexCube(i, y, z + num_cube + 1, 1.0f, Soil));
    }
    for (int i = z + 1; i <= z + num_cube; i++) {
        this->insertCube(TexCube(x, y, i, 1.0f, Soil));
        this->insertCube(TexCube(x + num_cube + 1, y, i, 1.0f, Soil));
    }
}

// ¥Û ˜
void CubeManager::buildTree(int x, int y, int z) {
    for (int i = y; i <= y + 5; i++) {
        this->insertCube(TexCube(x, i, z, 1.0f, Tree));
    }
    for (int n = 3; n > 0; n--) {
        for (int i = x - n; i <= x + n; i++) {
            for (int j = z - n; j <= z + n; j++) {
                this->insertCube(TexCube(i, y + 6 + (3 - n), j, 1.0f, Leaf));
            }
        }
    }
}

// ◊Í Ø–°¬•
void CubeManager::buildDiamondBuilding(int x, int y, int z) {
    for (int k = y; k < y + 9; k++) {
        for (int i = x; i < x + 5; i++) {
            for (int j = z; j < z + 5; j++) {
                this->insertCube(TexCube(i, k, j, 1.0f, Diamond));
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->insertCube(TexCube(x + i + 1, y + 9, z + j + 1, 1.0f, Diamond));
        }
    }
    this->insertCube(TexCube(x, y + 9, z + 2, 1.0f, Diamond));
    this->insertCube(TexCube(x + 2, y + 9, z, 1.0f, Diamond));
    this->insertCube(TexCube(x + 2, y + 9, z + 4, 1.0f, Diamond));
    this->insertCube(TexCube(x + 4, y + 9, z + 2, 1.0f, Diamond));
    this->insertCube(TexCube(x + 2, y + 1, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 2, y + 2, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 1, y + 3, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 3, y + 3, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 2, y + 4, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 1, y + 5, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 3, y + 5, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 1, y + 6, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 2, y + 6, z, 1.0f, RedSand));
    this->insertCube(TexCube(x + 3, y + 6, z, 1.0f, RedSand));
}