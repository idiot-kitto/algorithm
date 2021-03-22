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
	while(t--) {
		int n, m; cin >> n >> m; vi ans(m+1, 0), f[m+1], check(n+1, 0);
		for(int i=1 ; i<=m ; i++){
            int a; cin >> a;
            for(int j=0 ; j<a ; j++){
                int b; cin >> b;
                f[i].pb(b);
            }
		}
 
		for(int i=1 ; i<=m ; i++){
            if(f[i].size() == 1){
                int k = f[i][0];
                ans[i] = k;
                check[k]++;
            }
		}
 
		for(int i=1 ; i<=m ; i++){
            if(f[i].size() > 1){
                for(int j=0 ; j<f[i].size() ; j++){
                    int k = f[i][j];
                    if(check[k] < (m+1)/2){
                        ans[i] = k;
                        check[k]++;
                        break;
                    }
                }
            }
		}
 
		for(int i=1 ; i<=n ; i++){
            if(check[i] > (m+1)/2) {cout << "NO\n"; goto here;}
		}
		cout << "YES\n";
		for(int i=1 ; i<=m ; i++) cout << ans[i] << ' '; cout << '\n';
		here:;
 
	}
}
