/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:42:11 by tkobb             #+#    #+#             */
/*   Updated: 2019/01/26 12:55:16 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>
#include <GameObjectList.hpp>

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

}


/*
** check is obj is in bounds
** delete it if necesary, remove from object list and map
*/
void			checkBounds(GameObject &obj) {

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
	while (true) { //TODO: Limit frame rate
		updateObjects();
		renderObjects(window);
	}
}
