#include "portal.h"
#include <math.h>

Portal::Portal(Texture &image, float x, float y, float target_x, float target_y, bool is_blue) {
	sprite.setTexture(image);
	sprite.setTextureRect(
		is_blue ?
		IntRect(0, 3 * UNIT + 5, UNIT, UNIT * 2) :
		IntRect(0, 5 * UNIT + 7, UNIT, UNIT * 2));
	rect = FloatRect(100, 180, UNIT, UNIT);
	is_vertical = true;
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
}

void Portal::update(float time) {
	if (is_projectile) {
		this->sprite.move(dx, dy);
	}
}


void Portal::Collision() {

}