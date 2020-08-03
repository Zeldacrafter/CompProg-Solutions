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

    // Build first wire as set.
    vector<operation> ops = parseNextLine();
    set<ii> wire;
    applyOnWire(ops, [&wire](int x, int y) { wire.insert(ii(x, y)); });
    
    // Get shortest distance to origin from pts where first & second wires cross.
    ops = parseNextLine();
    int best = INF;
    applyOnWire(ops, [&wire, &best](int x, int y) {
                    if(wire.find(ii(x, y)) != wire.end())
                        best = min(best, abs(x) + abs(y));
                });

    printf("%d\n", best);
}