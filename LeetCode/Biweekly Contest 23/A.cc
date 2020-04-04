class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> cnt(92);
        for(int i = 1; i <= n; ++i) {
            int s = 0, j = i;
            while(j) {
                s += j % 10;
                j /= 10;
            }
            cnt[s]++;
        }
        
        int m = 0;
        int res = 0;
        for(int i = 0; i < 92; ++i) {
            if(m < cnt[i]) {
                res = 1;
                m = cnt[i];
            } else if(cnt[i] == m)
                res++;
        }
        return res;
    }
};
