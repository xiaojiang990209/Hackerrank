#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool valid(int i, int j) {
    return 0 <= i && i < 10 &&
           0 <= j && j < 10;
}

int dfs(int i, int j, int graph[][10], bool visited[][10]){

    // Setup counters
    int count = 1;

    // Marked visited locations
    visited[i][j] = true;
    for(int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) {
                continue;
            }
            int new_i = i + di;
            int new_j = j + dj;
            if (valid(new_i, new_j) && 
                !visited[new_i][new_j] && 
                graph[new_i][new_j] == 1) {
                count += dfs(new_i, new_j, graph, visited);
            }
        }
    }

    return count;

}

int main() {

    int n = 0;
    cin >> n;
    int m = 0;
    cin >> m;
    int graph[10][10];
    bool visited[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            visited[i][j]=false;
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && graph[i][j] == 1) {
                int result = dfs(i, j, graph, visited);
                //cout << result << endl;
                max = result > max ? result : max; 
            }
        }
    }
    cout << max;


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}