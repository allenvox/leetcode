#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int rows[9][9] = {{0}}, cols[9][9] = {{0}}, squares[9][9] = {{0}};
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        int n_index = board[i][j] - '0' - 1;  // atoi & num_index = num - 1
        int k = (i / 3) * 3 + j / 3;          // index of 3x3 square
        if (rows[i][n_index] || cols[j][n_index] || squares[k][n_index])
          return false;
        rows[i][n_index] = cols[j][n_index] = squares[k][n_index] = 1;
      }
    }
    return true;
  }

  void output(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << board[i][j] << "  ";
      }
      cout << endl;
    }
    cout << "^ This sudoku board is ";
    bool res = isValidSudoku(board);
    if (!res) cout << "not ";
    cout << "valid ";
    if (res) cout << "(but not guaranteed solvable)";
    cout << "\n\n";
  }
};

int main() {
  Solution s;
  vector<vector<char>> b1{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  s.output(b1);
  vector<vector<char>> b2{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  s.output(b2);
  return 0;
}