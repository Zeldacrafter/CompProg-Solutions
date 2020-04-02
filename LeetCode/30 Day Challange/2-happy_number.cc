#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n != 1) {
            s.insert(n);
            int sum = 0;
            while(n) {
                int k = n % 10;
                sum += k*k;
                n /= 10;
            }
            n = sum;
            if(s.find(n) != s.end())
                return false;
        }
        return true;
    }
};
