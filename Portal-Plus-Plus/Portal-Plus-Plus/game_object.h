#ifndef GAMEOBJECT
#define GAMEOBJECT

#include "world.h"

class IGameObject {

public:
	// the x and y velocities of the game object
	float dx, dy;

	// the rectangle used for hit detection of this object
	FloatRect rect;

	// the sprite used for rendering this object
	Sprite sprite;

	// move this object in the x direction by the given offset
	void moveX(float x);

	// move this object in the y direction by the given offset
	void moveY(float y);

	// update the state of this game object by the given time duration
	// since the last clock tick
	virtual void update(float time) = 0;

private:

};

#endif // GAMEOBJECT

