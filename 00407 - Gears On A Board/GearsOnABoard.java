import java.util.ArrayList;
import java.util.Scanner;

import static java.lang.Math.abs;

public class GearsOnABoard {

    static class Gear {
        int x, y, radIn, radOut;
        double rpm;

        ArrayList<Integer> outAdj = new ArrayList<>();
        ArrayList<Integer> inAdj = new ArrayList<>();

        public Gear(int _x, int _y, int _radIn, int _radOut) {
            x = _x;
            y = _y;
            radIn = _radIn;
            radOut = _radOut;
        }

        public Gear(int _x, int _y, int _radIn, int _radOut, int _rpm) {
            x = _x;
            y = _y;
            radIn = _radIn;
            radOut = _radOut;
            rpm = _rpm;
        }
    }

    static Gear[] gears = new Gear[31]; //pos 0 is motor

    static double gearDist(Gear a, Gear b) {
        return Math.sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    }

    static boolean isZero(double d) {
        return abs(d) < 1e-8;
    }

    static boolean[] visited;
    static boolean dfs(int v) {
        visited[v] = true;

        Gear curr = gears[v];

        for(int i = 0; i < curr.inAdj.size(); i++) {
            int u = gears[v].inAdj.get(i);
            Gear adj = gears[u];

            double rpmOfAdj = -curr.rpm * curr.radIn / adj.radIn;
            if(adj.rpm != 0) {
                //rpm was already set.
                if(adj.rpm != rpmOfAdj)
                    return false;
            } else {
                adj.rpm = rpmOfAdj;
            }

            if(!visited[u]) //visit adj
                if(!dfs(u)) return false; //Cancel on error.
        }

        for(int i = 0; i < curr.outAdj.size(); i++) {
            int u = gears[v].outAdj.get(i);
            Gear adj = gears[u];

            double rpmOfAdj = -curr.rpm * curr.radOut / adj.radOut;
            if(adj.rpm != 0) {
                //rpm was already set.
                if(adj.rpm != rpmOfAdj)
                    return false;
            } else {
                adj.rpm = rpmOfAdj;
            }

            if(!visited[u]) //visit adj
                if(!dfs(u)) return false; //Cancel on error.
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        mainLoop:
        for(int simNr = 1; s.hasNext(); simNr++) {
            System.out.println("Simulation #" + simNr);

            Gear motor = new Gear(s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt());
            int gearAmount = s.nextInt() + 1;

            gears[0] = motor;
            for (int i = 1; i < gearAmount; i++)
                gears[i] = new Gear(s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt());

            // Build graph
            for (int i = 0; i < gearAmount; i++) {
                for (int j = 0; j < i; j++) {
                    double dist = gearDist(gears[i], gears[j]);
                    double diffOut = dist - (gears[i].radOut + gears[j].radOut);
                    if(isZero(diffOut)) {
                        gears[i].outAdj.add(j);
                        gears[j].outAdj.add(i);
                    } else if(diffOut < 0) {
                        System.out.println("Error -- Overlapping Gears\n");
                        continue mainLoop;
                    }
                    double diffIn = dist - (gears[i].radIn + gears[j].radIn);
                    if(isZero(diffIn)) {
                        gears[i].inAdj.add(j);
                        gears[j].inAdj.add(i);
                    } else if(diffIn < 0) {
                        System.out.println("Error -- Overlapping Gears\n");
                        continue mainLoop;
                    }
                }
            }

            visited = new boolean[gearAmount];
            boolean succ = dfs(0);

            if(!succ)
                System.out.println("Error -- Conflicting Gear Rotation");
            else {
                for (int i = 1; i < gearAmount; i++) {
                    Gear g = gears[i];
                    System.out.print(" " + i + ": ");
                    if(g.rpm == 0) {
                        System.out.println("Warning -- Idle Gear");
                    }else {
                        System.out.printf("%c %.2f\n", g.rpm > 0 ? 'R' : 'L', Math.abs(g.rpm));
                    }
                }
            }

            System.out.println();
        }

        s.close();
    }


}
