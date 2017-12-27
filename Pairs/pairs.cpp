#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
/* Head ends here */

int pairs(vector < int > a, int k) {
    int ans = 0;
    // set<int> s(a.begin(), a.end());

    // for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
    //     int a = (*it);
    //     int b = k - a < 0? a - k: k - a;
    //     //cout << "(" << a << "," << b << ")" << endl;
    //     if (a != b && s.find(b) != s.end()) {
    //         ans ++;
    //     }
    // }
    sort(a.begin(), a.end());
    int i = 0;
    int j = 1;
    int n = a.size();
    while (j < n) {
        int diff = a[j] - a[i];
        if (diff == k) {
            ans++;
            j++;
        } else if (diff > k) {
            i++;
        } else if (diff < k) {
            j++;
        }
    }
    return ans;
}

/* Tail starts here */
int main() {
    int res;
    
    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = pairs(_a,_k);
    cout << res;
    
    return 0;
}
