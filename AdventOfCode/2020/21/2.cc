#include "../template.cc"

void solve() {
    vector<string> ss = getInp();

    map<string, set<string>> fromAllergen;
    for(string& s : ss) {
        auto [ingrediantStr, allergenStr] = splitP(s, " (contains ");
        allergenStr.pop_back();
        vector<string> ingrediants = split(ingrediantStr, " ");
        vector<string> allergens = split(allergenStr, ", ");

        set<string> ingrediantsSet(ALL(ingrediants));
        for(string& allerg : allergens) {
            if(fromAllergen.count(allerg)) {
                vector<string> v;
                set_intersection(ALL(fromAllergen[allerg]), ALL(ingrediantsSet), back_inserter(v));
                fromAllergen[allerg] = set(ALL(v));
            } else {
                fromAllergen[allerg] = ingrediantsSet;
            }
        }
    }

    map<string, set<string>> toAllergen;
    for(auto& [allergen, ingrediants] : fromAllergen)
        for(string ing : ingrediants)
            toAllergen[ing].insert(allergen);

    queue<string> q;
    for(auto& [_, allergs] : toAllergen)
        if(SZ(allergs) == 1)
            q.push(*allergs.begin());

    while(SZ(q)) {
        string& curr = q.front();
        q.pop();
        for(auto& [_, allergs] : toAllergen)
            if(SZ(allergs) > 1 && allergs.erase(curr) && SZ(allergs) == 1) 
                q.push(*allergs.begin());
    }

    vector<string> ings;
    for(auto& [ing, _] : toAllergen) 
        if(!count(ALL(ings), ing))
            ings.pb(ing);
    sort(ALL(ings), [&](auto& a, auto& b) { return *toAllergen[a].begin() < *toAllergen[b].begin(); });

    cout << pp(ings, ",") << endl;
}
