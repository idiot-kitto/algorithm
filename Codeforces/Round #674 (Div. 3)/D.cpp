#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const int MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int n, ans;
vector<ll> v;

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;v.resize(n);
    for(int i=0 ; i<n ; i++) cin >> v[i];
    set<ll> s;
    s.insert(0);
    ll sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += v[i];
        if(s.find(sum) != s.end()){
            ans++;
            sum = v[i];
            s.clear();
            s.insert(0);
        }
        s.insert(sum);
    }
    cout << ans;
    return 0;
}
