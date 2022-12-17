#include "../utils.cc"

#define LINE 0
#define PLUS 1
#define L 2
#define I 3
#define SQUARE 4

typedef pair<ll, ll> pll;

const vector<pll>
          block_line = { mp(0, 0), mp(1, 0), mp(2, 0), mp(3, 0) },
          block_plus = { mp(1, 0), mp(0,-1), mp(1,-1), mp(2,-1), mp(1,-2) },
          block_l = { mp(2, 0), mp(2,-1), mp(0,-2), mp(1,-2), mp(2,-2) },
          block_i = { mp(0, 0), mp(0,-1), mp(0,-2), mp(0,-3) },
          block_square = { mp(0, 0), mp(0, -1), mp(1, -1), mp(1, 0) };

const vector<vector<pll>>
    blocks = {block_line, block_plus, block_l, block_i, block_square};

ll maxY = 0;
set<pll> seen;

pll startCoord(int type) {
    switch(type) {
        case LINE:   return mp(2, maxY + 4);
        case PLUS:   return mp(2, maxY + 6);
        case L:      return mp(2, maxY + 6);
        case I:      return mp(2, maxY + 7);
        case SQUARE: return mp(2, maxY + 5);
        default: assert(false);
    }
    return {-1 , -1};
}

bool collides(int type, pll coord) {
    for(pll c : blocks[type]) {
        auto [x, y] = coord + c;
        if(x < 0 || x >= 7 || seen.count(mp(x, y))) return true;
    }
    return false;
}

pair<bool, pll> move(int type, pll coord, pll dC) {
    if(collides(type, coord + dC))
        return mp(false, coord);
    else
        return mp(true, coord + dC);
}

void solve() {
    F0R(i, 7) seen.emplace(i, 0);
    const ll GOAL = 2022;

    string dirs = getInp()[0];

    for(ll amt = 0, dirI = 0; amt < GOAL; ++amt) {
        ll type = amt % SZ(blocks);
        pll coord = startCoord(type);

        while(true) {
            char c = dirs[dirI];
            if(c == '>') coord = move(type, coord, mp(1, 0)).se;
            else coord = move(type, coord, mp(-1, 0)).se;
            dirI = (dirI + 1) % SZ(dirs);

            auto [ok, newCoord] = move(type, coord, mp(0, -1));
            if(ok) coord = newCoord;
            else {
                // Place block
                for(pll dCoord : blocks[type]) {
                    ckmax(maxY, (coord + dCoord).se);
                    seen.insert(coord + dCoord);
                }
                break;
            }
        }
    }

    cout << maxY << endl;
}

