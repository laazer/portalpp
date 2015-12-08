#include "enemy.h"


#define RIGHT_ENEMY IntRect(0, 0, UNIT, UNIT)
#define LEFT_ENEMY IntRect(UNIT, 0, UNIT, UNIT)
#define DEAD_ENEMY IntRect(58, 0, UNIT, UNIT)
#define ENEMY_MAP_CHARACTER 'X'

void Enemy::set(Texture &image, int x, int y)
{
	sprite.setTexture(image);
	sprite.setTextureRect(RIGHT_ENEMY);
	rect = FloatRect(x, y, UNIT, UNIT);

	dx = ENEMY_SPEED;
	life = true;
}

void Enemy::update(float time)
{
	rect.left += dx * time;

	Collision();

	if (!life) {
		sprite.setScale(0, 0);
	}
	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
}

void Enemy::Collision()
{

	for (int i = rect.top / UNIT; i < (rect.top + rect.height) / UNIT; i++) {
		for (int j = rect.left / UNIT; j < (rect.left + rect.width) / UNIT; j++) {
			if (World::TileMap[i][j] != ' ' && World::TileMap[i][j] != ENEMY_MAP_CHARACTER) {
				dx *= -1;
				if (dx < 0) {
					sprite.setTextureRect(LEFT_ENEMY);
				}
				else {
					sprite.setTextureRect(RIGHT_ENEMY);
				}
			}
		}
	}
}
