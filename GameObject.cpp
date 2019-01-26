/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 15:08:31 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"

GameObject::GameObject(
		bool _enemy,
		char _entity,
		int _xp,
		int _yp, 
		int _xv, 
		int _yv) :
	xp(_xp),
	yp(_yp),
	xv(_xv),
	yv(_yv),
	enemy(_enemy),
	entity(_entity)
{
	std::cout << "Called GameObject Constructor\n";
}

GameObject::GameObject(GameObject& copy)
{
	xp = copy.xp;
	yp = copy.yp;
	xv = copy.xv;
	yv = copy.yv;
	enemy = copy.enemy;
	entity = copy.entity;
}

GameObject::~GameObject(void)
{	
	std::cout << "Called GameObject Destructor\n";
}

GameObject& GameObject::operator=(GameObject& copyFrom)
{
	xp = copyFrom.xp;
	yp = copyFrom.yp;
	xv = copyFrom.xv;
	yv = copyFrom.yv;
	enemy = copyFrom.enemy;
	entity = copyFrom.entity;
	return *this;
}

void	GameObject::update(void)
{
	xp += xv;
	yp += yv;
}

//virtual and will be overriden in child classes
void	GameObject::render(WINDOW *window) const
{
	//make ncurses call with char entity
	mvwaddch(window, yp, xp, entity);
}

int				GameObject::getX(void) const
{
	return xp;
}

int				GameObject::getY(void) const
{
	return yp;
}

char			GameObject::getEntity(void) const
{
	return entity;
}
