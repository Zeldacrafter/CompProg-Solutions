import java.util.Scanner;

import static java.lang.Math.*;

public class Solveit {

    static int p, q, r, s, t, u;

    static double f(double x) {
        return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
    }

    static double f_prime(double x) {
        return -p*exp(-x) + q*cos(x) - r*sin(x) + s / (cos(x)*cos(x)) + 2*t*x;
    }

    static double solve() {
        if (f(0) == 0) return 0;
        double guess = 0.5;
        for (;;) {
            double guess1 = guess - f(guess) / f_prime(guess);
            if (abs(guess1 - guess) < 1e-7) return guess1;
            guess = guess1;
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(sc.hasNext()) {
            p = sc.nextInt();
            q = sc.nextInt();
            r = sc.nextInt();
            s = sc.nextInt();
            t = sc.nextInt();
            u = sc.nextInt();

            if (f(0) * f(1) > 0) {
                System.out.println("No solution");
            } else {
                System.out.println(String.format("%.4f", solve()));
            }
        }

        sc.close();
    }
}
