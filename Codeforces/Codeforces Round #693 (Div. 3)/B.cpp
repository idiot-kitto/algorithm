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
        int n; cin >> n; vi v(n);
        int sum = 0, one = 0, two = 0;
        for(int i=0 ; i<n ; i++) {cin >> v[i]; sum += v[i]; if(v[i]==1) one++; if(v[i]==2) two++;}
        if(sum % 2 != 0){cout << "NO\n";}
        else{
            if(two % 2 == 0){
                if(one % 2 == 0) cout << "YES\n";
                else cout << "NO\n";
            }else{
                if(one>=2){
                    if(one%2==0)cout << "YES\n";
                    else cout << "NO\n";
                }else cout << "NO\n";
            }
        }
    }
 
    return 0;
}
