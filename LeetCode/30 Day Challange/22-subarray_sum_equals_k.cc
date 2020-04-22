class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0]++;
        int sum = 0, res = 0;
        for(int i : nums) {
            sum += i;
            res += m[sum - k];
            m[sum]++;
        }
        return res;
    }
};
