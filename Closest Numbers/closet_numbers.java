import java.io.*;
import java.util.*;

public class closet_numbers {
    
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] ar = new int[N];
        for (int i = 0; i < N; i++) {
            ar[i] = in.nextInt();
        }
        
        Arrays.sort(ar);
        
        int min = ar[1] - ar[0];
        StringBuilder result = new StringBuilder();
        result.append(ar[0] + " " + ar[1] + " ");
        for (int i = 1; i < N - 1; i++) {
            if (ar[i + 1] - ar[i] < min) {
                min = ar[i + 1] - ar[i];
                result.setLength(0);
                result.append(ar[i] + " " + ar[i + 1] + " ");
            } else if (ar[i + 1] - ar[i] == min){
                result.append(ar[i] + " " + ar[i + 1] + " ");
            } else {
                continue;
            }
        }
        
        System.out.println(result.toString());
    }
}