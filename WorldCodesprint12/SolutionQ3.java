import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/**
 * 1 + (7 + 1) + (1 + 12 + 24)
 */

public class SolutionQ3 {

    static long longestSequence(long[] a) {
        //  Return the length of the longest possible sequence of moves.
        long sum = 0;
        for (int i = 0; i < a.length; i++) {
            if (isPrime(a[i])) {
                sum += (1+ a[i]);
            } else if (a[i] % 2 == 0) {

                if (a[i] == 2) {
                    sum += 3;
                } else {
                    // Finding smallest odd factor
                    long f;
                    long prev_factor = 1;
                    long rest = a[i];
                    while (rest != 1) {
                        for (f = 3; f <= rest; f+=2) {
                            if (rest % f == 0) {
                                break;
                            }
                        }
                        rest = rest / f;
                        if (isPowerOf2(rest)) {
                            sum += (2*rest - 1) * f * prev_factor;
                            break;
                        }
                        sum += (prev_factor * f);
                        prev_factor *= f;
                        
                    }
                    sum ++;
                }
            } else {
                if (a[i] == 1) {
                    sum ++;
                } else {
                    long prime_factor;
                    long rest = a[i];
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

    public static boolean isPowerOf2(long n) {
        double p = Math.log(n) / Math.log(2);
        return p == (long)p;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long[] a = new long[n];
        for(int a_i = 0; a_i < n; a_i++){
            a[a_i] = in.nextLong();
        }
        long result = longestSequence(a);
        System.out.println(result);
        in.close();
    }

    static boolean isPrime(long n) {
        if (n == 1) return false;
        if (n%2 == 0) return false;
        for (int i = 3; i*i <= n; i += 2) {
            if (n%i == 0) return false;
        }
        return true;
    }
}
