#ifndef MOUSE_HANDLER
#define MOUSE_HANDLER

#include "game_model.h"

// class for handling user mouse input
class MouseHandler {
public:
	MouseHandler() = default;
	MouseHandler(GameModel * model);

	// change the model based on a mouse event and return a pointer to the model
	GameModel * handleMouse(sf::Event &event);

private:
	// the model that this MouseHandler controls
	GameModel * m_model;
};




#endif // MOUSE_HANDLER
