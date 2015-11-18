#include "level_map.h"

LevelMap::LevelMap(std::vector<WallBlock> blocks, int width, int height, Posn & target) {
	this->m_blocks = blocks;
	this->m_width = width;
	this->m_height = height;
	this->m_target = target;
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

Posn LevelMap::getTarget() {
	return m_target;
}

bool LevelMap::collisionTop(GameObject * object) {
	double top = object->getPosn()->getY();
	double x = object->getPosn()->getX();
	for (int index = 0; index < m_blocks.size(); ++index) {
		double bot_edge_y = m_blocks.at(index).getPosn()->getY() +
			m_blocks.at(index).getHeight();
		double top_edge_y = m_blocks.at(index).getPosn()->getY();
		double left_x = m_blocks.at(index).getPosn()->getX();
		double right_x = left_x + m_blocks.at(index).getWidth();
		double object_x = object->getPosn()->getX();
		if (top <= bot_edge_y && top >= top_edge_y &&
			x >= left_x && x <= right_x) {
			return true;
		}
	}
	return false;
}

bool LevelMap::collisionBottom(GameObject * object) {
	double bottom = object->getPosn()->getY() + object->getHeight();
	double x = object->getPosn()->getX();
	for (int index = 0; index < m_blocks.size(); ++index) {
		double bot_edge_y = m_blocks.at(index).getPosn()->getY() +
			m_blocks.at(index).getHeight();
		double top_edge_y = m_blocks.at(index).getPosn()->getY();
		double left_x = m_blocks.at(index).getPosn()->getX();
		double right_x = left_x + m_blocks.at(index).getWidth();
		double object_x = object->getPosn()->getX();
		if (bottom >= top_edge_y && bottom <= bot_edge_y &&
			x >= left_x && x <= right_x) {
			return true;
		}
	}
	return false;
}

bool LevelMap::collisionSide(GameObject * object) {
	Posn * p = object->getPosn();
	double left = p->getX();
	double top = p->getY();
	double bottom = top + object->getHeight();
	double right = left + object->getWidth();
	for (int index = 0; index < m_blocks.size(); ++index) {
		WallBlock b = m_blocks.at(index);
		double left_edge = b.getPosn()->getX();
		double right_edge = b.getPosn()->getX() + b.getWidth();
		double top_y = b.getPosn()->getY();
		double bottom_y = top_y + b.getHeight();

		// check for collisions on the left side
		if (left <= right_edge && left >= right_edge &&
			(bottom < bottom_y || top > top_y)) {
			return true;
		}
		// check for collisions on the right side
		if (right >= left_edge && right <= right_edge &&
			(bottom < bottom_y || top > top_y)) {
			return true;
		}
	}
	return false;
}