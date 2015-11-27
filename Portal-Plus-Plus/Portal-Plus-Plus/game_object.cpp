#include "game_object.h"

void IGameObject::moveX(float x) {
	this->dx += x;
}

void IGameObject::moveY(float y) {
	this->dy += y;
}
