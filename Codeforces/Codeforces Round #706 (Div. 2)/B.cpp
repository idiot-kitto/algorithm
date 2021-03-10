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
        ll n, k; cin >> n >> k; vl v(n); map<ll, ll> mp;
 
        for(int i=0 ; i<n ; i++) {
            cin >> v[i];
            mp[v[i]]++;
        }sort(all(v));
        int ans = mp.size();
        int cnt = 0;
        while(cnt != k){
            ll mx = *max_element(all(v));
            ll mex = -1;
            for(int i=0 ; i<v.size() ; i++) if(v[i] != i) {mex = i; break;}
            if(mex == -1) mex = mx + 1;
 
            if(mp[(mx+mex+1)/2]) {ans = mp.size(); break;}
            else{
                if((mx+mex+1)/2 > mx) {cout << mp.size() + k - 1 << '\n'; goto here;}
                v.pb((mx+mex+1)/2); sort(all(v)); mp[(mx+mex+1)/2]++;
            }
            cnt++;
        }cout << mp.size() << '\n';
        here:;
 
    }
 
    return 0;
}
