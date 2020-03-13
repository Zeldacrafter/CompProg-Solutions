import java.util.Scanner;

public class SaveSetu {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            String op = s.next("report|donate");
            switch (op) {
                case "report":
                    System.out.println(sum);
                    break;
                case "donate":
                    sum += s.nextInt();
            }
        }

        s.close();
    }
}
