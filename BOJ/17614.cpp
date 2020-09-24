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

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        string s = to_string(i);
        for(int i=0 ; i<s.size() ; i++)
            if(s[i] == '3' || s[i] == '6' || s[i] == '9') ans++;
    }
    cout << ans;

    return 0;
}
