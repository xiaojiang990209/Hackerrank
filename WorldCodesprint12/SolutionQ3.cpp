#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(long long n) {
    if (n == 1) return false;
    if (n%2 == 0) return false;
    for (int i = 3; i*i <= n; i += 2) {
        if (n%i == 0) return false;
    }
    return true;
}

bool isPowerOfTwo (long long n)
{
    while (((n & 1) == 0) && n > 1) /* While x is even and > 1 */
        n >>= 1;
    return (n == 1);
}

long long longestSequence(vector<long long> a) {
        //  Return the length of the longest possible sequence of moves.
        long long sum = 0;
        for (vector<long long>::iterator it = a.begin(); it != a.end(); ++it) {
            long long elem = *it;
            if (isPrime(elem)) {
                sum += (1+ elem);
            } else if (elem % 2 == 0) {

                if (elem == 2) {
                    sum += 3;
                } else {
                    // Finding smallest odd factor
                    long f;
                    long prev_factor = 1;
                    long rest = elem;
                    while (rest != 1) {
                        for (f = 3; f <= rest; f+=2) {
                            if (rest % f == 0) {
                                break;
                            }
                        }
                        rest = rest / f;
                        if (isPowerOfTwo(rest)) {
                            sum += (2*rest - 1) * f * prev_factor;
                            break;
                        }
                        sum += (prev_factor * f);
                        prev_factor *= f;
                        
                    }
                    sum ++;
                }
            } else {
                if (elem == 1) {
                    sum ++;
                } else {
                    long prime_factor;
                    long rest = elem;
                    long prev_factor = 1;
                    while(rest != 1) {
                        // Find largest prime factor
                        for (prime_factor = rest; prime_factor >= 2; prime_factor -= 2) {
                            if (isPrime(prime_factor) && rest % prime_factor == 0) {
                                sum += (prev_factor * prime_factor);
                                rest = rest / prime_factor;
                                prev_factor *= prime_factor;
                                break;
                            }
                        }
                    }
                    sum ++;
                }
            }
        }
        return sum;

    }

int main() {  
    int n;
    cin >> n;
  
    vector <long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
  
    /* Enter your code here. Print output to STDOUT */   
    cout << longestSequence(a);
 
    return 0;
}
