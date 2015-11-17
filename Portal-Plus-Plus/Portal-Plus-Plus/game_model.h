#pragma once
#include <vector>
#include "level_map.h"
#include "game_object.h"
#include "player.h"

#define MAX_PLAYER_VEL 3.0
#define PLAYER_HORIZONTAL_ACCEL 0.5

// represents the interface for programming against the model of this game
class GameModel {
public:
	GameModel() = default;
	GameModel(LevelMap & level, std::vector<GameObject> objects, Player & player);
	
	// gets the level associated with this model
	LevelMap * getLevel();

	// gets the Player associated with this model
	Player * getPlayer();

	// move the player in this model either right or left
	// returns a pointer to this GameModel
	GameModel * movePlayer(bool moveRight);

	// updates all objects in this model for one clock tick
	void onTick();

private:
	LevelMap m_level;
	std::vector<GameObject> m_objects;
	Player m_player;
};