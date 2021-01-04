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
        int n; cin >> n; deque<ll> even, odd;
        for(int i=0 ; i<n ; i++) {ll a; cin >> a; if(a%2) odd.pb(a); else even.pb(a);}
        sort(all(even)); reverse(all(even));
        sort(all(odd)); reverse(all(odd));
        ll alice = 0, bob = 0;
        while(1){
            if(even.empty() && odd.empty()) break;
 
            if(!even.empty() && !odd.empty()){
                if(even[0] > odd[0]){alice += even[0]; even.pop_front();}
                else odd.pop_front();
            }else if(!even.empty() && odd.empty()){alice += even[0]; even.pop_front();}
            else if(even.empty() && !odd.empty()){odd.pop_front();}
 
            if(even.empty() && odd.empty()) break;
 
            if(!odd.empty() && !even.empty()){
                if(odd[0] > even[0]){bob += odd[0]; odd.pop_front();}
                else even.pop_front();
            }else if(!odd.empty() && even.empty()){bob += odd[0]; odd.pop_front();}
            else if(odd.empty() && !even.empty()){even.pop_front();}
        }
        if(alice > bob) cout << "Alice\n";
        else if(alice < bob) cout << "Bob\n";
        else cout << "Tie\n";
    }
 
    return 0;
}
