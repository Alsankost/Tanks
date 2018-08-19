#include <GL/glut.h>


#include "./includes/bullet.h"

#define DEFAULT_BULLET_SPEED 8
#define DEFAULT_BULLET_DAMAGE 1

Bullet::Bullet(int x, int y, Direction dir, int speed, int damage):GameObject(x, y) {
	this->setPosition(x, y);
	this->direction = dir;
	this->speed     = speed;
	this->damage    = damage;
}

Bullet::Bullet(int x, int y, Direction dir):Bullet(x, y, dir, DEFAULT_BULLET_SPEED, DEFAULT_BULLET_DAMAGE) { }

void Bullet::start(Map* map) {
	this->w_mask = 4;
	this->h_mask = 4;
}

void Bullet::update(Map* map) {
	switch (this->direction) {
		case TD_FRONT:
			this->y -= this->speed;
			break;
		case TD_BACK:
			this->y += this->speed;
			break;
		case TD_LEFT:
			this->x -= this->speed;
			break;
		case TD_RIGHT:
			this->x += this->speed;
	}
}

void Bullet::dead(Map* map)	{}

void Bullet::collision(Map* map, GameObject* obj) {
	if (obj->isSolid()) {
		this->flagHp = false;
	}
};

void Bullet::addDamage(int val) {
	if (val > 0) this->flagHp = false;
}

bool Bullet::isTarget() {
	return false;
}

bool Bullet::isSolid() {
	return false;
}

bool Bullet::isDead() {
	return !flagHp;
}

void Bullet::draw(int x, int y) {
	glColor3f(0.4f, 0.4f, 0.4f);

	glBegin(GL_QUADS);
		glVertex3f(this->x    , this->y    , 0);
		glVertex3f(this->x + 4, this->y    , 0);
		glVertex3f(this->x + 4, this->y + 4, 0);
		glVertex3f(this->x    , this->y + 4, 0);
	glEnd();
}