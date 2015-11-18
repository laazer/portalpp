#include "key_handler.h"
#include <iostream>

KeyHandler::KeyHandler(GameModel * model) {
	m_model = model;
}

GameModel * KeyHandler::handleKey() {
	// check if left arrow is currently pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_model->getPlayer()->getPosn()->move(-0.25, 0);
	}
	// check if right arrow is currently pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_model->getPlayer()->getPosn()->move(0.25, 0);
	}
	return m_model;
}

GameModel * KeyHandler::handleEvent(sf::Event event) {
	if (event.key.code == sf::Keyboard::Up) {
		if (!(m_model->getPlayer()->isJumping())) {
			m_model->getPlayer()->setJumping(true);
			m_model->getPlayer()->updateVel(0 - m_model->getPlayer()->getVelocity().getX(), -0.4);
			m_model->getPlayer()->updatePos(false);
		}
	}
	return m_model;
}