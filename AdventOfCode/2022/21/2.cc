#include "../utils.cc"

map<string, function<ll(ll)>> calc;
map<string, function<bool(void)>> usesInp;

void solve() {

    getInp([&](auto& cin, int) {
        string name, e1, e2;
        char op;
        cin >> name >> e1;
        name.pop_back();
        if(isdigit(e1[0])) {
            if(name == "humn") {
                calc[name] = [&](ll target) -> ll { return target; };
                usesInp[name] = [&](void) -> bool { return true; };
            }
            else {
                calc[name] = [=](ll) -> ll { return stol(e1); };
                usesInp[name] = [&](void) -> bool { return false; };
            }
        } else {
            cin >> op >> e2;
            if(name == "root") {
                calc[name] = [=](ll target) -> ll {
                    assert(usesInp[e1]() ^ usesInp[e2]());
                    assert(target == 1);
                    if(usesInp[e1]()) return calc[e1](calc[e2](-1));
                    else return calc[e2](calc[e1](-1));
                };
            } else if(op == '+') {
                calc[name] = [=](ll target) -> ll {
                    assert(target == -1 || (usesInp[e1]() ^ usesInp[e2]()));

                    if(target == -1) return calc[e1](-1) + calc[e2](-1);

                    if(usesInp[e1]()) return calc[e1](target - calc[e2](-1));
                    else return calc[e2](target - calc[e1](-1));
                };
            } else if(op == '-') {
                calc[name] = [=](ll target) -> ll {
                    assert(target == -1 || (usesInp[e1]() ^ usesInp[e2]()));

                    if(target == -1) return calc[e1](-1) - calc[e2](-1);

                    if(usesInp[e1]()) return calc[e1](target + calc[e2](-1));
                    else return calc[e2](calc[e1](-1) - target);
                };
            }else if(op == '*') {
                calc[name] = [=](ll target) -> ll {
                    assert(target == -1 || (usesInp[e1]() ^ usesInp[e2]()));

                    if(target == -1) return calc[e1](-1) * calc[e2](-1);

                    if(usesInp[e1]()) return calc[e1](target / calc[e2](-1));
                    else return calc[e2](target / calc[e1](-1));
                };
            }else if(op == '/') {
                calc[name] = [=](ll target) -> ll {
                    assert(target == -1 || (usesInp[e1]() ^ usesInp[e2]()));

                    if(target == -1) return calc[e1](-1) / calc[e2](-1);

                    if(usesInp[e1]()) return calc[e1](target * calc[e2](-1));
                    else return calc[e2](calc[e1](-1) / target);
                };
            }
            else assert(false);

            usesInp[name] = [=](void) -> bool { return usesInp[e1]() || usesInp[e2](); };
        }
    });


    cout << calc["root"](1) << endl;
}

