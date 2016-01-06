#include "Player.h"

Player::Player(Point p)
{
	m_position = p;
}


Player::~Player()
{
}

void Player::draw()
{
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
	sf2d_draw_fill_circle((int)m_position.x, (int)m_position.y, (int)(getSize() / 2), RGBA8(0xFF, 0xFF, 0x00, 0xFF));
	sf2d_end_frame();
}

void Player::setPosition(Point p)
{
	m_position = p;
}

void Player::move(int h, int v){
	
	if (h < 0 && m_position.x-getMovSpd() - getSize()/2>=0)
		m_position.x -= getMovSpd();
	else if (h>0 && m_position.x + getMovSpd() + getSize() / 2 <= SCREEN_SIZE_X)
		m_position.x += getMovSpd();
	if (v < 0 && m_position.y - getMovSpd() - getSize() / 2 >= 0)
		m_position.y -= getMovSpd();
	else if (v>0 && m_position.y + getMovSpd() + getSize() / 2 <= SCREEN_SIZE_Y)
		m_position.y += getMovSpd();
}

Point Player::getPosition(){
	return m_position;
}

void Player::setMovSpd(float v){
	if (v > 0)
		m_movespeed = v;
	else
		m_movespeed = 0;
}
float Player::getMovSpd(){
	return m_movespeed;
}
void Player::setSize(float v){
	if (v > 0)
		m_size = v;
	else
		m_size = 0;
}
float Player::getSize(){
	return m_size;
}
