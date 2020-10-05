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

string s;
ll ans, pw[100010];
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s;
    reverse(s.begin(),s.end());
    ll sum = 0; pw[0] = 1;
    for(int i=1 ; i<100010 ; i++) pw[i] = pw[i-1] * 10 % MOD;
    for(int i=0 ; i<s.size() ; i++){
        ans = (ans + (((ll)(s.size()-i-1)*(ll)(s.size()-i)/2) % MOD) * (pw[i]*(s[i]-'0'))) % MOD;
        // number of possible cases * value of s[i]
        ans = (ans + (s[i]-'0')*sum) % MOD;
        sum = (sum + pw[i]*(i+1)) % MOD;
        // sum progress : 1 > 21 > 321 > 4321 .... 
    }
    cout << ans;
    return 0;
}
