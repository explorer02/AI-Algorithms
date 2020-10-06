import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;

public class Puzzle8 {

    static char[][] initialState;
    static char[][] finalState;
    static HashSet<String> visited;

    public static void main(String[] args) throws IOException {
        initialState = new char[3][3];
        finalState = new char[3][3];
        visited = new HashSet();

        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter 3 x 3 initial state");
        for (int i = 0; i < 3; i++){
            String[] inp = br.readLine().split(" ");
            initialState[i][0] = inp[0].charAt(0);
            initialState[i][1] = inp[1].charAt(0);
            initialState[i][2] = inp[2].charAt(0);
        }

        System.out.println();

        System.out.println("Enter 3 x 3 final state");
        for (int i = 0; i < 3; i++){
            String[] inp = br.readLine().split(" ");
            finalState[i][0] = inp[0].charAt(0);
            finalState[i][1] = inp[1].charAt(0);
            finalState[i][2] = inp[2].charAt(0);
        }

        System.out.println("=====================================");

        int x = 0;
        int y = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (initialState[i][j] == '@'){
                    x = i;
                    y = j;
                }
            }
        }

        solve(initialState, 0, x, y);


    }


    private static void solve(char[][] matrix, int level, int i, int j){

        if (compare(matrix)) {
            System.out.println("Solution found!");
            return;
        }

        System.out.println("Level : " + level);

        int[][] directions = new int[][]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int min = Integer.MAX_VALUE;
        int nextI = -1;
        int nextJ = -1;
        for (int[] direction : directions){
            int nextX = i + direction[0];
            int nextY = j + direction[1];
            if (isValid(nextX, nextY)){
                char temp = matrix[nextX][nextY];
                matrix[nextX][nextY] = matrix[i][j];
                matrix[i][j] = temp;
                if (!visit(matrix)) {
                    int d = print(matrix);
                    if (d < min) {
                        min = d;
                        nextI = nextX;
                        nextJ = nextY;
                    }
                }
                temp = matrix[nextX][nextY];
                matrix[nextX][nextY] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }

        if (nextI == -1) return;

        char temp = matrix[nextI][nextJ];
        matrix[nextI][nextJ] = matrix[i][j];
        matrix[i][j] = temp;

        markVisited(matrix);

        System.out.println("Selected Matrix: ");
        print(matrix);

        System.out.println("=====================================");
        solve(matrix, level + 1, nextI, nextJ);

    }


    private static int print(char[][] matrix){
        for (int i = 0; i < 3; i++){
            System.out.println(Arrays.toString(matrix[i]));
        }
        int d = dValue(matrix);
        System.out.println();
        System.out.println("d = " + d);
        System.out.println();
        return d;
    }


    private static int dValue(char[][] matrix){
        int d = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (matrix[i][j] != finalState[i][j]) d++;
            }
        }
        return d;
    }


    private static boolean isValid(int i, int j){
        if (i >= 0 && i < 3 && j >= 0 && j < 3) return true;
        return false;
    }

    private static boolean compare(char[][] matrix){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (matrix[i][j] != finalState[i][j]) return false;
            }
        }
        return true;
    }

    private static boolean visit(char[][] matrix){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                sb.append(matrix[i][j]);
            }
        }

        String s = sb.toString();
        return visited.contains(s);
    }

    private static void markVisited(char[][] matrix){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                sb.append(matrix[i][j]);
            }
        }

        visited.add(sb.toString());
    }
}
