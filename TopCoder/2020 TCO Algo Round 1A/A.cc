#include <bits/stdc++.h>
using namespace std;
    
class AveragePrice {
    public:
    double nonDuplicatedAverage(vector<int> a) {
        set<int> s(a.begin(), a.end());
        int sum = 0;
        for(int i : s)
            sum += i;
        return (double)sum / s.size();
    }
};
