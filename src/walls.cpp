#include <iostream>

#include <GL/glut.h>

#include "./includes/walls.h"

BrickWall::BrickWall(int x, int y):GameObject(x, y) {
}

void BrickWall::start(Map* map) {
	this->flagHp = true;
	this->w_mask = 16;
	this->h_mask = 16;
}

void BrickWall::update(Map* map) { }
void BrickWall::dead(Map* map) { }
void BrickWall::collision(Map* map, GameObject* obj) { };


void BrickWall::outsideMap(Map* map) { }

void BrickWall::addDamage(int val) {
	if (val > 0) {
		this->flagHp = false;
	}
}

bool BrickWall::isTarget() {
	return false;
}

bool BrickWall::isSolid() {
	return true;
}

bool BrickWall::isDead() {
	return !this->flagHp;
}

void BrickWall::draw(int x, int y) {
	glColor3f(0.6, 0.6, 0.2);
	glBegin(GL_QUADS);
		glVertex3f(this->x     , this->y     , 0);
		glVertex3f(this->x + 16, this->y     , 0);
		glVertex3f(this->x + 16, this->y + 16, 0);
		glVertex3f(this->x     , this->y + 16, 0);
	glEnd();
}