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
    int n, d; cin >> n >> d;
    vi v;
    for(int i=0 ; i<d ; ++i) v.pb(i);
    sort(all(v));
    int ans = 2e9;
    do {
        int val = 1, res = 0;
        for(int i=0 ; i<v.size() ; ++i) {
            res += v[i] * val;
            val *= d;
        }if(res > n && v[(int)v.size()-1] != 0) ans = min(ans, res);
    }while(next_permutation(all(v)));
    if(ans == 2e9) cout << -1;
    else cout << ans;

    return 0;
}
