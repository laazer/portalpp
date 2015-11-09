#include "level_view.h"
#include <iostream>
#include <math.h>

LevelView::LevelView(LevelMap & level) {
	this->m_level = level;
	this->m_mouse = Posn(-100, -100); // start the mouse off the screen
	this->m_target_image = new sf::Texture();
	m_target_image->loadFromFile(ASSETS_DIR TARGET_IMAGE, sf::IntRect());
	m_target_image->setSmooth(true);
	this->m_crosshair_image = new sf::Texture();
	m_crosshair_image->loadFromFile(ASSETS_DIR CROSSHAIR_IMAGE, sf::IntRect());
	m_crosshair_image->setSmooth(true);
}

LevelView::~LevelView() {
	delete m_target_image;
}

void LevelView::updateMouse(Posn & p) {
	m_mouse = p;
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

	// render the exit target onto the canvas
	sf::Sprite target_sprite;
	target_sprite.setTexture(*m_target_image);
	target_sprite.setPosition(m_level.getTarget().getX(), m_level.getTarget().getY());
	canvas.draw(target_sprite);

	// render the crosshair onto the canvas
	sf::Sprite crosshair;
	crosshair.setTexture(*m_crosshair_image);
	sf::Vector2u size(m_crosshair_image->getSize());
	crosshair.setPosition(m_mouse.getX() - (size.x / 2),
		m_mouse.getY() - (size.y / 2));
	canvas.draw(crosshair);

}