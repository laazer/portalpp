#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "game_model.h"
#include "level_view.h"
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

	Posn p1 = Posn(0, 560);
	WallBlock bottom(800, 40, p1);
	Posn p2 = Posn(0, 0);
	WallBlock left(40, 600, p2);
	Posn p3 = Posn(760, 0);
	WallBlock right(40, 600, p3);
	Posn p4 = Posn(0, 0);
	WallBlock top(800, 40, p4);

	Posn p5 = Posn(0, 260);
	WallBlock b1(240, 340, p5);
	Posn p6 = Posn(540, 0);
	WallBlock b2(50, 425, p6);
	std::vector<WallBlock> walls = std::vector<WallBlock>();
	walls.push_back(bottom);
	walls.push_back(left);
	walls.push_back(right);
	walls.push_back(top);
	walls.push_back(b1);
	walls.push_back(b2);
	Posn p7 = Posn(60, 160);
	LevelMap level_map = LevelMap(walls, CANVAS_WIDTH, CANVAS_HEIGHT, p7);
	std::vector<GameObject> objects = std::vector<GameObject>();
	Player player = Player(Posn(0, 0));
	GameModel model = GameModel(level_map, objects, player);
	LevelView view = LevelView(model);
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
				std::cout << event.key.code << std::endl;
			}
		}

		sf::Vector2i mouse_coords = sf::Mouse::getPosition(window);
		Posn p8 = Posn(mouse_coords.x, mouse_coords.y);
		view.updateMouse(p8);
		window.clear();
		view.render(window);
		window.display();
	}

	return 0;
}