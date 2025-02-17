#include "Node.h"
#include "Arc.h"

//+++�������� �����
class ArcIterator {
private:
	Nref CurrentNode;
	Aref CurrentArc;
public:
	ArcIterator(Nref currentnode, Aref currentarc);
	int operator*();
	ArcIterator& operator++();
	bool operator!=(const ArcIterator other);
};