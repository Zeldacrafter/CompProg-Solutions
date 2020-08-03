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
map<ii, vector<pair<int, ii>> > adj;

#define END 1000
#define START -1000

ii start;
ii goal;

ii findPortal(char name[], int currX, int currY) {
    // This code is a judgement-free zone!

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
    // Looking at own discretion

    FOR(y, 0, sizeY) {
        FOR(x, 0, sizeX) {
            if(input[y][x] == '.') {
                FOR(d, 0, 4) {
                    int newX = x + dx[d];
                    int newY = y + dy[d];
                    char c = input[newY][newX];
                    if(c == '.') {
                        adj[ii(x, y)].push_back({0, ii(newX, newY)});
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
                            int layerChange = (x == 2 || x == sizeX - 3 || y == 2 || y == sizeY - 3)
                                ? -1 : 1;

                            assert(node.first != x || node.second != y);
                            adj[ii(x, y)].push_back({layerChange, node});
                        }
                    }
                }
            }
        }
    }
}

int bfs(ii from, ii to) {

    // Dist - layer - coord
    queue<pair<int, pair<int, ii>>> q;
    q.push( {0, {0, from}} );

    set<pair<int, ii>> seen;
    seen.insert({0, from});

    while(!q.empty()) {
 
        pair<int, pair<int, ii>> curr = q.front();
        q.pop();
        int dist = curr.first;
        int layer = curr.second.first;
        ii pos = curr.second.second;

        if(pos == to && layer == 0)
            return dist;

        for(pair<int, ii> v : adj[pos]) {

            int newLayer = layer + v.first;
            pair<int, ii> next = {newLayer, v.second};

            if(newLayer < 0 || seen.find(next) != seen.end())
                continue;

            q.push({dist + 1, next});
            seen.insert(next);
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