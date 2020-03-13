import java.util.Arrays;
import java.util.Scanner;

public class CostCutting {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        for(int i = 0; i < n; i++) {
            int[] arr = new int[3];
            for(int j = 0; j < 3; j++) arr[j] = s.nextInt();

            Arrays.sort(arr);

            System.out.println("Case " + (i+1) + ": " + arr[1]);
        }

        s.close();
    }

}
