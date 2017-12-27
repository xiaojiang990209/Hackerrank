import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class SolutionQ4 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] A = new int[n];
        for(int A_i = 0; A_i < n; A_i++){
            A[A_i] = in.nextInt();
        }
        in.nextLine();
        for(int a0 = 0; a0 < m; a0++){
            // Write Your Code H
            String input = in.nextLine();
            String[] instruction = input.split(" ");
            int f = Integer.valueOf(instruction[1]) - 1;
            int r = Integer.valueOf(instruction[2]) - 1;
            //System.out.println("f = " + f + ", r = " + r);
            switch(instruction[0]) {
                case "1": 
                    for(int i = f; i <= r; i++) {
                        A[i]++;
                    }
                    break;
                case "2":
                    long sum = 0;
                    for(int i = f; i <= r; i++) {
                        sum += calc_factorial_mod_10_9(A[i]);
                        sum %= Math.pow(10, 9);
                    }
                    System.out.println(sum);
                    break;
                case "3":
                    A[f] = r;
                    break;
            }
        }
        in.close();
    }

    public static long calc_factorial_mod_10_9 (long n) {

        long sum = 1;
        
        for (long i = n; i >= 1; i--) {
            sum *= i;
            sum %= (long)Math.pow(10, 9);
        }

        return sum;

    }
}
