#include "game_object.h"

GameObject::GameObject(int height, int width, Posn & p) {
	m_height = height;
	m_width = width;
	m_pos = p;
	image_name = "";
}

GameObject::GameObject(GameObject & o) {

}

void GameObject::setImage(string s) {
	this->image_name = s;
}

bool operator==(const GameObject & g1, const GameObject & g2) {
	return g1.m_width == g2.m_width && g1.m_height == g2.m_height && g1.m_pos == g2.m_pos && g1.image_name == g2.image_name;
}

bool operator!=(const GameObject & g1, const GameObject & g2) {
	return !(g1 == g2);
}

bool GameObject::hasCollided(GameObject & g) {
	//TODO
	return false;
}

void GameObject::move(Velocity v) {
	
}