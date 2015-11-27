#ifndef ENEMY_H
#define ENEMY_H

#include "game_object.h"

class Enemy : public IGameObject
{

public:
	bool life;
	void set(Texture &image, int x, int y);
	void update(float time);
	void Collision();

};

#endif // ENEMY_H
