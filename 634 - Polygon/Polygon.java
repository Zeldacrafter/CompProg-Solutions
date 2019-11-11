import java.util.Scanner;

public class Main {

    static final double EPS = 1e-9;

    static class Pt {
        double x, y;
        public Pt(double _x, double _y) {x = _x; y = _y;};
    }

    static double dot(Pt a, Pt b) {
        return a.x*b.x + a.y*b.y;
    }

    static double normSqr(Pt a) {
        return a.x*a.x + a.y*a.y;
    }

    static double cross(Pt a, Pt b) {
        return a.x * b.y - a.y * b.x;
    }

    static boolean ccw(Pt a, Pt b, Pt c) {
        return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
    }

    static double angle(Pt a, Pt o, Pt b) {
        Pt oa = new Pt(o.x - a.x, o.y - a.y);
        Pt ob = new Pt(o.x - b.x, o.y - b.y);
        return Math.acos(dot(oa, ob) / Math.sqrt(normSqr(oa) * normSqr(ob)) );
    }

    static boolean collinear(Pt p, Pt q, Pt r) {
        Pt pq = new Pt(q.x - p.x, q.y - p.y);
        Pt pr = new Pt(r.x - p.x, r.y - p.y);
        return Math.abs(cross(pq, pr)) < EPS;
    }

    static boolean inPolygon(Pt[] poly, Pt p) {
        //We assume that poly[0] = poly[poly.length-1]
        if(poly.length == 0) return false;
        double sum = 0;
        for(int i = 0; i < poly.length-1; i++) {
            if(ccw(p, poly[i], poly[i+1]) || collinear(p, poly[i], poly[i+1]))
                sum += angle(poly[i], p, poly[i+1]); //Left turn
            else
                sum -= angle(poly[i], p, poly[i+1]); //Right turn
        }
        return Math.abs( Math.abs(sum) - 2*Math.PI ) < EPS;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while(true) {
            int n = s.nextInt();
            if(n == 0) break;
            Pt[] pts = new Pt[n+1];
            for(int i = 0; i < n; i++)
                pts[i] = new Pt(s.nextInt(), s.nextInt());
            pts[n] = pts[0];
            Pt p = new Pt(s.nextInt(), s.nextInt());
            System.out.println(inPolygon(pts, p) ? "T" : "F");
        }
        s.close();
    }
}
