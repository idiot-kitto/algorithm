#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> v;
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;v.resize(n);
        for(int i=0;i<n;i++)cin>>v[i];
        reverse(v.begin(),v.end());
        for(int i=0;i<n;i++)cout<<v[i] << " ";
        cout << "\n";
    }
    return 0;
}
