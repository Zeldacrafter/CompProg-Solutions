class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> pref(nums.size() + 1);
        unordered_map<int, int> m;
        m[0] = 0;
        int best = 0;
        for(int i = 1; i < nums.size() + 1; ++i) {
            pref[i] = (nums[i - 1] ? 1 : -1) + pref[i - 1];
            if(m.count(pref[i]))
                best = max(best, i - m[pref[i]]);
            else
                m[pref[i]] = i;
        }
        return best;
    }
};
