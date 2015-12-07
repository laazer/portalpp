#ifndef LEVEL_VIEW_H
#define LEVEL_VIEW_H
#include "game_model.h"
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
	LevelView(GameModel * model, sf::Sprite * life_sprite);
	void render(sf::RenderWindow * canvas);

private:
	GameModel * m_model;
	sf::Sprite * m_life_sprite;
};

#endif