/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LivingObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 16:01:58 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "LivingObject.hpp"
#include <iostream>

LivingObject::LivingObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives) : GameObject(_enemy, _entity, _xp, _yp, _xv, _yv), lives(_lives)
{
	std::cout << "Living Object Constructor Called\n";
}

LivingObject::LivingObject(LivingObject& copy) : GameObject(copy.enemy, copy.entity, copy.xp, copy.yp, copy.xv, copy.yv)
{
	std::cout << "Living Object Copy Constructor Called\n";
}

LivingObject::~LivingObject(void)
{
	std::cout << "Living Object Destructor Called\n";
}

LivingObject&  LivingObject::operator=(LivingObject& copyFrom)
{
	xp = copyFrom.xp;
	yp = copyFrom.yp;
	xv = copyFrom.xv;
	yv = copyFrom.yv;
	enemy = copyFrom.enemy;
	entity = copyFrom.entity;	
	return *this;
}

int			LivingObject::getLives(void) const
{
	return lives;
}

bool		LivingObject::takeDamage(void)
{
	if (lives >= 1)
		lives--;
	return lives > 0 ? true : false;
}
