#include <iostream>

const int s = 8;


bool check(bool board[s][s], int x, int y) {
	for (int i = 0; i < s; ++i) {

		if (board[x][i]) return false;
		if (board[i][y]) return false;
		for (int j = 0; j < s; ++j) {
			if (i == x && j == y) continue;
			if (board[i][j]) {
				if (x - y == i - j) return false;
				if (x + y == i + j) return false;
			}
		}
	}

	return true;

}

bool Queens(bool board[s][s], int x) {

	if (x == s) return true;

	for (unsigned int y = 0; y < s; ++y) {
		if (check(board, x, y)) {

			board[x][y] = true;

			if (Queens(board, x + 1)) return true;;

			board[x][y] = false;
		}
	}

	return false;

}


void main() {
		
	bool board[s][s];

	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			board[i][j] = false;

	std::cout << std::boolalpha << Queens(board, 0);
}
