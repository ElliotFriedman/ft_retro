/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LivingObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 11:44:02 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIVINGOBJECT_HPP
#define  LIVINGOBJECT_HPP

#include "GameObject.hpp"

class LivingObject : public GameObject
{
	protected:
		int	xp;
		int yp;
		int	xv;
		int yv;
		bool	enemy;
		char	entity;
		
	public:
		LivingObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv);
		LivingObject(LivingObject& copy);
		~LivingObject(void);
		LivingObject& operator=(LivingObject& copyFrom);
};

#endif
