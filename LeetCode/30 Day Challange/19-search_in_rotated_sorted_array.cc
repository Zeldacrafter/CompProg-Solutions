class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        
        int n = nums.size();
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }
        
        if(nums[0] > target)
            r = n;
        else
            l = 0;

        auto find = lower_bound(nums.begin() + l, nums.begin() + r, target);
        
        return find == nums.begin() + r || *find != target ? -1 : distance(nums.begin(), find);
    }
};
