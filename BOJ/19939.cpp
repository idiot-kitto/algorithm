#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k; v.resize(k);
    for(int i=0 ; i<k ; i++) v[i] = 1;
    n -= k;

    for(int i=1 ; i<k ; i++) {v[i] += i; n -= i;}
    if(n<0) {cout << -1; return 0;}
    n %= k;
    if(n) cout << v[k-1] - v[0] + 1;
    else cout << v[k-1] - v[0];

    return 0;
}
