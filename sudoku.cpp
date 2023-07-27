#include <iostream>
#include <vector>

const int N = 9; // 数独盘面的大小

// 判断数独规则是否满足
bool is_valid(const std::vector<std::vector<int>>& board, int row, int col, int num) {
    // 判断同一行是否有重复数字
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // 判断同一列是否有重复数字
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // 判断同一个3X3宫内是否有重复数字
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

// 解数独
bool solve_sudoku(std::vector<std::vector<int>>& board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) { // 如果该位置为空格
                for (int num = 1; num <= 9; num++) { // 枚举数字
                    if (is_valid(board, row, col, num)) { // 如果该数字符合数独规则
                        board[row][col] = num; // 填入数字
                        if (solve_sudoku(board)) { // 递归求解剩余空格
                            return true;
                        }
                        board[row][col] = 0; // 回溯，恢复为空格
                    }
                }
                return false; // 如果所有数字都不符合数独规则，则返回false
            }
        }
    }
    return true; // 如果所有空格都已填满，则返回true
}

// 输出数独盘面
void print_board(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0)); // 初始化数独盘面为全0
    std::cout << "请输入数独盘面，用空格分隔每个数字，空格用0表示：" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }

    if (solve_sudoku(board)) { // 解数独
        std::cout << "解出的数独盘面为：" << std::endl;
        print_board(board); // 输出数独盘面
    } else {
        std::cout << "无解" << std::endl;
    }

    return 0;
}
