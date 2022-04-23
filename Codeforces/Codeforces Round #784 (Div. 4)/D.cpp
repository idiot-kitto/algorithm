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
        int n; cin >> n;
        string s; cin >> s;
        if(n==1 && s != "W") { cout << "NO\n"; continue; }
        if(n==1 && s == "W") { cout << "YES\n"; continue; }
        bool ok = true;
        for(int i=1 ; i<n-1 ; ++i) if(s[i] != 'W' && s[i-1] == 'W' && s[i+1] == 'W') ok = false;
 
        int cnt = 0;
        for(int i=0 ; i<s.size() ; ++i) if(s[i] != 'W') cnt++;
        if(cnt == 1) ok = false;
 
        if(cnt == 0) { cout << "YES\n"; continue; }
 
        bool cr = false, cb = false;
        for(int i=0 ; i<s.size() ; ++i) {
            if(s[i] == 'R') cr = true;
            if(s[i] == 'B') cb = true;
        }
 
        istringstream ss(s);
        vs v;
        string word;
        while(getline(ss, word, 'W')) v.pb(word);
        for(auto k : v) {
            if(k.size() == 1) ok = false;
            else {
                bool ok1 = false, ok2 = false;
                if(k == "") continue;
                for(auto c : k) {
                    if(c == 'R') ok1 = true;
                    if(c == 'B') ok2 = true;
                }
                if(!ok1 || !ok2) ok = false;
            }
        }
 
        if(!(cr && cb)) ok = false;
 
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
 
    return 0;
}