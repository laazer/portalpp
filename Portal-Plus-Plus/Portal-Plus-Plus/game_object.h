#pragma once
#include <string>
#include "posn.h"
#include "velocity.h"

using namespace std;


class GameObject {
	public:
		GameObject() = default;
		GameObject(int height, int width, Posn & p); //square object constructor
		GameObject(GameObject & g); // copy constructor
		//returns true if 2 game objects have collided
		bool hasCollided(GameObject & g);
		friend bool operator ==(const GameObject & g1, const GameObject & g2);
		friend bool operator !=(const GameObject & p1, const GameObject & p2);
		//moves a game object by the velocity vector
		void move(Velocity v);
		void setImage(string path);
		// returns the width/height of this object
		int getWidth();
		int getHeight();
		// returns the position of this object
		Posn getPosn();
		
	protected:
		int m_height; //in pixels
		int m_width; //in pixels
		Posn m_pos;

	private:
		
		//the file path to the object's image reresentation, subject to change
		string image_name;

		
};