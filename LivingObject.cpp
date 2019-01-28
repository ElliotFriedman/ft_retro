/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LivingObject.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/27 21:50:20 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LivingObject.hpp"
#include <iostream>

LivingObject::LivingObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives, int _framecount)// : enemy(_enemy), entity(_entity), xp(_xp), yp(_yp), xv(_xv), yv(_yv), lives(_lives)
{
	xp = _xp;
	yp = _yp;
	xv = _xv;
	yv = _yv;
	enemy = _enemy;
	entity = _entity;	
	lives = _lives;
	std::cout << "Living Object Constructor Called\n";
	framecount = _framecount;
	if (lives < 1)
		std::cout << "Error, you must initialize a living object with lives\n\n";
}

LivingObject::LivingObject(void) {
	framecount = -1;
	entity = ' ';
};

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
	framecount = copy.framecount;
	std::cout << "Living Object Copy Constructor Called\n";
}

LivingObject::~LivingObject(void)
{
	std::cout << "Living Object Destructor Called\n";
}

LivingObject*  LivingObject::operator=(LivingObject* copyFrom)
{
	xp = copyFrom->xp;
	yp = copyFrom->yp;
	xv = copyFrom->xv;
	yv = copyFrom->yv;
	enemy = copyFrom->enemy;
	entity = copyFrom->entity;	
	lives = copyFrom->lives;
	framecount = copyFrom->framecount;
	return this;
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
	framecount = copyFrom.framecount;
	return *this;
}

int			LivingObject::getLives(void) const
{
	return lives;
}

void	LivingObject::update(void)
{
	xp += xv;
	yp += yv;
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

bool			LivingObject::takeDamage(void)
{
	std::cout << "Took damage\n";
	return --lives > 0 ? true : false;
}

void				LivingObject::setDead(void)
{
	this->framecount = -1;
}

int				LivingObject::getVecX(void)
{
	return (this->xv);
}

int				LivingObject::getVecY(void)
{
	return (this->yv);
}

void			LivingObject::upFramecount(void)
{
	this->framecount += 1;
}

int				LivingObject::getFramecount(void)
{
	return this->framecount;
}

void			LivingObject::setFramecount(int number)
{
	this->framecount = number;
}

/*
*Will change object live count (up or down) and return 0 is object is dead and 1 if still alive
*/

int			LivingObject::liveChange(int number)
{
	this->lives += number;
	if (this->lives > 0)
		return this->lives;
	return 0;
}

// void		LivingObject::setEntity(char E)
// {
// 	this->entity = E;
// }
