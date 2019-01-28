#include "Game.hpp"
#include <chrono>
#include "LivingObject.hpp"
#include <iostream>

Game::Game(int _w, int _h) : w(_w), h(_h)
{
	map = new LivingObject*[h];
	for (int x = 0; x < h; x++) {
		map[x] = new LivingObject[w]();
	}
}

Game::Game(Game &copyFrom): w(copyFrom.w), h(copyFrom.h)
{
	map = copyFrom.map;
}

Game::~Game()
{
	for (int x = 0; x < h; x++)
	{
		delete[] map[x];
	}
	delete[] map;

}

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
	int x = obj.getX();
	int y = obj.getY();
	if ((x < 0 || x >= w) || (y < 0 || y >= h)) {
		obj.setDead();
		return (0);
	}
	return (1);
}

int		Game::checkCollision(int x, int y)
{
	int vec_x = map[y][x].getVecX();

	int i = x;
	while (i < x + vec_x)
	{
		if (map[y][x + i].isAlive())
		{
			map[y][x].setDead();
			map[y][x + i].setDead();
			return 0;
		}	 
		i++;
	}
	return 1;
}

int		Game::moveObject(int x, int y)
{
	if (w > x ||) 
		int vec_x = map[y][x].getVecX();
	int vec_y  = map[y][x].getVecY();

	map[y + vec_y][x + vec_x] = map[y][x];
	map[y][x].setDead();
	return 
}


/*
 ** Runs through map/array. Checks for border bounds, collision. Then moves
 */
void	Game::updateObjects(void) {
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j  < w; j++)
		{
			if (map[i][j].getCount() > 0 && map[i][j].getCount() == frame_count)	//node in 2d map is 'alive' and other items can be assessed
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

void	Game::testLitterMap(void)
{
	int total = 0;
	for(int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (total % 5 == 0)
				map[y][x].setEntity('E');
			else if (total % 7 == 0)
				map[y][x].setEntity('.');
			else
				map[y][x].setEntity(' ');
			total++;
		}
	}
}
