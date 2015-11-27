#include "game_model.h"

GameModel::GameModel(Player * player, std::vector<Enemy*> & enemies) {
	m_player = player;
	m_enemies = enemies;
}

void GameModel::update(float time) {
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
	
}