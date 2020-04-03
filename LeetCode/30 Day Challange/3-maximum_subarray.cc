#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums[0], sum = 0;
        for(int n : nums) {
            sum += n;
            m = max(m, sum);
            if(sum < 0) sum = 0;
        }
        return m;
    }
};
