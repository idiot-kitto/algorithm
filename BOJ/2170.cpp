#include <bits/stdc++.h>
using namespace std;
int n, s, e, ans, l = -INT_MAX, r = -INT_MAX;
pair<int,int> line[1000000];
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> s >> e;
        line[i] = make_pair(s,e);
    }
    sort(line, line + n);

    for(int i=0 ; i<n ; i++){
        if(r < line[i].first){
            ans += r-l;
            l = line[i].first;
            r = line[i].second;
        }
        else r = max(r, line[i].second);
    }
    ans += r-l;
    cout << ans;
    return 0;
}
