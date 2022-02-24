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

vl v(1010101), tree(4040404);

ll init(ll n, ll s, ll e) {
    ll mid = (s + e) / 2;
    if(s == e) return tree[n] = v[s];
    else return tree[n] = max(init(n * 2, s, mid), init(n * 2 + 1, mid + 1, e));
}

ll query(ll n, ll s, ll e, ll l, ll r) {
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[n];
    int mid = (s + e) / 2;
    return max(query(n * 2, s, mid, l, r), query(n * 2 + 1, mid + 1, e, l, r));
}

int main(){fastio
    ll n, m; cin >> n >> m;
    for(ll i=1 ; i<=n ; ++i) cin >> v[i];
    init(1, 1, n);
    for(ll i=m ; i<=n-m+1 ; ++i)
        cout << query(1, 1, n, i - m + 1, i + m - 1) << ' ';

    return 0;
}