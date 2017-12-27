#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    unordered_map< long, pair<long, long> > map;
    unordered_map< long, pair<long, long> >::iterator it;
    long n,m = 0;
    int k = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        long r = 0;
        cin >> r;
        long c1,c2 = 0;
        cin >> c1 >> c2;
        it = map.find(r);
        // If rth row is not in map
        if (it == map.end()) {
            map[r] = make_pair(c1, c2);
        } else {
            pair<long, long> pair = it -> second;
            long new_c1 = c1 < pair.first? c1: pair.first;
            long new_c2 = c2 > pair.second? c2: pair.second;
            it -> second = make_pair(new_c1, new_c2);
        }
    }

    long long total_grid = n*m;
    long long track = 0;

    cout << "Total grid = " << total_grid << endl;

    for (it = map.begin(); it != map.end(); ++it) {
          cout << "Key = " << it -> first 
               << "Value = (" << (it -> second).first << ',' 
               << (it -> second).second << ')' << endl;
        track += ((it->second).second - (it->second).first) + 1;
    }

    cout << "Track = " << track << endl;

    cout << total_grid - track << endl;

    return 0;
}
