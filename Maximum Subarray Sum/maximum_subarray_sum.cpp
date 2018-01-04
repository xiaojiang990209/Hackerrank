#include <bits/stdc++.h>

using namespace std;

long maximumSum(vector <long> a, long m) {
    // Complete this function

    /**
     * Steps :
     *      1. Compute prefix_sum % m array
     *      2. Sort the prefix_sum array, with respect to
     *         the prefix_sum, along with their original 
     *         indices.
     *      3. First option: 
     *          => Find minimum distance b/w two adjacent 
     *             elements of the sorted prefix_sum array,
     *             provided the second element has a larger 
     *             index than the first. Then subtract the 
     *             difference from m
     *         Second option:
     *          => Find the maximum of the prefix_sum array
     *         Then, return max{first option, second option}
     * 
     * Example:
     *   Consider 3 2 7 4, with m = 7
     *   prefix_sum[] % m = 3 5 5 2
     *                      0 1 2 3
     *   sorted:
     *   prefix_sum[] % m = 2 3 5 5 
     *                      4 1 2 3
     * 
     *   Note that the maximum occurs when 
     *   p_s[0] = 3 and p_s[3] = 2, since 
     *   by subtracting 3 from the rest of
     *   the prefix_sum array, it would become
     *   2 2 -1=>6. Therefore, by sorting 
     *   and finding the minimum of the sorted
     *   prefix array, will give us the maximum
     *   subarray sum.
     * 
     *  Remark:
     *      When working with subarray problems, it is often easier
     *    to consider the prefix array of the given array.
     * 
     * 
     * 
     * */

    long max_f = 0;
    int n = a.size();
    // Compute first option
    //     1. Compute prefix array
    pair<long, int> prefix_sum[n];
    long cur_prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_prefix_sum += a[i];
        prefix_sum[i] = make_pair(cur_prefix_sum % m, i);
    }
    //     2. Sort the prefix array
    sort(prefix_sum, prefix_sum + n);
    //     3. Find the minimum distance
    long min = INT64_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (prefix_sum[i].second > prefix_sum[i+1].second &&
            prefix_sum[i+1].first - prefix_sum[i].first < min) {
            min = prefix_sum[i+1].first - prefix_sum[i].first;
        }
    }
    max_f = m - min;
    // Compute second option : prefix_sum[n-1].first

    return max_f > prefix_sum[n-1].first ? max_f : prefix_sum[n-1].first;


}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        long m;
        cin >> n >> m;
        vector<long> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        long result = maximumSum(a, m);
        cout << result << endl;
    }
    return 0;
}
