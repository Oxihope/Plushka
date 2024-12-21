#include "ArcIterator.h"

ArcIterator::ArcIterator(Nref currentnode, Aref currentarc) {
	CurrentNode = currentnode;
	CurrentArc = currentarc;
}
int ArcIterator::operator*() {
	return CurrentArc->Id->Key;
}
ArcIterator& ArcIterator::operator++() {
	if (CurrentArc == nullptr || CurrentArc->Next == nullptr) {
		if (CurrentNode->Next != nullptr) {
			CurrentNode = CurrentNode->Next;
			CurrentArc = CurrentNode->Trail;
		}
	}
	else {
		CurrentArc = CurrentArc->Next;
	}
	return *this;
}
bool ArcIterator::operator!=(const ArcIterator other) {
	return this->CurrentArc != other.CurrentArc;
}