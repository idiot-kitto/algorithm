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
        int n,m, cnt = 0; cin >> n >> m;
        int arr[100][2][2];
        bool check[100];
        for(int i=0 ; i<n ; i++){
            cin >> arr[i][0][0] >> arr[i][0][1] >> arr[i][1][0] >> arr[i][1][1];
            if(arr[i][0][1] == arr[i][1][0]){
                check[i] = true;
                cnt++;
            }
        }
        if(m%2 == 0){
            if(cnt){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
