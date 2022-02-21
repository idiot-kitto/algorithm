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

int n, e, p;
vpll v[5050];

ll solve(ll s, ll e) {
    vl w(n+1, 1e18);
    priority_queue<pll, vpll, greater<>> pq;
    pq.push({w[s] = 0, s});

    while(!pq.empty()) {
        int cw = pq.top().first, cn = pq.top().second; pq.pop();
        if(w[cn] < cw) continue;
        for(auto k : v[cn]) {
            ll to = k.first, tw = k.second;
            ll nw = cw + tw;
            if(nw < w[to]) pq.push({w[to] = nw, to});
        }
    } return w[e];
}

int main(){fastio
    cin >> n >> e >> p;
    for(int i=1 ; i<=e ; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        v[a].pb({b, c}); v[b].pb({a, c});
    }
    if(solve(1, n) == solve(1, p) + solve(p, n)) cout << "SAVE HIM";
    else cout << "GOOD BYE";
    
    return 0;
}