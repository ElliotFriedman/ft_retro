/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObjectList.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:11:33 by tkobb             #+#    #+#             */
/*   Updated: 2019/01/26 12:44:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_LIST
#define  GAME_OBJECT_LIST
#include <GameObject.hpp>

struct GameObjectListNode {
	GameObject	*obj;
	GameObjectListNode		*next;
};

class GameObjectList {
	GameObjectListNode	head;

public:
	GameObjectList(void);
	~GameObjectList(void);
	GameObjectList(GameObjectList& copyFrom);
	GameObjectList		&operator=(GameObjectList &rhs);
	GameObjectListNode	*getHead(void) const;
	void				add(GameObject &obj);
	void				remove(GameObject &obj);
	void				remove(GameObjectListNode &node);
};

#endif
