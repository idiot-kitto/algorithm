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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n; vi v(n+1, 0), ps1(n+1, 0), ps2(n+1, 0);
        for(int i=1 ; i<=n ; ++i) cin >> v[i], ps1[i] = v[i], ps2[i] = v[i];
        for(int i=1 ; i<=n ; ++i) ps1[i] += ps1[i-1];
        for(int i=n-1 ; i>=1 ; --i) ps2[i] += ps2[i+1];
 
        int l = 1, r = n, lv = ps1[1], rv = ps2[n];
        int ans = 0;
        while(l<r) {
            if(lv == rv) {
                ans = l + n - r + 1;
                l++; r--;
                lv = ps1[l];
                rv = ps2[r];
            } else if(lv < rv) {
                l++;
                lv = ps1[l];
            } else {
                r--;
                rv = ps2[r];
            }
        } cout << ans << '\n';
 
    }
 
    return 0;
}