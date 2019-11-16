import java.time.LocalDate;
import java.util.Scanner;

public class Y3K {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(true) {
            int toPredict = s.nextInt();
            int days = s.nextInt();
            int month = s.nextInt();
            int year = s.nextInt();
            if(toPredict == 0 && days == 0 && month == 0 && year == 0) break;

            LocalDate d = LocalDate.of(year, month, days);
            d = d.plusDays(toPredict);
            System.out.println(d.getDayOfMonth() + " " + d.getMonthValue() + " " + d.getYear());
        }

        s.close();
    }
}
