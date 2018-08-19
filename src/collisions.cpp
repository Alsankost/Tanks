#include "./includes/collisions.h"
/*
bool isCollisionLines(Line l1, Line l2) {
	double A1 = (l1.p1.y - l1.p2.y) / (l1.p1.x - l1.p2.x);
	double A2 = (l2.p1.y - l2.p2.y) / (l2.p1.x - l2.p2.x);
	double b1 = l1.p1.y - A1 * l1.p1.x;
	double b2 = l2.p1.y - A2 * l2.p1.x;
	 
	if (A1 == A2) {
	    return false;
	}

	double Xa = (b2 - b1) / (A1 - A2);
	 
	if ((Xa < max(l1.p1.x, p3.x)) || (Xa > min(l1.p2.x, l2.p2.x))) {
	    return false;
	}
	else {
	    return true;
	}
}


bool isCollisionLineAndRect(Line line, Rectangle rect) {
	if ((line.p1.x >= rect.p1.x && line.p1.x <= rect.p2.x &&
		 line.p1.y >= rect.p1.y && line.p1.y <= rect.p2.y) ||
		(line.p2.x >= rect.p1.x && line.p2.x <= rect.p2.x &&
		 line.p2.y >= rect.p1.y && line.p2.y <= rect.p2.y)) {
		return true;
	}

	bool flag = isCollisionLines(line, Line{rect.p1, Point{rect.p2.x, rect.p1.y}});
	if (flag) return true;
	flag = isCollisionLines(line, Line{rect.p2, Point{rect.p2.x, rect.p3.y}});
	Line l3 = Line{rect.p3, Point{rect.p4.x, rect.p3.y}};
	Line l3 = Line{rect.p4, Point{rect.p4.x, rect.p1.y}};

}*/

bool isCollisionRectangles(Rectangle rect1, Rectangle rect2) {
	Point ps1[4] = {
		rect1.p1,
		Point{rect1.p2.x, rect1.p1.y},
		rect1.p2,
		Point{rect1.p1.x, rect1.p2.y}
	};

	Point ps2[4] = {
		rect2.p1,
		Point{rect2.p2.x, rect2.p1.y},
		rect2.p2,
		Point{rect2.p1.x, rect2.p2.y}
	};

	for (int i = 0; i < 4; i++) {
		Point tmp = ps1[i];
		if (tmp.x >= rect2.p1.x && tmp.x <= rect2.p2.x &&
			tmp.y >= rect2.p1.y && tmp.y <= rect2.p2.y) {
			return true;
		}

		tmp = ps2[i];
		if (tmp.x >= rect1.p1.x && tmp.x <= rect1.p2.x &&
			tmp.y >= rect1.p1.y && tmp.y <= rect1.p2.y) {
			return true;
		}
	}

	return false;
}