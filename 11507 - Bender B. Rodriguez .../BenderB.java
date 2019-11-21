import java.util.Scanner;

public class BenderB {

    enum Dir {
        px, mx, py, my, pz, mz
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(true) {
            int l = s.nextInt();
            if(l == 0) break;
            s.nextLine();

            Dir dir = Dir.px;
            String[] actions = s.nextLine().split(" ");
            for (String a : actions) {
                switch (a) {
                    case "+y":
                        switch(dir) {
                            case px:
                                dir = Dir.py;
                                break;
                            case mx:
                                dir = Dir.my;
                                break;
                            case py:
                                dir = Dir.mx;
                                break;
                            case my:
                                dir = Dir.px;
                        }
                        break;
                    case "-y":
                        switch(dir) {
                            case px:
                                dir = Dir.my;
                                break;
                            case mx:
                                dir = Dir.py;
                                break;
                            case py:
                                dir = Dir.px;
                                break;
                            case my:
                                dir = Dir.mx;
                        }
                        break;
                    case "+z":
                        switch(dir) {
                            case px:
                                dir = Dir.pz;
                                break;
                            case mx:
                                dir = Dir.mz;
                                break;
                            case pz:
                                dir = Dir.mx;
                                break;
                            case mz:
                                dir = Dir.px;
                        }
                        break;
                    case "-z":
                        switch(dir) {
                            case px:
                                dir = Dir.mz;
                                break;
                            case mx:
                                dir = Dir.pz;
                                break;
                            case pz:
                                dir = Dir.px;
                                break;
                            case mz:
                                dir = Dir.mx;
                        }
                        break;
                }

            }

            switch (dir) {
                case px:
                    System.out.println("+x");
                    break;
                case mx:
                    System.out.println("-x");
                    break;
                case py:
                    System.out.println("+y");
                    break;
                case my:
                    System.out.println("-y");
                    break;
                case pz:
                    System.out.println("+z");
                    break;
                case mz:
                    System.out.println("-z");
                    break;
            }
        }

        s.close();
    }
}
