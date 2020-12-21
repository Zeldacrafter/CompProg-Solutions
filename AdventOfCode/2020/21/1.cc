#include "../template.cc"

void solve() {
    vector<string> ss = getInp();

    map<string, int> cnt;
    map<string, set<string>> fromAllergen;
    set<string> allIng;
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

        for(string& ing : ingrediants) cnt[ing]++;
        allIng.insert(ALL(ingrediantsSet));
    }

    set<string> maybeBad;
    for(auto& [_, ings] : fromAllergen)
        maybeBad.insert(ALL(ings));

    vector<string> safe;
    set_difference(ALL(allIng), ALL(maybeBad), back_inserter(safe));

    ll res = 0;
    for(string& s : safe)
        res += cnt[s];
    cout << res << endl;
}
