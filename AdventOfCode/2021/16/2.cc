#include "../utils.cc"

ll toInt(const vector<bool>& bits) {
    ll res = 0;
    for(bool b : bits) res = res*2 + b;
    return res;
}

vector<bool> read(queue<bool>& bits, int n) {
    vector<bool> res;
    F0R(i, n) {
        res.pb(bits.front());
        bits.pop();
    }
    return res;
}

ll initVal(int id) {
    switch(id) {
        case 0: return 0;
        case 1: return 1;
        case 2: return numeric_limits<ll>::max();
        case 3: return numeric_limits<ll>::min();
    }
    return -1;
    assert(false);
}

ll eval(int id, ll val1, ll val2) {
    switch(id) {
        case 0: return val1 + val2;
        case 1: return val1 * val2;
        case 2: return min(val1, val2);
        case 3: return max(val1, val2);
        case 5: return val1 > val2;
        case 6: return val1 < val2;
        case 7: return val1 == val2;
    }
    assert(false);
    return -1;
}

pair<int, ll> decode(queue<bool>& bits) {
    int parsed = 0;
    
    int version = toInt(read(bits, 3)); parsed += 3;
    int id = toInt(read(bits, 3)); parsed += 3;

    if(id == 4) {
        vector<bool> content;
        while(true) {
            bool stopBit = read(bits, 1)[0];
            F0R(j, 4) content.pb(read(bits, 1)[0]);
            parsed += 5;
            if(!stopBit) break;
        }
        return mp(parsed, toInt(content));
    } else {
        bool lenId = read(bits, 1)[0]; parsed++;

        if(!lenId) {
            int len = toInt(read(bits, 15)); parsed += 15;

            if(id == 5 || id == 6 || id == 7) {
                auto [p1, val1] = decode(bits); len -= p1; parsed += p1;
                auto [p2, val2] = decode(bits); len -= p2; parsed += p2;
                assert(!len);
                return mp(parsed, eval(id, val1, val2));
            } else {
                ll res = initVal(id);
                while(len) {
                    auto [p, v] = decode(bits);
                    parsed += p; len -= p;
                    res = eval(id, res, v);
                }
                return mp(parsed, res);
            }
        } else {
            int subPacketCnt = toInt(read(bits, 11)); parsed += 11;

            if(id == 5 || id == 6 || id == 7) {
                assert(subPacketCnt == 2);
                auto [p1, val1] = decode(bits); parsed += p1;
                auto [p2, val2] = decode(bits); parsed += p2;
                return mp(parsed, eval(id, val1, val2));
            } else {
                ll res = initVal(id);
                F0R(_, subPacketCnt) {
                    auto [p, v] = decode(bits); parsed += p;
                    res = eval(id, res, v);
                }
                return mp(parsed, res);
            }
        }
        assert(false);
        return mp(parsed, -1);
    } 
}

void solve() {
    string s = getInp()[0];
    queue<bool> bits;
    for(char c : s) {
        if(isdigit(c)) c -= '0';
        else c -= 'A' - 10;
        F0R(i, 4) bits.emplace((c >> (3 - i)) & 1);
    }

    cout << decode(bits).se << endl;
}
