#include "../utils.cc"

#define OP(x) [=](void) -> ll { return calc[e1]() x calc[e2](); }
map<string, function<ll(void)>> calc;

void solve() {
    getInp([&](auto& cin, int) {
        string name, e1, e2;
        char op;
        cin >> name >> e1;
        name.pop_back();
        if(isdigit(e1[0])) {
            calc[name] = [=](void) -> ll { return stol(e1); };
        } else {
            cin >> op >> e2;
            if(op == '+') calc[name] = OP(+);
            else if(op == '-') calc[name] = OP(-);
            else if(op == '*') calc[name] = OP(*);
            else if(op == '/') calc[name] = OP(/);
            else assert(false);
        }
    });

    cout << calc["root"]();
}

