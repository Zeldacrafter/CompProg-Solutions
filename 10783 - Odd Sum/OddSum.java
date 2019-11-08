import java.util.Scanner;

public class OddSum {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int cases = s.nextInt();

        for(int i = 1; i <= cases; i++) {
            int a = s.nextInt();
            int b = s.nextInt();

            int res = ((b+1)/2) * ((b+1)/2) - (a/2) * (a/2);

            System.out.println("Case " + i + ": " + res);
        }

        s.close();

    }
}
