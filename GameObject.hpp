/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:43:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 12:47:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
#define  GAMEOBJECT_HPP

class GameObject
{
	protected:
		int	xp;
		int yp;
		int	xv;
		int yv;
		bool	enemy;
		char	entity;
		
	public:
		GameObject(bool _enemy, char _entity, int _xp, int _yp, int _xv, int _yv);
		GameObject(GameObject& copy);
		~GameObject(void);
		GameObject& operator=(GameObject& copyFrom);
		void			update(void);
		virtual void	render(void) const;
		int				getX(void) const;
		int				getY(void) const;

};

#endif
