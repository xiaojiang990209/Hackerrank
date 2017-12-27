#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int ar[200000]; 
    for (int i = 0; i < 200000; i++) {
        ar[i] = 0;
    }
    int n = 0;
    cin >> n;
    int index = 0;
    for (int i = 0; i < n; i++) {
        //cout << "First: " << i << endl;
        cin >> index;
        ar[index]--;
    }
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        //cout << "Second: " << i << endl;
        cin >> index;
        ar[index]++;
    }
    for (int i = 0; i < 200000; i++) {
        if (ar[i] > 0) {
            cout << i << ' ';
        }
        //cout << "(" << i << "," << ar[i] << "), ";
    }

    return 0;
}


























