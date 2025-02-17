#ifndef ARC_H
#define ARC_H

class Node;
class Arc {
public:
	Node* Id = nullptr;
	Arc* Next = nullptr;
};

typedef Arc* Aref;

#endif