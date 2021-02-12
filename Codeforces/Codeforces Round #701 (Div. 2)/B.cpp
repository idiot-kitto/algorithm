#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
 
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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
 
int main(){fastio
    int n, q, k; cin >> n >> q >> k; vi v(n+1);
    for(int i=1 ; i<=n ; i++) cin >> v[i];
    while(q--){
        int l, r; cin >> l >> r;
        cout << v[l] - 1 + k - v[r] + 2 * (k - (r - l + 1) - (v[l] - 1 + k - v[r])) << '\n';
    }
 
    return 0;
}
