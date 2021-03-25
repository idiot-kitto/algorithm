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
        int n; cin >> n; vi arr(n+1); map<int,int> mp;
        for(int i=1 ; i<=n ; i++) cin >> arr[i], mp[arr[i]]++;

        vpii v;
        for(auto &iter : mp) v.pb({iter.second, iter.first});
        sort(all(v), greater<>());

        vi vv;
        for(int i=0 ; i<v.size() ; i++)
            for(int j=0 ; j<v[i].first ; j++)
                vv.pb(v[i].second);

        vi ans(n+1,0);

        int tmp = 0;
        for(int i=1 ; i<=n ; i+=2) ans[i] = vv[tmp++];
        for(int i=2 ; i<=n ; i+=2) ans[i] = vv[tmp++];

        int val = 0;
        for(int i=1 ; i<n ; i+=2) if(ans[i] == ans[i+1]) val += 2;
        if(n%2) val++;
        cout << val << '\n';
    }
    return 0;
}
