import java.util.Scanner;

public class Nessie {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int caseAmount = s.nextInt();

        for(int i = 0; i < caseAmount; i++) {

            int n = s.nextInt();
            int m = s.nextInt();

            if(n >= 3) n -= 2;
            if(m >= 3) m -= 2;

            int res = (int)(Math.ceil(n/3.0) * Math.ceil(m/3.0));
            System.out.println(res);

        }

        s.close();
    }
}
