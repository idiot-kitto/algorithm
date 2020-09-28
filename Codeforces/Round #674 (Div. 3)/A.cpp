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
 
int t;
 
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        int n, x, ans = 0;
        cin >> n >> x;
        if(n<=2) {cout << 1 << "\n"; continue;}
        n-=2;ans++;
        if(n%x==0) ans += n/x;
        else {ans+= n/x;ans++;}
        cout << ans << "\n";
    }
    return 0;
}
