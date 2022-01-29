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
    vi v(10101); iota(all(v), 0);
    int n; cin >> n; for(int i=1 ; i<=n ; ++i) cin >> v[i];
    int idx1 = 1, idx2 = 1, idx3 = 1, idx4 = 1;
    vi vv = v;
    for(int i=1 ; i<=n ; ++i) {
        if(vv[i] != i) {
            idx1 = i;
            for(int j=1 ; j<=n ; ++j) if(vv[j] == i) { idx2 = j; goto here; }
        }
    }here:;
    reverse(vv.begin() + idx1, ++vv.begin() + idx2);
    for(int i=1 ; i<=n ; ++i) {
        if(vv[i] != i) {
            idx3 = i;
            for(int j=1 ; j<=n ; ++j) if(vv[j] == i) { idx4 = j; goto here2; }
        }
    }here2:;
    reverse(vv.begin() + idx3, ++vv.begin() + idx4);
    
    bool ok = true;
    for(int i=1 ; i<=n ; ++i) if(vv[i] != i) ok = false;
    if(ok) { cout << idx1 << ' ' << idx2 << '\n' << idx3 << ' ' << idx4; return 0; }
    
    vv = v;
    for(int i=n ; i>=1 ; --i) {
        if(vv[i] != i) {
            idx1 = i;
            for(int j=n ; j>=1 ; --j) if(vv[j] == i) { idx2 = j; goto here3; }
        }
    }here3:;
    reverse(vv.begin() + idx2, ++vv.begin() + idx1);
    for(int i=n ; i>=1 ; --i) {
        if(vv[i] != i) {
            idx3 = i;
            for(int j=n ; j>=1 ; --j) if(vv[j] == i) { idx4 = j; goto here4; }
        }
    }here4:;
    reverse(vv.begin() + idx4, ++vv.begin() + idx3);
    
    ok = true;
    for(int i=1 ; i<=n ; ++i) if(vv[i] != i) ok = false;
    if(ok) { cout << idx2 << ' ' << idx1 << '\n' << idx4 << ' ' << idx3; return 0; }    

    return 0;
}