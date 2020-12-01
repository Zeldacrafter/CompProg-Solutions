#include "../template.cc"

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n = 200;
    vi a(n);
    cin >> a;

    F0R(i, n) 
        FOR(j, i + 1, n)
            if(a[i] + a[j] == 2020)
                cout << a[i]*a[j] << endl;
}
