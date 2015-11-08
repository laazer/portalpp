#include "level_view.h"

LevelView::LevelView(LevelMap & level) {
	this->m_level = level;
}

void LevelView::render(sf::RenderWindow & canvas) {
	// first render the background onto the canvas
	sf::RectangleShape bg(sf::Vector2f(m_level.getWidth(), m_level.getHeight()));
	bg.setFillColor(LEVEL_COLOR);
	bg.setPosition(0, 0);
	canvas.draw(bg);

	// render all of the WallBlocks on top of the background
	std::vector<WallBlock> blocks = m_level.getBlocks();
	for (int i = 0; i < blocks.size(); ++i) {
		WallBlock block = blocks.at(i);
		sf::RectangleShape rect(sf::Vector2f(block.getWidth(), block.getHeight()));
		rect.setFillColor(WALL_COLOR);
		rect.setPosition(sf::Vector2f(block.getPosn().getX(), block.getPosn().getY()));
		canvas.draw(rect);
	}
}