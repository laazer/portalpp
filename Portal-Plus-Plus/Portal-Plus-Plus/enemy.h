#ifndef ENEMY_H
#define ENEMY_H

#include "game_object.h"
#include "world.h"

#define ENEMY_SPEED 0.14

// represents an enemy that can kill the player
class Enemy : public IGameObject
{

public:
	// is the enemy still alive?
	bool life;

	// set the texture of this enemy and its position
	void set(Texture &image, int x, int y);

	// move the enemy based on the elapsed time since the last clock tick
	virtual void update(float time);

	// handle collsions between the enemy and other game objects
	void Collision();

};

#endif // ENEMY_H
