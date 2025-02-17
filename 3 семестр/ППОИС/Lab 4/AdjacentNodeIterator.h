#include "Node.h"
#include "Arc.h"

//+++Итератор смежных данной вершине вершин
class AdjacentNodeIterator {
private:
	Nref Node;
	Nref CurrentNode;
public:
	AdjacentNodeIterator(Nref node, Nref currentnode);
	int operator*();
	AdjacentNodeIterator& operator++();
	bool operator!=(const AdjacentNodeIterator other);
};
