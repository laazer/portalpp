#include "enemy.h"

void Enemy::set(Texture &image, int x, int y)
{
	sprite.setTexture(image);
	rect = FloatRect(x, y, UNIT, UNIT);

	dx = 0.05;
	currentFrame = 0;
	life = true;
}

void Enemy::update(float time)
{
	rect.left += dx * time;

	Collision();

	currentFrame += time * 0.005;

	if (currentFrame > 2) {
		currentFrame -= 2;
	}

	sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, UNIT, UNIT));

	if (!life) {
		sprite.setTextureRect(IntRect(58, 0, UNIT, UNIT));
	}
	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
}

void Enemy::Collision()
{

	for (int i = rect.top / UNIT; i < (rect.top + rect.height) / UNIT; i++) {
		for (int j = rect.left / UNIT; j < (rect.left + rect.width) / UNIT; j++) {
			if (TileMap[i][j] == 'W') {
				if (dx > 0) {
					rect.left = (j * UNIT) - rect.width;
					dx *= -1;
				}
				else if (dx < 0) {
					rect.left = (j * UNIT) + UNIT;
					dx *= -1;
				}
			}
		}
	}
}
