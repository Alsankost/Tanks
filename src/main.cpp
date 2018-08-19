#include <iostream>
#include <GL/glut.h>

#include "./walls.h"
#include "./game.h"
#include "./tanks.h"
#include "./player.h"
#include "./bullet.h"

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
		case GLUT_KEY_HOME:
			currentMap->addObject(new Bullet(player->getX(), player->getY(), player->getDirection()));

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

void processNormalKeys(unsigned char key, int x, int y) {
	//std::cout << key;
	//if (key == 27) exit(0);

	if (key == 'w') {
		player->setDirection(TD_FRONT);
		player->forward(5);
	}

	if (key == 's') {
		player->setDirection(TD_BACK);
		player->forward(5);
	}

	if (key == 'd') {
		player->setDirection(TD_RIGHT);
		player->forward(5);
	}

	if (key == 'a') {
		player->setDirection(TD_LEFT);
		player->forward(5);
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
	glutSpecialUpFunc(releaseKey);
	glutIgnoreKeyRepeat(0);

	glutTimerFunc(10, update, 0);

	glutMainLoop();
	return 0;
}