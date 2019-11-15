import java.util.Scanner;

public class HajjAkbar {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        a:
        for (int i = 1;; i++) {
            String line = s.nextLine();

            switch (line) {
                case "*": break a;
                case "Hajj":
                    System.out.println("Case " + i + ": Hajj-e-Akbar");break;
                case "Umrah":
                    System.out.println("Case " + i + ": Hajj-e-Asghar");
            }
        }

        s.close();
    }
}
