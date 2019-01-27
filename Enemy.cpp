/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 16:41:52 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "LivingObject.hpp"
#include "Enemy.hpp"
#include <iostream>

EnemyObject::EnemyObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives) : /* GameObject(_enemy, _entity, _xp, _yp, _xv, _yv),*/ LivingObject(_enemy, _entity, _xp, _yp, _xv, _yv, _lives)
{
	std::cout << "Enemy Object Constructor Called\n";
}

EnemyObject::EnemyObject(EnemyObject& copy) : LivingObject(copy)
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


