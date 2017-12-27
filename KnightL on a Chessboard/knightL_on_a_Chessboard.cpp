#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


using point = pair< pair<int, int>, int>;

bool isValid(point p, int n) {
    return 0 <= p.first.first && p.first.first < n &&
           0 <= p.first.second && p.first.second < n;
}

bool reach_end(point s, int n) {
    return s.first.first == n-1 &&
           s.first.second == n-1;
}

int bfs(point s, int a, int b, int n) {

    // Create visited points to mark visited locations
    bool visited[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    visited[0][0] = true;

    list<point> queue;
    queue.push_back(s);

    while(!queue.empty()) {
        point p = queue.front();
        queue.pop_front();
        for (int i = -a; i <= a; i += a) {
            for (int j = -b; j <= b; j += b) {
                if (i == 0 || j == 0) continue;
                // Take out old coordinates
                int old_x = p.first.first;
                int old_y = p.first.second;
                int old_d = p.second;
                // Use old coordinates to construct new points
                point next_1 = make_pair(make_pair(old_x + i, old_y + j), old_d + 1);
                point next_2 = make_pair(make_pair(old_x + j, old_y + i), old_d + 1);

                // Check if first one is the end
                if (reach_end(next_1, n)) {
                    // cout << '(' << next_1.first.first << ','
                    //      << next_1.first.second << ")\n";
                    return next_1.second;
                }
                // Check if the second one is the end 
                if (reach_end(next_2, n)) {
                    // cout << '(' << next_2.first.first << ','
                    //      << next_2.first.second << ")\n";
                    return next_2.second;
                }
                // Check if the first one is valid and if it is visited 
                if (isValid(next_1, n) && 
                           !visited[next_1.first.first][next_1.first.second]) {
                    queue.push_back(next_1);
                    visited[next_1.first.first][next_1.first.second] = true;
                    //cout << "Point_1: (" << next_1.first.first << ',' << next_1.first.second << ")\n";
                
                }
                // Check if the second one is valid and if it is visited 
                if (isValid(next_2, n) && 
                           !visited[next_2.first.first][next_2.first.second]) {
                    queue.push_back(next_2);
                    visited[next_2.first.first][next_2.first.second] = true;
                    //cout << "Point_2: (" << next_2.first.first << ',' << next_2.first.second << ")\n";
                }
            }
        }
    }

    return -1;

}

int main(){
    int n;
    cin >> n;
    // your code goes here
    point s = make_pair(make_pair(0,0), 0);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cout << bfs(s, i, j, n) << ' ';
        }
        cout << endl;
    }

    return 0;
}
