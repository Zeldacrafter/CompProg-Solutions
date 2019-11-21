import java.util.Scanner;

public class CarBuyer {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(true) {
            int loanDur = s.nextInt();
            if(loanDur < 0) break;
            double downPayment = s.nextDouble();
            double loan = s.nextDouble();
            double deprAmount = s.nextInt();

            double[] depr = new double[110];
            for (int i = 0; i < deprAmount; i++) {
                int month = s.nextInt();
                double d = s.nextDouble();
                for(int j = month; j < depr.length; j++)
                    depr[j] = d;
            }

            double monthlyPayment = 1.0*loan / loanDur;
            double carVal = loan + downPayment;
            carVal -= carVal * depr[0];

            int currMonth = 0;
            while(carVal < loan) {
                currMonth++;
                carVal -= carVal * depr[currMonth];
                loan -= monthlyPayment;
            }

            System.out.println(currMonth + " month" + (currMonth == 1 ? "" : "s"));
        }


        s.close();
    }
}
