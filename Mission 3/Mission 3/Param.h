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
#define PI 3.1415926535898


//相对坐标常量
//const static double PI = acos(-1.0);
//const double INCREMENT = 0.05;

// 世界参数
Point center = Point(0, 0, 0);
Point lookAt = Point(5, 5, 5);
float near_sight = 1;
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

double floor_move_x = 0.0;
double floor_move_y = 0.0;
double view_stretch = 5.0;


GLfloat dx = 0;


float right_thigh_angle = -120;
float left_arm_angle = -115;
float left_forearm_angle = -30;
float right_arm_angle = -75;
float right_forearm_angle = -15;
