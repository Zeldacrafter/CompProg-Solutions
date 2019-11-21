import java.util.*;

public class CounterfeitDollar {

    static Set<Character> fillList() {
        Set<Character> set = new HashSet<>();
        for (char i = 'A'; i <= 'L'; i++) {
            set.add(i);
        }
        return set;
    }

    static List<Character> asList(char[] arr) {
        ArrayList<Character> res = new ArrayList<>();
        for(char c : arr) res.add(c);
        return res;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int cases = s.nextInt();
        for (int i = 0; i < cases; i++) {
            Set<Character> lighter = fillList();
            Set<Character> heavier = fillList();

            for(int j = 0; j < 3; j++) {
                List<Character> left = asList(s.next("[^ ]+").toCharArray());
                List<Character> right = asList(s.next("[^ ]+").toCharArray());
                String op = s.nextLine();
                switch(op) {
                    case " even":
                        lighter.removeAll(left);
                        lighter.removeAll(right);
                        heavier.removeAll(left);
                        heavier.removeAll(right);
                        break;
                    case " up":
                        lighter.retainAll(right);
                        heavier.retainAll(left);
                        break;
                    case " down":
                        lighter.retainAll(left);
                        heavier.retainAll(right);
                        break;
                }

            }
            if(lighter.size() == 1) {
                System.out.println(lighter.iterator().next() + " is the counterfeit coin and it is light.");
            } else {
                System.out.println(heavier.iterator().next() + " is the counterfeit coin and it is heavy.");
            }
        }

        s.close();
    }
}
