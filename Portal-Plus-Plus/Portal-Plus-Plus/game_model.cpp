#include "game_model.h"
#include <stdlib.h>
#include <iostream>

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
	m_player.applyGravity();
	std::cout << m_player.getVelocity().getY() << std::endl;
	m_player.updatePos();
	std::cout << m_player.getPosn().getX() << " " << m_player.getPosn().getY() << std::endl;
}