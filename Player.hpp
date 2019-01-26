/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 13:02:27 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYEROBJECT_HPP
#define  PLAYEROBJECT_HPP

#include "GameObject.hpp"

class PlayerObject : public GameObject
{
	
	public:
		bool	destroyOutOfBounds;
		PlayerObject( bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv);
		PlayerObject(PlayerObject& copy);
		~PlayerObject(void);
		PlayerObject& operator=(PlayerObject& copyFrom);
};

#endif
