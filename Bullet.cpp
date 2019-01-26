/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 15:04:03 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "Bullet.hpp"
#include <iostream>

BulletObject::BulletObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv) : GameObject(_enemy, _entity, _xp, _yp, _xv, _yv)
{
	std::cout << "Bullet Object Constructor Called\n";
}

BulletObject::BulletObject(BulletObject& copy) : GameObject(copy.enemy, copy.entity, copy.xp, copy.yp, copy.xv, copy.yv)
{
	std::cout << "Bullet Object Copy Constructor Called\n";
}

BulletObject::~BulletObject(void)
{
	std::cout << "Bullet Object Destructor Called\n";
}

BulletObject&  BulletObject::operator=(BulletObject& copyFrom)
{
	xp = copyFrom.xp;
	yp = copyFrom.yp;
	xv = copyFrom.xv;
	yv = copyFrom.yv;
	enemy = copyFrom.enemy;
	entity = copyFrom.entity;	
	return *this;
}

