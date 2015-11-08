#include "level_map.h"

LevelMap::LevelMap(std::vector<WallBlock> blocks, int width, int height) {
	this->m_blocks = blocks;
	this->m_width = width;
	this->m_height = height;
}

std::vector<WallBlock> LevelMap::getBlocks() {
	return m_blocks;
}

int LevelMap::getWidth() {
	return m_width;
}

int LevelMap::getHeight() {
	return m_height;
}
