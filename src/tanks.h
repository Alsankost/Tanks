#ifndef __TANKS_H__
#define __TANKS_H__

#include "./game.h"

class Tank : public GameObject {
	protected:
		bool flagHp = true;
		bool flagFriend;
		Direction direction;

	public:
		Tank(int x, int y, bool isFriend);

		virtual void start(Map* map);

		virtual void update(Map* map);
		virtual void dead(Map* map);
		virtual void collision(Map* map, GameObject* obj);

		virtual void addDamage(int val);

		virtual bool isTarget();
		virtual bool isSolid();
		virtual bool isDead();

		virtual void draw(int x, int y);

		void turnLeft();
		void turnRight();
		void forward(int k);

		void      setDirection(Direction dir);
		Direction getDirection();
};

#endif