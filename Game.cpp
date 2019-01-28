#include "Game.hpp"
//#include <Enemy.hpp>
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
	//	objects = copyFrom.objects;
		map = copyFrom.map;
}

Game::~Game() {};

Game	&Game::operator=(Game &rhs) {
	w = rhs.w;
	h = rhs.h;
	//objects = rhs.objects;
	map = rhs.map;
	return *this;
}

// void	Game::renderObjects(WINDOW *window) const {
// 	GameObjectListNode	*node;

// 	node = objects.getHead();
// 	while (node) {
// 		node->obj->render(window);
// 		node = node->next;
// 	}
// 	wrefresh(window);
// }

/*
 ** for each x, y between prev and obj, check map for other objects and handle
 ** remove node from list if an object gets destroyed
 ** update the map with the new positions
 */
// void	Game::handleCollision(LivingObject &prev, GameObjectListNode &node) {
// 	int	sy = MIN(prev.getY(), node.obj->getY());
// 	int	my = MAX(prev.getY(), node.obj->getY());
// 	int	sx = MIN(prev.getX(), node.obj->getX());
// 	int	mx = MAX(prev.getX(), node.obj->getX());
// 	int x, y;

// 	for (x = sx; x <= mx; x++) {
// 		for (y = sy; y <= my; y++) {
// 			if (map[y][x]) {
// 				if (map[y][x]->isEnemy() != node.obj->isEnemy()) {
// 					if (map[y][x]->takeDamage() == false) {

// 						//figure out how to delete this properly
// 						delete map[y][x];

// 						map[y][x] = nullptr;

// 					}
// 					if (node.obj->takeDamage() == false) {
					
// 						objects.remove(*node.obj);
						
// 						delete node.obj;
// 					}
// 				}
// 			}
// 		}
// 	}
// }

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
	int vec_y  = map[y][x].getVecY();

	if (!map[y + vec_y][x + vec_x].isAlive())
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
			if (map[i][j].getCount() > 0 && map[i][j].getCount() == frame_count)	//node in 2d map is 'alive' and other items can be assessed
			{
				if (checkBounds(map[i][j]) && checkCollision(j, i))//if colision occurs, remove the lesser live item. If requal.. remove both
					moveObject(j, i);	//moves object and also updates in framecount
			}
		}
	}
}

// void	Game::run(WINDOW *window) {
// 	//std::high_resolution_clock::time_point fps24;
// 	std::chrono::time_point<std::chrono::system_clock> start, end; 
// 	std::chrono::duration<double> elapsed_seconds;


// 	start = std::chrono::system_clock::now(); 
// 	end = std::chrono::system_clock::now(); 
// 	elapsed_seconds = end - start;

// 	while (true) { //TODO: Limit frame rate
// 		//		int i = 0;
// 		//		while ( i < 48 )
// 		//		{
// 		end = std::chrono::system_clock::now();
// 		start = std::chrono::system_clock::now();
// 		elapsed_seconds = end - start;
// 		//this tells us how long till we refresh frames
// 		while (elapsed_seconds.count() < 0.0207f)
// 		{
// 			//always update keystrokes
// 			updateObjects();
// 			elapsed_seconds = end - start;
// 			end = std::chrono::system_clock::now();
// 		}
// 		//			i++;
// 		//update 48 times a second
// 		renderObjects(window);
// 		//			std::cout << std::to_string(i) + "\n";
// 		//		}

// 		//updateObjects();
// 		//renderObjects(window);
// 	}
// }


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