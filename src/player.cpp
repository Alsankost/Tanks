#include "./includes/player.h"

#define PLAYER_SPEED 3

Player::Player(int x, int y):Tank(x, y, true) {

}

void Player::start(Map* map) {
	Tank::start(map);
}

void Player::update(Map* map) {
	Tank::update(map);

	bool moveFlag = false;

	if (moveSignals[0]) {
		Tank::setDirection(TD_FRONT);
		moveFlag = true;		
	}

	if (moveSignals[1]) {
		Tank::setDirection(TD_BACK);
		moveFlag = true;		
	}

	if (moveSignals[2]) {
		Tank::setDirection(TD_LEFT);
		moveFlag = true;		
	}

	if (moveSignals[3]) {
		Tank::setDirection(TD_RIGHT);
		moveFlag = true;		
	}
	
	if (moveFlag) {
		Tank::forward(PLAYER_SPEED);
	}
}

void Player::dead(Map* map) {
	Tank::dead(map);
}

void Player::collision(Map* map, GameObject* obj) {
	Tank::collision(map, obj);
}

void Player::addDamage(int val) {
	Tank::addDamage(val);
}

bool Player::isTarget() {
	return true;
}

bool Player::isSolid() {
	return true;
}

bool Player::isDead() {
	return Tank::isDead();
}

void Player::draw(int x, int y) {
	Tank::draw(x, y);
}

void Player::sendMoveSignal(Direction dir, bool val) {
	switch (dir) {
		case TD_FRONT:
			moveSignals[0] = val;
			break;
		case TD_BACK:
			moveSignals[1] = val;
			break;
		case TD_LEFT:
			moveSignals[2] = val;
			break;
		case TD_RIGHT:
			moveSignals[3] = val;
	}
}
