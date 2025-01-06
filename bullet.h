#pragma once
#include "sgg/graphics.h"
#include "GameState.h"
#include "GameObject.h"
#include <string>
#include "cursor.h"


class bullet : public GameObject
{
private:
	
	graphics::Brush* m_bullet_br = nullptr;
	float posx = 0.0f;
	float posy = 0.0f;
	float sizeFactor = 0.5;
	float speedFavtor = 7.5;
	std::string pName = "";
	bool hostile = false; //true if it comes from an enemy
public:

	bullet(std::string name);
	~bullet();
	void init();
	void draw();
	void update(float dt);
	float getX();
	float getY();

}; 
	