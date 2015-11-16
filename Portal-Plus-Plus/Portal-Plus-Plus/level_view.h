#ifndef LEVEL_VIEW_H
#define LEVEL_VIEW_H
#include "game_model.h"
#include "level_map.h"
#include "posn.h"
#include <SFML/Graphics.hpp>
#define LEVEL_COLOR sf::Color(0, 0, 0)
#define WALL_COLOR sf::Color(200, 200, 200)
#define ASSETS_DIR "../assets/"
#define TARGET_IMAGE "target_image.png"
#define CROSSHAIR_IMAGE "crosshair.png"
#define PLAYER_IMAGE "player.png"


class LevelView {
public:
	LevelView() = default;
	~LevelView();
	LevelView(GameModel & model);
	void render(sf::RenderWindow & canvas);
	void updateMouse(Posn & p);
private:
	GameModel m_model;
	LevelMap m_level;
	Player m_player;
	sf::Texture * m_target_image;
	Posn m_mouse;
	sf::Texture * m_crosshair_image;
	sf::Texture * m_player_image;
};

#endif