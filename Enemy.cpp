/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 15:07:17 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "Enemy.hpp"
#include <iostream>

EnemyObject::EnemyObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv) : GameObject(_enemy, _entity, _xp, _yp, _xv, _yv)
{
	std::cout << "Enemy Object Constructor Called\n";
}

EnemyObject::EnemyObject(EnemyObject& copy) : GameObject(copy.enemy, copy.entity, copy.xp, copy.yp, copy.xv, copy.yv)
{
	std::cout << "Enemy Object Copy Constructor Called\n";
}

EnemyObject::~EnemyObject(void)
{
	std::cout << "Enemy Object Destructor Called\n";
}

EnemyObject&  EnemyObject::operator=(EnemyObject& copyFrom)
{
	xp = copyFrom.xp;
	yp = copyFrom.yp;
	xv = copyFrom.xv;
	yv = copyFrom.yv;
	enemy = copyFrom.enemy;
	entity = copyFrom.entity;	
	return *this;
}


