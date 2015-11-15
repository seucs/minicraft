#pragma once
#include "Point.h"

class Man
{
public:
	float basic_size = 0.25;
	Point hair_scale, head_scale, thigh_scale, body_scale, arm_scale;
	Point head, hair, body, thighL, thighR, armL, armR;
	float x, y, z;
	float vangle = 0;
	float lthigh_angle = -60;
	float rthigh_angle = -120;
	bool move = false;
public:
	// 构造函数
	Man()
	{
		resetSize(basic_size);
	}
	// 重绘人物
	void resetSize(float new_basic)
	{
		this->basic_size = new_basic;
		// 比例控制
		hair_scale = Point(0.5, 0.3, 0.75, basic_size);
		head_scale = Point(0.5, 0.5, 0.75, basic_size);
		thigh_scale = Point(1.4, 0.4, 0.4, basic_size);
		body_scale = Point(0.75, 1.25, 0.75, basic_size);
		arm_scale = Point(1.3, 0.3, 0.3, basic_size);

		// 相对位置控制
		head = Point(0, body_scale.y + head_scale.y / 2, 0, basic_size);
		hair = Point(0, body_scale.y + head_scale.y + head_scale.y / 2, 0, basic_size);
		body = Point(0, body_scale.y / 2, 0, basic_size);
		thighL = Point(thigh_scale.x / 2, 0, thigh_scale.z / 2, basic_size);
		thighR = Point(thigh_scale.x / 2, 0, -thigh_scale.z / 2, basic_size);
		armL = Point(arm_scale.x / 2, 0, (arm_scale.z + body_scale.z) / 2, basic_size);
		armR = Point(arm_scale.x / 2, 0, -(arm_scale.z + body_scale.z) / 2, basic_size);

	}
	// 是否正在走动
	bool isMoving()
	{
		return move;
	}
	// 设置人物坐标
	void setLocation(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};