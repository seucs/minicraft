#pragma once

#include <iostream>
#include <cmath>
#include <gl/GLUT.h>
#include "Point.h"
#include "Crawler.h"
#include "Man.h"
using namespace std;

#define DELAY 12
#define NUM_OF_LINE 32
#define BLOCK_SIZE 1
#define VIEW_SCALE 2
#define PI 3.1415926535898


//相对坐标常量
//const double INCREMENT = 0.05;

// 世界参数
Point center = Point(0, 0, 0);
Point lookAt = Point(5, 5, 5);
Point cameraAt = Point(5, 5, 5);
bool first_person = false;
float near_sight = 10;
float far_sight = 200;
int scr_w;
int scr_h;


// 物体
Man man;
//Crawler crawler;

//相对坐标参数
bool left_forward = true;
bool right_forward = false;
bool look_from_left = true;
