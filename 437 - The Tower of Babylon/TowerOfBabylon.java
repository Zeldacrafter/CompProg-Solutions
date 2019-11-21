import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {

    static class Pt {
        long x, y, z;
        public Pt(long _x, long _y, long _z) {
            x = _x;
            y = _y;
            z = _z;
        }
    }

    static long[][] adj = new long[100][100];
    static Pt[] towers = new Pt[100];

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        for(int testCase = 1; ; testCase++) {

            int towerC = s.nextInt() * 3;
            if(towerC == 0) break;

            Arrays.fill(towers, null);
            for (int i = 0; i < towerC; i++)
                Arrays.fill(adj[i], -1_000_000);

            for (int i = 0; i < towerC; i += 3) {
                long x = s.nextLong();
                long y = s.nextLong();
                long z = s.nextLong();
                towers[i]   = new Pt(x, y, z);
                towers[i+1] = new Pt(z, x, y);
                towers[i+2] = new Pt(y, z, x);
            }

            for (int i = 0; i < towerC; i++) {
                Pt bottom = towers[i];
                for (int j = 0; j < towerC; j++) {
                    Pt top = towers[j];
                    if( (bottom.x > top.x && bottom.y > top.y) || (bottom.x > top.y && bottom.y > top.x)) {
                        //System.out.println("Added edge from " + bottom.x + ", " + bottom.y + " to " + top.x + ", " + top.y + "!");
                        adj[i][j] = top.z;
                    }
                }
            }

            for (int k = 0; k < towerC; k++)
                for (int i = 0; i < towerC; i++)
                    for (int j = 0; j < towerC; j++)
                        adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);

            long res = 0;
            for (int x = 0; x < towerC; x++)
                for (int y = 0; y < towerC; y++)
                    res = max(res, towers[x].z +  adj[x][y]);

            System.out.println("Case " + testCase + ": maximum height = " + res);
        }

        s.close();
    }
}
