#include <iostream>
#include "TicTacToe.h"

string UserMenu(int key) {
	switch (key)
	{
	case 1:
		return "Введите размер игрового поля(от 3 до 10): ";
	case 2:
		return "Ошибка! Неверный размер игрового поля! Введите число (от 3 до 10): ";
	case 3:
		return "Выберите команду:\n1.Проверка возможности установления крестика/нолика в указанную позицию\n2.Получение значения указанной позиции\n3.Установка значения указанной позиции (Ход игрока)\n4.Проверка победы одного из игроков\n5.Вывод текущего игрока\n6.Выход\n";
	case 4:
		return "Ошибка!Неверный номер команды!Введите число(от 1 до 6): ";
	case 5:
		return "Введите номер столбца\n";
	case 6:
		return "Введите номер строки\n";
	case 7:
		return "Да, можно\n";
	case 8:
		return "Нет, нельзя\n";
	case 9:
		return "Ячейка пуста\n";
	case 10:
		return "Значение позиции: ";
	case 11:
		return "Ошибка! Выход за рамки игрового поля!\n";
	case 12:
		return "Ячейка уже занята\n";
	case 13:
		return "Есть ПОБЕДИТЕЛЬ!!!\n";
	case 14:
		return "Победителя нет\n";
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