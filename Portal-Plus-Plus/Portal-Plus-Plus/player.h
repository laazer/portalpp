#pragma once
#include "posn.h"


class Player {
public:

	Player(int x_pos, int y_pos) {
		pos = new Posn(x_pos, y_pos);
	}


private:
	
	// current position of the center of the Player
	Posn * pos;

};
