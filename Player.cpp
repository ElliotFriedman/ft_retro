/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 23:17:11 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "Player.hpp"
#include <iostream>

PlayerObject::PlayerObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives) : /*GameObject(_enemy, _entity, _xp, _yp, _xv, _yv),*/ LivingObject(_enemy, _entity, _xp, _yp, _xv, _yv, _lives)
{
	std::cout << "Player Object Constructor Called\n";
}

PlayerObject::PlayerObject(PlayerObject& copy) : LivingObject(copy.enemy, copy.entity, copy.xp, copy.yp, copy.xv, copy.yv, copy.lives)
{
	std::cout << "Player Object Copy Constructor Called\n";
}

PlayerObject::~PlayerObject(void)
{
	std::cout << "Player Object Destructor Called\n";
}

PlayerObject&  PlayerObject::operator=(PlayerObject& copyFrom)
{
	xp = copyFrom.xp;
	yp = copyFrom.yp;
	xv = copyFrom.xv;
	yv = copyFrom.yv;
	enemy = copyFrom.enemy;
	entity = copyFrom.entity;	
	return *this;
}


