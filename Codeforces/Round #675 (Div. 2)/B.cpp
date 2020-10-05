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

int t, n, m;

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> n >> m;
        ll arr[n+1][m+1];
        for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) cin >> arr[i][j];

        for(int i=1 ; i<=n/2 ; i++){
            for(int j=1 ; j<=m/2 ; j++){
                vector<ll> v;
                v.push_back(arr[i][j]);
                v.push_back(arr[i][m-j+1]);
                v.push_back(arr[n-i+1][j]);
                v.push_back(arr[n-i+1][m-j+1]);
                sort(v.begin(),v.end());
                ans += abs(v[1] - arr[i][j]);
                ans += abs(v[1] - arr[i][m-j+1]);
                ans += abs(v[1] - arr[n-i+1][j]);
                ans += abs(v[1] - arr[n-i+1][m-j+1]);
            }
        }
        if(n%2){
            int l=1,r=m;
            while(l<r){
                ans+=abs(arr[n/2+1][l]-arr[n/2+1][r]);
                l++;r--;
            }
        }
        if(m%2){
            int l=1,r=n;
            while(l<r){
                ans+=abs(arr[l][m/2+1]-arr[r][m/2+1]);
                l++;r--;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
