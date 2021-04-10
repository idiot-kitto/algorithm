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
 
int main(){fastio
    int t; cin >> t;
    while(t--){
        int n, l, r, s; cin >> n >> l >> r >> s; vi v(n+1,0),check(n+1,0);
        ll s1 = 0, s2 = 0;
        int k = r-l+1;
        for(int i=1 ; i<1+k ; i++) s1 += i;
        for(int i=n ; i>n-k ; i--) s2 += i;
        if(s>s2 || s<s1) {cout << "-1\n"; continue;}
 
        vi vv;
        int val = 0;
        for(int i=1 ; i<=k ; i++) vv.pb(i), val += i;
        val = s - val;
        int d = val / (int)vv.size(), m = val % (int)vv.size();
        for(int i=0 ; i<(int)vv.size() ; i++) vv[i] += d;
        for(int i=(int)vv.size()-1 ; i>=0 ; i--){
            if(!m) break;
            vv[i]++;
            m--;
        }
        for(int i=0 ; i<(int)vv.size() ; i++) check[vv[i]] = 1;
        for(int i=l ; i<=r ; i++) v[i] = vv[i-l];
 
        int idx = 1;
        for(int i=1 ; i<=n ; i++){
            while(1){
                if(check[idx] == 0) break;
                idx++;
            }
            if(v[i] == 0){
                v[i] = idx;
                check[idx] = 1;
            }
        }
        for(int i=1 ; i<=n ; i++) cout << v[i] << ' '; cout << '\n';
 
    }
 
    return 0;
}
