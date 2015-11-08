#include "level_map.h"

LevelMap::LevelMap(std::vector<WallBlock> blocks, int width, int height) {
	this->m_blocks = blocks;
	this->m_width = width;
	this->m_height = height;
}

void LevelMap::draw(sf::RenderWindow & canvas) {
	sf::RectangleShape bg(sf::Vector2f(m_width, m_height));
	bg.setFillColor(LEVEL_COLOR);
	bg.setPosition(0, 0);
	canvas.draw(bg);

	for (int i = 0; i < m_blocks.size(); ++i) {
		m_blocks.at(i).draw(canvas);
	}
}