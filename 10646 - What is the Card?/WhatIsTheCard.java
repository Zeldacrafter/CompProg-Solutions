import java.util.ArrayList;
import java.util.Scanner;

public class WhatIsTheCard {

    static int getVal(String card) {
        int v = card.charAt(1);
        if(v >= '2' && v <= '9') return Integer.parseInt(v + "");
        else return 10;
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int tests = s.nextInt();
        for (int i = 1; i <= tests; i++) {

            ArrayList<String> deck = new ArrayList<>();
            for (int j = 0; j < 52; j++)
                deck.add(s.next());

            int y = 0;

            int pileSize = 52 - 25;
            for (int j = 0; j < 3; j++) {
                String curr = deck.get(pileSize-1);
                int val = getVal(curr);
                y += val;
                deck.remove((pileSize--) -1);
                for (int k = 0; k < 10 - val; k++)
                    deck.remove((pileSize--) - 1);
            }

            System.out.println("Case " + i + ": " + deck.get(y-1));
        }

        s.close();

    }

}
