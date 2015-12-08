#ifndef GAME_MODEL_H
#define GAME_MODEL_H
#include <vector>
#include "game_object.h"
#include "player.h"
#include "enemy.h"
#include "portal.h"

#define MAX_PLAYER_VEL 3.0
#define PLAYER_HORIZONTAL_ACCEL 0.5

// represents the interface for programming against the model of this game
class GameModel {
public:
	GameModel() = default;
	GameModel(Texture * image, Player * player, std::vector<Enemy*> & enemies, const sf::FloatRect door);
	~GameModel();

	// update the positions of all the contents of this level
	void update(float time);
	
	// launch a new portal towards the given x and y coordinates
	void launchPortal(float target_x, float target_y, bool portal_1);

	// if the player has entered a portal, move them accordingly
	void checkPortals();

	// get const pointers to all of the objects in this model ot render
	const std::vector<IGameObject*> getRenderObjects();

	// get the player object that is contained within this model
	Player * getPlayer();

	// return true if the player has reached a door
	bool reachedDoor();

	// configure this model using the given game objects
	//void configure(float player_x, float player_y, std::vector<sf::Vector2f> enemy_pos, FloatRect door);

private:
	// pointer to the player in this level
	Player * m_player;
	// contains pointers to all enemies in this level
	std::vector<Enemy*> m_enemies;
	// pointer to the blue portal
	Portal * m_portal_1;
	// pointer to the red portal
	Portal * m_portal_2;
	// sprite sheet used to render game objects in this model
	Texture * m_image;
	// the rectangel corresponding to the door in this level
	FloatRect m_door;
};

#endif