#include "world.h"

String World::TileMap[H] = {
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	"W                         FFF          W",
	"W                         FFF          W",
	"W                         FFF          W",
	"W                         FFF          W",
	"W                         FFF          W",
	"W                         FFF          W",
	"W                                      W",
	"W                                      W",
	"W                         FFF          W",
	"W                         FFF          W",
	"W                         WWW          W",
	"W        0    X    0      WWW          W",
	"W         FFFFFFFFF       WWW          W",
	"W       FFFFFFFFFFFF      WWW     E    W",
	"W P    FFFFFFFFFFFFFF     WWW          W",
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
};

std::vector<String*> World::m_levels = std::vector<String*>();
int World::current_level = 0;

void World::initLevels() {
	String Level1[H] = {
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WFFFFFWWWWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW",
		"WF                                     W",
		"WW                                     W",
		"WW                                     W",
		"WW                                     W",
		"WF                              E      W",
		"WF                                     W",
		"WF            FFFFFFFFWWWWWWWWWWWWWWWWWW",
		"WF            FFFFFFFFFFFFFFFFFFFFFFFFFW",
		"WF            FFFFFFFFFFFFFFFFFFFFFFFFFW",
		"WF            FFFFFFFFFFFFFFFFFFFFFFFFFW",
		"WF            FFFFFFFFFFFFFFFFFFFFFFFFFW",
		"WF            FFFFFFFFFFFFFFFFFFFFFFFFFW",
		"WF            FFFFFFFFFFFFFFFFFFFFFFFFFW",
		"WF P          FFFFFFFFFFFFFFFFFFFFFFFFFW",
		"WFFFFFWWWWFFFFFWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	};
	m_levels.push_back(Level1);

	String static Level2[H] = {
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"W                         FFF          W",
		"W                         FFF          W",
		"W                         FFF          W",
		"W                         FFF          W",
		"W                         FFF          W",
		"W                         FFF          W",
		"W                                      W",
		"W                                      W",
		"W                         FFF          W",
		"W                         FFF          W",
		"W                         WWW          W",
		"W        0    X    0      WWW          W",
		"W         FFFFFFFFF       WWW          W",
		"W       FFFFFFFFFFFF      WWW     E    W",
		"W P    FFFFFFFFFFFFFF     WWW          W",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	};
	m_levels.push_back(Level2);

	String static Level3[H] = {
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"W                                      W",
		"W                                      W",
		"W P                                    W",
		"WFFFFFFFFFFFFFFFFFFFFFFFFFF  FFFFFFFFFFW",
		"WFFFFFFFFFFFFFFFFFF   X   X    X     X W",
		"WFFFFFFFFFFFFFFFFFFFFFFFFFF  FFFFFFFFFFW",
		"WFFFFFFFFFFFFFFFFFF     X      X   X   W",
		"WFFFFFFFFFFFFFFFFFFFFFFFFFF  FFFFFFFFFFW",
		"WFFFFFFFFFFFFFFFFFF  X X  X      X     W",
		"WFFFFFFFFFFFFFFFFFFFFFFFFFF  FFFFFFFFFFW",
		"WFFFFFFFFFFFFFFFFFFX   X  X            W",
		"WFFFFFFFFFFFFFFFFFFFFFFFFFF  FFFFFFFFFFW",
		"WFFFFFFFFFFFFFFFFFF                    W",
		"WFFFFFFFFFFFFFFFFFF                E   W",
		"WFFFFFFFFFFFFFFFFFF                    W",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	};
	m_levels.push_back(Level3);

	String static Level4[H] = {
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WFFFWWWWWFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFW",
		"W                                      W",
		"W                                      W",
		"W                                      W",
		"W                                  E   W",
		"W     FFFFFFFFFFFF                     W",
		"W     FFFFFFFFFFFF     WFFFFFFFFFFFFFFFW",
		"W     FFFFFFFFFFFF     WFFFFFFFFFFFFFFFW",
		"W     FFFFFFFFFFFF     WFFFFFFFFFFFFFFFW",
		"W     FFFFFFFFFFFF     WFFFFFFFFFFFFFFFW",
		"W     FFFFFFFFFFFF     WFFFFFFFFFFFFFFFW",
		"W     FFFFFFFFFFFF     WFFFFFFFFFFFFFFFW",
		"W     FFFFFFFFFFFF     WFFFFFFFFFFFFFFFW",
		"W                      WFFFFFFFFFFFFFFFW",
		"W P          X     X   WFFFFFFFFFFFFFFFW",
		"WFFFFFFFFFFFFFFFFFWWWWWWFFFFFFFFFFFFFFFW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	};
	m_levels.push_back(Level4);

	String static Level5[H] = {
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
		"WFFFFFFFFFFFFFFFFFFFFFFFWWWWWWWWWWWWWWWW",
		"WFFFFFFFFFFFFFFFFFFFFFFF        E     WW",
		"WFFWWWFFFWFFFWFFWFWWWWFF              WW",
		"WFFWFFFFWFWFFWFWFFWFFFFF  FFFFFFFFFFFFFW",
		"WFFWFFFFWWWFFWWFFFWWWFFF  FFFFFFFFFFFFFW",
		"WFFWFFFWFFFWFWFWFFWFFFFF  FFFFFFFFFFFFFW",
		"WFFWWWFWFFFWFWFFWFWWWWFF  FWFFFWWWFWWWFW",
		"WFFFFFFFFFFFFFFFFFFFFFFF  FWFFFFWFFWFFFW",
		"WFFFFFFFFFFFFFFFFFFFFFFF  FWFFFFWFFWWFFW",
		"WFFWWWFFWWWFFFFFFWFFFFFF  FWFFFFWFFWFFFW",
		"WFFFWFFWFFFFFFFFWFWFFFFF  FWWWFWWWFWWWFW",
		"WFFFWFFFWWFFFFFFWWWFFFFF  FFFFFFFFFFFFFW",
		"WFFFWFFFFFWFFFFWFFFWFFFF  FFFFFFFFFFFFFW",
		"WFFWWWFWWWFFFFFWFFFWFFFF  FFFFFFFFFFFFFW",
		"W                         WFFFFFFFFFFFFW",
		"W  P    X X X X X X X X   WFFFFFFFFFFFFW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	};
	m_levels.push_back(Level5);

}


void World::setLevel(int level) {
	for (int i = 0; i < H; ++i) {
		World::TileMap[i] = m_levels.at(level)[i];
	}
	World::current_level = level;
}
/*
void World::updateModel(GameModel * model) {
	float player_x;
	float player_y;
	std::vector<sf::Vector2f> enemy_positions;
	FloatRect door;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
		{
			if (World::TileMap[i][j] == 'X') {
				enemy_positions.push_back(sf::Vector2f(j * UNIT, i * UNIT));
			}
			else if (World::TileMap[i][j] == 'P') {
				player_x = j * UNIT;
				player_y = j * UNIT;
			}
			else if (World::TileMap[i][j] == 'E') {
				// set the rectangle of the door to a space just above the floor
				// where the door contacts the ground
				door = FloatRect((j + 0.45) * UNIT, (i + 2) * UNIT - 10,
					UNIT / 10.0, UNIT);
			}
		}
	}
	std::tuple<float, float, std::vector<sf::Vector2f>, FloatRect> values;
	values.
	model->configure(player_x, player_y, enemy_positions, door);
}
*/
