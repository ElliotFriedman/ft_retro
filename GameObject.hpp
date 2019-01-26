/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/26 15:08:19 by efriedma         ###   ########.fr       */
=======
/*   Updated: 2019/01/26 12:47:14 by tkobb            ###   ########.fr       */
>>>>>>> 7d11b03ce436d831aacca2a04dbfc2b1eb469e74
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
#define  GAMEOBJECT_HPP

#include <curses.h>
#include <iostream>

class GameObject
{
	protected:
		int	xp;
		int yp;
		int	xv;
		int yv;
		bool	enemy;
		char	entity;
		
	public:
		GameObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv);
		GameObject(GameObject& copy);
		~GameObject(void);
		GameObject& operator=(GameObject& copyFrom);
		void			update(void);
		void			shift(void);
		int				getX(void) const;
		int				getY(void) const;
		char			getEntity(void) const;
		virtual void	render(WINDOW *window) const;
};

#endif
