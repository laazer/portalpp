#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

#define SPEED_X 0.05

class Player : public IGameObject {

public:

	bool onGround;
	Player(Texture &image);
	void update(float time);
	void Collision(int num);
	void moveLeft();
	void moveRight();
};


#endif // PLAYER_H
