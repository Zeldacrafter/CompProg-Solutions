class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        int p1 = S.size() - 1, p2 = T.size() - 1;
        while (~p1 || ~p2) {
            for (int b = 0; p1 >= 0; --p1) {
                if (S[p1] == '#')
                    ++b;
                else if (b)
                    --b;
                else
                    break;
            }
            for (int b = 0; ~p2; --p2) {
                if (T[p2] == '#')
                    ++b;
                else if (b)
                    --b;
                else
                    break;
            }
            if ((p1 >= 0 ? S[p1] : '*') != (p2 >= 0 ? T[p2] : '*'))
                return false;
            p1 = max(-1, p1 - 1);
            p2 = max(-1, p2 - 1);
        }
        return p1 == -1 && p2 == -1;
    }
};
