#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

vi v[32323];
int cnt[32323], ans[32323];

int main(){fastio
    int n, m; cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        v[a].pb(b);
        cnt[b]++;
    }
    queue<int> q;
    for(int i=1 ; i<=n ; ++i) if(!cnt[i]) q.push(i);
    int idx = 1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ans[idx++] = cur;
        for(auto next : v[cur]) if(!(--cnt[next])) q.push(next);
    } for(int i=1 ; i<=n ; ++i) cout << ans[i] << ' ';

    return 0;
}
