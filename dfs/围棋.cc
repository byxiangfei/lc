#include "../common.h"

int dir[ 4 ][ 2 ] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void helper(vector<vector<char>> &board, int i, int j) {
    int m = board.size();
    int n = board[ 0 ].size();
    if (i < 0 || j < 0 || i >= m || j >= n || board[ i ][ j ] != 'O')
        return;
    board[ i ][ j ] = '.';
    for (auto d : dir)
        helper(board, i + d[ 0 ], j + d[ 1 ]);
}

void solve(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[ 0 ].size();
    for (int i = 0; i < m; i++) {
        helper(board, i, 0);
        helper(board, i, n - 1);
    }
    for (int j = 0; j < n; j++) {
        helper(board, 0, j);
        helper(board, m - 1, j);
    }
    for (auto &rows : board) {
        for (auto &col : rows) {
            if (col == 'O')
                col = 'X';
            else if (col == '.')
                col = 'O';
        }
    }
}

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    solve(board);
    for (auto r : board) {
        for (auto c : r) {
            cout << c << " ";
        }
        cout << endl;
    }
}
