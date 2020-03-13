import java.util.Scanner;

public class GreyCodes {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int testCases = s.nextInt();
        for (int i = 0; i < testCases; i++) {
            s.nextInt(); // n not relevant
            int k = s.nextInt();

            System.out.println(k ^ (k >> 1));
        }

        s.close();
    }

}
