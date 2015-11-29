#include "key_handler.h"
#include <iostream>

KeyHandler::KeyHandler(GameModel * model) {
	m_model = model;
}

GameModel * KeyHandler::handleKey() {
	// check if A is currently pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_model->getPlayer()->moveLeft();
	}
	// check if D is currently pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_model->getPlayer()->moveRight();
	}
	// check if W is currently pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_model->getPlayer()->jump();
	}
	return m_model;
}
