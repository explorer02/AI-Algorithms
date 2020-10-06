import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;

public class SteepestHillClimbing {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter number of queens: ");
        int n = Integer.parseInt(br.readLine());
        int[] board = generateRandom(n);
        int h = heuristic(board);
        System.out.println("Initial Board: " + Arrays.toString(board));
        System.out.println("Heuristic: " + h);
        System.out.println("*******************************");
        System.out.println();
        for (int col = 0; col < n; col++){
            System.out.println("Column " + (col+1));
            if (h == 0) break;
            int bestMove = board[col];
            int hBest = h;
            int[] bestBoard = board.clone();
            for (int row = 0; row < n; row++){
                if (bestMove == row) continue;
                int[] newBoard = board.clone();
                newBoard[col] = row;
                int hNew = heuristic(newBoard);
                System.out.println("Intermediate Board: " + Arrays.toString(newBoard));
                System.out.println("Intermediate Heuristic: " + hNew);
                System.out.println();
                if (hNew <= hBest){
                    bestBoard = newBoard;
                    hBest = hNew;
                }
            }

            System.out.println("Selected Board: " + Arrays.toString(bestBoard));
            System.out.println("Heuristic: " + hBest);
            System.out.println("*******************************");
            System.out.println();
            board = bestBoard;
            h = hBest;
        }

        System.out.println("Board: " + Arrays.toString(board));
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
