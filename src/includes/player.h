#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "./tanks.h"

class Player : public Tank {
	private:
		//Signals: FRONT BACK LEFT RIGHT
		bool moveSignals[4] = {false, false, false, false};

	public:
		Player(int x, int y);

		virtual void start(Map* map);

		virtual void update(Map* map);
		virtual void dead(Map* map);
		virtual void collision(Map* map, GameObject* obj);
		virtual void outsideMap(Map* map);

		virtual void addDamage(int val);

		virtual bool isTarget();
		virtual bool isSolid();
		virtual bool isDead();

		virtual void draw(int x, int y);

		void sendMoveSignal(Direction dir, bool val);
};

#endif