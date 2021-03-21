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
        ll n; cin >> n; vl v(n+1);
        for(int i=1 ; i<=n ; i++) cin >> v[i];
        ll m = 0, c = 0, s = 0;
 
        bool flag1 = false, flag2 = false;
        for(int i=1 ; i<n ; i++){
            if(v[i] > v[i+1]) flag1 = true;
            else if(v[i] < v[i+1]) flag2 = true;
        }
        if((!flag1 && flag2) || (flag1 && !flag2)){
            map<int,int> mp;
            for(int i=1 ; i<n ; i++) mp[v[i+1] - v[i]]++;
            if(mp.size() <= 1) { cout << "0\n"; continue; }
            else { cout << "-1\n"; continue; }
        }

        for(int i=1 ; i<n ; i++)
            if(v[i] > v[i+1]) { m += (v[i] - v[i+1]); break; }
        for(int i=1 ; i<n ; i++)
            if(v[i] < v[i+1]) { m += v[i+1] - v[i]; c = v[i+1] - v[i]; break; }
        s = v[1];
        
        if(m == 0) {cout << "0\n"; continue;}
        vl a(n+1); a[1] = s % m;
        for(int i=2 ; i<=n ; i++) a[i] = (a[i-1] + c) % m;
 
        for(int i=1 ; i<=n ; i++)
            if(v[i] != a[i]) {cout << "-1\n"; goto here;}
        cout << m << ' ' << c << '\n';
        here:;
    }
 
    return 0;
}
