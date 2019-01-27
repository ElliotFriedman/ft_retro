/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 16:32:16 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYEROBJECT_HPP
#define  PLAYEROBJECT_HPP

#include "LivingObject.hpp"

class PlayerObject : public LivingObject
{
	
	public:
		bool	destroyOutOfBounds;
		PlayerObject( bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv, int _lives);
		PlayerObject(PlayerObject& copy);
		~PlayerObject(void);
		PlayerObject& operator=(PlayerObject& copyFrom);
};

#endif
