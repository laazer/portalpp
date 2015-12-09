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
	}
	void testEnemyUpdate(void) {

	}
	void testEnemyCollision(void) {

	}

	// Tests for Game Model
	void testGameModelConstructor1(void) {

	}
	void testGameModelConstructor2(void) {

	}
	void testGameModelDestructor(void) {

	}
	void testGameModelUpdate(void) {

	}
	void testGameModelLaunchPortal(void) {

	}
	void testGameModelCheckPortals(void) {

	}
	void testGameModelGetRenderObjects(void) {

	}
	void testGameModelGetPlayer(void) {

	}

	// Tests for Key Handler
	void testKeyHandlerConstructor1(void) {

	}
	void testKeyHandlerConstructor2(void) {

	}
	void testKeyHandlerHandleKey(void) {

	}

	// Tests for Level View
	void testLevelViewConstructor1(void) {

	}
	void testLevelViewConstructor2(void) {

	}
	void testLevelViewRender(void) {

	}

	// No tests for Main

	// Tests for Mouse Handler
	void testMouseHandlerConstructor1(void) {

	}
	void testMouseHandlerConstructor2(void) {

	}
	void testMouseHandlerHandleMouse(void) {

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
