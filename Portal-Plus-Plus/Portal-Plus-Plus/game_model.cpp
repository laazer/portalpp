#include "game_model.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

GameModel::GameModel(LevelMap & level, std::vector<GameObject> objects, Player & player) :
	m_level(level), m_objects(objects), m_player(player) { }

LevelMap * GameModel::getLevel() {
	return & m_level;
}

Player * GameModel::getPlayer() {
	return & m_player;
}

GameModel * GameModel::movePlayer(bool moveRight) {
	if (abs(m_player.getVelocity().getX()) < MAX_PLAYER_VEL) {
		if (moveRight) {
			m_player.updateVel(PLAYER_HORIZONTAL_ACCEL, 0);
		}
		else {
			m_player.updateVel(0.0 - PLAYER_HORIZONTAL_ACCEL, 0);
		}
	}
}

void GameModel::onTick() {
	bool collision_top = m_level.collisionTop(&m_player);
	bool collision_bottom = m_level.collisionBottom(&m_player);
	if (collision_top || collision_bottom) {
		m_player.updateVel(0, 0.0 - m_player.getVelocity().getY());
	}
	if (collision_bottom) {
		m_player.setJumping(false);
	}
	m_player.applyGravity();
	m_player.updatePos(collision_bottom);
}