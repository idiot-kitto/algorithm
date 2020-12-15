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
    int v[51], cnt = 1;
    for(int i=0 ; i<51 ; i++) v[i] = -1;
    for(int i=1 ; i<10 ; i++) v[i] = i;
    for(int i=10 ; i<18 ; i++) v[i] = (10*cnt++)+9; cnt = 1;
    for(int i=18 ; i<25 ; i++) v[i] = (100*cnt++)+89; cnt = 1;
    for(int i=25 ; i<31 ; i++) v[i] = (1000*cnt++)+789; cnt = 1;
    for(int i=31 ; i<36 ; i++) v[i] = (10000*cnt++)+6789; cnt = 1;
    for(int i=36 ; i<40 ; i++) v[i] = (100000*cnt++)+56789; cnt = 1;
    for(int i=40 ; i<43 ; i++) v[i] = (1000000*cnt++)+456789; cnt = 1;
    for(int i=43 ; i<45 ; i++) v[i] = (10000000*cnt++)+3456789 ; cnt = 1;
    v[45] = 123456789;
    while(t--){
        int x; cin >> x;
        cout << v[x] << '\n';
    }
    return 0;
}
