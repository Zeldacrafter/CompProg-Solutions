import java.util.Scanner;

public class NumberingRoads {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        for(int i = 1;;i++) {

            int r = s.nextInt();
            int n = s.nextInt();

            if (r == 0 && n == 0) break;

            int k = (int)Math.ceil((r-n)/(double)n); // TODO:


            if (k <= 26) System.out.println("Case " + i + ": " + k);
            else System.out.println("Case " + i + ": impossible");
        }

        s.close();
    }
}
