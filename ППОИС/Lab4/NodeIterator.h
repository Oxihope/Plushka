#include "Node.h"
#include "Arc.h"

//+++Итератор вершин
class NodeIterator {
private:
	Nref CurrentNode;
public:
	NodeIterator(Nref currentNode);
	int operator*();
	NodeIterator& operator++();
	bool operator!=(const NodeIterator other);
};