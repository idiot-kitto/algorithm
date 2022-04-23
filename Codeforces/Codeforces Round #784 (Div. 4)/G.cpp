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
 
char arr[55][55];
 
int main(){fastio
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=m ; ++j) cin >> arr[i][j];
 
        for(int i=1 ; i<=m ; ++i) {
            for(int j=n ; j>=1 ; --j) {
                if(arr[j][i] == '.') {
                    for(int k=j-1 ; k>=1 ; --k) {
                        if(arr[k][i] == 'o') break;
                        else if(arr[k][i] == '*') { swap(arr[j][i], arr[k][i]); break; }
                    }
                }
            }
        }
 
        for(int i=1 ; i<=n ; ++i) {
            for(int j=1 ; j<=m ; ++j) cout << arr[i][j];
            cout << '\n';
        }
    }
 
    return 0;
}