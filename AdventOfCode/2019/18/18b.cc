#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int keyCount = 0;
char maze[100][100];
int dist[300][300];
map<char, vector<char>> adj;

bool visited[100][100];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void buildGraphBFS(ii from) {
    // Build adj-list and distances

    char fromChar = maze[from.second][from.first];
    visited[from.second][from.first] = true;
    
    // Dist-coord-pair
    queue<pair<int, ii>> q;
    q.push({0, from});

    while(!q.empty()) {
        pair<int, ii> curr = q.front();
        q.pop();
        int x = curr.second.first;
        int y = curr.second.second;
        int currDist = curr.first;

        FOR(d, 0, 4) {
            int newX = x + dx[d];
            int newY = y + dy[d];
            char newC = maze[newY][newX];

            if(visited[newY][newX] || newC == '#')
                continue;

            if(newC == '.') {
                visited[newY][newX] = true,
                q.push({currDist + 1, {newX, newY}});
                continue;
            }

            assert(islower(newC) || isupper(newC));

            adj[newC].push_back(fromChar);
            adj[fromChar].push_back(newC);
            
            dist[newC][fromChar] = currDist + 1;
            dist[fromChar][newC] = currDist + 1;

            buildGraphBFS({newX, newY});
        }
    }

}

struct state {
    int dist;
    char pos[4];
    int keys;
};

struct state_compare {
    bool operator() (const state& s1, const state& s2) const {
        FOR(i, 0, 4)
            if(s1.pos[i] != s2.pos[i]) 
                return s1.pos[i] < s2.pos[i];
        return s1.keys < s2.keys;
    }
};

int dijkstra() {
    //FIXME: 
}

int main() {

    memset(maze, 0, sizeof(maze[0][0]) * 100 * 100);
    memset(dist, 10000, sizeof(dist[0][0]) * 300 * 300);
    memset(visited, false, sizeof(visited[0][0]) * 100 * 100);

    int sizeY = 0;
    for(; scanf("%s", maze[sizeY]) != EOF; ++sizeY);
    int sizeX = 0;
    for(; maze[0][sizeX] != 0; ++sizeX);

    // Find start
    vector<ii> starts;
    FOR(y, 0, sizeY) {
        FOR(x, 0, sizeX) {
            if(maze[y][x] == '@') {
                // All starts need a different symbol
                // since we need to map every start to a different
                // adj-list.
                maze[y][x] = '@' - starts.size();
                starts.push_back({x, y});
            } else if(islower(maze[y][x])) {
                keyCount++;
            }
        }
    }

    // Get complete graph
    for(ii start : starts)
        buildGraphBFS(start);
    
    for(auto p : adj) {
        printf("%c: ", p.first);
        for(char c : p.second)
            printf("%c ", c);
        printf("\n");
    }

    dijkstra(); //TODO:
    return 0;
}