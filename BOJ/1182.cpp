#include <bits/stdc++.h>
using namespace std;
int n, s, ans;
vector<int> v;

void dfs(int val, int idx)
{
    if(idx>=n) return;
    if(val+v[idx]==s) ans++;
    dfs(val,idx+1);
    dfs(val+v[idx],idx+1);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    v.resize(n);
    for(int i=0 ; i<n ; i++) cin >> v[i];
    dfs(0,0);
    cout << ans;
    return 0;
}
