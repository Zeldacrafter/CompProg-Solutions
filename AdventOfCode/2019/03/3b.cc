#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define INF 100000
#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'

struct operation {
    char dir;
    int dist;
};

vector<operation> parseNextLine() {
    char line[10000];
    scanf(" %10000[^\n]", line);

    stringstream ss(line);

    vector<operation> res;

    string tmp;
    while(getline(ss, tmp, ','))
        res.push_back(
            { tmp[0], stoi(string(tmp, 1, tmp.length())) }
        );

    return res;
}

void applyOnWire(vector<operation> &ops, function<void(int, int)> f) {
    // Apply a function on every coordinate
    // of the wire.

    int posX = 0;
    int posY = 0;
    for(operation op : ops) {
        // Notice that (0, 0) is not part of the wire as we preincrement the coordinates.
        switch(op.dir) {
            case UP:
                for(int i = 0; i < op.dist; ++i)
                    f(posX, --posY);
                break;
            case RIGHT:
                for(int i = 0; i < op.dist; ++i) 
                    f(++posX, posY);
                break;
            case LEFT:
                for(int i = 0; i < op.dist; ++i)
                    f(--posX, posY);
                break;
            case DOWN:
                for(int i = 0; i < op.dist; ++i)
                    f(posX, ++posY);
                break;
            default:
                assert(false); // Not possible
        }
    }
}

int main() {

    vector<operation> ops = parseNextLine();
    // Mapping of coordinates to wire length
    map<pair<int, int>, int> wire;
    int len = 0;
    applyOnWire(ops, [&wire, &len](int x, int y) {
            wire[ii(x, y)] = ++len;
        });

    ops = parseNextLine();
    // Finding intersection with lowest wire length
    len = 0;
    int best = INF;
    applyOnWire(ops, [&wire, &len, &best](int x, int y) {
            ++len;
            auto it = wire.find(ii(x, y));
            if(it != wire.end())
                best = min(best, len + it->second);
        });

    printf("%d\n", best);
    
}