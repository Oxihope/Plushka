#include <iostream>
#include "TicTacToe.h"

bool TicTacToe::IsValidMove(pair<int, int> position) {
	int column = position.first;
	int row = position.second;
	return IsValidPosition(column, row) && board_[column][row] == ' ';
}
char* TicTacToe::operator[](pair<int, int> position) {
	int column = position.first;
	int row = position.second;
	if (IsValidPosition(column, row)) {
		return &board_[column][row];
	}
	return nullptr;
}
bool TicTacToe::CheckWinner() {
	for (int i = 0; i < size_; i++) {
		if (CheckLine(0, i, 1, 0) || CheckLine(i, 0, 0, 1)) {
			return true;
		}
	}
	return CheckLine(0, 0, 1, 1) || CheckLine(0, size_ - 1, 1, -1);
}
void TicTacToe::DisplayBoard() {
	for (int i = 0; i < size_ * 2 + 1; i++) {
		cout << "-";
	}
	cout << endl;
	for (int row = 0; row < size_; row++) {
		cout << "|";
		for (int column = 0; column < size_; column++) {
			cout << board_[column][row] << "|";
		}
		cout << endl;
		for (int i = 0; i < size_ * 2 + 1; i++) {
			cout << "-";
		}
		cout << endl;
	}
}
char TicTacToe::GetCurrentPlayer() {
	return currentplayer_;
}
bool TicTacToe::IsValidPosition(int column, int row) {
	return (column >= 0 && column < size_) && (row >= 0 && row < size_);
}
bool TicTacToe::CheckLine(int startColumn, int startRow, int deltaColumn, int deltaLine) {
	char first = board_[startColumn][startRow];
	if (first == ' ') {
		return false;
	}
	for (int i = 1; i < size_; i++) {
		int column = startColumn + i * deltaColumn;
		int row = startRow + i * deltaLine;
		if (board_[column][row] != first) {
			return false;
		}
	}
	return true;
}
void TicTacToe::PlayerSwitch() {
	if (currentplayer_ == 'X') {
		currentplayer_ = 'O';
	}
	else {
		currentplayer_ = 'X';
	}
}