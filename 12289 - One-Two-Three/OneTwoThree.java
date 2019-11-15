import java.util.Scanner;

public class OneTwoThree {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int testCases = s.nextInt();
        s.nextLine();
        for(int i = 0; i < testCases; i++) {

            String str = s.nextLine();
            if(str.length() == 5) System.out.println(3);
            else {
                int c = 0;
                c += str.contains("o") ? 1 : 0;
                c += str.contains("n") ? 1 : 0;
                c += str.contains("e") ? 1 : 0;
                if(c >= 2) System.out.println(1);
                else System.out.println(2);
            }

        }

        s.close();
    }
}
