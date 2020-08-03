#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))

typedef long long ll;
typedef pair<int, int> ii;

char maze[100][100];

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

struct pos {
    int x;
    int y;
    set<char> keys;
    int dist;
};

struct pos_compare {
    bool operator() (const pos& p1, const pos& p2) const {
        if(p1.x != p2.x) return p1.x < p2.x;
        if(p1.y != p2.y) return p1.y < p2.y;
        return p1.keys < p2.keys;
    }
};

void printPos(pos p) {
    printf("(%d, %d): %d\n\tKeys: ", p.x, p.y, p.dist);
    for(char key : p.keys)
        printf("%c ", key);
    printf("\n");
}

pos bfs(int startX, int startY, unsigned int keyCount) {
    pos start = {startX, startY, set<char>(), 0};

    queue<pos> q;
    q.push(start);
    set<pos, pos_compare> seen;
    seen.insert(start);

    while(!q.empty()) {

        pos curr = q.front();
        q.pop();

        if(seen.size() % 100000 == 0) {
            printf("%ld\n", seen.size());
        }

        if(curr.keys.size() == keyCount) {
            printf("%d\n", curr.dist);
            return curr;
        }

        FOR(d, 0, 4) {
            int nextX = curr.x + dx[d];
            int nextY = curr.y + dy[d];

            char c = maze[nextY][nextX];
            
            if(c == '#')
                continue;
            if(isupper(c) && curr.keys.find(tolower(c)) == curr.keys.end())
               continue;

            pos next;
            if(islower(c)) {
                set<char> nextKeys(curr.keys);
                nextKeys.insert(c);
                next = {nextX, nextY, nextKeys, curr.dist + 1};
            } else {
                next = {nextX, nextY, curr.keys, curr.dist + 1};
            }

            if(seen.find(next) != seen.end())
                continue;

            seen.insert(next);
            q.push(next);

        }
    }
    assert(false);
}

int main() {

    memset(maze, 0, sizeof(maze[0][0]) * 100 * 100);

    int sizeY = 0;
    for(; scanf("%s", maze[sizeY]) != EOF; ++sizeY);

    int sizeX = 0;
    for(; maze[0][sizeX] != 0; ++sizeX);

    int startX = -1;
    int startY = -1;
    unsigned int keyCount = 0;
    FOR(i, 0, sizeY) {
        FOR(j, 0, sizeX) {
            if(maze[i][j] == '@') {
                startX = j;
                startY = i;
            } else if(islower(maze[i][j])) {
                ++keyCount;
            }
        }
    }

    assert(startX != -1 && startY != -1);
    bfs(startX, startY, keyCount);

    return 0;
}