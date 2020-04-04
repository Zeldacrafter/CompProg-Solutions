#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int l = 0, z = 0; l < nums.size(); ++l) {
            while(z < nums.size() && nums[z])
                ++z;
            if(z < l && nums[l])
                swap(nums[l], nums[z]);
        }
    }
};
