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

bool ok(ll n) {
    if(n <= 1) return false;
    for(ll i=2 ; i*i<=n ; ++i) {
        if(n % i == 0) return false;
    } return true;
}

int main(){fastio
    ll n; cin >> n;
    vl v, vv;
    for(ll i=2 ; i<1e4+1 ; ++i) if(ok(i)) v.pb(i);
    for(ll i=0 ; i<(ll)v.size() - 1 ; ++i) if(v[i] * v[i+1] < 1e5) vv.pb(v[i] * v[i+1]);
    for(auto k : vv) if(k > n) { cout << k; break; }
    return 0;
}
