import java.util.Scanner;

public class CombLock {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(true) {
            int a = s.nextInt();
            int b = s.nextInt();
            int c = s.nextInt();
            int d = s.nextInt();

            if(a == 0 && b == 0 && c == 0 && d == 0) break;

            int n = 360*3 +
                    (
                        (a - b + 40) % 40 +
                        (c - b + 40) % 40 +
                        (c - d + 40) % 40
                    ) * 9;
            System.out.println(n);
        }

        s.close();
    }
}
