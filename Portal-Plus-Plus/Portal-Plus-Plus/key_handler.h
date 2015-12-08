#ifndef KEY_HANDLER_H
#define KEY_HANDLER_H
#include "game_model.h"


class KeyHandler {
public:
	KeyHandler() = default;
	KeyHandler(GameModel * model);

	// handles the key input appropriately
	GameModel * handleKey();

private:
	// represents the model that this KeyHandler controls
	GameModel * m_model;
};

#endif