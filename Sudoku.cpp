#include <iostream>

const unsigned int SIZE = 9;

bool ZERO_CHECK(unsigned int board[SIZE][SIZE]) {
    
    for (unsigned int i = 0; i < SIZE; ++i)
        for (unsigned int j = 0; j < SIZE; ++j)
            if (board[i][j] == 0) return false;

    return true;
}

bool solve(unsigned int board[SIZE][SIZE]) {

	for (unsigned int r = 0; r < SIZE; ++r) {
		unsigned int nums[9] = { 0 };
        for (unsigned int c = 0; c < SIZE; ++c) {

            int val = board[r][c];

            if (val == 0) continue;
            if (nums[val - 1] > 0) return false;
            nums[val - 1]++;     
        }
	}

    for (unsigned int c = 0; c < SIZE; ++c) {
        unsigned int nums[9] = { 0 };
        for (unsigned int r = 0; r < SIZE; ++r) {

            int val = board[r][c];

            if (val == 0) continue;
            if (nums[val - 1] > 0) return false;
            nums[val - 1]++;
        }
    }

    for(unsigned int r = 0; r < SIZE; r += 3)
        for (unsigned int c = 0; c < SIZE; c += 3) {
            unsigned int nums[9] = { 0 };
            for (unsigned int i = 0; i < SIZE / 3; ++i)
                for (unsigned int j = 0; j < SIZE / 3; ++j) {
                    int val = board[i+r][j+c];
                    if (val == 0) continue;
                    if (nums[val - 1] > 0) return false;
                    nums[val - 1]++;
                }
        }


	return true;
}

bool isValid(unsigned int board[SIZE][SIZE], const unsigned int row, const unsigned int col, unsigned int num) {
    board[row][col] = num;
    bool solution = solve(board);
    board[row][col] = 0;
    return solution;
}

void find_empty(const unsigned int board[SIZE][SIZE], unsigned int& row, unsigned int& col) {
    for (unsigned int i = 0; i < SIZE; ++i)
        for (unsigned int j = 0; j < SIZE; ++j)
            if (board[i][j] == 0) {
                row = i;
                col = j;
                return;
            }
}


bool sudoku(unsigned int board[SIZE][SIZE]) {

    if (ZERO_CHECK(board)) return true;

    unsigned int row = 9, col = 9; // Default стойности 9;

    find_empty(board, row, col);

    for (unsigned int num = 1; num <= 9; ++num) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (sudoku(board)) return true;
            board[row][col] = 0;
        }
    }

    return false;
}


void main() {
    unsigned int board[SIZE][SIZE] = {
       {5,3,0, 0,7,0, 0,0,0},
       {6,0,0, 1,9,5, 0,0,0},
       {0,9,8, 0,0,0, 0,6,0},

       {8,0,0, 0,6,0, 0,0,3},
       {4,0,0, 8,0,3, 0,0,1},
       {7,0,0, 0,2,0, 0,0,6},

       {0,6,0, 0,0,0, 2,8,0},
       {0,0,0, 4,1,9, 0,0,5},
       {0,0,0, 0,8,0, 0,7,9}
    };

    std::cout << "Original board:\n";
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j)
            std::cout << board[i][j] << " ";
        std::cout << '\n';
    }

    std::cout << "\nSolving...\n";

    if (sudoku(board)) {
        std::cout << "\nSolved board:\n";
        for (unsigned int i = 0; i < SIZE; ++i) {
            for (unsigned int j = 0; j < SIZE; ++j)
                std::cout << board[i][j] << " ";
            std::cout << '\n';
        }
    }
    else {
        std::cout << "No solution found.\n";
    }
	
}
