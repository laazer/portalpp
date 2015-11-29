#include "game_model.h"

GameModel::GameModel(Texture * image, Player * player, std::vector<Enemy*> & enemies) {
	m_player = player;
	m_enemies = enemies;
	m_image = image;
	m_portal_1 = NULL;
	m_portal_2 = NULL;
}

GameModel::~GameModel() {

}

Player * GameModel::getPlayer() {
	return m_player;
}

void GameModel::update(float time) {
	checkPortals();
	m_player->update(time);

	for (int i = 0; i < m_enemies.size(); ++i) {
		Enemy * enemy = m_enemies.at(i);
		enemy->update(time);
		if (m_player->rect.intersects(enemy->rect)) {
			if (enemy->life) {
				if (m_player->dy > 0) {
					enemy->dx = 0;
					m_player->dy = -0.2;
					enemy->life = false;
				}
				else {
					m_player->sprite.setColor(Color::Red);
				}
			}
		}
	}
	if (m_portal_1) {
		m_portal_1->update(time);
	}
	if (m_portal_2) {
		m_portal_2->update(time);
	}
}

void GameModel::checkPortals() {
	if (m_portal_1 && m_portal_2) {
		if (m_portal_1->rect.intersects(m_player->rect)) {
			m_portal_1->teleport(m_player, m_portal_2);
		}
		else if (m_portal_2->rect.intersects(m_player->rect)) {
			m_portal_2->teleport(m_player, m_portal_1);
		}
	}
}

void GameModel::launchPortal(float target_x, float target_y, bool portal_1) {
	if (m_portal_1 && portal_1) {
		delete m_portal_1;
	}
	if (m_portal_2 && !portal_1) {
		delete m_portal_2;
	}
	if (portal_1) {
		m_portal_1 = new Portal(
			*m_image,
			m_player->sprite.getPosition().x,
			m_player->sprite.getPosition().y,
			target_x,
			target_y,
			true);
	}
	else {
		m_portal_2 = new Portal(
			*m_image,
			m_player->sprite.getPosition().x,
			m_player->sprite.getPosition().y,
			target_x,
			target_y,
			false);
	}
}

const std::vector<IGameObject*> GameModel::getRenderObjects() {
	std::vector<IGameObject*> objects = std::vector<IGameObject*>();
	for (int i = 0; i < m_enemies.size(); ++i) {
		objects.push_back(m_enemies.at(i));
	}
	objects.push_back(m_player);
	if (m_portal_1) {
		objects.push_back(m_portal_1);
	}
	if (m_portal_2) {
		objects.push_back(m_portal_2);
	}
	return objects;
}