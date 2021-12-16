#include "../utils.cc"

ll toInt(const vector<bool>& bits) {
    ll res = 0;
    for(bool b : bits) res = res*2 + b;
    return res;
}

vector<bool> read(queue<bool>& bits, int n, int& parsed) {
    vector<bool> res;
    F0R(i, n) {
        res.pb(bits.front());
        bits.pop();
    }
    parsed += n;
    return res;
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
    
    int version = toInt(read(bits, 3, parsed));
    int id = toInt(read(bits, 3, parsed));

    if(id == 4) {
        vector<bool> content;
        while(true) {
            bool stopBit = read(bits, 1, parsed)[0];
            F0R(j, 4) content.pb(read(bits, 1, parsed)[0]);
            if(!stopBit) break;
        }
        return mp(parsed, toInt(content));
    } else {
        bool lenId = read(bits, 1, parsed)[0];

        if(!lenId) {
            int len = toInt(read(bits, 15, parsed));

            auto [p, res] = decode(bits); parsed += p; len -= p;
            while(len) {
                auto [p, v] = decode(bits);
                parsed += p; len -= p;
                res = eval(id, res, v);
            }
            return mp(parsed, res);
        } else {
            int subPacketCnt = toInt(read(bits, 11, parsed));

            auto [p, res] = decode(bits); parsed += p;
            F0R(_, subPacketCnt - 1) {
                auto [p, v] = decode(bits); parsed += p;
                res = eval(id, res, v);
            }
            return mp(parsed, res);
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
