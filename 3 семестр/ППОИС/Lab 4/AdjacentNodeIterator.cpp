#include "AdjacentNodeIterator.h"

AdjacentNodeIterator::AdjacentNodeIterator(Nref node, Nref currentnode) {
	Node = node;
	CurrentNode = currentnode;
}
int AdjacentNodeIterator::operator*() {
	if (CurrentNode) { 
		return CurrentNode->Key; 
	}
}
AdjacentNodeIterator& AdjacentNodeIterator::operator++() {
	Aref p = Node->Trail;
	while (p && p->Id != CurrentNode) {
		p = p->Next;
	}
	if (p == nullptr) {
		CurrentNode = nullptr;
	}
	else {
		if (p->Next != nullptr) {
			CurrentNode = p->Next->Id;
		}
		else {
			CurrentNode = nullptr;
		}
	}
	return *this;
}
bool AdjacentNodeIterator::operator!=(const AdjacentNodeIterator other) {
	return this->CurrentNode != other.CurrentNode;
}