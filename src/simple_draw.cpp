#include <GL/glut.h>

#include "./includes/simple_draw.h"

void drawRectangle(int x, int y, int w, int h) {
	glBegin(GL_QUADS);
		glVertex3f(    x,     y, 0);
		glVertex3f(x + w,     y, 0);
		glVertex3f(x + w, y + h, 0);
		glVertex3f(    x, y + h, 0);
	glEnd();
}