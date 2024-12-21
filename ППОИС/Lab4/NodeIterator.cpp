#include "NodeIterator.h"

NodeIterator::NodeIterator(Nref currentNode) {
	CurrentNode = currentNode;
}
int NodeIterator::operator*() {
	return CurrentNode->Key;
}
NodeIterator& NodeIterator::operator++() {
	if (CurrentNode->Next != nullptr) {
		CurrentNode = CurrentNode->Next;
	}
	return *this;
}
bool NodeIterator::operator!=(const NodeIterator other) {
	return CurrentNode != other.CurrentNode;
}