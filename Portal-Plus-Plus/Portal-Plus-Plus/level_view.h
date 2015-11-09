#pragma once
#include "level_map.h"
#include "posn.h"
#include <SFML\Graphics.hpp>
#define LEVEL_COLOR sf::Color(153, 204, 255)
#define ASSETS_DIR "../assets/"
#define TARGET_IMAGE "target_image.png"
#define CROSSHAIR_IMAGE "crosshair.png"


class LevelView {
public:
	LevelView() = default;
	~LevelView();
	LevelView(LevelMap & level);
	void render(sf::RenderWindow & canvas);
	void updateMouse(Posn & p);
private:
	LevelMap m_level;
	sf::Texture * m_target_image;
	Posn m_mouse;
	sf::Texture * m_crosshair_image;
};