#include "Game.hpp"
#include <chrono>
#include "LivingObject.hpp"
#include <iostream>

Game::Game(int _w, int _h):
	w(_w), h(_h) {
		map = new LivingObject*[h];
		for (int x = 0; x < h; x++) {
			map[x] = new LivingObject[w]();
		}
	}

Game::Game(Game &copyFrom):
	w(copyFrom.w), h(copyFrom.h) {
		map = copyFrom.map;
}

Game::~Game() {};

Game	&Game::operator=(Game &rhs) {
	w = rhs.w;
	h = rhs.h;
	map = rhs.map;
	return *this;
}

/*
 ** check is obj is in bounds
 ** delete it if necesary, remove from object list and map
 */
int		Game::checkBounds(LivingObject &obj) {
	int x = obj.getX() + obj.getVecX();
	int y = obj.getY() + obj.getVecY();
	if ((x < 0 || x >= w) || (y < 0 || y >= h)) {
		obj.setDead();
		return (0);
	}
	return (1);
}

int		Game::checkCollision(int x, int y)
{
	int vec_x = map[y][x].getVecX();
	int vec_y  = map[y][x].getVecY();

	if (map[y + vec_y][x + vec_x].getFramecount() > 0)
	{
		map[y][x].setDead();
		map[y + vec_y][x + vec_x].setDead();
		return 0;
	}
	return 1;
}

int		Game::moveObject(int x, int y)
{
	int vec_x = map[y][x].getVecX();
	int vec_y  = map[y][x].getVecY();

	map[y + vec_y][x + vec_x] = map[y][x];
	map[y][x].setDead();
}


/*
 ** Runs through map/array. Checks for border bounds, collision. Then moves
 */
void	Game::updateObjects(void) {
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j  < w; j++)
		{
			if (map[i][j].getFramecount() > 0 && map[i][j].getFramecount() == frame_count)	//node in 2d map is 'alive' and other items can be assessed
			{
				if (checkBounds(map[i][j]) && checkCollision(j, i))//if colision occurs, remove the lesser live item. If requal.. remove both
					moveObject(j, i);	//moves object and also updates in framecount
			}
		}
	}
}

void	Game::dumpMap(void)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			std::cout << map[y][x].getEntity();
		}
		std::cout << "\n";
	}
}