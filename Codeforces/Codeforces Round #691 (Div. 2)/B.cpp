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
    ll dp[1010];
    dp[1] = 4; dp[2] = 4; 
    dp[3] = 12; dp[4] = 9; 
    dp[5] = 24; dp[6] = 16;
    ll cnt = 5;
    ll val = 16;
    for(int i = 7 ; i<=1000 ; i++){
        if(i%2==0) {dp[i] = cnt*cnt; cnt++;}
        else {dp[i] = dp[i-2] + val; val += 4;}
    }
    int n; cin >> n; cout << dp[n];
 
    return 0;
}
