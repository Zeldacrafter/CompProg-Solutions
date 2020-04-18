class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        const int MAX = numic_limits<int>::max();
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m));
        
        dist[0][0] = grid[0][0];
        for(int r = 0; r < n; ++r)
            for(int c = !r; c < m; ++c)
                dist[r][c] = grid[r][c] + min(r ? dist[r - 1][c] : MAX,
                                              c ? dist[r][c - 1] : MAX);
        return dist[n - 1][m - 1];
    }
};
