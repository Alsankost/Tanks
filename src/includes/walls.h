#ifndef __WALLS_H__
#define __WALLS_H__

#include "./game.h"

class BrickWall : public GameObject {
	private:
		bool flagHp;

	public:
		BrickWall(int x, int y);

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
};

#endif