#include "mouse_handler.h"

MouseHandler::MouseHandler(GameModel * model) {
	m_model = model;
}

GameModel * MouseHandler::handleMouse(sf::Event &event) {
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		m_model->launchPortal(event.mouseButton.x, event.mouseButton.y, true);
	}
	else if (event.mouseButton.button == sf::Mouse::Right)
	{
		m_model->launchPortal(event.mouseButton.x, event.mouseButton.y, false);
	}
	return m_model;
}