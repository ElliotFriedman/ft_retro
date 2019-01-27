/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LivingObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 17:31:05 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LivingObject.hpp"
#include "LivingObject.hpp"
#include <iostream>

LivingObject::LivingObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives)// : enemy(_enemy), entity(_entity), xp(_xp), yp(_yp), xv(_xv), yv(_yv), lives(_lives)
{
	xp = _xp;
	yp = _yp;
	xv = _xv;
	yv = _yv;
	enemy = _enemy;
	entity = _entity;	
	lives = _lives;
	std::cout << "Living Object Constructor Called\n";
	if (lives < 1)
		std::cout << "Error, you must initialize a living object with lives\n\n";
}

LivingObject::LivingObject(LivingObject& copy)// : LivingObject(copy.enemy, copy.entity, copy.xp, copy.yp, copy.xv, copy.yv)
{
	xp = copy.xp;
	yp = copy.yp;
	xv = copy.xv;
	yv = copy.yv;
	enemy = copy.enemy;
	entity = copy.entity;	
	lives = copy.lives;
	lives = copy.lives;
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
	lives = copyFrom.lives;
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

void	LivingObject::update(void)
{
	xp += xv;
	yp += yv;
}

//virtual and will be overriden in child classes
void	LivingObject::render(WINDOW *window) const
{
	//make ncurses call with char entity
	mvwaddch(window, yp, xp, entity);
}

int				LivingObject::getX(void) const
{
	return xp;
}

int				LivingObject::getY(void) const
{
	return yp;
}

char			LivingObject::getEntity(void) const
{
	return entity;
}

bool            LivingObject::isEnemy(void) const
{
	return enemy;
}
