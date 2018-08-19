#include <iostream>

#include <GL/glut.h>

#include "./includes/tanks.h"
#include "./includes/simple_draw.h"

Tank::Tank(int x, int y, bool isFriend):GameObject(x, y) {
	this->flagFriend = isFriend;
}

void Tank::start(Map* map) {
	this->w_mask = 32;
	this->h_mask = 32;

	this->direction = TD_RIGHT;
}

void Tank::update(Map* map) { }
void Tank::dead(Map* map) { }
void Tank::collision(Map* map, GameObject* obj) {

}

void Tank::addDamage(int val) {
	if (val > 0) flagHp = false;
}

bool Tank::isTarget() {
	return true;
}

bool Tank::isSolid() {
	return true;
}

bool Tank::isDead() {
	return !this->flagHp;
}

void Tank::draw(int x, int y) {
	if (flagFriend) {
		glColor3f(0, 0.4, 0);
	}
	else {
		glColor3f(0.4, 0, 0);
	}

	glBegin(GL_QUADS);
		glVertex3f(this->x     , this->y     , 0);
		glVertex3f(this->x + 32, this->y     , 0);
		glVertex3f(this->x + 32, this->y + 32, 0);
		glVertex3f(this->x     , this->y + 32, 0);
	glEnd();

	if (flagFriend) {
		glColor3f(0, 0.8, 0);
	}
	else {
		glColor3f(0.8, 0, 0);
	}

	switch (this->direction) {
		case TD_RIGHT:
			drawRectangle(this->x + 16, this->y + 12, 18, 8);
			break;
		case TD_BACK:
			drawRectangle(this->x + 12, this->y + 16, 8, 18);
			break;
		case TD_LEFT:
			drawRectangle(this->x - 2, this->y + 12, 18, 8);
			break;
		case TD_FRONT:
			drawRectangle(this->x + 12, this->y - 2, 8, 18);
	}
}

void Tank::turnLeft() {
	switch (this->direction) {
		case TD_RIGHT: this->direction = TD_FRONT; break;
		case TD_FRONT: this->direction = TD_LEFT;  break;
		case TD_LEFT:  this->direction = TD_BACK;  break;
		case TD_BACK:  this->direction = TD_RIGHT; break;
	}
}

void Tank::turnRight() {
	switch (this->direction) {
		case TD_RIGHT: this->direction = TD_BACK;  break;
		case TD_FRONT: this->direction = TD_RIGHT; break;
		case TD_LEFT:  this->direction = TD_FRONT; break;
		case TD_BACK:  this->direction = TD_LEFT;  break;
	}
}

void Tank::forward(int k) {
	switch (this->direction) {
		case TD_RIGHT: this->x += k; break;
		case TD_FRONT: this->y -= k; break;
		case TD_LEFT:  this->x -= k; break;
		case TD_BACK:  this->y += k;  break;
	}
}

void Tank::setDirection(Direction dir) {
	this->direction = dir;
}

Direction Tank::getDirection() {
	return this->direction;
}