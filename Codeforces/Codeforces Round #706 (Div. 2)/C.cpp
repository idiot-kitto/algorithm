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
    cout << fixed; cout.precision(15);
    int t; cin >> t;
    while(t--){
        int n; cin >> n; vl miner, dia;
        long double ans = 0;
        for(int i=0 ; i<n*2 ; i++){
            ll x, y; cin >> x >> y;
            if(x == 0) miner.pb(abs(y));
            if(y == 0) dia.pb(abs(x));
        }sort(all(miner)); sort(all(dia));
        for(int i=0 ; i<n ; i++){
            ans += sqrt(miner[i]*miner[i] + dia[i]*dia[i]);
        }cout << ans << '\n';
 
    }
 
    return 0;
}
