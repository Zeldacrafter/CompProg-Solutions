import java.util.Scanner;

public class RequestForProposal {

    static class Proposal {
        String name;
        double price;
        int rCount;
        public Proposal(String s, double p, int r) {
            name = s;
            price = p;
            rCount = r;
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        for(int rfp = 1;; rfp++) {


            int reqC = s.nextInt();
            int propC = s.nextInt();
            if(reqC == 0 && propC == 0) break;
            s.nextLine();

            if(rfp != 1) {
                System.out.println();
            }
            System.out.println("RFP #" + rfp);

            for (int i = 0; i < reqC; i++)
                s.nextLine(); //Not needed.

            Proposal best = new Proposal("", Integer.MAX_VALUE, -1);
            for (int i = 0; i < propC; i++) {
                Proposal p = new Proposal(s.nextLine(), s.nextDouble(), s.nextInt());
                s.nextLine(); // After parsing int.
                for (int j = 0; j < p.rCount; j++)
                    s.nextLine(); // Just throw away the next n lines.
                if(best.rCount < p.rCount || (best.rCount == p.rCount && best.price > p.price))
                    best = p; //Found new best
            }

            System.out.println(best.name);

        }
        s.close();
    }
}
