import java.time.LocalDate;
import java.util.Scanner;
import java.util.GregorianCalendar;

public class CancerOrScorpio {

    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        for(int i = 1; i <= n; i++) {
            int date = s.nextInt();
            int year = date % 10000;
            date /= 10000;
            int day = date % 100;
            date /= 100;
            int month = date;

            LocalDate d = LocalDate.of(year, month, day);
            d = d.plusWeeks(40);
            year = d.getYear();
            day = d.getDayOfMonth();
            month = d.getMonthValue();
            System.out.print(i + " " +
                    ((month < 10) ? "0" : "") + month  + "/" +
                    ((day < 10) ? "0" : "") + day + "/"
                            + year + " ");

            if( (month == 1 && day >= 21) || (month == 2 && day <= 19) )
                System.out.println("aquarius");
            else if( (month == 2) || (month == 3 && day <= 20) )
                System.out.println("pisces");
            else if( (month == 3) || (month == 4 && day <= 20) )
                System.out.println("aries");
            else if( (month == 4) || (month == 5 && day <= 21) )
                System.out.println("taurus");
            else if( (month == 5) || (month == 6 && day <= 21) )
                System.out.println("gemini");
            else if( (month == 6) || (month == 7 && day <= 22) )
                System.out.println("cancer");
            else if( (month == 7) || (month == 8 && day <= 21) )
                System.out.println("leo");
            else if( (month == 8) || (month == 9 && day <= 23) )
                System.out.println("virgo");
            else if( (month == 9) || (month == 10 && day <= 23) )
                System.out.println("libra");
            else if( (month == 10) || (month == 11 && day <= 22) )
                System.out.println("scorpio");
            else if( (month == 11) || (month == 12 && day <= 22) )
                System.out.println("sagittarius");
            else
                System.out.println("capricorn");




        }

        s.close();
    }
}
