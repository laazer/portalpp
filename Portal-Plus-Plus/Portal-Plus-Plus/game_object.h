#pragma once
#include <string>
#include "posn.h"
#include "velocity.h"

using namespace std;


class GameObject {
	public:
		GameObject(int hieght, int width, Posn & p); //square object constructor
		GameObject(GameObject & g); // copy constructor
		//returns true if 2 game objects have collided
		bool hasCollided(GameObject & g);
		friend bool operator==(const GameObject & g1, const GameObject & g2);
		friend bool operator!=(const GameObject & p1, const GameObject & p2);
		//moves a game object by the velocity vector
		void move(Velocity v);
		void setImage(string path);
		
	protected:
	
	private:
		int hieght; //in pixels
		int width; //in pixels
		Posn p;
		//the file path to the object's image reresentation, subject to change
		string image_name;
		
}