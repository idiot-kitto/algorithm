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

int dp[4040][4040], ans;

int main(){fastio
    string s1, s2; cin >> s1 >> s2;
    for(int i=0 ; i<s1.size() ; ++i) {
        for(int j=0 ; j<s2.size() ; ++j) {
            if(s1[i] == s2[j]) {
                if(!i || !j) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    } cout << ans;
    return 0;
}