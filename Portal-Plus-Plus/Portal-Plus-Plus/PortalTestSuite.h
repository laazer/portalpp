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

	// Tests for Game Object
	void testGameObjectMoveX(void) {

	}
	void testGameObjectMoveY(void) {

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

	}
	void testPlayerUpdate(void) {

	}
	void testPlayerCollision(void) {

	}
	void testPlayerMoveLeft(void) {

	}
	void testPlayerJump(void) {

	}
	void testPlayerMoveRight(void) {

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

	// Tests for Velocity
	void testVelocityConstructor1(void) {

	}
	void testVelocityConstructor2(void) {

	}
	void testVelocityGetMagnitude(void) {

	}
	void testVelocityGetX(void) {

	}
	void testVelocityGetY(void) {

	}
	void testVelocitySetX(void) {

	}
	void testVelocitySetY(void) {

	}
	void testVelocityAssignment(void) {

	}
	// No tests for World
};