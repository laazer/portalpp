#pragma once
#include <vector>
#include "wall_block.h"
#include <SFML\Graphics.hpp>
#define LEVEL_COLOR sf::Color(153, 204, 255)

class LevelMap {
public:
	LevelMap() = default;
	LevelMap(std::vector<WallBlock> blocks, int width, int height);
	// adds all of the necessary shapes to draw this map to the
	// end of the given vector
	void draw(sf::RenderWindow & canvas);

private:
	std::vector<WallBlock> m_blocks;
	int m_height;
	int m_width;
	Posn m_target; // the location of the the target door
};
