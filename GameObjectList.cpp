#include <GameObjectList.hpp>

/* Node */

GameObjectListNode::GameObjectListNode(GameObject &obj):
	obj(obj), next(nullptr), prev(nullptr)
{

}

GameObjectListNode::~GameObjectListNode(void) {
	
}

GameObjectListNode::GameObjectListNode(GameObjectListNode& copyFrom) {

}

GameObjectListNode::GameObjectListNode	&GameObjectListNode::operator=(GameObjectListNode &rhs) {

}

/* List */

GameObjectList::GameObjectList(void): head(nullptr) {
	
}

GameObjectList::~GameObjectList(void) {
	
}

GameObjectList::GameObjectList(GameObjectList& copyFrom) {
	head = copyFrom.head;
}

GameObjectList::GameObjectList	&GameObjectList::operator=(GameObjectList &rhs) {
	head = rhs.head;
}

void	GameObjectList::add(GameObject &o) {
	GameObjectListNode *n = new GameObjectListNode(o);
	n->next = head;
	head->prev = n;
	n->prev= nullptr;
	head = n;
}

void	GameObjectList::remove(GameObjectListNode &node) {
	if (node == head) {
		
	}
}
