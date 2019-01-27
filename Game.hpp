/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 17:03:38 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define  GAME_HPP

#include <GameObject.hpp>
#include <GameObjectList.hpp>
#include <curses.h>
#define MIN(a, b) ((a)>(b)?(a):(b))
#define MAX(a, b) ((a)<(b)?(a):(b))

class Game
{
	protected:
		int	w;
		int	h;
		GameObjectList	objects;
		GameObject		***map;

	public:
		Game(int _w, int _h);
		Game(Game& copy);
		~Game(void);
		Game& operator=(Game& copyFrom);
		void			run(WINDOW *window);

	private:
		void			renderObjects(WINDOW *window) const;
		void			updateObjects(void);
		void			handleCollision(GameObject &prev, GameObjectListNode &node);
		void			checkBounds(GameObject &obj);

};

#endif
