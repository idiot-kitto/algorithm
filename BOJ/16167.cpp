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

int n, r;
vpll v[101];

int main(){fastio
    cin >> n >> r;
    for(int i=0 ; i<r ; ++i) {
        int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        if(e > 10) v[a].pb({b, c + d * (e - 10)});
        else v[a].pb({b, c});
    }

    vl w(n+1, 1e18), prev(n+1, -1);
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;
    pq.emplace(w[1] = 0, 1, 1);

    while(!pq.empty()) {
        ll cw = get<0>(pq.top()), cn = get<1>(pq.top()), cnt = get<2>(pq.top()); pq.pop();
        if(w[cn] < cw) continue;
        for(auto &k : v[cn]) {
            ll to = k.first, tw = k.second;
            ll nw = cw + tw;
            if(nw < w[to]) { pq.emplace(w[to] = nw, to, cnt + 1); prev[to] = cnt + 1; }
            else if(nw == w[to]) prev[to] = min(prev[to], cnt + 1);
        }
    } 
    
    if(w[n] == 1e18) cout << "It is not a great way.";
    else cout << w[n] << ' ' << prev[n];

    return 0;
}