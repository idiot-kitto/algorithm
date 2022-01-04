#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back

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

int main(){fastio
    ll n, m, x; cin >> n >> m >> x;
    vector<vector<tuple<ll, ll, ll>>> v(n+1);
    for(int i=0 ; i<m ; ++i) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        v[a].emplace_back(b, c, d);
        v[b].emplace_back(a, c, d);
    }
    if(n == 1) { cout << 0; return 0; }

    auto solve = [&](ll k) {
        vl dist(n+1, 1e18);
        priority_queue<pll, vpll, greater<>> pq;
        pq.push({dist[1] = 0, 1});

        while(!pq.empty()) {
            ll cd = pq.top().first, cn = pq.top().second; pq.pop();
            if(dist[cn] < cd) continue;
            for(auto &[to, d, color] : v[cn]) {
                ll tmp = d;
                if(color == 1) tmp += x - k;
                else if(color == 2) tmp += k;
                ll next = cd + tmp;
                if(next < dist[to]) pq.push({dist[to] = next, to});
            }
        } return dist[n];
    };

    ll l = 0, r = x, ans = -1;
    while(l + 3 <= r) {
        ll p = (l * 2 + r) / 3;
        ll q = (l + r * 2) / 3;

        if(solve(p) > solve(q)) r = q;
        else l = p;
    }
    for(ll i=l ; i<=r ; ++i) ans = max(ans, solve(i));
    cout << ans;

    return 0;
}
