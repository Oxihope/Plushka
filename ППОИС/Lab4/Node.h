#ifndef NODE_H
#define NODE_H

class Arc;
class Node {
public:
	int Key = 0;
	int Count_pred = 0;
	int Count_trail = 0;
	Node* Next = nullptr;
	Arc* Trail = nullptr;
	Arc* Pred = nullptr;
};

typedef Node* Nref;

#endif