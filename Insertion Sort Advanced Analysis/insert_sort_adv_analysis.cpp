#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int index_of_smallest_elem(int ar[], int begin, int end);
void swap_till(int *ar, int begin, int end);
void print(int *ar, int size);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N = 0;
        int dist = 0;
        cin >> N;
        int ar[N];
        for (int j = 0; j < N; j++) {
            cin >> ar[j];
        }
        for (int j = 0; j < N; j++) {
            int min_index = index_of_smallest_elem(ar, j, N);
            cout << "Min index = " << min_index << endl;
            cout << "Dist = " << (min_index - j) << endl;
            swap_till(ar, j, min_index);
            print(ar, N);
            dist += (min_index - j);
        }
        cout << dist << endl;
    }
    return 0;
}

int index_of_smallest_elem(int ar[], int begin, int end) {
    int index = begin;
    for (int i = index + 1; i < end; i++) {
        if (ar[i] < ar[index]) {
            index = i;
        }
    }
    return index;
}

void swap_till(int *ar, int begin, int end) {
    int temp = ar[end];
    for (int i = end; i > begin; i--) {
        ar[i] = ar[i-1];
    }
    ar[begin] = temp;
}

void print(int *ar, int size) {
    for (int i = 0; i < size; i++) {
        cout << ar[i] << ' ';
    }
    cout << endl;
}