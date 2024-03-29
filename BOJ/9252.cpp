#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100001

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

string dp[1010][1010];

int main(){fastio
    string s1, s2; cin >> s1 >> s2;
    for(int i=1 ; i<=s1.size() ; ++i)
        for(int j=1 ; j<=s2.size() ; ++j) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + s1[i-1];
            else {
                if(dp[i-1][j].size() >= dp[i][j-1].size()) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i][j-1];
            }
        }

    cout << dp[s1.size()][s2.size()].size() << '\n' << dp[s1.size()][s2.size()];

    return 0;
}

