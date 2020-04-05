class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        char last;
        if(a <= b && a <= c)
            last = 'a';
        else if(b <= a && b <= c)
            last = 'b';
        else
            last = 'c';
    
        while(a > 0 || b > 0 || c > 0) {
            if(last == 'a') {
                if(!b && !c)
                    break;
                if(b > c) {
                    if(b == max({a, b, c}) && b > 1) {
                        b -= 2;
                        s += "bb";
                    } else {
                        b--;
                        s += "b";
                    }
                    last = 'b';
                } else {
                    if(c == max({a, b, c}) && c > 1) {
                        c -= 2;
                        s += "cc";
                    } else {
                        c--;
                        s += "c";
                    }
                    last = 'c';
                }
            } else if(last == 'b') {
                if(!a && !c)
                    break;
                if(a > c) {
                    if(a == max({a, b, c}) && a > 1) {
                        a -= 2;
                        s += "aa";
                    } else {
                        a--;
                        s += "a";
                    }
                    last = 'a';
                } else {
                    if(c == max({a, b, c}) && c > 1) {
                        c -= 2;
                        s += "cc";
                    } else {
                        c--;
                        s += "c";
                    }
                    last = 'c';
                }
            } else if(last == 'c') {
                if(!a && !b)
                    break;
                if(b > a) {
                    if(b == max({a, b, c}) && b > 1) {
                        b -= 2;
                        s += "bb";
                    } else {
                        b--;
                        s += "b";
                    }
                    last = 'b';
                } else {
                    if(a == max({a, b, c}) && a > 1) {
                        a -= 2;
                        s += "aa";
                    } else {
                        a--;
                        s += "a";
                    }
                    last = 'a';
                }
            }
        }
        return s;
    }
};
