#ifndef WORLD
#define WORLD

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <iostream>

using namespace sf;

const std::string ASSET_DIR = "../assets";

const int UNIT = 32;

float static offsetX = 0;
float static offsetY = 0;

const int H = 18;
const int W = 40;

String static TileMap[H] = {
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
	"W                                      W",
	"W                                      W",
	"W                                      W",
	"W                                      W",
	"W                                      W",
	"W                                      W",
	"W                                      W",
	"W                                      W",
	"W                                      W",
	"W                                      W",
	"W                         WWW          W",
	"W                         WWW          W",
	"W         FFFFFFFFF       WWW          W",
	"W       FFFFFFFFFFFF      WWW          W",
	"W      FFFFFFFFFFFFFF     WWW          W",
	"W     FFFFFFFFFFFFFFFF    WWW          W",
	"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"
};
#endif // WORLD

