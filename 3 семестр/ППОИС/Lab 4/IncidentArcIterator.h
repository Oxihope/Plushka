#include "Node.h"
#include "Arc.h"

//+++Итератор инцидентных данной вершине ребер
class IncidentArcIterator {
private:
	Nref CurrentNode;
	Aref CurrentArc;
public:
	IncidentArcIterator(Nref currentnode, Aref currentarc);
	int operator*();
	IncidentArcIterator& operator++();
	bool operator!=(const IncidentArcIterator other);
};
