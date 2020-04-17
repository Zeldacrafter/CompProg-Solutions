#include <bits/stdc++.h>

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size() || !grid[0].size())
            return 0;
        
        vector<vector<int>> seen(grid.size(), vector<int>(grid[0].size(), false));
        
        int cnt = 0;
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[r].size(); ++c) {
                if(seen[r][c] || grid[r][c] == '0')
                    continue;
                cnt++;
                queue<pair<int, int>> q;
                q.emplace(r, c);
                seen[r][c] = true;
                while(!q.empty()) {
                    int currR = q.front().first;
                    int currC = q.front().second;
                    q.pop();
                    for(int i = 0; i < 4; ++i) {
                        int rr = currR + dx[i];
                        int cc = currC + dy[i];
                        if(rr < 0 || rr >= grid.size() || 
                           cc < 0 || cc >= grid[rr].size() || 
                           seen[rr][cc] || grid[rr][cc] == '0')
                            continue;
                        q.emplace(rr, cc);
                        seen[rr][cc] = true;
                    }
                }
            }
        }
        return cnt;
    }
};
