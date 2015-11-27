#include "level_view.h"
#include <iostream>
#include <math.h>

LevelView::LevelView(GameModel * model) {
	m_model = model;
}

void LevelView::render(sf::RenderWindow * canvas) {
	std::vector<IGameObject*> to_draw = m_model->getRenderObjects();
	for (int i = 0; i < to_draw.size(); ++i) {
		canvas->draw(to_draw.at(i)->sprite);
	}
}