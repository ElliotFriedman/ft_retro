#ifndef GAMEOBJECT_HPP
#define  GAMEOBJECT_HPP

#include <curses.h>
#include <iostream>

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
		void			shift(void);
		int				getX(void) const;
		int				getY(void) const;
		bool			isEnemy(void) const;
		char			getEntity(void) const;
		virtual void	render(WINDOW *window) const;
};

#endif
