#include "./player.h"

#define PLAYER_SPEED 5

Player::Player(int x, int y):Tank(x, y, true) {

}

void Player::start(Map* map) {
	Tank::start(map);
}

void Player::update(Map* map) {
	Tank::update(map);

	for (int i = 0; i < 4; i++) {
		if (moveSignals[i]) {
			Tank::forward(PLAYER_SPEED);
			break;
		}
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

void Player::sendMoveSignal(TankDirection dir, bool val) {
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
