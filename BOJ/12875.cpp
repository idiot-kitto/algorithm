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

int arr[101][101];

int main(){fastio
    int n, d; cin >> n >> d;
    for(int i=1 ; i<=n ; ++i) {
        string s; cin >> s;
        for(int j=1 ; j<=n ; ++j) {
            if(i == j) continue;
            if(s[j-1] == 'Y') arr[i][j] = d;
            if(s[j-1] == 'N') arr[i][j] = 1e9;
        }
    }

    for(int k=1 ; k<=n ; ++k)
        for(int i=1 ; i<=n ; ++i)
            for(int j=1 ; j<=n ; ++j)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
    
    int ans = 0;
    for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=n ; ++j) ans = max(ans, arr[i][j]);
    cout << (ans == 1e9 ? -1 : ans);
    
    return 0;
}