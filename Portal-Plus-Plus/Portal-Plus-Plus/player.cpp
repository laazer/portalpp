#include "player.h"

Player::Player(Texture &image)
{
	sprite.setTexture(image);
	rect = FloatRect(100, 180, 20, UNIT);
	dx = dy = 0.1;
	currentFrame = 0;
}

void Player::update(float time)
{
	rect.left += dx * time;
	Collision(0);

	if (!onGround) {
		dy = dy + 0.0005 * time; //gravity
	}

	rect.top += dy * time;
	onGround = false;
	Collision(1);

	currentFrame += time * 0.005;

	if (currentFrame > 3) {
		currentFrame -= 3;
	}

	if (dx > 0) {
		sprite.setTextureRect(IntRect(5 * UNIT + 10, 0, UNIT, UNIT));
	}
	if (dx < 0) {
		sprite.setTextureRect(IntRect(5 * UNIT + 10, 0, UNIT, UNIT));
	}
	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	dx = 0;
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

