#ifndef MOUSE_HANDLER
#define MOUSE_HANDLER

#include "game_model.h"

class MouseHandler {
public:
	MouseHandler() = default;
	MouseHandler(GameModel * model);

	GameModel * handleMouse(sf::Event &event);

private:
	GameModel * m_model;
};




#endif // MOUSE_HANDLER
