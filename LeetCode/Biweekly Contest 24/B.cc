class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(!k) return 0;
        vector<int> fibs;
        fibs.push_back(1);
        fibs.push_back(1);
        while(fibs[fibs.size() - 1] <= k)
            fibs.push_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);
        int cnt = 1;
        k -= fibs[fibs.size() - 2];
        while(k) {
            auto ind = upper_bound(fibs.begin(), fibs.end(), k);
            if(ind != fibs.begin())
                --ind;
            k -= *ind;
            cnt++;
        }
        return cnt;
    }
};
