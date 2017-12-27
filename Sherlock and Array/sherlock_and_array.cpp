#include <bits/stdc++.h>

using namespace std;

// string solve(vector < int > a){
//     // Complete this function
//     unordered_map<int, pair<int, int>> map;
//     int forward_sum = 0;
//     for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//         map[*it] = make_pair(forward_sum,0);
//         cout << *it << " (" << map[*it].first << "," 
//              << map[*it].second << ")\n";
//         forward_sum += *it;
//     }
//     int backward_sum = 0;
//     cout << "a.begin = " << *a.begin() << " a.end = " << *(a.end()-1) << endl;
//     for (vector<int>::iterator it = a.end()-1; it != a.begin()-1; it--) {
//         map[*it].second = backward_sum;
//         cout << *it << " (" << map[*it].first << "," 
//              << map[*it].second << ")\n";
//         backward_sum += *it;
//     }
//     int count = 0;
//     for (unordered_map<int, pair<int, int>>::iterator it = map.begin(); it != map.end(); ++it) {
//         pair<int, int> pair = it -> second;
//         cout << "Index = " << it -> first << " (" << pair.first << "," << pair.second << ")\n";
//         if (pair.first == pair.second) {
//             return "YES";
//         }
//     }
//     return "NO";


// }

string solve(vector<int> a) {
    //sort(a.begin(), a.end());
    int left_sum = 0;
    int right_sum = 0;
    for (int i = 1; i < a.size(); i++) {
        right_sum += a[i];
    }
    int index = 1;
    while(left_sum < right_sum) {
        //cout << "Left_sum = " << left_sum 
        //     << " Right_sum = " << right_sum << endl; 
        left_sum += a[index-1];
        right_sum -= a[index];
        index ++;
    }
    if (left_sum == right_sum) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = solve(a);
        cout << result << endl;
    }
    return 0;
}
