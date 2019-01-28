/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 20:25:26 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "LivingObject.hpp"
//# include <GameObject.hpp>
//# include "Enemy.hpp"
//# include "Bullet.hpp"
# include <curses.h>
# define MIN(a, b) ((a)>(b)?(a):(b))
# define MAX(a, b) ((a)<(b)?(a):(b))

class Game
{
	protected:
		int	w;
		int	h;
		int frame_count;	//keep track of frame count. When objects on map are alive they will keep the frame count in alive to know its been updated each frame
		LivingObject	**map;

	public:
		Game(int _w, int _h);
		Game(Game& copy);
		~Game(void);
		Game& operator=(Game& copyFrom);
//		void		run(WINDOW *window);
		int			checkBounds(LivingObject &obj);
		int			checkCollision(int x, int y);
		int			moveObject(int x, int y);
		void		dumpMap(void);
//		void		handleCollision(LivingObject &prev, GameObjectListNode &node);
	private:
//		void		renderObjects(WINDOW *window) const;
		void		updateObjects(void);
//		void		handleCollision(GameObject &prev, GameObjectListNode &node);
//		void		checkBounds(GameObject &obj);

};

#endif
