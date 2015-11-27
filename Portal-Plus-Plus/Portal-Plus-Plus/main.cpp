#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "game_model.h"
#include "level_view.h"
#include "key_handler.h"
#define CANVAS_WIDTH 800
#define CANVAS_HEIGHT 600


int main()
{

	// redirect cout to point to cout.txt for debugging purposes
	std::ofstream file;
	file.open("cout.txt");
	std::streambuf* sbuf = std::cout.rdbuf();
	std::cout.rdbuf(file.rdbuf());


	sf::RenderWindow window(sf::VideoMode(CANVAS_WIDTH, CANVAS_HEIGHT), "Portal++");
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(60);

	Posn bottom_block_posn = Posn(0, 560);
	WallBlock bottom(800, 40, bottom_block_posn);
	Posn left_block_posn = Posn(0, 0);
	WallBlock left(40, 600, left_block_posn);
	Posn right_block_posn = Posn(760, 0);
	WallBlock right(40, 600, right_block_posn);
	Posn top_block_posn = Posn(0, 0);
	WallBlock top(800, 40, top_block_posn);

	Posn b1_block_posn = Posn(0, 500);
	WallBlock b1(480, 340, b1_block_posn);
	Posn b2_block_posn = Posn(540, 0);
	WallBlock b2(50, 425, b2_block_posn);
	std::vector<WallBlock> walls = std::vector<WallBlock>();
	walls.push_back(bottom);
	walls.push_back(left);
	walls.push_back(right);
	walls.push_back(top);
	walls.push_back(b1);
	walls.push_back(b2);
	Posn target_posn = Posn(60, 160);
	std::cout << target_posn.getX() << " " << target_posn.getY() << std::endl;
	LevelMap level_map = LevelMap(walls, CANVAS_WIDTH, CANVAS_HEIGHT, target_posn);
	std::vector<GameObject> objects = std::vector<GameObject>();
	Posn player_posn = Posn(100.0, 160.0);
	Player player = Player(player_posn);
	player.updateVel(0.15, -0.45);
	std::cout << player.getPosn()->getX() << " " << player.getPosn()->getY() << std::endl;
	GameModel model = GameModel(level_map, objects, player);
	LevelView view = LevelView(&model);
	KeyHandler kh = KeyHandler(&model);
	/*
	Player player = Player(Posn(400, 0));
	sf::CircleShape shape(100.f);
	shape.setPosition(400, 0);
	shape.setFillColor(sf::Color::Blue);
	*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				kh.handleEvent(event);
			}
		}
		kh.handleKey();
		model.onTick();
		sf::Vector2i mouse_coords = sf::Mouse::getPosition(window);
		Posn p8 = Posn(mouse_coords.x, mouse_coords.y);
		view.updateMouse(p8);
		window.clear();
		view.render(window);
		window.display();
	}

	return 0;
}