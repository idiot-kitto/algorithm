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

vi v[20202];
int c[20202];

void go(int k, int n) {
    c[k] = n;
    for(auto next : v[k]) if(c[next] == 0) go(next, 3 - n);
}

int main(){fastio
    int t; cin >> t;
    while(t--) {
        for(int i=0 ; i<20202 ; ++i) v[i].clear();
        memset(c, 0, sizeof(c));
        int n, m; cin >> n >> m;
        while(m--) {
            int a, b; cin >> a >> b;
            v[a].pb(b); v[b].pb(a);
        }
        for(int i=1 ; i<=n ; ++i) if(c[i] == 0) go(i, 1);
        bool ok = true;
        for(int i=1 ; i<=n ; ++i) 
            for(auto next : v[i]) 
                if(c[next] == c[i]) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}