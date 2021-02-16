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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
 
 
vi ans, check, v;
int n;
void go(int idx, int cnt){
    if(idx != n){
        int mx = 0, nidx;
        for(int i=idx+1 ; i<=n ; i++){
            if(check[i]) break;
            mx = max(mx, v[i]);
        }
        for(int i=idx+1 ; i<=n ; i++) if(v[i] == mx) nidx = i, check[i] = 1, ans[i] = cnt;
        if(mx) go(nidx, cnt+1);
    }
    if(idx != 1){
        int mx = 0, nidx;
        for(int i=idx-1 ; i>=1 ; i--){
            if(check[i]) break;
            mx = max(mx, v[i]);
        }
        for(int i=idx-1 ; i>=1 ; i--) if(v[i] == mx) nidx = i, check[i] = 1, ans[i] = cnt;
        if(mx) go(nidx, cnt+1);
    }
}
 
int main(){fastio
    int tc; cin >> tc;
    while(tc--){
        cin >> n;
        v = vi(n+1); ans = vi(n+1, 0); check = vi(n+1, 0);
        int idx;
        for(int i=1 ; i<=n ; i++){
            cin >> v[i];
            if(v[i] == n) idx = i;
        }check[idx] = 1;
        go(idx,1);
 
        for(int i=1 ; i<=n ; i++) cout << ans[i] << ' '; cout << '\n';
    }
 
    return 0;
}
