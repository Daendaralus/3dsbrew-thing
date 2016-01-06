#pragma once
#include "ICollidable.h"
#include "I2DRenderable.h"
class Player : public I2DRenderable, public ICollidable
{
public:
	Player(Point);
	~Player();

	void draw();
	void move(int, int);
	void setMovSpd(float);
	float getMovSpd();
	void setSize(float);
	float getSize();

	Point getPosition();
private:
	Point m_position;
	void setPosition(Point);
	float m_movespeed;
	float m_size;
};

