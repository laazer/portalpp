#pragma once
#include "game_object.h"
#include <SFML\Graphics.hpp>
#define WALL_COLOR sf::Color(0, 0, 0)


class WallBlock : public GameObject {
public:
	// constructor
	WallBlock(int width, int height, Posn & p);
	WallBlock(const WallBlock & wb);
	
	void draw(sf::RenderWindow & canvas);


private:

};
