#include "../utils.cc"

vi run(ll A, ll B, ll C, vector<ll> mem) {
    auto combo = [&](ll i) {
        if(i <= 3) return i;
        if(i == 4) return A;
        if(i == 5) return B;
        if(i == 6) return C;
        assert(false);
        return -1ll;
    };
    vi outp;

    for(int ptr = 0; ptr < SZ(mem); ptr += 2) {
        switch(mem[ptr]) {
            case 0: A = A >> combo(mem[ptr + 1]);     break;
            case 1: B ^= mem[ptr + 1];                break;
            case 2: B = combo(mem[ptr + 1]) % 8;      break;
            case 3: if(A) ptr = mem[ptr + 1] - 2;     break;
            case 4: B ^= C;                           break;
            case 5: outp.pb(combo(mem[ptr + 1]) % 8); break;
            case 6: B = A >> combo(mem[ptr + 1]);     break;
            case 7: C = A >> combo(mem[ptr + 1]);     break;
            default: assert(false);
        }
    }
    return outp;
}

void solve() {
    ll A = -1, B = -1, C = -1;
    vector<ll> mem;
    getInp([&](auto& cin, int i) {
        string s; cin >> s >> s;
        switch(i) {
            case 0: cin >> A; break;
            case 1: cin >> B; break;
            case 2: cin >> C; break;
            case 4: for(string& o : split(s, ",")) mem.pb(stoll(o)); break;
        }
    });
    
    cout << pp(run(A, B, C, mem), ",") << endl;
}

