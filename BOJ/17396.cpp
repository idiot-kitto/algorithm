#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100001

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const int mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){fastio
    int n, m; cin >> n >> m;
    vi check(n);
    for(int i=0 ; i<n ; ++i) cin >> check[i];
    vector<vpll> v(n);
    for(int i=0 ; i<m ; ++i) {
        ll a, b, t; cin >> a >> b >> t;
        v[a].pb({b, t});
        v[b].pb({a, t});
    }

    vl dist(n, 1e18);
    priority_queue<pll, vpll, greater<>> pq;
    pq.push({dist[0] = 0, 0});

    while(!pq.empty()) {
        ll cur_dist = pq.top().first, cur_node = pq.top().second; pq.pop();
        if(dist[cur_node] < cur_dist) continue;
        for(auto &[to, to_dist] : v[cur_node]) {
            if(to != n-1 && check[to]) continue;
            ll next = cur_dist + to_dist;
            if(next < dist[to]) pq.push({dist[to] = next, to});
        }
    }

    if(dist[n-1] == 1e18) cout << -1;
    else cout << dist[n-1];

    return 0;
}
