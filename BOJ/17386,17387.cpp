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

ll ccw(pll a, pll b, pll c) { 
    ll tmp = a.first * b.second + b.first * c.second + c.first * a.second;
    tmp -= b.first * a.second + c.first * b.second + a.first * c.second;
    return (tmp > 0 ? 1 : (tmp == 0 ? 0 : -1));
}

ll check(pll a, pll b, pll c, pll d) {
    ll val1 = ccw(a, b, c) * ccw(a, b, d);
    ll val2 = ccw(c, d, a) * ccw(c, d, b);
    if(val1 == 0 && val2 == 0) {
        if(a > b) swap(a, b);
        if(c > d) swap(c ,d);
        if(a <= d && b >= c) return 1;
        else return 0;
    } else {
        if(val1 <= 0 && val2 <= 0) return 1;
        return 0;
    }
}

int main(){fastio
    vpll v;
    for(int i=0 ; i<4 ; ++i) { ll a, b; cin >> a >> b; v.pb({a, b}); }
    cout << check(v[0], v[1], v[2], v[3]);
    return 0;
}