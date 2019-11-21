import java.util.Scanner;

import static java.lang.Math.max;

public class HorrorDash {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int t = s.nextInt();
        for (int i = 0; i < t; i++) {
            int n = s.nextInt();
            int max = -1;
            for (int j = 0; j < n; j++) {
                max = max(max, s.nextInt());
            }
            System.out.println("Case " + (i+1) + ": " + max);
        }

        s.close();
    }
}
