import java.io.*;
import java.util.*;

public class find_median_sort {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] ar = new int[N];
        for (int i = 0; i < N; i++) {
            ar[i] = in.nextInt();
        }
        Arrays.sort(ar);
        if (N % 2 == 1) {
            System.out.println(ar[N/2]);
        } else {
            System.out.println((ar[N/2] + ar[N/2 + 1])/2.0);
        }

    }
}