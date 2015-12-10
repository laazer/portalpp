#include <cxxtest/TestSuite.h>
#include <iostream>
#include "enemy.h"
#include "game_model.h"
#include "game_object.h"
#include "key_handler.h"
#include "level_view.h"
#include "mouse_handler.h"
#include "player.h"
#include "portal.h"
#include "world.h"

class PortalTestSuite : public CxxTest::TestSuite {
public:
	void testPoop(void) {
		Enemy * enemy = new Enemy();
		delete enemy;
	}

	Texture * tileSet;
	void setUp() {
		tileSet = new Texture();
		tileSet->loadFromFile(ASSET_DIR + "/SpriteSheet1.png");
	}

	void breakDown() {
		delete tileSet;
	}

	// Tests for Enemy
	void testEnemySet(void) {
		setUp();

		Enemy *enemy = new Enemy();
		enemy->set(*tileSet, 0, 0);
		Sprite * testSprite = new Sprite();
		testSprite.setTexture(*tileSet);
		testSprite.setTextureRect(IntRect(0, 0, 1, 1));

		TS_ASSERT_EQUALS(enemy->sprite, testSprite);
		TS_ASSERT_EQUALS(enemy->rect, FloatRect(0, 0, 1, 1));
		TS_ASSERT_EQUALS(enemy->dx, ENEMY_SPEED);
		TS_ASSERT(enemy->life);

		delete enemy;
		breakDown();
	}
	void testEnemyUpdate(void) {
		setUp();

		Enemy *enemy = new Enemy();
		enemy->set(*tileSet, 0, 0);

		float left = enemy->rect.left;
		enemy->update(1);
		TS_ASSERT_EQUALS(enemy->rect.left, left + 1 * ENEMY_SPEED);

		left = enemy->rect.left;
		enemy->update(5);
		TS_ASSERT_EQUALS(enemy->rect.left, left + 5 * ENEMY_SPEED);

		delete enemy;
		breakDown();
	}
	void testEnemyCollision(void) {
		setUp();

		Enemy *enemy = new Enemy();
		enemy->set(*tileSet, 0, 0);

		World::initWorlds();
		World::setLevel(2);

		float dx = enemy->dx;

		enemy->update(1);
		TS_ASSERT_EQUALS(enemy->dx, dx);
		enemy->update(10);
		TS_ASSERT_EQUALS(enemy->dx, -1 * dx);

		delete enemy;
		breakDown();
	}

	// Tests for Game Model
	void testGameModelUpdate(void) {
		setUp();

		Player * testp = new Player(*tileSet, 0, 0);
		std::vector<Enemy*> & enemies;
		FloatRect door;
		GameModel * model = new GameModel(*tileSet, testp, enemies, door);

		model->update(1);
		const std::vector<IGameObject*> renderObjects = model->getRenderObjects();
		TS_ASSERT_EQUALS(model->getPlayer(), )

		delete testp;
		delete model;
		breakDown();
	}
	void testGameModelLaunchPortal(void) {

	}
	void testGameModelCheckPortals(void) {

	}
	void testGameModelGetRenderObjects(void) {
		setUp();

		Player * testp = new Player(*tileSet, 0, 0);
		std::vector<Enemy*> & enemies;
		FloatRect door;
		GameModel * model = new GameModel(*tileSet, testp, enemies, door);
		const std::vector<IGameObject*> renderObjects = model->getRenderObjects();

		TS_ASSERT(renderObjects.size() > 0);

		delete testp;
		delete model;
		breakDown();
	}
	void testGameModelGetPlayer(void) {
		setUp();

		Player * testp = new Player(*tileSet, 0, 0);
		std::vector<Enemy*> & enemies;
		FloatRect door;
		GameModel * model = new GameModel(*tileSet, testp, enemies, door);

		TS_ASSERT_EQUALS(model->getPlayer, testp);

		delete testp;
		delete model;
		breakDown();
	}
	void testGameModelReachedDoor(void) {

	}

	// Tests for Player
	void testPlayerConstructor(void) {
		setUp();
		Player * testp = new Player(*tileSet, 0, 0);
		TS_ASSERT(testp != NULL);
		TS_ASSERT(testp->lives_remaining = STARTING_LIVES);
		delete testp;
		breakDown();
	}
	void testPlayerUpdate(void) {
		setUp();
		Player * testp = new Player(*tileSet, 0, 0);
		testp->update(1);
		TS_ASSERT(testp->onGround);
		testp->jump();
		TS_ASSERT(!testp->onGround);
		delete testp;
		breakDown();
	}
	void testPlayerCollision(void) {
		setUp();
		Player * testp = new Player(*tileSet, 0, 0);
		testp->dx = 10;
		testp->dy = 10;
		testp->Collision(0);
		testp->setPos(15 * UNIT, testp->rect.top);
		testp->jump();
		testp->Collision(1);
		delete testp;
		breakDown();
	}
	void testPlayerMoveLeft(void) {
		setUp();
		Player * testp = new Player(*tileSet, 0, 0);
		TS_ASSERT(testp->dx == 0);
		testp->moveLeft();
		TS_ASSERT(testp->dx < 0);
		testp->jump();
		TS_ASSERT(testp->dx < 0);
		delete testp;
		breakDown();
	}
	void testPlayerJump(void) {
		setUp();
		Player * testp = new Player(*tileSet, 0, 0);
		TS_ASSERT(testp->onGround);
		testp->jump();
		TS_ASSERT(!testp->onGround);
		delete testp;
		breakDown();
	}
	void testPlayerMoveRight(void) {
		setUp();
		Player * testp = new Player(*tileSet, 0, 0);
		TS_ASSERT(testp->dx == 0);
		testp->moveLeft();
		TS_ASSERT(testp->dx > 0);
		testp->jump();
		TS_ASSERT(testp->dx > 0);
		delete testp;
		breakDown();
	}

	// Tests for Portal
	void testPortalConstructor(void) {

	}
	void testPortalUpdate(void) {

	}
	void testPortalCollision(void) {

	}
	void testPortalTeleport(void) {

	}

	// No tests for World
};
