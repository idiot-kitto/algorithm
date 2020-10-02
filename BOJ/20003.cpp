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

ll n, a, b, ja, mo;
vector<pll> v;
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a >> b;
        if(gcd(a,b) != 1) {ll k = gcd(a,b); a/=k; b/=k;}
        v.push_back({a,b});
        if(!i) mo = b;
        mo = max(mo, mo*b/gcd(mo,b));
    }
    for(int i=0 ; i<n ; i++) v[i].first *= (mo / v[i].second);
    sort(all(v),[](const pll &x, const pll &y){
         return x.first > y.first;
         });
    for(int i=0 ; i<n ; i++){
        if(!i) ja = v[i].first;
        else ja = gcd(ja,v[i].first);
    }
    cout << ja << " " << mo;
    return 0;
}
