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

vpii v[505];
vi cnt(11, 0);
int check[505][505];

int main(){fastio
    int n; cin >> n;
    int sum = 0;
    for(int i=1 ; i<=n ; ++i) {
        cin >> cnt[i];
        cnt[i] += cnt[i-1];
        for(int j=cnt[i-1] + 1 ; j<cnt[i] ; ++j) {
            v[j].pb({j+1, 1}); v[j+1].pb({j, 1});
        }
    }

    int m; cin >> m;
    while(m--) {
        int p1, p2, q1, q2; cin >> p1 >> p2 >> q1 >> q2;
        int a = cnt[p1-1] + p2, b = cnt[q1-1] + q2;
        v[a].pb({b, 0}); v[b].pb({a, 0});
    }

    auto go = [&](int s, int e, int t) {
        vi w(505, 1e9);
        priority_queue<pii, vpii, greater<>> pq;
        pq.push({w[s] = 0, s});

        while(!pq.empty()) {
            int cw = pq.top().first, cn = pq.top().second; pq.pop();
            if(w[cn] < cw) continue;
            for(auto k : v[cn]) {
                int to = k.first, tw = k.second;
                if(tw == 0) tw = t;
                int nw = cw + tw;
                if(nw < w[to]) pq.push({w[to] = nw, to});
            }
        } return w[e];
    };

    int k; cin >> k;
    while(k--) {
        int t, u1, u2, v1, v2; cin >> t >> u1 >> u2 >> v1 >> v2;
        int start = cnt[u1-1] + u2, end = cnt[v1-1] + v2;        
        cout << go(start, end, t) << '\n';
    }
    return 0;
}