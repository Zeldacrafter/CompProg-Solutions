import java.util.Scanner;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Parking {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int caseAmount = s.nextInt();
        for(int c = 0; c < caseAmount; c++) {

            int storeAmount = s.nextInt();
            int[] stores = new int[storeAmount];
            int min = 100000;
            int max = -1;
            for(int i = 0; i < storeAmount; i++) {
                stores[i] = s.nextInt();
                min = min(min, stores[i]);
                max = max(max, stores[i]);
            }

            System.out.println(2*(max-min));
        }

        s.close();
    }
}
