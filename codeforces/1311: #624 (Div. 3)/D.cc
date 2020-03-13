#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR(a, 0, b)
#define endl '\n'
template <typename T>
bool ckMin(T& a, T b) { if(b < a) { a = b; return true; } else { return false;} }
template <typename T>
bool ckMax(T& a, T b) { if(b > a) { a = b; return true; } else {return false;} }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--) {
        int a, b, c;
        cin >> a >> b >> c;

        int res = 2e9;
        int bestA, bestB, bestC;
        for(int A = 1; A <= 2*a; ++A)
            for(int B = A; B <= 2*b; B += A) {
                int C1 = c / B * B;
                int C2 = C1 + B;
                if(ckMin(res, abs(A-a) + abs(B-b) + abs(C2 - c))) {
                    bestA = A;
                    bestB = B;
                    bestC = C2;
                }
                if(C1 >= B)
                    if(ckMin(res, abs(A-a) + abs(B-b) + abs(C1 - c))) {
                        bestA = A;
                        bestB = B;
                        bestC = C1;
                    }
            }

        cout << res << endl << bestA << ' ' << bestB << ' ' << bestC << endl;
    }
}
