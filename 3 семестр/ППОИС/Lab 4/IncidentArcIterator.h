#include "Node.h"
#include "Arc.h"

//+++�������� ����������� ������ ������� �����
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
