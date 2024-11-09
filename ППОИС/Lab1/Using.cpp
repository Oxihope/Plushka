#include <iostream>
#include "TicTacToe.h"

string UserMenu(int key) {
	switch (key)
	{
	case 1:
		return "������� ������ �������� ����(�� 3 �� 10): ";
	case 2:
		return "������! �������� ������ �������� ����! ������� ����� (�� 3 �� 10): ";
	case 3:
		return "�������� �������:\n1.�������� ����������� ������������ ��������/������ � ��������� �������\n2.��������� �������� ��������� �������\n3.��������� �������� ��������� ������� (��� ������)\n4.�������� ������ ������ �� �������\n5.����� �������� ������\n6.�����\n";
	case 4:
		return "������!�������� ����� �������!������� �����(�� 1 �� 6): ";
	case 5:
		return "������� ����� �������\n";
	case 6:
		return "������� ����� ������\n";
	case 7:
		return "��, �����\n";
	case 8:
		return "���, ������\n";
	case 9:
		return "������ �����\n";
	case 10:
		return "�������� �������: ";
	case 11:
		return "������! ����� �� ����� �������� ����!\n";
	case 12:
		return "������ ��� ������\n";
	case 13:
		return "���� ����������!!!\n";
	case 14:
		return "���������� ���\n";
	}
	return "";
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << UserMenu(1);
	int size;
	cin >> size;
	TicTacToe game(size);
	game.DisplayBoard();
	int comand;
again:
	cout << UserMenu(3);
	cin >> comand;
	switch (comand) {
	case 1: {
		int column, row;
		cout << UserMenu(5);
		cin >> column;
		cout << UserMenu(6);
		cin >> row;
		if (game.IsValidMove({ column - 1, row - 1 })) {
			cout << UserMenu(7);
		}
		else {
			cout << UserMenu(8);
		}
		goto again;
	}
	case 2: {
		int column, row;
		cout << UserMenu(5);
		cin >> column;
		cout << UserMenu(6);
		cin >> row;
		if (game[{column - 1, row - 1}]) {
			if (*game[{column - 1, row - 1}] == ' ') {
				cout << UserMenu(9);
			}
			else {
				cout << UserMenu(10) << *game[{column - 1, row - 1}] << endl;
			}
		}
		else {
			cout << UserMenu(11);
		}
		goto again;
	}
	case 3: {
		int column, row;
		cout << UserMenu(5);
		cin >> column;
		cout << UserMenu(6);
		cin >> row;
		if (game[{column - 1, row - 1}]) {
			if (*game[{column - 1, row - 1}] == ' ') {
				*game[{column - 1, row - 1}] = game.GetCurrentPlayer();
				game.PlayerSwitch();
			}
			else {
				cout << UserMenu(12);
			}
		}
		else {
			cout << UserMenu(11);
		}
		game.DisplayBoard();
		goto again;
	}
	case 4: {
		if (game.CheckWinner()) {
			cout << UserMenu(13);
		}
		else {
			cout << UserMenu(14);
		}
		goto again;
	}
	case 5: {
		cout << "'" << game.GetCurrentPlayer() << "'" << endl;
		goto again;
	}
	case 6:
		break;
	}
	return 0;
}