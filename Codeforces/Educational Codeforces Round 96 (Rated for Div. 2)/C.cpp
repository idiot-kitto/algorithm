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
 
int t, n;
 
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cout << 2 << "\n";
        int a = n-2, b = n;
        for(int i=0 ; i<n-1 ; i++){
            if(!i) cout << n-1 << " " << n << "\n";
            else cout << a-- << " " << b-- << "\n";
        }
 
    }
    return 0;
}
