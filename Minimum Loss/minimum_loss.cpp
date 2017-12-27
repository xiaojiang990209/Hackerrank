#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using price = pair<long, int>;

long minimum_loss(long *ar, int n) {
    
    long min = INT64_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //cout << ar[i] << ' ' << ar[j] << endl;
            //cout << ar[i] - ar[j] << ' ' << min << endl;
            if (ar[i] > ar[j] && ar[i] - ar[j] < min) {
                min = ar[i] - ar[j];
            }
        }
    }

    return min;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n = 0;
    cin >> n;
    vector<price> vec;
    for (int i = 0; i < n; i++) {
        long p = 0;
        cin >> p;
        vec.push_back(make_pair(p, i));
    }

    sort(vec.begin(), vec.end());

    for (vector<price>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << "price = " << it->first << " index = " << it->second << endl;
    }

    long min = INT64_MAX;
    for (int i = 0; i < n-1; i++) {
        if (vec[i].second > vec[i+1].second &&
            vec[i+1].first - vec[i].first < min) {
            min = vec[i+1].first - vec[i].first;
        }
    }

    cout << min;

    return 0;
}
