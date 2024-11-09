#pragma once
#include <vector>

using namespace std;

class TicTacToe {
public:

	TicTacToe(int size) : size_(size), board_(size, vector<char>(size, ' ')), currentplayer_('X') {}

	bool IsValidMove(pair<int, int> position);

	char* operator[](pair<int, int> position);

	bool CheckWinner();

	void DisplayBoard();

	char GetCurrentPlayer();

	void PlayerSwitch();

private:

	int size_;
	char currentplayer_;
	vector<vector<char>> board_;

	bool IsValidPosition(int column, int row);

	bool CheckLine(int startColumn, int startRow, int deltaColumn, int deltaLine);
};