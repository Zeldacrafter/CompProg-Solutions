import java.util.Scanner;

public class AutomaticAnswer {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int cases = s.nextInt();

        for(int i = 0; i < cases; i++) {

            long n = s.nextInt();
            n = n*315 + 36962;
            n /= 10;
            System.out.println(Math.abs(n) % 10);
        }

        s.close();
    }
}
