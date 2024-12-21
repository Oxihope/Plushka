#include "Node.h"
#include "Arc.h"
#include "NodeIterator.h"
#include "ArcIterator.h"
#include "IncidentArcIterator.h"
#include "AdjacentNodeIterator.h"

class Spisok {
public:
	//+++Конструктор по умолчанию
	Spisok() {
		Head = Tail = new Node;
	}

	//+++Деструктор
	~Spisok() {
		if (Head != Tail) {
			Nref p = Head;
			while (p != Tail) {
				DeleteNode(p->Key);
				p = Head;
			}
		}
		delete Tail;
	}

	//+++Возврат начала списка
	Nref GetHead() {
		return Head;
	}

	//+++Возврат конца списка
	Nref GetTail() {
		return Tail;
	}

	//+++Проверка на пустой граф
	bool empty() {
		if (Head == Tail) {
			return true;
		}
		else {
			return false;
		}
	}

	//+++Очистка контейнера
	void clear() {
		if (Head != Tail) {
			Nref p = Head;
			while (p != Tail) {
				DeleteNode(p->Key);
				p = Head;
			}
		}
	}

	//+++Проверка наличия вершины в графе
	bool CheckNode(int key) {
		Nref p = NodeSearch(key);
		if (p != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	//+++Проверка наличия неориентированной дуги между X И Y
	bool CheckArc(int keyX, int keyY) {
		Aref XY = ArcSearch(keyX, keyY);
		Aref YX = ArcSearch(keyY, keyX);
		if (XY != nullptr && YX != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	//+++Получение количества вершин
	int CountNodes() {
		Nref p = Head;
		int count = 0;
		while (p != Tail) {
			count++;
			p = p->Next;
		}
		return count;
	}

	//+++Получение количества ребер
	int CountArcs() {
		Nref p = Head;
		int count = 0;
		while (p != Tail) {
			count = count + p->Count_trail;
			p = p->Next;
		}
		return count / 2;
	}

	//+++Вычисление степени вершины
	int NodeDegree(int key) {
		if (CheckNode(key)) {
			Nref p = NodeSearch(key);
			return p->Count_trail;
		}
		else {
			return 0;
		}
	}

	//+++Добавление вершины
	void AddNode(int key) {
		if (!CheckNode(key)) {
			Nref X = new Node;
			Tail->Next = X;
			Tail->Key = key;
			Tail = X;
		}
	}

	//+++Добавление ребра между вершинами X и Y
	void AddArc(int keyX, int keyY) {
		if (!CheckArc(keyX, keyY) && CheckNode(keyX) && CheckNode(keyY)) {
			AddArcXY(keyX, keyY);
			AddArcXY(keyY, keyX);
		}
	}

	//+++Удаление вершины
	void DeleteNode(int key) {
		//Зависит от CheckNode
		if (CheckNode(key)) {
			Nref p = Head;
			Nref q = nullptr;
			while (p->Key != key) {
				q = p;
				p = p->Next;
			}
			Nref r = Head;
			while (r != Tail) {
				DeleteArc(key, r->Key);
				r = r->Next;
			}
			if (q == nullptr) {
				Head = p->Next;
			}
			else {
				q->Next = p->Next;
			}
			p->Count_pred = 0;
			p->Count_trail = 0;
			p->Key = 0;
			p->Pred = nullptr;
			p->Trail = nullptr;
			p->Next = nullptr;
			delete p;
		}
	}

	//+++Удаление ребра между вершинами X и Y
	void DeleteArc(int keyX, int keyY) {
		//Зависит от наличия ребра (зависит от наличия х и у)
		if (CheckArc(keyX, keyY)) {
			DeleteArcXY(keyX, keyY);
			DeleteArcXY(keyY, keyX);
		}
	}

	NodeIterator beginN() {
		return NodeIterator(Head);
	}

	NodeIterator endN() {
		return NodeIterator(Tail);
	}

	ArcIterator beginA() {
		return ArcIterator(Head, Head->Trail);
	}

	ArcIterator endA() {
		return ArcIterator(Tail, nullptr);
	}

	IncidentArcIterator beginI(Nref node) {
		return IncidentArcIterator(node, node->Trail);
	}

	IncidentArcIterator endI(Nref node) {
		return IncidentArcIterator(node, nullptr);
	}

	AdjacentNodeIterator beginAdj(Nref node) {
		return AdjacentNodeIterator(node, node->Trail->Id);
	}

	AdjacentNodeIterator endAdj(Nref node) {
		return AdjacentNodeIterator(node,nullptr);
	}

private:
	Nref Head;
	Nref Tail;

	//+++Поиск вершины в графе
	Nref NodeSearch(int key) {
		Nref p = Head;
		Tail->Key = key;
		while (p->Key != key) {
			p = p->Next;
		}
		if (p == Tail) {
			p = nullptr;
		}
		return p;
	}

	//+++Поиск ориентированного ребра XY
	Aref ArcSearch(int keyX, int keyY) {
		Nref X = NodeSearch(keyX);
		Nref Y = NodeSearch(keyY);
		if (X != nullptr && Y != nullptr) {
			Aref p = X->Trail;
			while (p != nullptr && p->Id->Key != keyY) {
				p = p->Next;
			}
			return p;
		}
	}

	//+++Добавление ориентированного ребра XY
	void AddArcXY(int keyX, int keyY) {
		Nref X = NodeSearch(keyX);
		Nref Y = NodeSearch(keyY);
		AddArcY(keyY, X->Trail);
		AddArcY(keyX, Y->Pred);
		X->Count_trail++;
		Y->Count_pred++;
	}

	//+++Добавление ребра к вершине Y в список последующих/предыдущих вершин
	void AddArcY(int keyY, Aref& chainX) {
		Aref next = new Arc;
		Nref Y = NodeSearch(keyY);
		next->Id = Y;
		if (chainX == nullptr) {
			chainX = next;
		}
		else {
			Aref p = chainX;
			while (p->Next != nullptr) {
				p = p->Next;
			}
			p->Next = next;
		}
	}

	//+++Удаление ориентированного ребра XY
	void DeleteArcXY(int keyX, int keyY) {
		DeleteArcX(keyX, keyY);
		DeleteArcY(keyX, keyY);
	}

	//+++Удаление ребра от вершины X в списке предыдущих вершин вершины Y
	void DeleteArcX(int keyX, int keyY) {
		Nref X = NodeSearch(keyX);
		Nref Y = NodeSearch(keyY);
		Aref p = Y->Pred;
		Aref q = nullptr;
		while (p && p->Id->Key != X->Key) {
			q = p;
			p = p->Next;
		}
		if (q == nullptr) {
			Y->Pred = p->Next;
		}
		else {
			q->Next = p->Next;
		}
		p->Id = nullptr;
		p->Next = nullptr;
		delete p;
		Y->Count_pred--;
	}

	//+++Удаление ребра к вершине Y в списке последующих вершин вершины X
	void DeleteArcY(int keyX, int keyY) {
		Nref X = NodeSearch(keyX);
		Nref Y = NodeSearch(keyY);
		Aref p = X->Trail;
		Aref q = nullptr;
		while (p->Id->Key != Y->Key) {
			q = p;
			p = p->Next;
		}
		if (q == nullptr) {
			X->Trail = p->Next;
		}
		else {
			q->Next = p->Next;
		}
		p->Id = nullptr;
		p->Next = nullptr;
		delete p;
		X->Count_trail--;
	}
};