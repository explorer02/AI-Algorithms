import java.util.*;

public class BestFirst {

    public static void main(String[] args) {
        int[][] mat = new int[][]{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}; // variable input


        PriorityQueue<Node> open = new PriorityQueue<>(Comparator.comparingInt(a -> a.heuristic));
        LinkedList<String> closed = new LinkedList<>();
        HashMap<String, Parent> parent = new HashMap<>();

        open.offer(new Node(0, 0, mat[0][0], -1, -1));

        while(open.size() > 0){
            Node n = open.poll();
            if (!parent.containsKey(n.x + " " + n.y)){
                closed.add(n.x + " " + n.y);
                parent.put(n.x + " " + n.y, new Parent(n.parentX, n.parentY, n.heuristic));
            }
            else if (parent.get(n.x + " " + n.y).h > n.heuristic) parent.put(n.x + " " + n.y, new Parent(n.parentX, n.parentY, n.heuristic));


            if (n.x == 3 && n.y == 3){
                System.out.println("Minimum Heuristic: " + n.heuristic);
                printPath(mat, parent);
                return;
            }

            int[][] directions = new int[][]{{1, 0}, {0, 1}};
            for (int[] d : directions){
                int x = n.x + d[0];
                int y = n.y + d[1];

                if (x >= 0 && x < 4 && y >= 0 && y < 4){
                    open.add(new Node(x, y, n.heuristic + mat[x][y], n.x, n.y));
                }
            }
        }

        System.out.println("No Path");
    }


    static void printPath(int[][] mat, HashMap<String, Parent> parent){
        Stack<Integer> stack = new Stack<>();
        stack.push(mat[3][3]);
        Parent p = parent.get("3 3");
        int h = 0;

        while (p.parentX != -1 && p.parentY != -1){
            int x = p.parentX;
            int y = p.parentY;
            stack.add(mat[x][y]);
            p = parent.get(p.parentX + " " + p.parentY);
        }

        int n = stack.size();
        for (int i = 0; i < n; i++){
            System.out.print(stack.pop() + " ");
        }
    }
}


class Node{
    int x;
    int y;
    int heuristic;
    int parentX;
    int parentY;

    Node(int x, int y, int heuristic, int parentX, int parentY){
        this.x = x;
        this.y = y;
        this.heuristic = heuristic;
        this.parentX = parentX;
        this.parentY = parentY;
    }
}

class Parent{
    int parentX;
    int parentY;
    int h;

    public Parent(int parentX, int parentY, int h) {
        this.parentX = parentX;
        this.parentY = parentY;
        this.h = h;
    }
}
