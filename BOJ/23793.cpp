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

int main(){fastio
    int n, m; cin >> n >> m;
    vector<vpll> v(n+1);
    for(int i=0 ; i<m ; ++i) {
        int a, b, c; cin >> a >> b >> c;
        v[a].pb({b, c});
    }
    int x, y, z; cin >> x >> y >> z;

    vl w(n+1, 1e18);
    priority_queue<pll, vpll, greater<>> pq;

    auto go = [&](ll dest, int flag){
        w = vl(n+1, 1e18);
        while(!pq.empty()) {
            ll cw = pq.top().first, cn = pq.top().second; pq.pop();
            if(w[cn] < cw) continue;
            for(auto &[to, tw] : v[cn]) {
                ll next = cw + tw;
                if(next < w[to]) {
                    if(flag) {
                        if(to == dest) w[to] = next;
                        else pq.push({w[to] = next, to});
                    } else {
                        if(to != y) pq.push({w[to] = next, to});
                    }
                }
            }
        }
    };
    pq.push({w[x] = 0, x}); go(y, 1); pq.push({w[y], y}); go(z, 1);
    if(w[z] == 1e18) cout << -1 << ' ';
    else cout << w[z] << ' ';
    pq.push({w[x] = 0, x}); go(z, 0);
    if(w[z] == 1e18) cout << -1 << ' ';
    else cout << w[z] << ' ';

    return 0;
}
