#pragma once
struct Point
{
	Point()
	{
		x = 0, y = 0;
	}

	Point(float xval, float yval)
	{
		x = xval;
		y = yval;
	}
	float x, y;
};