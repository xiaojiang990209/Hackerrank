#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N = 0;
    cin >> N;
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    sort(array, array + N);

    if (N % 2 == 1) {
        cout << array[N/2];
    } else {
        cout << (array[N/2] + array[N/2 + 1]) / 2.0;
    }

    return 0;
}
