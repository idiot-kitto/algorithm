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
int dir[3][2] = {{-1,0}, {-1,-1}, {-1,1}};

int dp[4040];

int main(){fastio

    for(int i=0 ; i<4040 ; ++i) dp[i] = 1e9;

    dp[600] = 2;
    for(int i=1200 ; i<=3600 ; i+=600) dp[i] = min(dp[i], dp[i-600] + 1);

    dp[60] = 2;
    for(int i=120 ; i<=3600 ; i+=60) dp[i] = min(dp[i], dp[i-60] + 1);

    dp[30] = 1;
    for(int i=60 ; i<=3600 ; i+=30) dp[i] = min(dp[i], dp[i-30] + 1);

    dp[10] = 2;
    for(int i=20 ; i<=3600 ; i+=10) dp[i] = min(dp[i], dp[i-10] + 1);

    for(int i=630 ; i<=3600 ; i+=600) dp[i] = min(dp[i], dp[i-600] + 1);
    for(int i=90 ; i<=3600 ; i+=60) dp[i] = min(dp[i], dp[i-60] + 1);
    for(int i=20 ; i<=3600 ; i+=10) dp[i] = min(dp[i], dp[i-10] + 1);

    string str; cin >> str;
    int m = (str[0] - '0') * 10 + (str[1] - '0');
    int s = (str[3] - '0') * 10 + (str[4] - '0');
    int k = m * 60 + s;
    cout << dp[k];
    return 0;
}