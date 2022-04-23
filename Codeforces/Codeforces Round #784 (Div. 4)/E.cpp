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
        map<string, ll> mp;
        while(n--) {
            string s; cin >> s;
            mp[s]++;
        }
 
        ll ans = 0;
 
        for(int i=0 ; i<11 ; ++i) {
            char c = 'a';
            vl v;
            for(auto it : mp) {
                string s = it.first;
                if(s[0] == c+i) v.pb(it.second);
            }
            if(v.size() > 1) {
                for(int j=0 ; j<v.size()-1 ; ++j)
                    for(int k=j+1 ; k<v.size() ; ++k)
                        ans += v[j] * v[k];
            }
        }
 
        for(int i=0 ; i<11 ; ++i) {
            char c = 'a';
            vl v;
            for(auto it : mp) {
                string s = it.first;
                if(s[1] == c+i) v.pb(it.second);
            }
            if(v.size() > 1) {
                for(int j=0 ; j<v.size()-1 ; ++j)
                    for(int k=j+1 ; k<v.size() ; ++k)
                        ans += v[j] * v[k];
            }
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}