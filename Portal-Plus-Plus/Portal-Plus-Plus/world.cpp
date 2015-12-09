#include "world.h"

String World::TileMap[H] = {
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

std::vector<String*> World::m_levels = std::vector<String*>();
int World::m_current_level = 0;

void World::initLevels() {
	String static Level1[H] = {
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

	String static Level6[H] = {
		"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF",
		"F                                      F",
		"F                                      F",
		"W                                   E  F",
		"W                                      F",
		"W                                   FF F",
		"W  P                                   F",
		"WFFFFWWWWFFFFFF  FFFFFFFFFFFFF         W",
		"W                                      W",
		"W     0    X X 00  X X         0       W",
		"WFFFFFFFFFFFFFF  FFFFFFFFFFFFFFFWWWWFFFW",
		"WFFFFFFFWWWWWWW  WWWWWWWWWWWWWWWWWWWWWWW",
		"WFFFFFFFWWWWWWW  WWWWWWWWWWWWWWWWWWWWWWW",
		"WFFFFFFFWWWWWWW  WWWWWWWWWWWWWWWWWWWWWWW",
		"WFFFFFFFWWWWWWW  WWWWWWWWWWWWWWWWWWWWWWW",
		"WFFFFFFFWWWWWWW  WWWWWWWWWWWWWWWWWWWWWWW",
		"WFFFFFFFWWWWWWW  WWWWWWWWWWWWWWWWWWWWWWW",
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
	};
	m_levels.push_back(Level6);

}


void World::setLevel(int level) {
	if (level < World::getNumLevels()) {
		for (int i = 0; i < H; ++i) {
			World::TileMap[i] = m_levels.at(level)[i];
		}
	}
	World::m_current_level = level;
	std::cout << "CURRENT LEVEL:  " << World::m_current_level << std::endl;
	std::cout << "MAX LEVELS:  " << World::getNumLevels() << std::endl;
}

void World::setCurrentLevel(int level) {
	World::m_current_level = level;
}

int World::getNumLevels() {
	return World::m_levels.size();
}

int World::getCurrentLevel() {
	return World::m_current_level;
}

bool World::isGameWon() {
	std::cout << "MADE IT" << std::endl;
	return World::getCurrentLevel() >= World::getNumLevels();
}
