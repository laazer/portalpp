#include "portal.h"
#include <math.h>

Portal::Portal(Texture &image, float x, float y, float target_x, float target_y, bool is_blue) {
	m_is_blue = is_blue;
	sprite.setTexture(image);
	sprite.setTextureRect(
		is_blue ?
		IntRect(0, 3 * UNIT + 5, UNIT, 10) :
		IntRect(0, 5 * UNIT + 7, UNIT, 10));
	wall = NONE;
	this->sprite.setPosition(x, y);
	// calculate the unit vector in the correct direction to the target
	float x_component = target_x - x;
	float y_component = target_y - y;
	float magnitude = sqrt(x_component * x_component + y_component * y_component);
	x_component /= magnitude;
	y_component /= magnitude;
	dx = x_component * PORTAL_SPEED;
	dy = y_component * PORTAL_SPEED;
	is_projectile = true;
	rect = FloatRect(x, y, 16, 64);
	sprite.setOrigin(sprite.getOrigin().x + rect.width / 2,
		sprite.getOrigin().y + rect.height / 2);
}

void Portal::update(float time) {
	if (is_projectile) {
		this->sprite.move(dx, dy);
		rect.top = rect.top + dy;
		rect.left = rect.left + dx;
		Collision();
	}
}


void Portal::Collision() {

	int top = (int)(rect.top / UNIT);
	top = top >= 0 ? top : 0;

	int bottom = (int)((rect.top + rect.height) / UNIT);
	bottom = bottom < H ? bottom : H - 1;

	int left = (int)(rect.left / UNIT);
	left = left > 0 ? left : 0;

	int right = (int)((rect.left + rect.width) / UNIT);
	right = right < W ? right : W - 1;

	bool top_left = TileMap[top][left] == 'W';
	bool top_right = TileMap[top][right] == 'W';
	bool bottom_left = TileMap[bottom][left] == 'W';
	bool bottom_right = TileMap[bottom][right] == 'W';

	if (top_left && top_right) {
		is_projectile = false;
		wall = TOP;
		sprite.setTextureRect(
			m_is_blue ?
			IntRect(0, 3 * UNIT + 5, UNIT, UNIT * 2) :
			IntRect(0, 5 * UNIT + 7, UNIT, UNIT * 2));
		sprite.setRotation(90);
	}
	else if (bottom_left && bottom_right) {
		is_projectile = false;
		wall = BOTTOM;
		sprite.setTextureRect(
			m_is_blue ?
			IntRect(0, 3 * UNIT + 5, UNIT, UNIT * 2) :
			IntRect(0, 5 * UNIT + 7, UNIT, UNIT * 2));
		sprite.setRotation(90);
	}
	else if (top_left && bottom_left) {
		is_projectile = false;
		wall = LEFT;
		sprite.setTextureRect(
			m_is_blue ?
			IntRect(0, 3 * UNIT + 5, UNIT, UNIT * 2) :
			IntRect(0, 5 * UNIT + 7, UNIT, UNIT * 2));
	}
	else if (top_right && bottom_right) {
		is_projectile = false;
		wall = RIGHT;
		sprite.setTextureRect(
			m_is_blue ?
			IntRect(0, 3 * UNIT + 5, UNIT, UNIT * 2) :
			IntRect(0, 5 * UNIT + 7, UNIT, UNIT * 2));
	}
}