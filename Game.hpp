/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 11:17:57 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define  GAME_HPP

#include "GameObject.hpp"

class Game
{
	protected:
		int	xh;
		int yh;
		GameObject	*map[yh][xh];
		
	public:
		Game(int _xw, int _yw);
		Game(Game& copy);
		~Game(void);
		Game& operator=(Game& copyFrom);
		void			run(void);

};

#endif
