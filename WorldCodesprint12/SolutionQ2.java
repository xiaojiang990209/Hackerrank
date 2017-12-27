import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class SolutionQ2 {

    static  class State {
        public int i;
        public int j;
        public String prevOp;
        public State prevState;

        public State(int i, int j, String prevOp, State prevState) {
            this.i = i;
            this.j = j;
            this.prevOp = prevOp;
            this.prevState = prevState;
        }
    }

    static void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
        //  Print the distance along with the sequence of moves
        boolean[][] visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        // -2 => L; 2 => R; -3 => UL; 1 => LL; -1 => UR; 3 => LR

        HashMap<Integer, String> operationMap = new HashMap<>();
        HashMap<Integer, int[]> dirMap = new HashMap<>();

        initHashMap(operationMap, dirMap);



        LinkedList<State> queue = new LinkedList<>();

        State initial = new State(i_start, j_start, null, null);

        queue.add(initial);

        while (!queue.isEmpty()) {
            State s = queue.pop();
            if (s.i == i_end && s.j == j_end) {
                State temp = s;
                int count = 0;
                String path = "";
                while (temp.prevState != null) {
                    count ++;
                    path = temp.prevOp + " " + path;
                    temp = temp.prevState;
                }
                System.out.println(count);
                System.out.println(path);
                return;
            }
            // Try all possible moves
            for (int k = 0; k < dirMap.size(); k++) {
                int[] dir = (int[])dirMap.get(k);
                int new_i = s.i + dir[0];
                int new_j = s.j + dir[1];
                if (isValidCoordinate(new_i, new_j, n) && !visited[new_i][new_j]) {
                    queue.add(new State(new_i, new_j, operationMap.get(dir[0]+dir[1]), s));
                    visited[new_i][new_j] = true;
                }
            
            }
        }
        System.out.println("Impossible");

    }

    private static void initHashMap(HashMap<Integer, String> operationMap, HashMap<Integer, int[]> dirMap) {
        operationMap.put(-2, "L");
        operationMap.put(2, "R");
        operationMap.put(-3, "UL");
        operationMap.put(3, "LR");
        operationMap.put(-1, "UR");
        operationMap.put(1, "LL");
        dirMap.put(0, new int[]{-2,-1});
        dirMap.put(1, new int[]{-2,1});
        dirMap.put(2, new int[]{0,2});
        dirMap.put(3, new int[]{2,1});
        dirMap.put(4, new int[]{2,-1});
        dirMap.put(5, new int[]{0,-2});
    }

    private static boolean isValidCoordinate(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int i_start = in.nextInt();
        int j_start = in.nextInt();
        int i_end = in.nextInt();
        int j_end = in.nextInt();
        printShortestPath(n, i_start, j_start, i_end, j_end);
        in.close();
    }
}
