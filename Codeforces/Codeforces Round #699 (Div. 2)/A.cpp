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
        int px, py; cin >> px >> py;
        string s; cin >> s;
        int r=0, u=0, l=0, d=0, rr=0, uu=0, ll=0, dd=0;
        if(px>0) rr = px;
        else if(px<0) ll = -px;
 
        if(py>0) uu = py;
        else if(py<0) dd = -py;
 
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == 'R') r++;
            else if(s[i] == 'U') u++;
            else if(s[i] == 'L') l++;
            else if(s[i] == 'D') d++;
        }
        if(px>0){
            if(py>0){
                if(rr <= r && uu <= u){cout << "YES\n"; }
                else {cout << "NO\n"; }
            }else if(py<0){
                if(rr <= r && dd <= d){cout << "YES\n"; }
                else {cout << "NO\n"; }
            }else{
                if(rr <= r) cout << "YES\n";
                else cout << "NO\n";
            }
        }else if(px<0){
            if(py>0){
                if(ll <= l && uu <= u){cout << "YES\n"; }
                else {cout << "NO\n"; }
            }else if(py<0){
                if(ll <= l && dd <= d){cout << "YES\n"; }
                else {cout << "NO\n"; }
            }else{
                if(ll <= l)cout <<"YES\n";
                else cout << "NO\n";
            }
        }else{
            if(py>0){
                if(uu <= u) cout << "YES\n";
                else cout << "NO\n";
            }else if(py<0){
                if(dd <= d) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
 
    return 0;
}
