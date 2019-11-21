import java.util.Scanner;

public class BlocksProblem {

    static class Block {
        int i;
        Block next = null;
        Block prev = null;
        public Block(int _i) {i = _i;}
    }

    static Block[] blocks;

    static boolean inSameStack(Block A, Block B) {
        while(B.prev != null) B = B.prev;
        while(A.prev != null) A = A.prev;
        return A.i == B.i;
    }

    static void resetAbove(Block A) {
        while (A.next != null) {
            Block tmp = A.next;
            A.next.prev = null;
            A.next = null;
            A = tmp;
        }
    }

    static void moveOnto(Block A, Block B) {
        resetAbove(B);
        moveOver(A, B);
    }

    static void moveOver(Block A, Block B) {
        resetAbove(A);
        pileOver(A, B);
    }

    static void pileOnto(Block A, Block B) {
        resetAbove(B);
        pileOver(A, B);
    }

    static void pileOver(Block A, Block B) {
        if(A.prev != null) A.prev.next = null;

        while(B.next != null) B = B.next;

        B.next = A;
        A.prev = B;
        if(A.equals(B.prev)) B.prev = null;
        if(B.equals(A.next)) A.next = null;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        blocks = new Block[n];
        for(int i = 0; i < n; i++)
            blocks[i] = new Block(i);

        while(true) {
            String what = s.next();
            if("quit".equals(what)) break;
            Block A = blocks[s.nextInt()];
            String where = s.next();
            Block B = blocks[s.nextInt()];

            if(inSameStack(A, B)) continue;

            if("move".equals(what)) {
                if("onto".equals(where)) moveOnto(A,B);
                else moveOver(A,B);
            }else {
                if("onto".equals(where)) pileOnto(A,B);
                else pileOver(A,B);
            }

        }

        for(int i = 0; i < blocks.length; i++) {
            System.out.print(i + ":");
            if(blocks[i].prev == null) {
                Block curr = blocks[i];
                while(curr != null) {
                    System.out.print(" " + curr.i);
                    curr = curr.next;
                }
            }
            System.out.println();
        }

        s.close();
    }
}
