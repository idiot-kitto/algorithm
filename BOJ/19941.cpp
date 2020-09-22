#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
bool check;
string s;
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k >> s;
    for(int i=0 ; i<n ; i++){
        check = false;
        for(int j=k ; j>=1 ; j--)
            if(i-j>=0 && s[i]=='P' && s[i-j]=='H'){
                ans++; s[i-j] = 'X';
                check = true;
                break;
            }
        if(check) continue;
        for(int j=1 ; j<=k ; j++)
            if(i+j<n && s[i]=='P' && s[i+j]=='H'){
                ans++; s[i+j] = 'X';
                break;
            }
    }
    cout << ans;
    return 0;
}
