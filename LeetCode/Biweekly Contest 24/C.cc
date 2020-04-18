class Solution {
public:
    vector<string> str;
    int lim;
    void getStrs(string &s, int k) {

        if(k == lim) {
            bool ok = true;
            for(int i = 0; i < s.size() - 1; ++i) {
                if(s[i] == s[i + 1]) {
                    ok = false;
                    break;
                }
            }

            if(ok)
                str.push_back(s);
            return;
        }
        
        for(int i = 1; i < 4; ++i) {
            if(s[k] == 'a')
                s[k] = 'b';
            else if(s[k] == 'b')
                s[k] = 'c';
            else
                s[k] = 'a';
            getStrs(s, k + 1);
        }
    
    }
    
    string getHappyString(int n, int k) {
        lim = n;
        string s(n, 'a');
        getStrs(s, 0);
        
        if(str.size() < k)
            return "";
        
        sort(str.begin(), str.end());
        return str[k - 1];
    }
};
