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
        int a, b; cin >> a >> b; string s; cin >> s;
        int n = (int)s.size();
 
        for(int i=0 ; i<n ; i++){
            if(s[i] == '0') a--;
            else if(s[i] == '1') b--;
        }
 
        for(int i=0 ; i<n/2 ; i++){
            if(s[i] == '?' && s[n-1-i] != '?'){
                if(s[n-1-i] == '1'){s[i] = s[n-1-i]; b--;}
                else if(s[n-1-i] == '0'){s[i] = s[n-1-i]; a--;}
            }else if((s[i] != '?' && s[n-1-i] == '?')){
                if(s[i] == '1'){s[n-1-i] = s[i]; b--;}
                else if(s[i] == '0'){s[n-1-i] = s[i]; a--;}
            }
        }
 
        for(int i=0 ; i<n/2 ; i++){
            if(s[i] == '?'){
                if(a>1){
                    s[i] = '0';
                    s[n-i-1] = '0';
                    a -= 2;
                }else if(b>1){
                    s[i] = '1';
                    s[n-1-i] = '1';
                    b-=2;
                }
            }
        }
 
        if(n%2){
            if(a>0) {s[n/2] = '0';a--;}
            else if(b>0) {s[n/2] = '1';b--;}
        }
 
        if(a<0 || b<0){cout << "-1\n"; continue;}
 
        for(int i=0 ; i<n/2 ; i++){
            if(s[i] != s[n-1-i] || s[i] == '?' || s[n-1-i] == '?'){
                cout << "-1\n"; goto here;
            }
        }
 
        cout << s << '\n';
 
        here:;
    }
 
    return 0;
}
