#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool valid_position(int i, int j) {
    return i >= 0 && i <= 8 && j >= 0 && j <= 8;
}


// mode parameter denotes which mode we are in
// we have 0: horizontal and vertical
//         1: diagnoal
//         2: both
// we also have a black/white king param to enhance reusability
// we have 0: see if white king is checked
//         1: see if black king is checked
bool check(int i, int j, vector<vector<char>> board, int mode, int king) {
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (mode == 0 && di * dj != 0) continue;
            if (mode == 1 && di * dj == 0) continue;
            if (di == 0 & dj == 0) continue;
            int new_i = i + di;
            int new_j = j + dj;
            while (valid_position(new_i, new_j)) {
                if (board[new_i][new_j] == 'K' && king == 0) {
                    return true;
                } else if (board[new_i][new_j] == 'k' && king == 1) {
                    return true;
                } else if (board[new_i][new_j] == '#') {
                    new_i += di;
                    new_j += dj;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool is_white_king_attacked(int i, int j, char piece, vector<vector<char>> board) {
    switch(piece) {
        case 'k': for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        int new_i = i + di;
                        int new_j = j + dj;
                        if (valid_position(new_i, new_j) && board[new_i][new_j] == 'K'){
                            return true;
                        } else if (valid_position(new_i, new_j) && board[new_i][new_j] == '#') {
                            continue;
                        } else {
                            return false;
                        }
                    }
                  }
                  return false;
        case 'n': for (int di = -2; di <= 2; di++) {
                      for (int dj = -2; dj <= 2; dj++) {
                          if (di * dj != 2) continue;
                          int new_i = i + di;
                          int new_j = j + dj;
                          if (valid_position(new_i, new_j) && board[new_i][new_j] == 'K') {
                              return true;
                          } else if (valid_position(new_i, new_j) && board[new_i][new_j] == '#') {
                              continue;
                          } else {
                              return false;
                          }
                      }
                  }
                  return false;
        case 'q': return check(i, j, board, 2, 0); 
        case 'r': return check(i, j, board, 0, 0);
        case 'b': return check(i, j, board, 1, 0);
    }
}

bool expose_white_king(vector<vector<char>> board) {
    bool white_king_checked = false;
    // Traverse entire chess board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == '#') continue;
            // Check if white king is attacked by using the above function
            if (board[i][j] == 'k' && is_white_king_attacked(i, j, 'k', board)) {
                return true;
            } else if (board[i][j] == 'q' && is_white_king_attacked(i, j, 'q', board)) {
                return true;
            } else if (board[i][j] == 'n' && is_white_king_attacked(i, j, 'n', board)) {
                return true;
            } else if (board[i][j] == 'b' && is_white_king_attacked(i, j, 'b', board)) {
                return true;
            } else if (board[i][j] == 'r' && is_white_king_attacked(i, j, 'r', board)) {
                return true;
            } else {
                continue;
            }
        }
    }
    return false;
}
                


bool valid_move(int c, vector<vector<char>> board) {
    if (board[1][c] != 'P') {
        return false;
    }
    if (board[0][c] != '#') {
        return false;
    }
    board[1][c] = '#';
    board[0][c] = 'P';
    return !expose_white_king(board);
}

int waysToGiveACheck(vector < vector<char> > board) {
    for (int c = 0; c < 8; c++) {
        if (valid_move(c, board)) {
            //Do something...
            board[1][c] = '#';
            board[0][c] = 'P';
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        vector< vector<char> > board(8, vector<char>(8));
        for (int board_i = 0; board_i < 8; board_i++) {
            for (int board_j = 0; board_j < 8; board_j++) {
                cin >> board[board_i][board_j];
            }
        }
        int result = waysToGiveACheck(board);
        cout << result << endl;
    }
    return 0;
}
