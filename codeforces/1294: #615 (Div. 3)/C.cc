#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		int n;
		cin >> n;
		
		int a = -1;
		for(int i = 2; i*i <= n; ++i)
			if(n % i == 0) {
				n /= i;
				a = i;
				break;
			}
	
		if(a == -1) {
			cout << "NO\n";
			continue;
		}

		int b = -1;
		for(int i = 2; i*i <= n; ++i)
			if(n % i == 0 && i != a) {
				n /= i;
				b = i;
				break;
			}

		if(b == -1 || n == 1 || n == a || n == b)
			cout << "NO\n";
		else {
		   	cout << "YES\n" << a << ' ' << b << ' ' << n << endl;
		}
	}
}
