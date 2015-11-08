#pragma once
#include "level_map.h"
#include <SFML\Graphics.hpp>
#define LEVEL_COLOR sf::Color(153, 204, 255)
#define ASSETS_DIR "../assets/"
#define TARGET_IMAGE "target_image.png"


class LevelView {
public:
	LevelView() = default;
	~LevelView();
	LevelView(LevelMap & level);
	void render(sf::RenderWindow & canvas);
private:
	LevelMap m_level;
	sf::Texture * m_target_image;
};