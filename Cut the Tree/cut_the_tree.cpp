#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <bits/stdc++.h>
using namespace std;

void remove_edge(unordered_map<int, list<int, int>>& graph,
                pair<int, int> edge) {
    graph[edge.first].remove(edge.second);
}

int sum_connected_components(unordered_map<int, list<int>> graph, int ar[], int n) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
}

int dfs(unordered_map<int, list<int>> graph, int ar[], int n, bool visited[]) {
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int n = 0;
    cin >> n;
    int ar[n];
    unordered_map<int, list<int>> graph;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        graph[i] = list<int>();
    }
    pair<int, int> edges[n-1];
    for (int i = 0; i < n - 1; i++) {
        int f = 0;
        int r = 0;
        cin >> f >> r;
        edges[i] = make_pair(f, r);
        graph[f].push_back(r);
    }

    // For every edge, remove it and do dfs 
    // connected components



    


    return 0;
}
