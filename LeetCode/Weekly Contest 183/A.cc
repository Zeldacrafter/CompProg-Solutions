class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sum2 = 0;
        vector<int> res;
        for(int i = 0; i < nums.size() && sum2 <= sum; ++i) {
            sum2 += nums[i];
            sum -= nums[i];
            res.push_back(nums[i]);
        } 
        return res;
    }
};
