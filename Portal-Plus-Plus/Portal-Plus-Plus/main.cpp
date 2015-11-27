#include "player.h"
#include "world.h"
#include "enemy.h"
#include "key_handler.h"

int main()
{
	// redirect cout to point to cout.txt for debugging purposes
	std::ofstream file;
	file.open("cout.txt");
	std::streambuf* sbuf = std::cout.rdbuf();
	std::cout.rdbuf(file.rdbuf());

	RenderWindow window(VideoMode(W * UNIT, H * UNIT), "Portal++!");

	window.setMouseCursorVisible(false);

	Texture * tileSet = new Texture();
	tileSet->loadFromFile(ASSET_DIR + "/SpriteSheet1.png");

	Player player(*tileSet);
	Enemy enemy;
	enemy.set(*tileSet, 4 * UNIT, 3 * UNIT);
	std::vector<Enemy*> enemies;
	enemies.push_back(&enemy);

	Sprite tile(*tileSet);

	/** For adding sound
	SoundBuffer buffer;
	buffer.loadFromFile("Jump.ogg");
	Sound sound(buffer);
	**/
	Clock clock;

	sf::Sprite crosshair(*tileSet);
	crosshair.setTextureRect(IntRect(2 * UNIT, 2 * UNIT, UNIT, UNIT));
	
	GameModel model = GameModel(&player, enemies);
	KeyHandler key_handler = KeyHandler();

	while (window.isOpen())
	{
		sf::Vector2i mouse_coords = sf::Mouse::getPosition(window);

		crosshair.setPosition(mouse_coords.x, mouse_coords.y);

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 500;

		if (time > 20) {
			time = 20;
		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			player.dx = -0.05;
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			player.dx = 0.05;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (player.onGround) {
				player.dy = -0.27;
				player.onGround = false;
				//sound.play();
			}
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			//event on mouse click
		}

		model.update(time);


		window.clear(Color(107, 140, 255));

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'F')  tile.setTextureRect(IntRect(2 * UNIT, 3 * UNIT, UNIT, UNIT));
				if (TileMap[i][j] == 'W')  tile.setTextureRect(IntRect(3 * UNIT, 0, UNIT, UNIT));
				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) continue;
				tile.setPosition(j*UNIT - offsetX, i*UNIT - offsetY);
				window.draw(tile);
			}
		}

		window.draw(player.sprite);
		window.draw(enemy.sprite);
		window.draw(crosshair);
		window.display();
	}

	return 0;
}



