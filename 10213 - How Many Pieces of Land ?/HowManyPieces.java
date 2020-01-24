import java.math.BigInteger;
import java.util.Scanner;

public class HowManyPieces {

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int tc = s.nextInt();

      BigInteger one = new BigInteger("1");
      BigInteger two = new BigInteger("2");
      BigInteger three = new BigInteger("3");
      BigInteger tw4 = new BigInteger("24");

    while (tc-- != 0) {
      BigInteger n = new BigInteger(s.nextInt() + "");

      BigInteger tmp = n.multiply(n.subtract(one));
      BigInteger nC4 = tmp.multiply(n.subtract(two))
                           .multiply(n.subtract(three))
                           .divide(tw4);
      BigInteger res = tmp.divide(two).add(nC4).add(one);

      System.out.println(res.toString());
    }
  }
}
