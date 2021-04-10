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
        int n; cin >> n; vl b(n+3);
        for(int i=1 ; i<=n+2 ; i++) cin >> b[i];
        sort(b.begin()+1, b.end());
 
        ll sum = 0, k = b[n+2];
 
        for(int i=1 ; i<=n+1 ; i++) sum += b[i];
 
        for(int i=1 ; i<=n+1 ; i++){
            if(k == sum - b[i]){
                for(int j=1 ; j<=n+1 ; j++){
                    if(j != i) cout << b[j] << ' ';
                }cout << '\n'; goto here;
            }
        }
 
        k = b[n+1];
        sum = 0;
        for(int i=1 ; i<=n ; i++) sum += b[i];
        if(sum == k){
            for(int i=1 ; i<=n ; i++) cout << b[i] << ' '; cout << '\n';
        }else cout << "-1\n";
 
 
        here:;
    }
 
    return 0;
}
