import java.util.Scanner;

import static java.lang.Math.max;

public class BridgeHandEvaluator {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            String[] line = s.nextLine().split(" ");

            int score = 0;

            int spadeAm = 0;
            int heartAm = 0;
            int diamondAm = 0;
            int clubAm = 0;

            boolean clubKing = false;
            boolean heartKing = false;
            boolean diamondKing = false;
            boolean spadeKing = false;

            boolean clubQueen = false;
            boolean heartQueen = false;
            boolean diamondQueen = false;
            boolean spadeQueen = false;

            boolean clubJack = false;
            boolean heartJack = false;
            boolean diamondJack = false;
            boolean spadeJack = false;

            boolean clubStopped = false;
            boolean heartStopped = false;
            boolean diamondStopped = false;
            boolean spadeStopped = false;

            for (int i = 0; i < line.length; i++) {
                char val = line[i].charAt(0);
                char suit = line[i].charAt(1);

                if(val == 'A' || val == 'K' || val == 'Q' || val == 'J') {
                    if(val == 'A') {
                        score += 4;
                        if(suit == 'S') spadeStopped = true;
                        else if(suit == 'H') heartStopped = true;
                        else if(suit == 'D') diamondStopped = true;
                        else if(suit == 'C') clubStopped = true;
                    }
                    else if(val == 'K') {
                        score += 3;
                        if(suit == 'S') spadeKing = true;
                        else if(suit == 'H') heartKing = true;
                        else if(suit == 'D') diamondKing = true;
                        else if(suit == 'C') clubKing = true;
                    }
                    else if(val == 'Q') {
                        score += 2;
                        if(suit == 'S') spadeQueen = true;
                        else if(suit == 'H') heartQueen = true;
                        else if(suit == 'D') diamondQueen = true;
                        else if(suit == 'C') clubQueen = true;
                    }
                    else if(val == 'J') {
                        score += 1;
                        if(suit == 'S') spadeJack = true;
                        else if(suit == 'H') heartJack = true;
                        else if(suit == 'D') diamondJack = true;
                        else if(suit == 'C') clubJack = true;
                    }
                }

                if(suit == 'S') spadeAm++;
                else if(suit == 'H') heartAm++;
                else if(suit == 'D') diamondAm++;
                else if(suit == 'C') clubAm++;
            }

            if(spadeKing && spadeAm == 1) score--;
            if(diamondKing && diamondAm == 1) score--;
            if(heartKing && heartAm == 1) score--;
            if(clubKing && clubAm == 1) score--;

            if(spadeQueen && spadeAm <= 2) score--;
            if(diamondQueen && diamondAm <= 2) score--;
            if(heartQueen && heartAm <= 2) score--;
            if(clubQueen && clubAm <= 2) score--;

            if(spadeJack && spadeAm <= 3) score--;
            if(diamondJack && diamondAm <= 3) score--;
            if(heartJack && heartAm <= 3) score--;
            if(clubJack && clubAm <= 3) score--;

            if(spadeKing && spadeAm > 1) spadeStopped = true;
            if(heartKing && heartAm > 1) heartStopped = true;
            if(diamondKing && diamondAm > 1) diamondStopped = true;
            if(clubKing && clubAm > 1) clubStopped = true;

            if(spadeQueen && spadeAm > 2) spadeStopped = true;
            if(heartQueen && heartAm > 2) heartStopped = true;
            if(diamondQueen && diamondAm > 2) diamondStopped = true;
            if(clubQueen && clubAm > 2) clubStopped = true;

            if (score >= 16 && spadeStopped && diamondStopped && heartStopped && clubStopped) {
                System.out.println("BID NO-TRUMP");
            } else {
                if (clubAm == 2) score++;
                if (heartAm == 2) score++;
                if (spadeAm == 2) score++;
                if (diamondAm == 2) score++;

                if (clubAm < 2) score += 2;
                if (heartAm < 2) score += 2;
                if (spadeAm < 2) score += 2;
                if (diamondAm < 2) score += 2;

                if (score < 14) System.out.println("PASS");
                else {
                    int max = max(max(clubAm, heartAm), max(spadeAm, diamondAm));
                    if (max == spadeAm) System.out.println("BID S");
                    else if (max == heartAm) System.out.println("BID H");
                    else if (max == diamondAm) System.out.println("BID D");
                    else System.out.println("BID C");
                }
            }
        }

        s.close();
    }
}
