class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int m = 1, sum = 0;
        for(int n : nums) {
            sum += n;
            m = min(m, sum);
        }
        return m < 0 ? -m + 1 : m;
    }
};
