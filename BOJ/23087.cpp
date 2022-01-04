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
const ll mod = 1e9 + 9;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){fastio
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<vpll> v(n+1);
    vl dp(n+1, 0);

    for(int i=0 ; i<m ; ++i) {
        int a, b; ll c; cin >> a >> b >> c;
        v[a].pb({b, c});
    }

    vector<tuple<ll, int>> dist(n+1, {1e18, 1});
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll,ll,ll>>, greater<>> pq;
    pq.emplace(get<0>(dist[x]) = 0, x, 0);
    dp[x] = 1;

    while(!pq.empty()) {
        auto [cd, cn, cnt] = pq.top(); pq.pop();
        if(get<0>(dist[cn]) < cd) continue;
        for(auto &[to, d] : v[cn]) {
            ll next = cd + d;
            if(next < get<0>(dist[to])) {
                pq.emplace(get<0>(dist[to]) = next, to, get<1>(dist[to]) = cnt + 1);
                dp[to] = dp[cn];
            } else if(next == get<0>(dist[to]) && cnt + 1 == get<1>(dist[to])) {
                dp[to] += dp[cn];
                dp[to] %= mod;
            }
        }
    }
    auto [a, b] = dist[y];
    if(a == 1e18) cout << -1;
    else cout << a << '\n' << b << '\n' << dp[y];
    
    return 0;
}

