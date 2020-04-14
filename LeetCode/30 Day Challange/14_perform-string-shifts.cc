class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int r = 0;
        for(vector<int> v : shift) {
            r += (v[0] ? 1 : -1)*v[1];
        }
        while(r < 0)
            r += s.size();
        r %= s.size();
        string res;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[(i - r + s.size()) % s.size()];
            res.push_back(c);
        } 
        return res;
    }
};
