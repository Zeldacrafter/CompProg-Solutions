import java.util.Scanner;

public class TexQuotes {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        boolean replace = true;
        while(s.hasNextLine()) {

            String line = s.nextLine();
            for(int i = 0; i < line.length(); i++) {
                if(line.charAt(i) == '\"') {
                    if(replace) System.out.print("``");
                    else System.out.print("''");
                    replace = !replace;
                } else
                    System.out.print(line.charAt(i));
            }

            System.out.println();
        }

        s.close();

    }
}
