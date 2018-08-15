#include "./game.h"

class GameObject {
	private:
		int x, y;
		int w_mask, h_mask;

virtual GameObject::GameObject() {

}

virtual GameObject::~GameObject() {

}

int GameObject::getX() {
	return this->x;
}

int GameObject::getY() {
	return this->y;
}

void GameObject::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

int GameObject::maskWidth() {
	return this->w_mask;
}

int GameObject::heightMask() {
	return this->h_mask;
}