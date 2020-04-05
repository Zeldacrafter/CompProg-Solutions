class Solution {
public:
    string stoneGameIII(vector<int>& v) {
        vector<int> a(v.size() + 5, 0), b(v.size() + 5, 0);
        
        for(int i = v.size() - 1; ~i; --i) {
            int next1 =                    v[i]                       - a[i + 1] + b[i + 1];
            int next2 = i + 1 < v.size() ? v[i] + v[i + 1]            - a[i + 2] + b[i + 2] : -1000000;
            int next3 = i + 2 < v.size() ? v[i] + v[i + 1] + v[i + 2] - a[i + 3] + b[i + 3] : -1000000;
            int m = max({next1, next2, next3});
            if(next1 == m) {
                a[i] = next1 + a[i + 1];
                b[i] = a[i + 1];
            } else if(next2 == m) {
                a[i] = next2 + a[i + 2];
                b[i] = a[i + 2];
            } else if(next3 == m) {
                a[i] = next3 + a[i + 3];
                b[i] = a[i + 3];
            }
        }
        
        if(a[0] > b[0])
            return "Alice";
        else if (a[0] < b[0])
            return "Bob";
        else
            return "Tie";
    }
};
