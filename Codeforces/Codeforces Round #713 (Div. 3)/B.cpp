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
        int n; cin >> n; vector<vc> v(n+1,vc(n+1));
        int a=0, b=0, c=0, d=0;
        for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++){cin >> v[i][j]; if(v[i][j] == '*'){if(!a){a=i;b=j;} else{c=i;d=j;}}}
 
        if(a != c && b != d){
            v[a][d] = '*';
            v[c][b] = '*';
        }
        else if(a == c && b != d){
            if(a != 1){
                v[a-1][b] = '*';
                v[a-1][d] = '*';
            }else{
                v[a+1][b] = '*';
                v[a+1][d] = '*';
            }
        }
        else if(a != c && b == d){
            if(b != 1){
                v[a][b-1] = '*';
                v[c][b-1] = '*';
            }else{
                v[a][b+1] = '*';
                v[c][b+1] = '*';
            }
        }
 
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++) cout << v[i][j];
            cout << '\n';
        }
 
    }
 
    return 0;
}
