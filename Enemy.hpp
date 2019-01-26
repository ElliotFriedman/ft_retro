/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 15:08:42 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYOBJECT_HPP
#define  ENEMYOBJECT_HPP

#include "GameObject.hpp"

class EnemyObject : public GameObject
{
	
	public:
		bool	destroyOutOfBounds;
		EnemyObject( bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv);
		EnemyObject(EnemyObject& copy);
		~EnemyObject(void);
		EnemyObject& operator=(EnemyObject& copyFrom);
};

#endif
