import java.util.Scanner;

import static java.lang.Math.abs;

public class Main {

    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }

    static class Pt {
        long x, y;
        public Pt(long _x, long _y) {x = _x; y = _y;}
    }

    static long onEdge(Pt[] pts) {
        long res = pts.length;
        for(int i = 0; i < pts.length; i++) {
            int adjI = (i+1) % pts.length;
            long dx = (pts[i].x - pts[adjI].x);
            long dy = (pts[i].y - pts[adjI].y);
            res += abs(gcd(dx,dy)) - 1;
        }
        return res;
    }

    static long area(Pt[] pts) {
        long res = 0;
        for (int i = 0; i < pts.length; i++) {
            Pt p = (i != 0) ? pts[i - 1] : pts[pts.length-1];
            Pt q = pts[i];
            res += (p.x - q.x) * (p.y + q.y);
        }
        return abs(res);
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        while(true) {

            int n = s.nextInt();
            if(n == 0) break;

            Pt[] pts = new Pt[n];
            for(int i = 0; i < pts.length; i++)
                pts[i] = new Pt(s.nextLong(), s.nextLong());

            long res = (long)(area(pts)/2.0 - onEdge(pts)/2.0 + 1);
            System.out.println(res);
        }

        s.close();

    }
}
