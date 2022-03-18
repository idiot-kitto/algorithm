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

vpii v[1010101];
int arr[1010][1010];
vi p;
int start;

int main(){fastio
    int n; cin >> n;
    for(int i=1 ; i<=n ; ++i) 
        for(int j=1 ; j<=n ; ++j) { 
            cin >> arr[i][j]; 
            if(arr[i][j] == -1) start = n * (i - 1) + j, arr[i][j] = 0;
            else if(arr[i][j] == 0) p.pb(n * (i - 1) + j);
        }

    for(int i=1 ; i<=n ; ++i) 
        for(int j=1 ; j<=n ; ++j) 
            for(int k=0 ; k<4 ; ++k) {
                int ni = i + dir[k][0], nj = j + dir[k][1];
                if(ni >= 1 && ni <= n && nj >= 1 && nj <= n) v[n * (i - 1) + j].pb({n * (ni - 1) + nj, arr[ni][nj]});
            }
    
    if(p.empty()) { cout << 0; return 0; }

    auto go = [&](int s, int e) {
        vi w(1010101, 1e9);
        priority_queue<pii, vpii, greater<>> pq;
        pq.push({w[s] = 0, s});
        while(!pq.empty()) {
            int cw = pq.top().first, cn = pq.top().second; pq.pop();
            if(w[cn] < cw || cn == e) continue;
            for(auto k : v[cn]) {
                int to = k.first, tw = k.second;
                int nw = cw + tw;
                if(nw < w[to]) {
                    if(to == e) { w[e] = min(w[e], nw); continue; }
                    pq.push({w[to] = nw, to});
                }
            }
        } return w[e];
    };

    int ans = 1e9; sort(all(p));
    map<pii, int> mp;
    for(int k : p) mp[{start, k}] = go(start, k), mp[{k, start}] = mp[{start, k}];
    for(int i=0 ; i<p.size() - 1 ; ++i) {
        for(int j=i+1 ; j<p.size() ; ++j) {
            mp[{p[i], p[j]}] = go(p[i], p[j]);
            mp[{p[j], p[i]}] = mp[{p[i], p[j]}];
        }
    }
    
    do {
        int tmp = 0;
        tmp += mp[{start, p[0]}];
        for(int i=0 ; i<p.size()-1 ; ++i) tmp += mp[{p[i], p[i+1]}];
        tmp += mp[{p.back(), start}];
        ans = min(ans, tmp);
    } while(next_permutation(all(p)));
    
    cout << (ans == 1e9 ? 0 : ans);
    return 0;
}