#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--) {
		int a, b, c, n;
		cin >> a >> b >> c >> n;

		int m = max(a, max(b, c));
		int s = 3*m - (a + b + c);
		if(n >= s && (n - s) % 3 == 0)
            cout << "YES\n";
		else
            cout << "NO\n";
	}
}
