#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int sizeY, sizeX;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char input[200][200];
map<ii, vii> adj;

#define END 1000
#define START -1000

ii start;
ii goal;

ii findPortal(char name[], int currX, int currY) {

    if(name[0] == 'A' && name[1] == 'A')
        return ii(START, START);
    if(name[0] == 'Z' && name[1] == 'Z')
        return ii(END, END);

    FOR(y, 0, sizeY) {
        FOR(x, 0, sizeX) {
            if(input[y][x] == name[0] && (x != currX || y != currY)) {
                if(x + 2 < sizeX && input[y][x + 1] == name[1] && input[y][x + 2] == '.')
                    return ii(x + 2, y);
                if(x + 1 < sizeX && input[y][x + 1] == name[1] && input[y][x - 1] == '.')
                    return ii(x - 1, y);
                if(y + 2 < sizeY && input[y + 1][x] == name[1] && input[y + 2][x] == '.')
                    return ii(x, y + 2);
                if(y + 1 < sizeY && input[y + 1][x] == name[1] && input[y - 1][x] == '.')
                    return ii(x, y - 1);
            }
        }
    }
    printf("Did not find!\n"); exit(0);
    return ii(-1,-1);
}

void getAdj() {
    // Looking at own risk

    FOR(y, 0, sizeY) {
        FOR(x, 0, sizeX) {
            if(input[y][x] == '.') {
                FOR(d, 0, 4) {
                    int newX = x + dx[d];
                    int newY = y + dy[d];
                    char c = input[newY][newX];
                    if(c == '.') {
                        adj[ii(x, y)].push_back(ii(newX, newY));
                    } else if(c <= 'Z' && c >= 'A') {
                        char portal[2];
                        ii node;
                        if(dx[d] == 1) {
                            portal[0] = input[y][x + 1];
                            portal[1] = input[y][x + 2];
                            node = findPortal(portal, x + 1, y);
                        } else if (dx[d] == -1) {
                            portal[0] = input[y][x - 2];
                            portal[1] = input[y][x - 1];
                            node = findPortal(portal, x - 2, y);
                        } else if (dy[d] == 1) {
                            portal[0] = input[y + 1][x];
                            portal[1] = input[y + 2][x];
                            node = findPortal(portal, x, y + 1);
                        } else {
                            assert(dy[d] == -1);
                            portal[0] = input[y - 2][x];
                            portal[1] = input[y - 1][x];
                            node = findPortal(portal, x, y - 2);
                        }

                        if(node.first == START && node.second == START)
                            start = ii(x, y);
                        else if(node.first == END && node.second == END)
                            goal = ii(x, y);
                        else {
                            assert(node.first != x || node.second != y);
                            adj[ii(x, y)].push_back(node);
                        }
                    }
                }
            }
        }
    }
}

int bfs(ii from, ii to) {

    queue<pair<int, ii>> q;
    q.push( {0, from} );

    set<ii> seen;
    seen.insert(from);

    while(!q.empty()) {
        pair<int, ii> curr = q.front();
        q.pop();
        int dist = curr.first;
        ii pos = curr.second;
        printf("Testing (%d, %d) with %d adj\n", pos.first, pos.second, adj[pos].size());

        if(pos == to)
            return dist;

        for(ii v : adj[pos]) {
            if(seen.find(v) != seen.end())
                continue;
            
            q.push({dist + 1, v});
            seen.insert(v);
        }
    }

    printf("Not found!");
    exit(0);

    return -1;
}

int main() {

    sizeY = 0;
    for(char c;scanf("%200[^\n]", input[sizeY]) != EOF; ++sizeY) {
        scanf("%c", &c);
        assert(c == '\n');
    }
    sizeX = strlen(input[0]);

    getAdj();

    printf("Distance: %d\n", bfs(start, goal));

    return 0;
}