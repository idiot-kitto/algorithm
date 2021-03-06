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
        ll n, x; cin >> n >> x; vi v;
        ll k = 0;
        for(int i=0 ; i<n ; i++){
            int a; cin >> a;
            if(a%x==0) k+= a/x;
            else {k+=a/x;v.pb(a%x);}
        }
        ll mn = k, mx = k + v.size();
        ll sum = 0;
        for(int i=0 ; i<v.size() ; i++) sum += v[i];
        if(sum%x==0) mn += sum/x;
        else mn = mn + sum/x + 1;
 
        cout << mn << ' ' << mx << '\n';
    }
 
    return 0;
}
