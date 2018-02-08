#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool valid_position(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}


// mode parameter denotes which mode we are in
// we have 0: horizontal and vertical
//         1: diagnoal
//         2: both
// we also have a black/white king param to enhance reusability
// we have 'k': represents black king being attacked
//         'K': represents white king being attacked
bool check(int i, int j, vector<vector<char>> board, int mode, char attacked_king) {
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (mode == 0 && di * dj != 0) continue;
            if (mode == 1 && di * dj == 0) continue;
            if (di == 0 & dj == 0) continue;
            int new_i = i + di;
            int new_j = j + dj;
            while (valid_position(new_i, new_j)) {
                if (board[new_i][new_j] == attacked_king) {
                    return true;
                } else if (board[new_i][new_j] == '#') {
                    new_i += di;
                    new_j += dj;
                } else {
                    break;
                }
            }
        }
    }
    return false;
}

bool check_knight(int i, int j, vector<vector<char>> board, char attacked_king) {
    for (int di = -2; di <= 2; di++) {
        for (int dj = -2; dj <= 2; dj++) {
            if (di * dj != 2 && di * dj != -2) continue;
            int new_i = i + di;
            int new_j = j + dj;
            //cout << "new_i: " << new_i << " new_j: " << new_j << endl;
            if (valid_position(new_i, new_j) && board[new_i][new_j] == attacked_king) {
                return true;
            } else {
                continue;
            }
        }
    }
    return false;
}

bool check_king(int i, int j, vector<vector<char>> board, char attacked_king) {
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;
            int new_i = i + di;
            int new_j = j + dj;
            if (valid_position(new_i, new_j) && board[new_i][new_j] == attacked_king){
                return true;
            } else {
                continue;
            }
        }
    }
    return false;
}

bool is_king_attacked(int i, int j, char piece, vector<vector<char>> board) {
    char k = piece >= 'a' ? 'k' : 'K';
    char n = piece >= 'a' ? 'n' : 'N';
    char q = piece >= 'a' ? 'q' : 'Q';
    char r = piece >= 'a' ? 'r' : 'R';
    char b = piece >= 'a' ? 'b' : 'B';
    char attacked_king = piece >= 'a' ? 'K' : 'k';
    if (piece == k) {
        //cout << "fine here pt 1" << endl;
        return check_king(i, j, board, attacked_king);
    } else if (piece == n) {
        //cout << "fine here pt 2" << endl;
        return check_knight(i, j, board, attacked_king);
    } else if (piece == q) {
        //cout << "fine here pt 3" << endl;
        return check(i, j, board, 2, attacked_king);
    } else if (piece == r) {
        //cout << "fine here pt 4" << endl;
        return check(i, j, board, 0, attacked_king);
    } else if (piece == b) {
        //cout << "fine here pt 5" << endl;
        return check(i, j, board, 1, attacked_king);
    } else {
        return false;
    }
}

bool expose_king(vector<vector<char>> board, char king) {
    char k = king == 'k' ? 'K' : 'k';
    char q = king == 'k' ? 'Q' : 'q';
    char n = king == 'k' ? 'N' : 'n';
    char b = king == 'k' ? 'B' : 'b';
    char r = king == 'k' ? 'R' : 'r';
    // Traverse entire chess board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //
            if (board[i][j] == '#') continue;
            
            // Check if white king is attacked by using the above function
            //cout << "NOT EVEN HERE?!" << " i: " << i << " j: " << j << endl;
            if (board[i][j] == k && is_king_attacked(i, j, k, board)) {
                //cout << "1" << endl;
                return true;
            } else if (board[i][j] == q && is_king_attacked(i, j, q, board)) { //cout << "2" << endl;
                return true;
            } else if (board[i][j] == n && is_king_attacked(i, j, n, board)) { //cout << "3" << endl;
                return true;
            } else if (board[i][j] == b && is_king_attacked(i, j, b, board)) { //cout << "4" << endl;
                return true;
            } else if (board[i][j] == r && is_king_attacked(i, j, r, board)) { //cout << "5" << endl;
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
    return !expose_king(board, 'K');
}

int waysToGiveACheck(vector < vector<char> > board) {
    for (int c = 0; c < 8; c++) {
        if (valid_move(c, board)) {
            //cout << "HERE!" << endl;
            //Do something...
            board[1][c] = '#';
            board[0][c] = 'P';
            // If black king is available to be checked, then no matter
            // what is promoted, it will always be a checked situation
            if (expose_king(board, 'k')) {
                return 4;
            }
            int count = 0;
            // Promote to queen
            if (check(0, c, board, 2, 'k')) {
                //cout << "Promoted to Queen" << endl;
                count++;
            }
            // Promote to rook
            if (check(0, c, board, 0, 'k')) {
                //cout << "Promoted to Rook" << endl;
                count++;
            }
            //Promote to bishop
            if (check(0, c, board, 1, 'k')) {
                //cout << "Promoted to Bishop" << endl;
                count++;
            }
            // Promote to knight
            if (check_knight(0, c, board, 'k')) {
                //cout << "Promoted to Knight" << endl;
                count++;
            }
            return count;
        }
    }
    return 0;
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
