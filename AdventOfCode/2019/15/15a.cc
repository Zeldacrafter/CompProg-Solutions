#include <bits/stdc++.h>
#include "../IntCode.hpp"
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
typedef long long ll;
typedef pair<int, int> ii;

#define GRID_SIZE 50
#define INF 10000

#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4

int dx[] = {-100000, 0, 0, -1, 1};
int dy[] = {-100000, -1, 1, 0, 0};
int opp[] = {-100000, 2, 1, 4, 3};

#define WALL 0
#define EMPTY 1
#define FOUND 2
#define UNKNOWN -1

queue<int> findPath(ii start, ii goal, int map[GRID_SIZE][GRID_SIZE]) {
    // BFS
    queue<pair<ii, queue<int>>> q;
    set<ii> seen;

    q.emplace(start, queue<int>());
    seen.insert(start);

    while(!q.empty()) {
        ii coord = q.front().first;
        queue<int> moves = q.front().second;
        q.pop();

        if(coord == goal)
            return moves;

        FOR(d, 1, 5) {
            ii newCoord = ii(coord.first + dx[d], coord.second + dy[d]);
            
            int mapEntry = map[newCoord.first][newCoord.second];
            if(mapEntry == UNKNOWN || mapEntry == WALL)
                continue;

            if(seen.find(newCoord) != seen.end())
                continue;

            queue<int> newMoves(moves);
            newMoves.push(d);

            q.emplace(newCoord, newMoves);
            seen.insert(newCoord);
        }
    }

    printf("Did not find path from (%d, %d) to (%d, %d).\n", 
            start.first, start.second, goal.first, goal.second);
    assert(false);
}

void drawGrid(int minX, int maxX, int minY, int maxY, int map[GRID_SIZE][GRID_SIZE]) {
    char ch[] = {'#', ' ', 'X'};
    FOR(x, minX, maxX + 1) {
        FOR(y, minY, maxY + 1)
            if(map[x][y] == UNKNOWN)
                printf(".");
            else
                printf("%c", ch[map[x][y]]);
        printf("\n");
    }
}

struct mv {
    int dir; // Direction that we need to move in to check a new square.
    int x;
    int y;
};

int main() {

    ll opcode;
    vector<ll> mem;
    for(int c = scanf(" %lld", &opcode); c != EOF; c = scanf(" ,%lld", &opcode))
        mem.push_back(opcode);

    int map[GRID_SIZE][GRID_SIZE];
    memset(map, UNKNOWN, sizeof(map[0][0]) * GRID_SIZE * GRID_SIZE);

    int distanceToStart[GRID_SIZE][GRID_SIZE];
    memset(distanceToStart, INF, sizeof(distanceToStart[0][0]) * GRID_SIZE * GRID_SIZE);

    int currX = GRID_SIZE / 2;
    int currY = GRID_SIZE / 2;
    distanceToStart[currX][currY] = 0;
    map[currX][currY] = EMPTY;

    // BFS to slowly explore the map and count the distances at the same time.
    queue<mv> toCheck;
    FOR(d, 1, 5)
        toCheck.push({d, currX, currY});

    bool processOutput = true;
    IntCodeInterpreter vm(
        mem,
        [&processOutput, &toCheck, &currX, &currY, &map]() {
            static queue<int> q;

            if(q.empty()) {
                if(toCheck.empty())
                    return 100; // Crash the vm with an invalid instruction. We are done.

                mv next = toCheck.front();
                if(next.x != currX || next.y != currY) {
                    processOutput = false;
                    // Move to wanted position.
                    q = findPath(ii(currX, currY), ii(next.x, next.y), map);
                    currX = next.x;
                    currY = next.y;
                } else {
                    processOutput = true;
                    // We are at the wanted position.
                    // Move to the next square we want to discover now.
                    q.push(next.dir);
                }
            }

            int res = q.front();
            q.pop();
            return res;
        },
        [&processOutput, &toCheck, &currX, &currY, &distanceToStart, &map](ll outp) {
            if(!processOutput)
                return;
            
            int lastDir = toCheck.front().dir;
            toCheck.pop();

            int nextX = currX + dx[lastDir];
            int nextY = currY + dy[lastDir];

            map[nextX][nextY] = outp;
            if(outp == EMPTY || outp == FOUND) {
                // We moved
                distanceToStart[nextX][nextY] = 1 + distanceToStart[currX][currY];
                currX = nextX;
                currY = nextY;

                // Add new undiscovered neighbours to the queue
                FOR(d, 1, 5)
                    if(map[currX + dx[d]][currY + dy[d]] == UNKNOWN)
                        toCheck.push({d, currX, currY});
            }

            if(outp == FOUND)
                printf("%d\n", distanceToStart[currX][currY]);
        },
        false);

    vm.run();

    drawGrid(0, GRID_SIZE - 1, 0, GRID_SIZE - 1, map);

    return 0;
}
