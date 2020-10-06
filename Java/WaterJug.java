import java.util.*;

public class WaterJug {

    static HashSet<String> set;
    static TreeMap<Integer, ArrayList<int[]>> map;
    static int solLevel = Integer.MAX_VALUE;

    public static void main(String[] args) {
        set = new HashSet<>();
        map = new TreeMap<>();

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0, 0});
        while (q.size() > 0) {
            int[] poll = q.poll();
            int x = poll[0];
            int y = poll[1];
            int level = poll[2];
            if (set.contains("" + x + y)) continue;
            set.add("" + x + y);
            map.putIfAbsent(level, new ArrayList<>());
            map.get(level).add(new int[]{x, y, level});
            if (x == 2) {
                System.out.println("Solution found at level : " + level);
                solLevel = Math.min(level, solLevel);
            }
            ArrayList<int[]> nextStage = new ArrayList<>();

            if (x < 4) {
                nextStage.add(new int[]{4, y, level + 1});
            }
            if (y < 3) {
                nextStage.add(new int[]{x, 3, level + 1});
            }
            if (x > 0) {
                nextStage.add(new int[]{0, y, level + 1});
            }
            if (y > 0) {
                nextStage.add(new int[]{x, 0, level + 1});
            }
            if (x + y >= 4 && y > 0) {
                nextStage.add(new int[]{4, y - (4 - x), level + 1});
            }
            if (x + y >= 3 && x > 0) {
                nextStage.add(new int[]{x - (3 - y), 3, level + 1});
            }
            if (x + y <= 4 && y > 0) {
                nextStage.add(new int[]{x + y, 0, level + 1});
            }
            if (x + y <= 3 && x > 0) {
                nextStage.add(new int[]{0, x + y, level + 1});
            }
            q.addAll(nextStage);
        }

        for (Map.Entry<Integer, ArrayList<int[]>> e : map.entrySet()) {
            System.out.println("Level: " + e.getKey());
            for (int[] entry : e.getValue()) {
                System.out.print(Arrays.toString(entry));
            }
            if (e.getKey() == solLevel) break;
            System.out.println();
        }
    }
}