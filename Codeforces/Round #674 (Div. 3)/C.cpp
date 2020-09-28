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
 
        int n, num, ans; cin >> n;
        for(int i=1 ; i<=32000 ; i++){
            if(n>=i*i) continue;
            else {num = i-1; break;}
        }
        if(n == 1) {cout << 0 <<"\n"; continue;}
        if(n%num == 0) ans = num + n/num - 2;
        else ans = num + n/num - 1;
 
        cout << ans << "\n";
    }
    return 0;
}
