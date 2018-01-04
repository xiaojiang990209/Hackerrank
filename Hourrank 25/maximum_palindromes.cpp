#include <bits/stdc++.h>

using namespace std;

void initialize(string s) {
    // This function is called once before all queries.
}

int answerQuery(string s, int l, int r) {
    // Return the answer for this query modulo 1000000007.
    if (r - l == 0) {
        return 1;
    }
    if (r - l == 1) {
        return s[l-1] == s[r-1];
    }
    if (r - l == 2) {
        return s[l-1] == s[l] || s[l-1] == s[l+1] || s[l] == s[l+1];
    }
    if (r - l == 3) {
        unordered_map<char, int> map;
        for (int i = l - 1; i < r; i++) {
            map[s[i]]++;
        }
        for (unordered_map<char, int>::iterator it = map.begin(); it != map.end(); ++it) {
            cout << it->first << ' ' << it -> second << endl;
        }
    }
}

/**
 * amim => mim / mam
 * amimb => mim / mam / mbm
 * amima => amima / maiam
 * aabb => abba / baab
 * 
 * For four letters, possibilities
 * 1. aaaa => 1
 * 2. aaab => 0
 * 3. aabc => 2
 * 4. abcd => 0
 * */

int main() {
    string s;
    cin >> s;
    initialize(s);
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int l;
        int r;
        cin >> l >> r;
        int result = answerQuery(s, l, r);
        cout << result << endl;
    }
    return 0;
}
