class Solution {
public:
    bool canJump(vector<int>& nums) {
        int r = 0;
        for(int i = 0; i <= r && i < nums.size(); ++i)
            r = max(i + nums[i], r);
        return r >= nums.size() - 1;
    }
};
