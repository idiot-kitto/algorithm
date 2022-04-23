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
    int n; cin >> n; vi c(n+1, 0); vector<vpii> v(n+1, vpii(n+1));
    for(int i=1 ; i<=n ; ++i) cin >> c[i];
    for(int i=1 ; i<=n ; ++i) {
        int m; cin >> m;
        while(m--) {
            int a, b; cin >> a >> b;
            v[i].pb({a, b});
        }
    }

    int ans = 1e9;
    vi idx(n); iota(all(idx), 1);
    do {
        vi cc(c);
        int tmp = 0;
        for(int i=0 ; i<n ; ++i) {
            int k = idx[i];
            tmp += cc[k];
            for(auto p : v[k]) {
                int a = p.first, b = p.second;
                cc[a] -= b;
                cc[a] = max(cc[a], 1);
            }
        } ans = min(ans, tmp);
    }while(next_permutation(all(idx)));
    cout << ans;
    
    return 0;
}