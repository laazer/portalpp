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
		testSprite->setTexture(*tileSet);
		testSprite->setTextureRect(IntRect(0, 0, 1, 1));

		TS_ASSERT_DELTA(enemy->dx, ENEMY_SPEED, 0.01);
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
		TS_ASSERT_DELTA(enemy->rect.left, left + 1 * ENEMY_SPEED, 0.01);

		left = enemy->rect.left;
		enemy->update(5);
		TS_ASSERT_DELTA(enemy->rect.left, left + 5 * ENEMY_SPEED, 0.01);

		delete enemy;
		breakDown();
	}
	void testEnemyCollision(void) {
		setUp();

		Enemy *enemy = new Enemy();
		enemy->set(*tileSet, 0, 0);

		World::initLevels();
		World::setLevel(2);

		float dx = enemy->dx;

		enemy->update(1);
		TS_ASSERT_DELTA(enemy->dx, dx, 0.01);

		delete enemy;
		breakDown();
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
		TS_ASSERT(testp->dx < 0);
		delete testp;
		breakDown();
	}

	// Tests for Portal
	void testPortalUpdate(void) {
		setUp();

		Portal portal(*tileSet, 0, 0, 0, 100, true);

		TS_ASSERT(portal.is_projectile);
		TS_ASSERT(portal.wall == Wall::NONE);
		TS_ASSERT_DELTA(portal.dy, PORTAL_SPEED, 0.001);
		TS_ASSERT_DELTA(portal.dx, 0.0, 0.001);

		breakDown();        
	}
	void testPortalTeleport(void) {
		setUp();

		Portal p1(*tileSet, 0, 0, 100, 100, true);
		Portal p2(*tileSet, 100, 100, 0, 0, false);
		Player player;
		FloatRect oldPos(p1.rect.left, p1.rect.top, p1.rect.width, p1.rect.height);
		p1.teleport(&player, &p2);

		p1.update(10);
		
		TS_ASSERT(oldPos.top != p1.rect.top);
		TS_ASSERT(oldPos.left != p1.rect.left);
		TS_ASSERT(oldPos.width != p1.rect.width);
		TS_ASSERT(oldPos.height != p1.rect.height);

		breakDown();
	}

	// Tests for World
	void testWorldIsGameWon(void) {
		World * world = new World();
		world->initLevels();
		TS_ASSERT(world->isGameWon() == false);
		delete world;
	}
};
