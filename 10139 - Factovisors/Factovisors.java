import java.util.Scanner;

public class Factovisors {

    static final int MAX_PRIME = 50000;
    static int[] primes = new int[5500];
    static int index = 0;

    static void getPrimes() {
        int[] isPrime = new int[MAX_PRIME];
        for(int i = 2; i < MAX_PRIME; i++) {
            if(isPrime[i] == 0) {
                primes[index++] = i;
                for(int j = 2*i; j < MAX_PRIME; j+=i) {
                    isPrime[j] = 1;
                }
            }
        }
    }

    static boolean isFactorOfFac(int n, int m) {
        for(int i = 0; i < index && primes[i]*primes[i] <= m; i++) {
            if(m % primes[i] == 0) {
                int count = 0;
                while(m % primes[i] == 0) {
                    count++;
                    m /= primes[i];
                }
                int temp = primes[i];
                int count2 = 0;
                while(temp <= n) {
                    count2 += n/temp;
                    temp *= primes[i];
                }
                if (count2 < count) return false;
            }
        }
        return m == 1 || n >= m;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        getPrimes();

        while(s.hasNext()) {
            int n = s.nextInt();
            int m = s.nextInt();

            if(isFactorOfFac(n, m))
                System.out.println(m + " divides " + n + "!");
            else
                System.out.println(m + " does not divide " + n + "!");
        }

        s.close();
    }
}