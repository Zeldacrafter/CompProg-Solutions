class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        int r = s.size() - 1;
        while(s.size() > 1) {
            res++;
            int r = s.size() - 1;
            if(s[r] == '0') {
                s = s.substr(0, s.size() - 1);
            } else {
                while(r >= 0 && s[r] == '1') {
                    s[r] = '0';
                    r--;
                }
                if(r < 0)
                    s = '1' + s;
                else
                    s[r] = '1';
            }
        }
        return res;
    }
};
