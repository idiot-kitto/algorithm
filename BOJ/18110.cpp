#include <bits/stdc++.h>
using namespace std;

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, sum = 0; cin >> n; vector<int> v(n);
    if(!n) {cout << 0; return 0;}
    
    for(int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin(),v.end());
    
    int k = (int)round(n * 0.15);
    for(int i=k ; i<n-k ; i++) sum += v[i];
    cout << (int)round(sum / (n - 2.0 * k));
    
    return 0;
}
