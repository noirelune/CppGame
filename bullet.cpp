#include "bullet.h"
#include "player1.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <list>

bullet::bullet(std::string name, float posx, float posy, float cur_x, float cur_y, float sizeFactor)
{

	posx = getX(); // the bullet is created a little above the player
							//if that makes sense
	posy = getY() + 1.0f;
	pName = name;
	//list that keeps active bullets
	static std::list<bullet*> active_list;
	
	
}

bullet::~bullet()
{
}



void bullet::init()
{
	m_bullet_br = new graphics::Brush;
	m_bullet_br->fill_opacity = 1.0f;
	m_bullet_br->texture = GameState::instance()->getFullAssetDir("bull1.png");
	m_bullet_br->outline_opacity = 0.0f;
	active_list.push_back(*this);
	
}	

void bullet::draw()
{

	
	graphics::setOrientation(180); //the bullets move in a straight line

	graphics::drawRect(posx, posy, sizeFactor, sizeFactor, *m_bullet_br);

	graphics::resetPose; //idk if I need this command
}

void bullet::update(float dt)
{
	float deT = dt / 1500.0f;
	
	//shooting (hopefully)
	if (graphics::getKeyState(graphics::SCANCODE_Z))

		posy += deT * speedFavtor;


	//clearing screen if there are more than 20 bullets	
	if (active_list.size() > 20)

		for (bullet b : active_list)
			active_list.pop_front(); //popping from the front to remove the oldest bullets first
			bullet::~bullet(); //calling the destroyer method

			

}

float bullet::getX()
{
	return posx;
}

float bullet::getY()
{
	return posy;
}
