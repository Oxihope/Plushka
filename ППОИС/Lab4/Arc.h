#ifndef ARC_H
#define ARC_H

struct Node;
struct Arc {
	Node* Id = nullptr;
	Arc* Next = nullptr;
};

typedef Arc* Aref;

#endif