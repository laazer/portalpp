#ifndef GAME_MODEL_H
#define GAME_MODEL_H
#include <vector>
#include "game_object.h"
#include "player.h"
#include "enemy.h"

#define MAX_PLAYER_VEL 3.0
#define PLAYER_HORIZONTAL_ACCEL 0.5

// represents the interface for programming against the model of this game
class GameModel {
public:
	GameModel() = default;
	GameModel(Player * player, std::vector<Enemy*> & enemies);
	
	void update(float time);


private:
	Player * m_player;
	std::vector<Enemy*> m_enemies;
};

#endif