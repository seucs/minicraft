// Visual Ball
// Created by Shengjia Yan
// 2016-1-9
#pragma once
#include "Param.h"

float curPos[3], dx, dy, dz;

// trackball
// 在 mouseMotion() 中加入此函数
void trackball_ptov(int x, int y, int width, int height, float v[3])
{
	float d, a;

	v[0] = (2.0F*x - width) / width;
	v[1] = (height - 2.0*y) / height;
	d = (float)sqrt(v[0] * v[0] + v[1] * v[1]);
	v[2] = (float)cos((PI / 2.0F) * ((d < 1.0F) ? d : 1.0F));
	a = 1 / (float)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	v[0] *= a;
	v[1] *= a;
	v[2] *= a;
}

// 在 mouseMotion() 中加入此函数，加在 trackball_ptov() 之后
void trackMouse()
{
  if (trackingMouse)
	{
		dx = curPos[0] - lastPos[0];
		dy = curPos[1] - lastPos[1];
		dz = curPos[2] - lastPos[2];

		if (dx || dy || dz)
		{
			angle = 90.0F * sqrt(dx*dx + dy*dy + dz*dz);

			axis[0] = lastPos[1] * curPos[2] - lastPos[2] * curPos[1];
			axis[1] = lastPos[2] * curPos[0] - lastPos[0] * curPos[2];
			axis[2] = lastPos[0] * curPos[1] - lastPos[1] * curPos[0];

			lastPos[0] = curPos[0];
			lastPos[1] = curPos[1];
			lastPos[2] = curPos[2];
		}
	}
}

void startMotion(int x, int y)
{
	trackingMouse = true;
	redrawContinue = false;
	startX = x; startY = y;
	curx = x; cury = y;
	trackball_ptov(x, y, scr_w, scr_h, lastPos);
	trackballMove = true;
}

void stopMotion(int x, int y)
{
	trackingMouse = false;
	angle = 0.0F;
	redrawContinue = false;
	trackballMove = false;
}
