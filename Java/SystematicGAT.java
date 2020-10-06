import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class SystematicGAT {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter number of elements: ");
        int n = Integer.parseInt(br.readLine());

        System.out.println("Enter elements: ");
        int[] arr = new int[n];
        String[] inp = br.readLine().split(" ");
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(inp[i]);
        }

        System.out.println("Enter target sum: ");
        int sum = Integer.parseInt(br.readLine());

        for (int i = 0; i < arr.length; i++)
            if (helper(arr, sum, arr[i], i, new ArrayList<>())) return;
    }


    private static boolean helper(int[] arr, int sum, int s, int index, ArrayList<Integer> l){
        if (s > sum) {
            l.add(arr[index]);
            System.out.println("Sum of " + l + " greater than required sum. Hence backtracking!");
            l.remove(l.size()-1);
            return false;
        }
        l.add(arr[index]);
        if (s == sum){
            System.out.println("Sum found!");
            System.out.println(l);
            return true;
        }


        for (int i = index+1; i < arr.length; i++){
            if (helper(arr, sum, s+arr[i], i, l)) return true;
        }
        l.remove(l.size()-1);
        return false;
    }
}
