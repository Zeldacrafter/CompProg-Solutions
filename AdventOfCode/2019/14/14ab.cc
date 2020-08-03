#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))

typedef long long ll;

struct req {
    int amount;
    string name;
};

struct reaction {
    int amountProduced;
    vector<req> required;
};

struct req_cmp {
    bool operator() (const req& r1, const req& r2) const {
        if(r1.amount != r2.amount) return r1.amount < r2.amount;
        else return r1.name < r2.name;
    }
};

map<string, reaction> reactions;

ll cost(ll fuel, map<string, ll> in) {
    // Kahn-Toposort to find out what cost
    // we need to produce that amount of fuel.

    // We know that "FUEL" has no incoming edges.
    // Therefore we can start at "FUEL" and go down the toposort.
    // If any item has no incoming edges anymore it means that we
    // already know how many we need to produce and can continue with that element.

    // Start with "FUEL" as it has no incoming edges.
    queue<string> q;
    q.push("FUEL");
    map<string, ll> reqAmount;
    reqAmount["FUEL"] = fuel;

    while(!q.empty()) {
        string curr = q.front();
        q.pop();

        ll n = reqAmount[curr];
        if(curr == "ORE") // Found our goal node.
            return n;     // We already processed it because it was in the queue.

        ll producedAmount = reactions[curr].amountProduced;
        vector<req> required = reactions[curr].required;

        // Calculate how much of the current material we need to produce.
        ll toProduce = (n + producedAmount - 1)/producedAmount;

        for(req r : required) {
            reqAmount[r.name] += r.amount * toProduce;

            in[r.name]--;
            if(in[r.name] == 0)
                q.push(r.name);
        }
    }

    // Failed to produce the wanted amount of fuel.
    assert(false);
    return -1;
}

int main() {

    char buffer[100];
    char buffer2[100];

    map<string, ll> in;

    // Input parsing. Probably not the most elegant but w/ever.
    while(scanf(" %[^=] => %15[^\n]", buffer, buffer2) != EOF) {

        int producedAmount;
        char resultName[10];
        sscanf(buffer2, "%d %s", &producedAmount, resultName);

        vector<req> reqs;
        stringstream ss(buffer);
        string tok;
        while(getline(ss, tok, ',')) {
            int amnt;
            char ident[10];
            sscanf(tok.c_str(), " %d %10[A-Z]", &amnt, ident);

            reqs.push_back({amnt, string(ident)});
            in[string(ident)]++;
        }

        reactions[string(resultName)] = {producedAmount, reqs};
    }

    // Just calculate the cost.
    printf("Part 1: %lld\n", cost(1, in));

    // Binary search over the solution range.
    ll low = 0;
    ll high = 1e12L;
    while(low + 1 < high) {
        ll mid = (low + high + 1) / 2;
        ll c = cost(mid, in);
        if(c <= 1e12L)
            low = mid;
        else
            high = mid;
    }
    printf("Part 2: %lld\n", low);
    return 0;
}