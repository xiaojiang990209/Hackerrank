#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

bool valid(int i, int j, int N, int M) {
    return 0 <= i && i < N &&
           0 <= j && j < M;
}

int dfs(int i, int j, char **forest, bool **visited, int N, int M) {
    // Current location
    //cout << "(" << i << "," << j << ")   ";
    // See if we are at destination
    if (forest[i][j] == '*') return 0;
    // Count how many available directions
    int dirs = 0;
    for (int m = -1; m <= 1; m++) {
        for (int n = -1; n <= 1; n++) {
            if (m * n != 0 || (m == 0 && n == 0)) continue;
            if (valid(i+m, j+n, N, M) && 
                (forest[i+m][j+n] == '.' || 
                 forest[i+m][j+n] == '*') &&
                !visited[i+m][j+n]) {
                dirs++;
            }
        }
    }
    //cout << "Dirs = " << dirs << endl;
    int wave = (dirs == 1 || dirs == 0) ? 0 : 1;
    //DFS
    for (int m = -1; m <= 1; m++) {
        for (int n = -1; n <= 1; n++) {
            if (m * n != 0 || (m == 0 && n == 0)) continue;
            if (valid(i+m, j+n, N, M) && 
                !visited[i+m][j+n]) {
                if (forest[i+m][j+n] == 'X') continue;
                visited[i+m][j+n] = true;
                int waves = dfs(i+m, j+n, forest, visited, N, M);
                if (waves == -1) {
                    continue;
                } else {
                    return waves + wave;
                }
            }
        }
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N = 0;
        int M = 0;
        cin >> N >> M;
        char **forest = new char*[N];
        bool **visited = new bool*[N];
        for (int i = 0; i < N; i++) {
            forest[i] = new char[M];
            visited[i] = new bool[M];
        }

        int start_i, start_j = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> forest[j][k];
                if (forest[j][k] == 'M') {
                    start_i = j;
                    start_j = k;
                }
                visited[j][k] = false;
            }
        }
        int K = 0;
        cin >> K;
        visited[start_i][start_j] = true;
        int waves = dfs(start_i, start_j, forest, visited, N, M);
        //cout << "Waves = " << waves << endl;
         if (waves == K) {
            cout << "Impressed" << endl;
        } else {
            cout << "Oops!" << endl;
        }
        
        for (int i = 0; i < N; i++) {
            delete(forest[i]);
            delete(visited[i]);
        }
        delete(forest);
        delete(visited);
    }
    return 0;
}
