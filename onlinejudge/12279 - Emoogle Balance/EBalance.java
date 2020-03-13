import java.util.Scanner;

public class EBalance {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        for(int cases = 1;;cases++) {
            int n = s.nextInt();
            if(n == 0) break;

            int balance = 0;

            for(int i = 0; i < n; i++)
                balance += (s.nextInt() == 0) ? -1 : 1;

            System.out.println("Case " + cases + ": " + balance );
        }

        s.close();
    }
}
