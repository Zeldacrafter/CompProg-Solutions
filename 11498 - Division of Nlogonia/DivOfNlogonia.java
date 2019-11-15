import java.util.Scanner;

public class DivOfNlogonia {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(true) {

            int queries = s.nextInt();
            if(queries == 0) break;
            int n = s.nextInt();
            int m = s.nextInt();
            for(int i = 0; i < queries; i++) {
                int x = s.nextInt();
                int y = s.nextInt();

                if(x == n || y == m) System.out.println("divisa");
                else if(x < n && y > m) System.out.println("NO");
                else if(x > n && y > m) System.out.println("NE");
                else if(x > n && y < m) System.out.println("SE");
                else if(x < n && y < m) System.out.println("SO");

            }
        }

        s.close();
    }
}
