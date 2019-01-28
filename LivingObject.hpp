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
		LivingObject(void);
		LivingObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives, int _framecount);
		LivingObject(LivingObject& copy);
		virtual ~LivingObject(void);
		LivingObject& operator=(LivingObject& copyFrom);
		LivingObject* operator=(LivingObject* copyFrom);
		int				getLives(void) const;
		void			update(void);
		void			shift(void);
		int				getX(void) const;
		int				getY(void) const;
		bool			isEnemy(void) const;
		char			getEntity(void) const;
		bool			takeDamage(void);
		void			setDead(void);
		int				getVecX(void);
		int				getVecY(void);
		int				liveChange(int number);
		
		void			upFramecount(void);
		int				getFramecount(void);
		void			setFramecount(int number);
};

#endif
