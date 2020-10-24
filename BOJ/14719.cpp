#include <bits/stdc++.h>
using namespace std;

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a, b; cin >> a >> b;
    vector<int> v(b);
    for(int i=0 ; i<b ; i++) cin >> v[i];
    int ans = 0, l, r;

    for(int i=1 ; i<b-1 ; i++){
        r = l = v[i];
        for(int j=0 ; j<i ; j++) l = max(l, v[j]);
        for(int j=i+1 ; j<b ; j++) r = max(r, v[j]);
        ans += (min(l,r) - v[i]);
    }
    cout << ans;
}
