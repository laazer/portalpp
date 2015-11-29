#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

#define SPEED_X 0.15
#define GRAVITY 0.0009
#define JUMP_SIZE 0.4
#define DRAG 0.3
#define AIR_ACCELERATION 0.07
#define MAX_SPEED 0.7

class Player : public IGameObject {

public:

	bool onGround;
	Player(Texture &image);
	void update(float time);
	void Collision(int num);
	void moveLeft();
	void jump();
	void moveRight();
};


#endif // PLAYER_H
