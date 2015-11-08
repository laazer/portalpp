#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
//#include "player.h"
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

	WallBlock bottom(800, 40, Posn(0, 560));
	WallBlock left(40, 600, Posn(0, 0));
	WallBlock right(40, 600, Posn(760, 0));
	WallBlock top(800, 40, Posn(0, 0));

	WallBlock b1(240, 340, Posn(0, 260));
	WallBlock b2(50, 425, Posn(540, 0));
	std::vector<WallBlock> walls = std::vector<WallBlock>();
	walls.push_back(bottom);
	walls.push_back(left);
	walls.push_back(right);
	walls.push_back(top);
	walls.push_back(b1);
	walls.push_back(b2);
	LevelMap level_map = LevelMap(walls, CANVAS_WIDTH, CANVAS_HEIGHT);
	LevelView view = LevelView(level_map);
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
		}

		window.clear();
		view.render(window);
		window.display();
	}

	return 0;
}