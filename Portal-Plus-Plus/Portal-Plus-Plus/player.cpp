#include "player.h"

Player::Player(Posn & p) : GravityObject(PLAYER_HEIGHT, PLAYER_WIDTH, p) {
	m_is_jumping = false;
}

void Player::setJumping(bool jumping) {
	m_is_jumping = jumping;
}

bool Player::isJumping() {
	return m_is_jumping;
}