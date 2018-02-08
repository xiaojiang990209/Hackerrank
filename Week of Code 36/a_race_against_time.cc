#include <bits/stdc++.h>

/**
 * Test case tracing:
 * *******************************
 * 5
 * 5
 * 6 1 2 7
 * -2 -7 7 -2
 * *******************************
 * 1. We encounter (6, -2). Since 6 > 5, we give the baton
 *    sum_time = 2; sum_price = -2; cur_height = 6.
 * 2. We encounter (1, -7). Abs.diff = |6-1| = 5. Price = -7
 *    Since it gives an overall negative, we give the baton
 *    sum_time = 8; sum_price = -9; cur_height = 1;
 * 3. We encounter (2, 7) We give the baton
 *    sum_time = 10; sum_price = -2; cur_height = 2;
 * 4. (7, -2) => Give baton => 
 *    sum_time = 16; sum_price


using namespace std;

long raceAgainstTime(int n, int mason_height, vector <int> heights, vector <int> prices) {
    // Complete this function
   long sum_time = 0;
   long sum_price = 0;
   int cur_height = mason_height;
   for (int i = 0; i < heights.size(); i++) {
       // First, see if we are forced to give the baton
       if (heights[i] > cur_height) {
           cur_height = heights[i];
           sum_price += prices[i];
       } else {
            // Second, see if it would be beneficial to give the baton
            // More specifically, we have the following choices:
            //   1. The abs.diff in heights + the price associated with it
            //      is less than 0, which creates a decrease in overall sum
            //   2. The abs.diff in heights + price is greater than or equal
            //      to 0, in this case we don't want to give the baton
            int abs_diff_heights = heights[i] - cur_height;
            abs_diff_heights = abs_diff_heights >= 0 ? abs_diff_heights : 
                                                        -abs_diff_heights;
            if (abs_diff_heights + prices[i] < 0) {
                // We pass the baton
                cur_height = heights[i];
                sum_time += abs_diff_heights;
                sum_price += prices[i];
            } 
       }      
       sum_time++;
   }
   return sum_time + sum_price;
}

int main() {
    int n;
    cin >> n;
    int mason_height;
    cin >> mason_height;
    vector<int> heights(n-1);
    for(int heights_i = 0; heights_i < n-1; heights_i++){
       cin >> heights[heights_i];
    }
    vector<int> prices(n-1);
    for(int prices_i = 0; prices_i < n-1; prices_i++){
       cin >> prices[prices_i];
    }
    long result = raceAgainstTime(n, mason_height, heights, prices);
    cout << result << endl;
    return 0;
}
