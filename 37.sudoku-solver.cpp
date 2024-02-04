/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int row, int col){
        if (col == 9){
            return backtrack(board, row+1, 0);
        }

        if (row == 9){
            return true;
        }

        if (board[row][col] != '.'){
            return backtrack(board, row, col+1);
        }

        for (char val = '1'; val <= '9'; val++){
            if (!isValid(board, row, col, val)){
                continue;
            }
            board[row][col] = val;
            if (backtrack(board, row, col+1)){
                return true;
            }
            board[row][col] = '.';
        }
        // no valid options
        return false;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, int val){
        for (int i = 0; i < 9; i++){
            if (board[row][i] == val) {return false;}
            if (board[i][col] == val) {return false;}
        }
        int gridRow = (row / 3) * 3;
        int gridCol = (col / 3) * 3;
        for (int i = 0 ; i < 3; i++){
            for (int k = 0; k < 3; k++){
                if(board[gridRow + i][gridCol + k] == val) {return false;}
            }
        }
        return true;
    }
};
// @lc code=end

