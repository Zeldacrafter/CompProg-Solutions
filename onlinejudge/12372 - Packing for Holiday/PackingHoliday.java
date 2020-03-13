import java.util.Scanner;

public class PackingHoliday {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();

        for(int i = 1; i <= n; i++) {

            if(s.nextInt() <= 20 & s.nextInt() <= 20 & s.nextInt() <= 20)
                System.out.println("Case " + i + ": good");
            else
                System.out.println("Case " + i + ": bad");
        }

        s.close();
    }
}
