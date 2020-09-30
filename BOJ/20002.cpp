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

int n, arr[301][301], dp[301][301], ans = -INT_MAX;

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++){
            cin >> arr[i][j];
            dp[i][j] += arr[i][j];
            ans = max(ans, arr[i][j]);
        }
    for(int i=2 ; i<=n ; i++){
        dp[1][i] += dp[1][i-1];
        dp[i][1] += dp[i-1][1];
    }
    for(int i=2 ; i<=n ; i++)
        for(int j=2 ; j<=n ; j++) dp[i][j] += (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]);

    for(int i=2 ; i<=n ; i++)
        for(int j=i ; j<=n ; j++)
            for(int k=i ; k<=n ; k++)
                ans = max(ans, dp[j][k] - dp[j-i][k] - dp[j][k-i] + dp[j-i][k-i]);
            
    cout << ans;
    return 0;
}
