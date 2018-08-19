#ifndef __BULLET_H__
#define __BULLET_H__

#include "./game.h"

class Bullet : public GameObject {
	protected:
		int speed;
		int damage;
		bool flagHp = true;
		Direction direction;

	public:
		Bullet(int x, int y, Direction dir, int speed, int damage);
		Bullet(int x, int y, Direction dir);

		//Custom:
		virtual void start(Map* map);
		virtual void update(Map* map);
		virtual void dead(Map* map);
		virtual void collision(Map* map, GameObject* obj);

		virtual void addDamage(int val);

		virtual bool isTarget();
		virtual bool isSolid();
		virtual bool isDead();

		virtual void draw(int x, int y);
};

#endif
