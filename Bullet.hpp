/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 12:39:42 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETOBJECT_HPP
#define  BULLETOBJECT_HPP

#include "GameObject.hpp"

class BulletObject : public GameObject
{
	
	public:
		bool	destroyOutOfBounds;
		BulletObject( bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv);
		BulletObject(BulletObject& copy);
		~BulletObject(void);
		BulletObject& operator=(BulletObject& copyFrom);

};

#endif
