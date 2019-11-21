import java.util.Scanner;

public class TheSnail {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(true) {
            int height = s.nextInt();
            if (height == 0) break;
            double up = s.nextInt();
            int down = s.nextInt();
            int fatigue = s.nextInt();

            double dist = 0;
            double lessPerDay = up * (fatigue / 100.0);

            int day = 1;
            while(true) {
                if (up > 0) {
                    dist += up;
                    if (dist > height) {
                        System.out.println("success on day " + day);
                        break;
                    }
                }
                up -= lessPerDay;
                dist -= down;
                if(dist < 0) {
                    System.out.println("failure on day " + day);
                    break;
                }
                day++;
            }

        }

        s.close();
    }
}
