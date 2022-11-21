
#include <iostream>
#include <iomanip>
#include <algorithm >
#include <fstream>
using namespace std;
const int N = 9;


bool isSafe(int board[N][N], int row, int col, int num) {
    // kiểm tra xem trên hàng cần thêm số num đã tồn tại num chưa
    for (int c = 0; c < N; c++) {
        if (board[row][c] == num) { // nếu đã tồn tại
            return false; // trả về không đặt được num ở hàng này
        }
    }
    // kiểm tra trên cột hiện tại đã có giá trị num chưa
    for (int r = 0; r < N; r++) {
        if (board[r][col] == num) {		// nếu có => không đặt được num vào ô này
            return false; 			
        }
    }
    // kiểm tra cụm 9 ô bao quanh ô [row, col] xem đã tồn tại giá trị num chưa
    int boxSize = 3;
    int boxRowStart = row - row % boxSize;
    int boxColStart = col - col % boxSize;
    for (int i = boxRowStart; i < boxRowStart + boxSize; i++) {
        for (int j = boxColStart; j < boxColStart + boxSize; j++) {
            if (board[i][j] == num) { // nếu tồn tại ô chứa giá trị num => k đc đặt
                return false; 
            }
        }
    }
    // mặc định giá trị num chưa tồn tại trong phạm vi cần kiểm tra
    return true;
}

bool solveSudoku(int board[N][N]) {
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }
    if (isEmpty) {
        return true;
    }
    for (int num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            else { // nếu không dẫn tới lời giải
                board[row][col] = 0; // quay lui
            }
        }
    }
    return false;
}

void showResult(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << "   ";
        }
        cout << "\n\n";
    }
}

void enterData(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

int main() {
    int board[N][N] = { 0 };
    int testNumber = 1;
    int t;
    enterData(board);
    if (solveSudoku(board)) {
    	cout << "\nLoi giai:\n\n";
        showResult(board);
    }
    else {
        cout << "Khong co loi giai.\n";
    }
}


/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 0 1 5 9 8 7
9 7 4 8 6 0 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 0 4 7 2 0 6
6 9 2 3 5 1 8 7 4
7 4 5 0 8 6 3 1 0

*/