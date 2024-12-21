#include "IncidentArcIterator.h"

IncidentArcIterator::IncidentArcIterator(Nref currentnode, Aref currentarc) {
	CurrentNode = currentnode;
	CurrentArc = currentarc;
}
int IncidentArcIterator::operator*() {
	return CurrentArc->Id->Key;
}
IncidentArcIterator& IncidentArcIterator::operator++() {
	if (CurrentArc != nullptr || CurrentArc->Next != nullptr) {
		CurrentArc = CurrentArc->Next;
		return *this;
	}
}
bool IncidentArcIterator::operator!=(const IncidentArcIterator other) {
	return this->CurrentArc != other.CurrentArc;
}