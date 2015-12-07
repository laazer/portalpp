#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

#define SPEED_X 0.15
#define GRAVITY 0.0009
#define JUMP_SIZE 0.4
#define DRAG 0.3
#define AIR_ACCELERATION 0.003
#define MAX_SPEED 0.7
#define STARTING_LIVES 3

class Player : public IGameObject {

public:

	Player() = default;
	Player(Texture &image, int x, int y);
	void update(float time);
	void Collision(int num);
	void moveLeft();
	void jump();
	void moveRight();
	void setPos(float x, float y);
	void resetPos();

	int lives_remaining;
	bool onGround;

private:
	sf::Vector2i m_original_pos;
};


#endif // PLAYER_H
