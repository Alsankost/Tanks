#ifndef __COLLISIONS_H__
#define __COLLISIONS_H__

struct Point {
	int x, y;
};

struct Line {
	Point p1, p2;
};

struct Rectangle {
	Point p1, p2;
};

/*bool isCollisionLines(Line l1, Line l2);
bool isCollisionLineAndRect(Line line, Rectangle rect);*/
bool isCollisionRectangles(Rectangle rect1, Rectangle rect2);

#endif