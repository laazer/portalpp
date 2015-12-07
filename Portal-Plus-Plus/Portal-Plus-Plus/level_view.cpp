#include "level_view.h"
#include <iostream>
#include <math.h>

LevelView::LevelView(GameModel * model, sf::Sprite * life_sprite) {
	m_model = model;
	m_life_sprite = life_sprite;
}

void LevelView::render(sf::RenderWindow * canvas) {
	std::vector<IGameObject*> to_draw = m_model->getRenderObjects();
	for (int i = 0; i < to_draw.size(); ++i) {
		canvas->draw(to_draw.at(i)->sprite);
	}

	for (int i = 1; i <= m_model->getPlayer()->lives_remaining; i++) {
		m_life_sprite->setPosition(UNIT *(W - 5 + i), 0);
		canvas->draw(*m_life_sprite);
	}
}