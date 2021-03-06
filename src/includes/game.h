#ifndef __GAME_H__
#define __GAME_H__

#include <vector>

#include "./collisions.h"

enum Direction {
	TD_FRONT,
	TD_BACK,
	TD_LEFT,
	TD_RIGHT
};

class Map;

class GameObject {
	protected:
		int x, y;
		int w_mask, h_mask;
		Direction direction;

	public:
		GameObject(int x, int y);
		virtual ~GameObject();

		//Custom:
		virtual void start(Map* map)  = 0;
		virtual void update(Map* map) = 0;
		virtual void dead(Map* map)	  = 0;
		virtual void collision(Map* map, GameObject* obj)  = 0;
		virtual void outsideMap(Map* map) = 0;

		virtual void addDamage(int val) = 0;

		virtual bool isTarget() = 0;
		virtual bool isSolid()  = 0;
		virtual bool isDead()   = 0;

		virtual void draw(int x, int y) = 0;

		//Native:
		int  getX();
		int  getY();
		void setX(int x);
		void setY(int y);
		void setPosition(int x, int y);

		int maskWidth();
		int maskHeight();

		Rectangle getMask();

		void      setDirection(Direction dir);
		Direction getDirection();
};

class Map {
	private:
		int width;
		int height;
		std::vector<GameObject*> objects;

		bool observeCollisions(GameObject* obj);

	public:
		Map(int w, int h);

		void update();
		void render();

		void addObject(GameObject* obj);
		//void killObject(GameObject* obj);

		bool isTargetObjectsToRectangle(Rectangle rect);
};

#endif