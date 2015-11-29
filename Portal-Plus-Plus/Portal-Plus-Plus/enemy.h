#ifndef ENEMY_H
#define ENEMY_H

#include "game_object.h"

#define ENEMY_SPEED 0.14

class Enemy : public IGameObject
{

public:
	bool life;
	void set(Texture &image, int x, int y);
	void update(float time);
	void Collision();

};

#endif // ENEMY_H
