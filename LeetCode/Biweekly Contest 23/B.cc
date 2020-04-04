class Solution {
public:
    bool canConstruct(string s, int k) {
        sort(s.begin(), s.end());
        int one = 0;
        for(int i = 0; i < s.size(); ++i)
            if(i + 1 < s.size() && s[i] == s[i + 1])
                i++;
            else
                one++;
        return one <= k && s.size() >= k;
    }
};

