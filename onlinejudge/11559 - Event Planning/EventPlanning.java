import java.util.Scanner;

import static java.lang.Math.min;

public class EventPlanning {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            int persons = s.nextInt();
            int budget = s.nextInt();
            int hotels = s.nextInt();
            int weeks = s.nextInt();

            int bestPrice = Integer.MAX_VALUE;
            for (int i = 0; i < hotels; i++) {
                int price = s.nextInt();
                boolean isGoodPrice = price*persons <= budget;
                boolean enoughRoom = false;
                for (int j = 0; j < weeks; j++) {
                    if(s.nextInt() >= persons) enoughRoom = true;
                }
                if(isGoodPrice && enoughRoom) bestPrice = min(bestPrice, price*persons);
            }

            if(bestPrice == Integer.MAX_VALUE) System.out.println("stay home");
            else System.out.println(bestPrice);
        }

        s.close();
    }
}
