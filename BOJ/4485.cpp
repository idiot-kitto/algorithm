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
    for(int t=1 ;; ++t) {
        int n; cin >> n; if(n == 0) break;
        vvi arr(n+1, vi(n+1, 0)); vpii v[n * n + 1];
        for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=n ; ++j) cin >> arr[i][j];
        for(int i=1 ; i<=n ; ++i) 
            for(int j=1 ; j<=n ; ++j) 
                for(int k=0 ; k<4 ; ++k) {
                    int ni = i + dir[k][0], nj = j + dir[k][1];
                    if(ni >= 1 && ni <= n && nj >= 1 && nj <= n) {
                        int cidx = n * (i - 1) + j, nidx = n * (ni - 1 ) + nj;
                        v[cidx].pb({nidx, arr[ni][nj]});
                    }
                }

        vi w(n * n + 1, 1e9);
        priority_queue<pii, vpii, greater<>> pq;
        pq.push({w[1] = arr[1][1], 1});
        while(!pq.empty()) {
            int cw = pq.top().first, cn = pq.top().second; pq.pop();
            if(w[cn] < cw) continue;
            for(auto k : v[cn]) {
                int to = k.first, tw = k.second;
                int nw = cw + tw;
                if(nw < w[to]) pq.push({w[to] = nw, to});
            }
        } cout << "Problem " << t << ": " << w[n * n] << '\n';
    }
    return 0;
}