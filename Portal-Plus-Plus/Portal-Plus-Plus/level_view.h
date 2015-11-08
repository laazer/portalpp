#pragma once
#include "level_map.h"
#include <SFML\Graphics.hpp>
#define LEVEL_COLOR sf::Color(153, 204, 255)


class LevelView {
public:
	LevelView() = default;
	LevelView(LevelMap & level);
	void render(sf::RenderWindow & canvas);
private:
	LevelMap m_level;
};