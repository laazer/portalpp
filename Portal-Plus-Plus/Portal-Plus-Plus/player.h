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
	
	// construct a player at a given position
	Player(Texture &image, int x, int y);

	~Player();

	// update the player's state based on the given elapsed time interval
	// since the last clock tick
	virtual void update(float time);

	// handle collisions with other game objects
	void Collision(int num);

	// make the player walk left at the defined walking speed
	void moveLeft();

	// increase the vertical velocity of the player in order to jump
	void jump();

	// make the player walk right at the defined walking speed
	void moveRight();

	// set the position of this player to the given x and y in pixel coordinates
	void setPos(float x, float y);

	// move the player back to the starting position of the level
	void resetPos();

	// represents the number of lives that the player has left before they lose
	int lives_remaining;

	// represents whether the player is on the ground or not
	bool onGround;

private:
	// represents the original position of the player when the level started
	sf::Vector2i m_original_pos;

};


#endif // PLAYER_H
