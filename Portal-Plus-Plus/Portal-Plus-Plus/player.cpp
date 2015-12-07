#include "player.h"

#define RIGHT_SPRITE IntRect(5 * UNIT + 10, 0, UNIT, UNIT)
#define LEFT_SPRITE IntRect(5 * UNIT + 10, UNIT, UNIT, UNIT)

Player::Player(Texture &image, int x, int y)
{
	sprite.setTexture(image);
	rect = FloatRect(x, y, 20, 22);
	sprite.setOrigin(rect.width / 2, rect.height / 2);
	sprite.setTextureRect(IntRect(5 * UNIT + 10, 0, UNIT, UNIT));
	dx = dy = 0;
	currentFrame = 0;
	lives_remaining = STARTING_LIVES;
	m_original_pos = sf::Vector2i(x, y);
}

void Player::update(float time)
{
	rect.left += dx * time;
	Collision(0);

	if (!onGround) {
		dy = dy + GRAVITY * time;
		if (dy > MAX_SPEED) {
			dy = MAX_SPEED;
		}
	}

	rect.top += dy * time;
	onGround = false;
	Collision(1);

	currentFrame += time * 0.005;

	if (currentFrame > 3) {
		currentFrame -= 3;
	}

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	
	if (onGround) {
		dx = 0;
	}
}

void Player::moveLeft() {
	if (onGround) {
		dx -= SPEED_X;
		
	}
	else {
		dx -= AIR_ACCELERATION;
	}
	sprite.setTextureRect(LEFT_SPRITE);
}

void Player::moveRight() {
	if (onGround) {
		dx += SPEED_X;

	}
	else {
		dx += AIR_ACCELERATION;
	}
	sprite.setTextureRect(RIGHT_SPRITE);
}

void Player::jump() {
	if (onGround) {
		dy = -JUMP_SIZE;
		onGround = false;
	}
}

void Player::setPos(float x, float y) {
	rect.top = UNIT * y;
	rect.left = UNIT * x;
}

void Player::resetPos() {
	rect = FloatRect(m_original_pos.x, m_original_pos.y, 20, 22);
	dx = dy = 0;
}

void Player::Collision(int num)
{
	for (int i = rect.top / UNIT; i < (rect.top + rect.height) / UNIT; i++)
		for (int j = rect.left / UNIT; j < (rect.left + rect.width) / UNIT; j++)
		{
			if (TileMap[i][j] == 'W' || TileMap[i][j] == 'F')
			{
				if (dy > 0 && num == 1) { //bottom collision
					rect.top = i*UNIT - rect.height;
					dy = 0;
					onGround = true;
				}
				if (dy < 0 && num == 1) { //top collsion
					rect.top = i*UNIT + UNIT;
					dy = 0;
				}
				if (dx > 0 && num == 0) { //collsion right
					rect.left = j*UNIT - rect.width;
				}
				if (dx < 0 && num == 0) { //collsion left
					rect.left = j*UNIT + UNIT;
				}
			}

		}
}

