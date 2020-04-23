class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(!n) return 0;
        
        int res = 0;
        for(int bit = 31 - __builtin_clz(n); ~bit && ((1 << bit) & m) == ((1 << bit) & n); --bit)
            res |= (1 << bit) & m;            
        return res;
    }
};
