class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        long long res = 0, sum = 0;
        for(int i = s.size() - 1; ~i; --i) {
            if(sum + s[i] > 0) {
                sum += s[i];
                res += sum;
            }
        }
        return res;
    }
};
