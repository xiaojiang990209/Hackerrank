#include <bits/stdc++.h>

using namespace std;

int sum_digits(int a) {
    int sum_d = 0;
    while (a != 0) {
        sum_d += a % 10;
        a /= 10;
    }
    return sum_d;
}

string canConstruct(vector <int> a) {
    // Return "Yes" or "No" denoting whether you can construct the required number.
    int sum = 0;
    for(vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
        sum += sum_digits(*it);
    }
    return sum % 3 == 0 ? "Yes" : "No";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = canConstruct(a);
        cout << result << endl;
    }
    return 0;
}
