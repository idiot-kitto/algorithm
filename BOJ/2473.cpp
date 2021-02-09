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

int main(){fastio
    int n; cin >> n; vl v(n+1);
    for(int i=1 ; i<=n ; i++) cin >> v[i];
    sort(v.begin()+1, v.end());
    ll a, b, c, val = 1e18;
    for(int i=1 ; i<=n-2 ; i++){
        int l = i+1, r = n;
        while(1){
            if(l>=r) break;
            ll tmp = v[i] + v[l] + v[r];
            if(tmp == 0){a = v[i], b = v[l], c = v[r]; goto here;}
            if(abs(tmp) < val) a = v[i], b = v[l], c = v[r], val = abs(tmp);

            if(tmp > 0) r--;
            else l++;
        }
    }here:; cout << a << ' ' << b << ' ' << c;
    return 0;
}
