#include "wall_block.h"

WallBlock::WallBlock(int width, int height, Posn & p) :
	GameObject(height, width, p) {
}


WallBlock::WallBlock(const WallBlock & wb) {
	this->m_height = wb.m_height;
	this->m_pos = wb.m_pos;
	this->m_width = wb.m_width;
}
