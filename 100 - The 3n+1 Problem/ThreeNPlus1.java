import java.util.Scanner;

public class ThreeNPlus1 {

    static long[] vals = new long[1000001];
    static long[] segTree = new long[4* vals.length];

    static int left(int p) {return p << 1;}
    static int right(int p) {return (p << 1) + 1;}

    static long build(int vert, int left, int right) {
        if (left == right) return segTree[vert] = vals[left];
        else {
            int mid = (left+right)/2;

            long valLeft = build(left(vert), left, mid);
            long valRight = build(right(vert), mid+1, right);

            return segTree[vert] = Math.max(valLeft, valRight);
        }
    }

    static long query(int vert, int left, int right, int i, int j) {
        if(i > right || j < left) return -1;
        if(i <= left && right <= j) return segTree[vert];

        int mid = (left + right) / 2;
        long valLeft = query(left(vert), left, mid, i, j);
        long valRight = query(right(vert), mid + 1, right, i, j);

        if(valLeft == -1) return valRight;
        if(valRight == -1) return valLeft;
        return Math.max(valLeft, valRight);
    }

    static long seq(long n) {
        int count = 1;
        while(n != 1) {
            if((n & 1) == 0) n >>= 1;
            else n = 3*n + 1;
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        for(int i = 1; i <= 1000000; i++)
            vals[i] = seq(i);

        build(1, 0, vals.length-1);

        while (s.hasNext()) {
            int i = s.nextInt();
            int j = s.nextInt();

            if(i <= j)
                System.out.println(i + " " + j + " " + query(1, 0, vals.length-1, i, j));
            else
                System.out.println(i + " " + j + " " + query(1, 0, vals.length-1, j, i));
        }

        s.close();
    }
}
