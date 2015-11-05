#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "player.h"


int main()
{

	// redirect cout to point to cout.txt for debugging purposes
	std::ofstream file;
	file.open("cout.txt");
	std::streambuf* sbuf = std::cout.rdbuf();
	std::cout.rdbuf(file.rdbuf());


	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Player player = Player(Posn(400, 0));
	sf::CircleShape shape(100.f);
	shape.setPosition(400, 0);
	shape.setFillColor(sf::Color::Blue);

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

		player.applyGravity();
		player.updatePos();
		Posn pos = player.getPos();
		std::cout << pos.getX() << "  " << pos.getY() << std::endl;
		shape.setPosition((float)pos.getX(), (float)pos.getY() / 10000.f);
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}