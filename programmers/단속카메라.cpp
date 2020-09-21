#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> routes) {
    int ans = 1;
    sort(routes.begin(),routes.end());
    int cur = routes[0][1];
    for(int i=1 ; i<routes.size() ; i++){
        if(routes[i][1] < cur) cur = routes[i][1];
        if(routes[i][0] > cur) {cur = routes[i][1]; ans++;}
    }
    return ans;
}
