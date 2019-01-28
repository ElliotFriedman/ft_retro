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
		int			checkBounds(LivingObject &obj);
		int			checkCollision(int x, int y);
		int			moveObject(int x, int y);
		void		dumpMap(void);
		void		testLitterMap(void);
	private:
		void		updateObjects(void);

};

#endif
