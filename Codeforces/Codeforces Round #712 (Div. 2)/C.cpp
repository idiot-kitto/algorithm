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
        int n; cin >> n;
        string s; cin >> s;
 
        int n0 = 0, n1 = 0;
 
        for(int i=0 ; i<n ; i++){
            if(s[i] == '0') n0++;
            else if(s[i] == '1') n1++;
        }
 
        if(s[0] == '0' || s[n-1] == '0'){ cout << "NO\n"; continue;}
        if(n0 % 2){ cout << "NO\n"; continue;}
 
        cout << "YES\n";
 
        string ss = "";
        int cnt0 = 0, cnt1 = 0;
        for(int i=0 ; i<n ; i++){
            if(s[i] == '0'){
                if(cnt0 % 2 == 0) ss += '(';
                else ss += ')';
                cnt0++;
            }
            else if(s[i] == '1'){
                if(cnt1 < n1 / 2) ss += '(';
                else ss += ')';
                cnt1++;
            }
        }
        cout << ss << '\n';
        for(int i=0 ; i<n ; i++){
            if(s[i] == '1') cout << ss[i];
            else{
                if(ss[i] == '(') cout << ')';
                else cout << '(';
            }
        }cout << '\n';
 
 
    }
 
    return 0;
}
