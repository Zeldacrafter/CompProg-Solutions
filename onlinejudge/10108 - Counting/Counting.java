import java.math.BigInteger;
import java.util.Scanner;

public class Counting {

    static BigInteger[] res = new BigInteger[1001];
    static int maxIndex = 0;
    static final BigInteger two = new BigInteger("2");

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            int n = s.nextInt();

            res[1] = new BigInteger("2");
            res[2] = new BigInteger("5");
            res[3] = new BigInteger("13");
            maxIndex = 3;

            while(n > maxIndex) {
                res[maxIndex+1] =
                        res[maxIndex].multiply(two)
                        .add(res[maxIndex-1])
                        .add(res[maxIndex-2]);
                maxIndex++;
            }
            System.out.println(res[n]);
        }

        s.close();
    }
}
