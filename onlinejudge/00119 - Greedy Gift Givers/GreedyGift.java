import java.util.HashMap;
import java.util.Scanner;

public class GreedyGift {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int caseNr = 0;
        while(s.hasNext()) {
            caseNr++;
            int n = s.nextInt();
            HashMap<String, Integer> bal = new HashMap<>();
            String[] names = new String[n];
            for (int i = 0; i < n; i++) {
                names[i] = s.next("[^ ]+");
                bal.put(names[i], 0);
            }

            for (int i = 0; i < n; i++) {
                String name = s.next("[^ ]+");
                int c = s.nextInt();
                int f = s.nextInt();
                if(f != 0) {
                    bal.put(name, bal.get(name) - c + c%f);
                    for (int j = 0; j < f; j++) {
                        String friend = s.next("[^ ]+");
                        bal.put(friend, bal.get(friend) + c/f);
                    }
                }

            }
            if(caseNr != 1) System.out.println();
            for (String name : names) {
                System.out.println(name + " " + bal.get(name));
            }
        }



        s.close();
    }
}
