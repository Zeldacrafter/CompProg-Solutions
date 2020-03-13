#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(auto (a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR((a), 0, (b))

int arr[100005];
int cnt[32] = {};
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    F0R(i, n) {
        cin >> arr[i];
        F0R(j, 32) 
            if(arr[i] & (1 << j))
                cnt[j]++;
    }

    int num = 0;
    F0R(i, 32)
        if(cnt[i] == 1)
            num |= 1 << i;
  
    int ind = -1;
    int unsetBit = 0;
    while(ind == -1) {
        F0R(i, n)
            if((arr[i] & num) == num) {
                ind = i;
                break;
            }

        if(ind == -1) {
            int oldnum = num;
            do
                num &= ~(1 << unsetBit++);
            while(oldnum == num);
        }
    }

    cout << arr[ind];
    F0R(i, n)
        if(i != ind)
            cout << ' ' << arr[i];
    return 0;
}
