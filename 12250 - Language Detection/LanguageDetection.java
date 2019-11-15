import java.util.Scanner;

public class LanguageDetection {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        a:
        for(int i = 1;;i++) {
            String line = s.nextLine();

            switch(line) {
                case "#": break a;
                case "HELLO": System.out.println("Case " + i + ": ENGLISH");
                    break;
                case "HALLO": System.out.println("Case " + i + ": GERMAN");
                    break;
                case "HOLA": System.out.println("Case " + i + ": SPANISH");
                    break;
                case "BONJOUR": System.out.println("Case " + i + ": FRENCH");
                    break;
                case "CIAO": System.out.println("Case " + i + ": ITALIAN");
                    break;
                case "ZDRAVSTVUJTE": System.out.println("Case " + i + ": RUSSIAN");
                    break;
                default:
                    System.out.println("Case " + i + ": UNKNOWN");
            }
        }

        s.close();
    }
}
