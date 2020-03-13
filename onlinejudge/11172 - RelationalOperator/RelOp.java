import java.util.Scanner;

public class RelOp {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        for(int i = 0; i < n; i++) {
            int a = s.nextInt();
            int b = s.nextInt();

            if(a > b) System.out.println(">");
            else if(a < b) System.out.println("<");
            else System.out.println("=");
        }

        s.close();
    }
}
