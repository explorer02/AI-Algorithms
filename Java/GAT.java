import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Random;

public class GAT {

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

        Random random = new Random();
        int max = (int)Math.pow(2, n);

        while (true){
            int r = random.nextInt(max);
            int s = 0;
            HashSet<Integer> set = new HashSet<>();
            String bin = Integer.toBinaryString(r);
            int index = 0;
            for (char c : bin.toCharArray()){
                if (c == '1'){
                    s += arr[index];
                    set.add(arr[index]);
                }
                index++;
            }

            System.out.println("Subset: " + set);
            System.out.println("Sum: " + s);
            if (s == sum){
                System.out.println("Solution Found!");
                break;
            }
            System.out.println();
        }
    }
}
