/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:42:11 by tkobb             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/26 17:38:48 by efriedma         ###   ########.fr       */
=======
/*   Updated: 2019/01/26 17:25:24 by tkobb            ###   ########.fr       */
>>>>>>> f67171a9c69ca617447c88668895477360fedf89
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>
#include <GameObjectList.hpp>
#include <Enemy.hpp>
#include <chrono>

Game::Game(int _w, int _h):
	w(_w), h(_h) {
	map = new GameObject**[w];
	for (int x = 0; x < h; x++) {
		map[x] = new GameObject*;
	}
}

Game::Game(Game &copyFrom):
	w(copyFrom.w), h(copyFrom.h) {
	objects = copyFrom.objects;
	map = copyFrom.map;
}

Game	&Game::operator=(Game &rhs) {
	w = rhs.w;
	h = rhs.h;
	objects = rhs.objects;
	map = rhs.map;
	return *this;
}

void	Game::renderObjects(WINDOW *window) const {
	GameObjectListNode	*node;
	
	node = objects.getHead();
	while (node) {
		node->obj->render(window);
		node = node->next;
	}
	wrefresh(window);
}

/*
** for each x, y between prev and obj, check map for other objects and handle
** remove node from list if an object gets destroyed
** update the map with the new positions
*/
void	Game::handleCollision(GameObject &prev, GameObjectListNode &node) {
	int	sy = MIN(prev.getY(), node.obj->getY());
	int	my = MAX(prev.getY(), node.obj->getY());
	int	sx = MIN(prev.getX(), node.obj->getX());
	int	mx = MAX(prev.getX(), node.obj->getX());
	int x, y;

	for (x = sx; x <= mx; x++) {
		for (y = sy; y <= my; y++) {
			if (map[y][x]) {
				if (map[y][x]->isEnemy() != node.obj->isEnemy()) {
					if (map[y][x]->takeDamage() == false) {
						delete map[y][x];
						map[y][x] = nullptr;
					}
					if (node.obj->takeDamage() == false) {
						objects.remove(*node.obj);
						delete node.obj;
					}
				}
			}
		}
	}
}

/*
** check is obj is in bounds
** delete it if necesary, remove from object list and map
*/
void	Game::checkBounds(GameObject &obj) {
	int x = obj.getX();
	int y = obj.getY();
	if ((x < 0 || x >= w) || (y < 0 || y >= h)) {
		// 
	}
}

/*
** Update objects, check for collisions, delete if necesary
*/
void	Game::updateObjects(void) {
	GameObjectListNode	*node;

	node = objects.getHead();
	while (node) {
		GameObject prev(*node->obj);
		node->obj->update();
		checkBounds(*node->obj);
		handleCollision(prev, *node);
		node = node->next;
	}
}

void	Game::run(WINDOW *window) {
	std::high_resolution_clock::time_point fps24;

	while (true) { //TODO: Limit frame rate
		
		updateObjects();
		renderObjects(window);
	}
}
