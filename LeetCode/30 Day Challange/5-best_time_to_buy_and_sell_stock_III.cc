class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int res = -prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] < prices[i - 1]) {
                res += prices[i - 1];
                res -= prices[i];
            }
        }
        return res + prices[prices.size() - 1];
    }
};
