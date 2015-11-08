#include "wall_block.h"

WallBlock::WallBlock(int width, int height, Posn & p) :
	GameObject(height, width, p) {
}


WallBlock::WallBlock(const WallBlock & wb) {
	this->m_height = wb.m_height;
	this->m_pos = wb.m_pos;
	this->m_width = wb.m_width;
}


void WallBlock::draw(sf::RenderWindow & canvas) {
	sf::RectangleShape rect(sf::Vector2f(m_width, m_height));
	rect.setFillColor(WALL_COLOR);
	rect.setPosition(sf::Vector2f(m_pos.getX(), m_pos.getY()));
	canvas.draw(rect);
}