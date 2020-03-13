import java.util.Scanner;

public class LightMoreLight {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        for(;;) {
            long n = s.nextLong();

            if (n == 0) break;

            double sqrt = Math.sqrt(n);
            if((long)sqrt == sqrt)
                System.out.println("yes");
            else
                System.out.println("no");
        }

        s.close();
    }

}