#include <ctime>
#include <cstdlib>
#include <stdlib.h>
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
	World::initLevels();

	RenderWindow * window = new RenderWindow(VideoMode(W * UNIT, H * UNIT), "Portal++");

	window->setMouseCursorVisible(false);

	Texture * tileSet = new Texture();
	tileSet->loadFromFile(ASSET_DIR + "/SpriteSheet1.png");

	Texture * background_texture = new Texture();
	background_texture->loadFromFile(ASSET_DIR + "/Background.png");
	sf::Sprite background(*background_texture);

	Sprite tile(*tileSet);

	Sprite * life = new Sprite(*tileSet);
	life->setTextureRect(IntRect(3 + UNIT * 2, 13 + UNIT * 7, UNIT, UNIT));

	srand(time(NULL));

	GameModel * model = new GameModel();
	KeyHandler * key_handler = new KeyHandler(model);
	MouseHandler * mouse_handler = new MouseHandler(model);
	LevelView * view = new LevelView(model, life);

	window->setFramerateLimit(60);
	bool game_over = false;

	for (int level = 1; level < 5; ++level) {
		std::cout << level << std::endl;
		World::setLevel(level);
		Player player;
		std::vector<Enemy*> enemies;
		FloatRect door;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				if (World::TileMap[i][j] == 'X') {
					Enemy *enemy = new Enemy();
					enemy->set(*tileSet, j * UNIT, i * UNIT);
					enemies.push_back(enemy);
					if (rand() % 2 == 0) {
						enemy->dx *= -1;
					}
				}
				else if (World::TileMap[i][j] == 'P') {
					player = Player(*tileSet, j * UNIT, i * UNIT);
				}
				else if (World::TileMap[i][j] == 'E') {
					// set the rectangle of the door to a space just above the floor
					// where the door contacts the ground
					door = FloatRect((j + 0.45) * UNIT, (i + 2) * UNIT - 10,
						UNIT / 10.0, UNIT);
					std::cout << "FOUND DOOR" << std::endl;
					std::cout << door.top << std::endl;
					std::cout << door.left << std::endl;
				}
			}
		}

		

		/** For adding sound
		SoundBuffer buffer;
		buffer.loadFromFile("Jump.ogg");
		Sound sound(buffer);
		**/
		Clock clock;

		sf::Sprite crosshair(*tileSet);
		crosshair.setTextureRect(IntRect(2 * UNIT, 2 * UNIT, UNIT, UNIT));

		*model = GameModel(tileSet, &player, enemies, door);
		

		while (!window->isOpen() && !game_over) {
			// wait for the window to open to prevent the game loop from
			// being skipped
		}

		while (window->isOpen())
		{
			// set the position of the crosshair based on the mosue position
			sf::Vector2i mouse_coords = sf::Mouse::getPosition(*window);
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
			while (window->pollEvent(event))
			{
				if (event.type == Event::Closed) {
					window->close();
				}
				if (event.type == sf::Event::MouseButtonPressed)
				{
					mouse_handler->handleMouse(event);
				}
			}

			// handles any keys that are currently pressed down
			key_handler->handleKey();

			// updates all game objects in the model
			model->update(time);

			// clear the window to a black background
			window->clear(Color(0, 0, 0));
			window->draw(background);

			// draw the level
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++)
				{
					if (World::TileMap[i][j] == 'F')  tile.setTextureRect(IntRect(2 * UNIT + 3, 3 * UNIT, UNIT, UNIT));
					if (World::TileMap[i][j] == 'W')  tile.setTextureRect(IntRect(3 * UNIT + 3, 0, UNIT, UNIT));
					if (World::TileMap[i][j] == ' ' || World::TileMap[i][j] == '0' || World::TileMap[i][j] == 'X' || World::TileMap[i][j] == 'P') continue;
					if (World::TileMap[i][j] == 'E')  tile.setTextureRect(IntRect(2 * UNIT + 3, 5.25 * UNIT, UNIT, 2 * UNIT));
					tile.setPosition(j*UNIT - offsetX, i*UNIT - offsetY);
					window->draw(tile);
				}
			}

			if (model->reachedDoor()) {
				World::setLevel(World::current_level + 1);
				break;
			}

			if (player.lives_remaining <= 0) {
				game_over = true;
				player.sprite.setColor(Color::Red);
			}


			// render the game objects on top of the level
			view->render(window);
			// draw the crosshair at the current mouse location
			window->draw(crosshair);
			// display the window
			window->display();
			if (game_over) {
				return 0;
			}

		}
		if (game_over || !window->isOpen()) {
			return 0;
		}

		
	}
	delete tileSet;
	delete life;
	return 0;
}



