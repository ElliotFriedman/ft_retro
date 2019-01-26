/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LivingObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 15:55:15 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIVINGOBJECT_HPP
#define  LIVINGOBJECT_HPP

#include "GameObject.hpp"

class LivingObject : public GameObject
{
	protected:
		int lives;
	
	public:
		LivingObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives);
		LivingObject(LivingObject& copy);
		~LivingObject(void);
		LivingObject& operator=(LivingObject& copyFrom);
		int		getLives(void) const;
		bool	takeDamage(void);

};

#endif
