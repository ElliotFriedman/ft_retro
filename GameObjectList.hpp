#ifndef GAME_OBJECT_LIST
#define  GAME_OBJECT_LIST
#include <GameObject.hpp>

struct GameObjectListNode {
	GameObject			*obj;
	GameObjectListNode	*next;
	GameObjectListNode	*prev;
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
