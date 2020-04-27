#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int aHp, aStr, bHp, bStr;
    cin >> aHp >> aStr >> bHp >> bStr;

    int aAtt = bHp / aStr + (bHp % aStr ? 1 : 0);
    int bAtt = aHp / bStr + (aHp % bStr ? 1 : 0);

    if(aAtt <= bAtt)
        cout << "Yes\n";
    else
        cout << "No\n";
}


