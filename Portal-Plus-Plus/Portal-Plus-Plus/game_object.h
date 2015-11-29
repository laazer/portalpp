#ifndef GAMEOBJECT
#define GAMEOBJECT

#include "world.h"

class IGameObject {

public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;
	void moveX(float x);
	void moveY(float y);

private:

};

#endif // GAMEOBJECT

