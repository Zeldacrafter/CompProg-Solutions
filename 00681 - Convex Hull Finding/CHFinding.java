import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class CHFinding {

    static class Pt {
        int x, y;

        public Pt(int x, int y) {this.x = x; this.y = y;}
    }

    static int dir(Pt a, Pt b, Pt c) { return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y); }
    static boolean cw(Pt a, Pt b, Pt c) { return dir(a, b, c) < 0; }
    static boolean ccw(Pt a, Pt b, Pt c) { return dir(a, b, c) > 0; }

    static void convexHull(List<Pt> pts) {
        if(pts.size() == 0) return;
        pts.sort((a, b) -> {
            if (a.x < b.x || (a.x == b.x && a.y < b.y)) return -1;
            if (a.x == b.x && a.y == b.y) return 0;
            return 1;
        });
        Pt fst = pts.get(0);
        Pt lst = pts.get(pts.size()-1);
        List<Pt> up = new ArrayList<>();
        List<Pt> down = new ArrayList<>();
        up.add(fst);
        down.add(fst);

        for(Pt p : pts) {
            if(p.equals(lst) || cw(fst, p, lst)) {
                while(up.size() >= 2 && !cw(up.get(up.size()-2), up.get(up.size()-1), p))
                    up.remove(up.size()-1);
                up.add(p);
            }
            if(p.equals(lst) || ccw(fst, p, lst)) {
                while(down.size() >= 2 && !ccw(down.get(down.size()-2), down.get(down.size()-1), p))
                    down.remove(down.size()-1);
                down.add(p);
            }
        }
        pts.clear();

        pts.addAll(down);
        for(int i = up.size() - 2; i > 0; i--)
            pts.add(up.get(i));

    }


    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int k = s.nextInt();
        System.out.println(k);

        for(int i = 0; i < k; i++) {
            int n = s.nextInt();

            ArrayList<Pt> pts = new ArrayList<>();
            for(int j = 0; j < n; j++)
                pts.add(new Pt(s.nextInt(), s.nextInt()));

            convexHull(pts);
            System.out.println(pts.size()+1);

            Pt firstElem = Collections.min(pts, (a, b) -> {
                if (a.y < b.y || (a.y == b.y && a.x < b.x)) return -1;
                if (a.x == b.x && a.y == b.y) return 0;
                return 1;
            });
            int firstIndex = pts.indexOf(firstElem);


            for(int j = 0; j < pts.size(); j++) {
                Pt curr = pts.get((j + firstIndex) % pts.size());
                System.out.println(curr.x + " " + curr.y);
            }
            System.out.println(firstElem.x + " " + firstElem.y);

            if(i != k-1) {
                System.out.println(-1);
                s.nextInt();
            }
        }

        s.close();
    }
}
