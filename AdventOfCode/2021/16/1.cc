#include "../utils.cc"

int toInt(const vector<bool>& bits) {
    int res = 0;
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

ii decode(queue<bool>& bits) {
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
    } else {
        bool lenId = read(bits, 1)[0]; parsed++;

        if(!lenId) {
            int len = toInt(read(bits, 15)); parsed += 15;

            while(len) {
                auto[p, v] = decode(bits);
                version += v;
                parsed += p; len -= p;
            }
        } else {
            int subPacketCnt = toInt(read(bits, 11)); parsed += 11;
            F0R(_, subPacketCnt) {
                auto [p, v] = decode(bits);
                version += v;
                parsed += p;
            }
        }
    } 
    return mp(parsed, version);
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
