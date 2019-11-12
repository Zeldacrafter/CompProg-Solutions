
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.lang.Math.*;

public class TrashRemoval {

    static class Pt {
        double x, y;

        public Pt(double x, double y) {this.x = x; this.y = y;}
    }

    /** Angle between points a and b on origin o */
    static double angle(Pt a, Pt o, Pt b) {
        Pt oa = toPoint(o, a);
        Pt ob = toPoint(o, b);
        return acos(dot(oa, ob) / Math.sqrt(normSqr(oa) * normSqr(ob)) );
    }

    static Pt toPoint(Pt a, Pt b) {return new Pt(a.x - b.x, a.y - b.y);}
    static Pt add(Pt a, Pt b) {return new Pt(a.x+b.x, a.y+b.y);}
    static double dot(Pt a, Pt b) {return a.x*b.x + a.y*b.y;}
    static double normSqr(Pt a) {return a.x*a.x + a.y*a.y;}
    static double cross(Pt a, Pt b) {return a.x * b.y - a.y * b.x;}
    static Pt scale(Pt a, double s) {return new Pt(a.x*s, a.y*s);}

    static double dist(Pt a, Pt b) {
        Pt ab = toPoint(a, b);
        return Math.sqrt(ab.x*ab.x + ab.y*ab.y);
    }

    static Pt shortestPtToLine(Pt p, Pt a, Pt b) {
        Pt ap = new Pt(a.x - p.x, a.y - p.y);
        Pt ab = new Pt(a.x - b.x, a.y - b.y);
        return toPoint(a, scale(ab, dot(ap, ab) / normSqr(ab))); //Point that is closest
    }

    /** Distance of point p through line (a,b) */
    static double distToLine(Pt p, Pt a, Pt b) {
        return dist(shortestPtToLine(p, a, b), p);
    }

    static double dir(Pt a, Pt b, Pt c) { return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y); }
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
        int caseCount = 1;
        while (true) {
            int n = s.nextInt();
            if(n == 0) break;

            ArrayList<Pt> poly = new ArrayList<>();
            for(int j = 0; j < n; j++)
                poly.add(new Pt(s.nextInt(), s.nextInt()));

            // Get convex hull of polynom successfully.
            convexHull(poly);

            //Try all pt - line combinations for the smallest distance
            double smallestDist = 1e10;
            for(int i = 0; i < poly.size(); i++) {
                Pt p = poly.get(i);
                Pt pNext = poly.get((i+1) % poly.size());
                Pt pPrev = poly.get((i-1 + poly.size()) % poly.size());
                double maxDist = 1e10;

                for(int j = 0; j < poly.size(); j++) {
                    int jP1 = (j+1)%poly.size();

                    //We are only interested in edges where p is not an endpoint
                    if(j == i || jP1 == i) continue;

                    Pt shortestAway = shortestPtToLine(p, poly.get(j), poly.get(jP1));
                    double angleNext = angle(shortestAway,p,pNext);
                    double anglePrev = angle(shortestAway,p,pPrev);
                    if ( (angleNext > PI/2 && angleNext < 3*PI/2) || (anglePrev > PI/2 && anglePrev < 3*PI/2) ) continue;

                    double d = distToLine(p, poly.get(j), poly.get(jP1));
                    maxDist = min(maxDist, d);
                }
                smallestDist = min(smallestDist, maxDist);
            }
            System.out.print("Case " + caseCount++ + ": ");
            smallestDist = Math.round(smallestDist*100.0)/100.0;
            System.out.println(String.format("%.2f", smallestDist));


        }
        s.close();
    }
}
