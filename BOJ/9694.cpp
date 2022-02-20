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
    int tt; cin >> tt;
    for(int t=1 ; t<=tt ; ++t) {
        int n, m; cin >> n >> m;
        vector<vpii> v(m+1);
        vi prev(m+1, -1);
        for(int i=0 ; i<n ; ++i) {
            int x, y, z; cin >> x >> y >> z;
            v[x].pb({y, z}); v[y].pb({x, z});
        }

        vi w(m+1, 1e9);
        priority_queue<pii, vpii, greater<>> pq;
        pq.push({w[0] = 0, 0});

        while(!pq.empty()) {
            int cw = pq.top().first, cn = pq.top().second; pq.pop();
            if(w[cn] < cw) continue;
            for(auto k : v[cn]) {
                int to = k.first, tw = k.second;
                int nw = cw + tw;
                if(nw < w[to]) {
                    pq.push({w[to] = nw, to});
                    prev[to] = cn;
                }
            }
        }

        auto solve = [&]() {
            if(w[m-1] == 1e9) { cout << -1 << '\n'; return; }
            stack<int> st;
            for(int i=m-1 ; i ; ) st.push(i = prev[i]);
            while(!st.empty()) {
                cout << st.top() << " ";
                st.pop();
            } cout << m-1 << '\n';
        };

        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}