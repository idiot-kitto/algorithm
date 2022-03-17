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

vpii v[1010];

int main(){fastio
    int N, V, E; cin >> N >> V >> E; vi h(N+1);
    int K, C; cin >> K >> C;
    for(int i=1 ; i<=N ; ++i) cin >> h[i];

    while(E--) {
        int a, b, l; cin >> a >> b >> l;
        v[a].pb({b, l});
        v[b].pb({a, l});
    }

    auto go = [&](int start, int end) {
        vi w(V+1, 1e9);
        priority_queue<pii, vpii, greater<>> pq;
        pq.push({w[start] = 0, start});
        while(!pq.empty()) {
            int cw = pq.top().first, cn = pq.top().second; pq.pop();
            if(w[cn] < cw) continue;
            for(auto k : v[cn]) {
                int to = k.first, tw = k.second;
                int nw = cw + tw;
                if(nw < w[to]) pq.push({w[to] = nw, to});
            }
        } return (w[end] == 1e9 ? -1 : w[end]);
    };

    int ans = 0;
    for(int i=1 ; i<=N ; ++i) ans += go(h[i], K) + go(h[i], C);
    cout << ans;

    return 0;
}