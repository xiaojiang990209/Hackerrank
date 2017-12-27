#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool valid(int i, int j) {
    return 0 <= i && i < 100 &&
           0 <= j && j < 100;
}

int dfs(int i, int j, char forest[100][100], bool visited[100][100]) {
    // See if we are at destination
    if (forest[i][j] == '*') return 0;
    // Count how many available directions
    int dirs = 0;
    for (int m = -1; m <= 1; m+=2) {
        for (int n = -1; n <= 1; n+=2) {
            if (forest[i+m][j+n] == '.') {
                dirs++;
            }
        }
    }
    int wave = dirs == 1? 0 : 1;
    //DFS
    for (int m = -1; m <= 1; m+=2) {
        for (int n = -1; n <= 1; n+=2) {
            if (valid[i+m][j+n] && 
                !visited[i+m][j+n] &&
                forest[i+m][j+n] == '.') {
                visited[i+m][j+n] = true;
                
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N = 0;
        int M = 0;
        cin >> N >> M;
        char forest[100][100];
        bool visited[100][100];
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> forest[i][j];
                visited[i][j] = false;
            }
        }
        int K = 0;
        cin >> K;
        int waves = dfs(}
    return 0;
}
