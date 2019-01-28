/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LivingObject.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/27 21:49:57 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIVINGOBJECT_HPP
#define  LIVINGOBJECT_HPP

# define BULLET '*'


class LivingObject
{
	protected:
		int		framecount;
		int		lives;
		int		xp;
		int		yp;
		int		xv;
		int		yv;
		bool	enemy;
		char	entity;
	
	public:
		LivingObject(int _x, int _y);
		LivingObject();
		LivingObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives, int _framecount);
		LivingObject(LivingObject& copy);
		virtual ~LivingObject(void);
		LivingObject& operator=(LivingObject& copyFrom);
		LivingObject* operator=(LivingObject* copyFrom);
<<<<<<< HEAD
=======

>>>>>>> 1722de01f396a38af148df4d9f2978ae563e7a1b
		int				getLives(void) const;
		void			update(void);
		void			shift(void);
		int				getX(void) const;
		int				getY(void) const;
		bool			isEnemy(void) const;
		char			getEntity(void) const;
		void			setEntity(char c);
		bool			takeDamage(void);
		void			setDead(void);
		int				getVecX(void);
		int				getVecY(void);
		void			setPX(int _x);
		int				liveChange(int number);
		
		void			upFramecount(void);
		int				getFramecount(void);
		void			setFramecount(int number);

		void			createBullet(bool _enemy, int _xp, int _yp, int _xv, int _yv, int _framecount);
		void			setEntity(char c, int _x, int _y);
};

#endif
