#include "portal.h"
#include <math.h>

#define PORTAL_HEIGHT 60
#define PORTAL_WIDTH 40

Portal::Portal(Texture &image, float x, float y, float target_x, float target_y, bool is_blue) {
	m_is_blue = is_blue;
	sprite.setTexture(image);
	sprite.setTextureRect(
		is_blue ?
		IntRect(0, 3 * UNIT + 20, UNIT, 10) :
		IntRect(0, 5 * UNIT + 20, UNIT, 10));
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
	rect = FloatRect(x - 2, y - 2, 14, 14);
	sprite.setOrigin(rect.width / 2, rect.height / 2);
}

void Portal::update(float time) {
	if (is_projectile) {
		this->sprite.move(dx, dy);
		rect.top = rect.top + dy;
		rect.left = rect.left + dx;
		Collision();
	}
}

void Portal::teleport(Player * player, Portal * to_portal) {	
	float orig_x_vel = player->dx;
	float orig_y_vel = player->dy;
	float new_x_vel;
	float new_y_vel;
	
	Wall to_portal_wall = to_portal->wall;
	// don't do anything if both portals aren't on a wall yet
	if (to_portal_wall == NONE || wall == NONE) {
		return;
	}
	
	// switch the velocity magnitudes if necessary without setting their signs yet
	if (wall == TOP || wall == BOTTOM) {
		if (to_portal_wall == TOP || to_portal_wall == BOTTOM) {
			new_x_vel = orig_x_vel;
			new_y_vel = orig_y_vel;
		}
		else {
			new_x_vel = orig_y_vel;
			new_y_vel = orig_x_vel;
		}
	}
	else if (wall == LEFT || wall == RIGHT) {
		if (to_portal_wall == LEFT || to_portal_wall == RIGHT) {
			new_x_vel = orig_x_vel;
			new_y_vel = orig_y_vel;
		}
		else {
			new_x_vel = orig_y_vel;
			new_y_vel = orig_x_vel;
		}
	}
	int new_top;
	int new_left;

	// fix the signs of the new velocities
	if (to_portal_wall == TOP) {
		new_y_vel = new_y_vel > 0 ? new_y_vel : -new_y_vel;
		new_top = to_portal->rect.top + PORTAL_WIDTH + 2;
		new_left = to_portal->rect.left + PORTAL_HEIGHT / 2;
	}
	else if (to_portal_wall == BOTTOM) {
		new_y_vel = new_y_vel < 0 ? new_y_vel : -new_y_vel;
		new_top = to_portal->rect.top - PORTAL_WIDTH - player->rect.height - 2;
		new_left = to_portal->rect.left + PORTAL_HEIGHT / 2;
	}
	else if (to_portal_wall == LEFT) {
		new_x_vel = new_x_vel > 0 ? new_x_vel : -new_x_vel;
		new_top = to_portal->rect.top + PORTAL_HEIGHT / 2;
		new_left = to_portal->rect.left + PORTAL_WIDTH + 2;
	}
	else if (to_portal_wall == RIGHT) {
		new_x_vel = new_x_vel < 0 ? new_x_vel : -new_x_vel;
		new_top = to_portal->rect.top + PORTAL_HEIGHT / 2;
		new_left = to_portal->rect.left - PORTAL_WIDTH - player->rect.width - 2;
	}

	// change the location of the given player
	player->rect.top = new_top;
	player->rect.left = new_left;
	player->sprite.setPosition(new_left, new_top);
	player->dx = new_x_vel;
	player->dy = new_y_vel;
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

	if (TileMap[top][left] == 'F' || TileMap[top][right] == 'F' ||
		TileMap[bottom][left] == 'F' || TileMap[bottom][right] == 'F') {
		is_projectile = false;
		sprite.setScale(0, 0);
		wall = NONE;
	}

	if (top_left && top_right) {
		is_projectile = false;
		wall = TOP;
		sprite.setTextureRect(
			m_is_blue ?
			IntRect(0, 3 * UNIT + 5, UNIT, UNIT * 2) :
			IntRect(0, 5 * UNIT + 12, UNIT, UNIT * 2));
		sprite.setRotation(90);
		sprite.move(PORTAL_HEIGHT / 2, 0);
		rect.height = PORTAL_WIDTH;
		rect.width = PORTAL_HEIGHT;
		rect.left -= PORTAL_HEIGHT / 2;
	}
	else if (bottom_left && bottom_right) {
		is_projectile = false;
		wall = BOTTOM;
		sprite.setTextureRect(
			m_is_blue ?
			IntRect(0, 3 * UNIT + 5, UNIT, UNIT * 2) :
			IntRect(0, 5 * UNIT + 12, UNIT, UNIT * 2));
		sprite.setRotation(90);
		sprite.move(PORTAL_HEIGHT / 2, 0);
		rect.height = PORTAL_WIDTH;
		rect.width = PORTAL_HEIGHT;
		rect.left -= PORTAL_HEIGHT / 2;
	}
	else if (top_left && bottom_left) {
		is_projectile = false;
		wall = LEFT;
		sprite.setTextureRect(
			m_is_blue ?
			IntRect(0, 3 * UNIT + 5, UNIT, UNIT * 2) :
			IntRect(0, 5 * UNIT + 12, UNIT, UNIT * 2));
		std::cout << rect.top << " " << rect.left << std::endl;
		rect.height = PORTAL_HEIGHT;
		rect.width = PORTAL_WIDTH;
		rect.top -= PORTAL_HEIGHT / 2;
	}
	else if (top_right && bottom_right) {
		is_projectile = false;
		wall = RIGHT;
		sprite.setTextureRect(
			m_is_blue ?
			IntRect(0, 3 * UNIT + 5, UNIT, UNIT * 2) :
			IntRect(0, 5 * UNIT + 12, UNIT, UNIT * 2));
		rect.height = PORTAL_HEIGHT;
		rect.width = PORTAL_WIDTH;
		rect.top -= PORTAL_HEIGHT / 2;
	}
}