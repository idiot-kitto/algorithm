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
    map<char, int> mp;
    mp['a'] = 1; mp['e'] = 1; mp['i'] = 1; mp['o'] = 1; mp['u'] = 1;
    
    while(1) {
        string s; cin >> s;
        if(s == "end") break;
        bool ok = false;
        for(int i=0 ; i<s.size() ; ++i) if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') { ok = true; break; }
        if(!ok) { cout << "<" << s << "> is not acceptable.\n"; continue; }
        if(s.size() >= 3) for(int i=0 ; i<s.size()-2 ; ++i) if(mp[s[i]] == mp[s[i+1]] && mp[s[i+1]] == mp[s[i+2]]) { ok = false; break; }
        if(!ok) { cout << "<" << s << "> is not acceptable.\n"; continue; }
        if(s.size() >= 2) for(int i=0 ; i<s.size()-1 ; ++i) if(s[i] == s[i+1] && !(s[i] == 'e' || s[i] == 'o')) { ok = false; break; }
        if(!ok) { cout << "<" << s << "> is not acceptable.\n"; continue; }
        cout << "<" << s << "> is acceptable.\n";
    }
    return 0;
}