#pragma once

struct Point
{
	float x, y, z;
	Point(float x, float y, float z, float basic_size = 1)
	{
		this->x = x * basic_size;
		this->y = y * basic_size;
		this->z = z * basic_size;
	}
	Point()
	{

	}
	void setPoint(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};