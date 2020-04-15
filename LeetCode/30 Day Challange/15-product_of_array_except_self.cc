class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> res(n);
        for(int i = n - 1; ~i; --i)
            res[i] = (i + 1 == n ? 1 : res[i + 1]) * nums[i];
        for(int i = 0, prod = 1; i < n; prod *= nums[i++])
            res[i] = prod * (i + 1 == n ? 1 : res[i + 1]);
        return res;
    }
};
