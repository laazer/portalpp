#include "player.h"
#include "world.h"
#include "enemy.h"
#include "key_handler.h"
#include "mouse_handler.h"
#include "level_view.h"

int main()
{
	// redirect cout to point to cout.txt for debugging purposes
	std::ofstream file;
	file.open("cout.txt");
	std::streambuf* sbuf = std::cout.rdbuf();
	std::cout.rdbuf(file.rdbuf());

	RenderWindow window(VideoMode(W * UNIT, H * UNIT), "Portal++");

	window.setMouseCursorVisible(false);

	Texture * tileSet = new Texture();
	tileSet->loadFromFile(ASSET_DIR + "/SpriteSheet1.png");

	Texture * background_texture = new Texture();
	background_texture->loadFromFile(ASSET_DIR + "/Background.png");
	sf::Sprite background(*background_texture);
	

	Player player(*tileSet, 100, 440);
	Enemy enemy;
	enemy.set(*tileSet, 10 * UNIT, 12 * UNIT);
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
	
	GameModel model = GameModel(tileSet, &player, enemies);
	KeyHandler key_handler = KeyHandler(&model);
	MouseHandler mouse_handler = MouseHandler(&model);
	LevelView view = LevelView(&model);

	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		// set the position of the crosshair based on the mosue position
		sf::Vector2i mouse_coords = sf::Mouse::getPosition(window);
		crosshair.setPosition(mouse_coords.x, mouse_coords.y);

		// get the clock time that has elapsed since the last clock tick to account for
		// any missed frames
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 500;

		if (time > 20) {
			time = 20;
		}

		// poll events and delegate to the mouse handler if there was a click
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				mouse_handler.handleMouse(event);
			}
		}

		// handles any keys that are currently pressed down
		key_handler.handleKey();

		// updates all game objects in the model
		model.update(time);

		// clear the window to a black background
		window.clear(Color(0, 0, 0));
		window.draw(background);

		// draw the level
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'F')  tile.setTextureRect(IntRect(2 * UNIT + 3, 3 * UNIT, UNIT, UNIT));
				if (TileMap[i][j] == 'W')  tile.setTextureRect(IntRect(3 * UNIT + 3, 0, UNIT, UNIT));
				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) continue;
				if (TileMap[i][j] == 'E')  tile.setTextureRect(IntRect(2 * UNIT + 3, 5.25 * UNIT, UNIT, 2 * UNIT));
				tile.setPosition(j*UNIT - offsetX, i*UNIT - offsetY);
				window.draw(tile);
			}
		}

		// render the game objects on top of the level
		view.render(&window);
		// draw the crosshair at the current mouse location
		window.draw(crosshair);
		// display the window
		window.display();
		
	}

	delete tileSet;
	return 0;
}



