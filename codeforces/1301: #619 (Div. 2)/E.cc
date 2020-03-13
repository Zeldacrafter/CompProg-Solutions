#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR (a, 0, b)
#define pb push_back
#define endl '\n'

vector<string> s;
int sz[500][500] = {};
int n, m;

bool valid(int y, int x, int size) {
    if (x - size < 0 || x + size + 1 >= m || y - size < 0 || y + size + 1 >= n)
        return false;

    F0R (i, size + 1) {
        if (s[y - size][x - i] != 'R') return false;
        if (s[y - i][x - size] != 'R') return false;

        if (s[y - size][x + 1 + i] != 'G') return false;
        if (s[y - i][x + 1 + size] != 'G') return false;

        if (s[y + 1 + size][x - i] != 'Y') return false;
        if (s[y + 1 + i][x - size] != 'Y') return false;

        if (s[y + 1 + size][x + 1 + i] != 'B') return false;
        if (s[y + 1 + i][x + 1 + size] != 'B') return false;
    }
    return true;
}

int spT[510][9][510][9];
void build() {
    F0R (ir, n) {
        F0R (ic, m)
            spT[ir][0][ic][0] = sz[ir][ic];

        for (int jc = 1; (1 << jc) <= m; ++jc)
            for (int ic = 0; ic + (1 << jc) <= m; ++ic)
                spT[ir][0][ic][jc] =
                    max(spT[ir][0][ic][jc - 1],
                        spT[ir][0][ic + (1 << (jc - 1))][jc - 1]);
    }

    for (int jr = 1; (1 << jr) <= n; ++jr)
        for (int ir = 0; ir + (1 << jr) <= n; ++ir)
            for (int jc = 0; (1 << jc) <= m; ++jc)
                for (int ic = 0; ic + (1 << jc) <= m; ++ic)
                    spT[ir][jr][ic][jc] =
                        max(spT[ir][jr - 1][ic][jc],
                            spT[ir + (1 << (jr - 1))][jr - 1][ic][jc]);
}

int query(int r1, int r2, int c1, int c2) {
    if (r1 < 0 || c1 < 0 || r1 > r2 || c1 > c2) return 0;

    int rk = 31 - __builtin_clz(r2 - r1 + 1);
    int ck = 31 - __builtin_clz(c2 - c1 + 1);

    return max(max(spT[r1][rk][c1][ck], spT[r1][rk][c2 - (1 << ck) + 1][ck]),
               max(spT[r2 - (1 << rk) + 1][rk][c1][ck],
                   spT[r2 - (1 << rk) + 1][rk][c2 - (1 << ck) + 1][ck]));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int q;
    cin >> n >> m >> q;
    F0R (i, n) {
        string str;
        cin >> str;
        s.pb(str);
    }

    int maxSize = 0;
    F0R (r, n - 1) {
        F0R (c, m - 1) {
            if (s[r][c] == 'R' && s[r + 1][c] == 'Y' && s[r][c + 1] == 'G' &&
                s[r + 1][c + 1] == 'B') {
                int size = 1;
                while (valid(r, c, size)) size++;
                sz[r][c] = size;
                maxSize = max(maxSize, size);
            }
        }
    }

    build();

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        int l = 0;
        int r = maxSize;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (query(r1 + mid - 1, r2 - mid, c1 + mid - 1, c2 - mid) >= mid)
                res = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        cout << 4 * res * res << endl;
    }

    return 0;
}
