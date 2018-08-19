#include <iostream>

#include "./includes/game.h"

//GameObject========================================
GameObject::GameObject(int x, int y) {
	this->x = x;
	this->y = y;
}

GameObject::~GameObject() {

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

int GameObject::maskHeight() {
	return this->h_mask;
}

Rectangle GameObject::getMask() {
	return Rectangle{Point{this->x, this->y}, Point{this->x + this->w_mask, this->y + this->h_mask}};
}

void GameObject::setDirection(Direction dir) {
	this->direction = dir;
}

Direction GameObject::getDirection() {
	return this->direction;
}

//Map=============================================
bool Map::observeCollisions(GameObject* obj) {
	Rectangle objMask = obj->getMask();
	bool solidFlag = false;
	for(auto it = objects.begin(); it != objects.end(); ++it) {
		if (*it != obj) {
			GameObject* tmp = *it;
			if (isCollisionRectangles(tmp->getMask(), objMask)) {
				obj->collision(this, tmp);
				if (tmp->isSolid()) {
					solidFlag = true;
				}
			}
		}
	}
	return solidFlag && obj->isSolid();
}

Map::Map(int w, int h) {
	this->width  = w;
	this->height = h;
}

void Map::update() {
	for (int i = 0; i < objects.size(); i++) {
		GameObject* obj = objects[i];
		if (obj->isDead()) {
			obj->dead(this);
			objects.erase(objects.begin() + i);
			delete obj;
			continue;
		}
		int xp = obj->getX(),
		    yp = obj->getY();
		obj->update(this);
		bool stopFlag = observeCollisions(obj);
		if (stopFlag || obj->getX() < 0 || obj->getX() + obj->maskWidth() > this->width ||
			obj->getY() < 0 || obj->getY() + obj->maskHeight() > this->height) {
			obj->setPosition(xp, yp);
		}
	}
}

void Map::render() {
	for(auto it = objects.begin(); it != objects.end(); ++it) {
		GameObject* obj = *it;
		obj->draw(0, 0);
	}
}
		
void Map::addObject(GameObject* obj) {
	obj->start(this);
	objects.insert(objects.end(), obj);
}
/*
void Map::killObject(GameObject* obj) {
	obj->dead(this);
	objects.erase(objects);
}*/

bool Map::isTargetObjectsToRectangle(Rectangle rect) {
	for(auto it = objects.begin(); it != objects.end(); ++it) {
		GameObject* tmp = *it;
		if (tmp->isTarget() && isCollisionRectangles(tmp->getMask(), rect)) {
			return true;
		}
	}
	return false;
}