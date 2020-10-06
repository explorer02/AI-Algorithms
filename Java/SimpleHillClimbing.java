import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;

public class SimpleHillClimbing {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter number of queens: ");
        int n = Integer.parseInt(br.readLine());
        int[] board = generateRandom(n);
        int h = heuristic(board);
        System.out.println("Initial Board: " + Arrays.toString(board));
        System.out.println("Heuristic: " + h);
        System.out.println();
        for (int col = 0; col < n; col++){
            if (h == 0) break;
            int bestMove = board[col];
            for (int row = 0; row < n; row++){
                if (bestMove == row) continue;
                int[] newBoard = board.clone();
                newBoard[col] = row;
                int hNew = heuristic(newBoard);
                if (hNew < h){
                    board = newBoard;
                    h = hNew;
                    System.out.println("Configuration: " + Arrays.toString(board));
                    System.out.println("Heuristic: " + h);
                    System.out.println();
                    break;
                }
            }
        }

        System.out.println("Final Board: " + Arrays.toString(board));
        System.out.println("Heuristic: " + h);
        if (h == 0) System.out.println("Solution found!");
        else System.out.println("Solution not found!");
    }


    private static int heuristic(int[] board){
        int clash = 0;
        for (int i = 0; i < board.length; i++){
            for (int j = i+1; j < board.length; j++) {
                if (board[i] == board[j]) clash++;
                int offset = j - i;
                if (board[i] == board[j] + offset || board[i] == board[j] - offset) clash++;
            }
        }

        return clash;
    }


    private static int[] generateRandom(int n){
        int[] board = new int[n];
        Random random = new Random();
        for (int i = 0; i < n; i++)
            board[i] = random.nextInt(n);
        return board;
    }
}
