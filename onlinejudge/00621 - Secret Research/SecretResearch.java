import java.util.Scanner;

public class SecretResearch {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        s.nextLine();
        for (int i = 0; i < n; i++) {
            String str = s.nextLine();

            if("1".equals(str) || "4".equals(str) || "78".equals(str) )
                System.out.println("+");
            else if(str.endsWith("35"))
                System.out.println("-");
            else if(str.startsWith("190"))
                System.out.println("?");
            else
                System.out.println("*");

        }

        s.close();
    }
}
