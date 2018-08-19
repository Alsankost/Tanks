#include <iostream>
#include <GL/glut.h>

#include "./includes/walls.h"
#include "./includes/game.h"
#include "./includes/tanks.h"
#include "./includes/player.h"
#include "./includes/bullet.h"

#define W_WIDTH 640
#define W_HEIGHT 480

void reshape(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

Map* currentMap;

void render() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	currentMap->render();

	glutSwapBuffers();
}

void update(int) {
	currentMap->update();
	//render();
	//std::cout<<"A" << '\n';
	glutTimerFunc(10, update, 0);
}

Player* player = new Player(200, 200);

void pressKey(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_UP:
			player->sendMoveSignal(TD_FRONT, true);
			break;
		case GLUT_KEY_DOWN:
			player->sendMoveSignal(TD_BACK, true);
			break;
		case GLUT_KEY_LEFT:
			player->sendMoveSignal(TD_LEFT, true);
			break;
		case GLUT_KEY_RIGHT:
			player->sendMoveSignal(TD_RIGHT, true);
			break;
	}
}

void releaseKey(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_UP:
			player->sendMoveSignal(TD_FRONT, false);
			break;
		case GLUT_KEY_DOWN:
			player->sendMoveSignal(TD_BACK, false);
			break;
		case GLUT_KEY_LEFT:
			player->sendMoveSignal(TD_LEFT, false);
			break;
		case GLUT_KEY_RIGHT:
			player->sendMoveSignal(TD_RIGHT, false);
			break;
	}
}

void pressNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) exit(0);

	switch (key) {
		case ' ':
			player->fire(currentMap, new Bullet(player->getX(), player->getY(), player->getDirection()));
			break;
	}
}

int main(int argc, char **argv) {
	std::cout << "#1" << '\n';
	glutInit(&argc, argv);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(W_WIDTH, W_HEIGHT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Tanks 0.0.1a");
	std::cout << "#2" << '\n';

	currentMap = new Map(W_WIDTH, W_HEIGHT);
	currentMap->addObject(new BrickWall(100, 100));
	currentMap->addObject(new BrickWall(116, 100));
	currentMap->addObject(new BrickWall(132, 100));
	currentMap->addObject(new BrickWall(132, 116));
	currentMap->addObject(new BrickWall(132, 132));
	currentMap->addObject(player);
	std::cout << "#3" << '\n';

	glutReshapeFunc(reshape);
	glutDisplayFunc(render);
	glutIdleFunc(render);

	glutSpecialFunc(pressKey);
	glutKeyboardFunc(pressNormalKeys);
	glutSpecialUpFunc(releaseKey);
	glutIgnoreKeyRepeat(0);

	glutTimerFunc(10, update, 0);

	glutMainLoop();
	return 0;
}