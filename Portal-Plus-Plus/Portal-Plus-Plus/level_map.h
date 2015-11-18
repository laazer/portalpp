#ifndef LEVEL_MAP_H
#define LEVEL_MAP_H
#include <vector>
#include "wall_block.h"
#include <SFML/Graphics.hpp>
#define LEVEL_COLOR sf::Color(153, 204, 255)

class LevelMap {
public:
	LevelMap() = default;
	LevelMap(std::vector<WallBlock> blocks, int width, int height, Posn & target);
	
	// return the vector of WallBlocks in this level
	std::vector<WallBlock> getBlocks();

	// return this width/height of this level
	int getWidth();
	int getHeight();

	// return true if the given game object is touching the ceiling in
	// this level on the top of the object
	bool collisionTop(GameObject * object);

	// return true if the given game object is touching the ground in
	// this level on the top of the object
	bool collisionBottom(GameObject * object);

	// return true if the given game object is touching a wall on either side
	bool collisionSide(GameObject * object);

	// return the end target associated with this LevelMap
	Posn getTarget();

private:
	std::vector<WallBlock> m_blocks;
	int m_height;
	int m_width;
	Posn m_target; // the location of the the target door
	Posn m_mouse;
};

#endif