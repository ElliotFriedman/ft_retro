/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LivingObject.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 23:25:22 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIVINGOBJECT_HPP
#define  LIVINGOBJECT_HPP

#include "GameObject.hpp"

class LivingObject// : public GameObject
{
	protected:
		int		lives;
		int		xp;
		int		yp;
		int		xv;
		int		yv;
		bool	enemy;
		char	entity;
	
	/*	
		GameObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv);
		GameObject(GameObject& copy);
		~GameObject(void);
		GameObject& operator=(GameObject& copyFrom);
	*/
	public:
		LivingObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives);
		LivingObject(LivingObject& copy);
		virtual ~LivingObject(void);
		LivingObject& operator=(LivingObject& copyFrom);
		int				getLives(void) const;
		void			update(void);
		void			shift(void);
		int				getX(void) const;
		int				getY(void) const;
		bool			isEnemy(void) const;
		char			getEntity(void) const;
		virtual void	render(WINDOW *window) const;
		bool			takeDamage(void);
};

#endif
