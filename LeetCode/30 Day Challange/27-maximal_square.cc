class Solution {
    
    bool in(int r, int c, vector<vector<int>>& m) {
        return r >= 0 && c >= 0 && r < m.size() && c < m[0].size();
    }
    
    bool ok(int r, int c, int size, vector<vector<int>>& dp) {
        return size*size == 
              dp[r][c]
            + (in(r - size, c - size, dp) ? dp[r - size][c - size] : 0)
            - (in(r - size, c       , dp) ? dp[r - size][c]        : 0)
            - (in(r           , c - size, dp) ? dp[r][c - size]        : 0);
    }
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size())
            return 0;
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        
        dp[0][0] = matrix[0][0] - '0';
        for(int r = 1; r < dp.size(); ++r)
            dp[r][0] = dp[r - 1][0] + matrix[r][0] - '0';
        for(int c = 1; c < dp[0].size(); ++c)
            dp[0][c] = dp[0][c - 1] + matrix[0][c] - '0';
        
        for(int r = 1; r < dp.size(); ++r)
            for(int c = 1; c < dp[0].size(); ++c)
                dp[r][c] = (matrix[r][c] == '1') + dp[r - 1][c] + dp[r][c - 1] - dp[r - 1][c - 1];
        
        int res = 0;
        for(int r = 0; r < dp.size(); ++r) {
            for(int c = 0; c < dp[0].size(); ++c) {
                if(matrix[r][c] == '0')
                    continue;
                int sz = 0;
                while(r - sz >= 0 && r - sz >= 0 && ok(r, c, sz + 1, dp))
                    sz++;
                res = max(res, sz*sz);
            }
        }
        return res;
    }
};
